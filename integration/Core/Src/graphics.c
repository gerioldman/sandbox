/*
 * graphics.c
 *
 *  Created on: 2022. jan. 31.
 *      Author: kgerg
 */
#include "graphics.h"
#include "math.h"
#include "ST7789.h"

mat4x4 proj_mat;
cube_mesh cube;

void Graphics_Init() {
	float fNear = 0.1f;
	float fFar = 1000.0f;
	float fFov = 90.0f;
	float fAspectRatio = 1;
	float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

	proj_mat.mat[0][0] = fAspectRatio * fFovRad;
	proj_mat.mat[0][1] = 0.0f;
	proj_mat.mat[0][2] = 0.0f;
	proj_mat.mat[0][3] = 0.0f;
	proj_mat.mat[1][0] = 0.0f;
	proj_mat.mat[1][1] = fFovRad;
	proj_mat.mat[1][2] = 0.0f;
	proj_mat.mat[1][3] = 0.0f;
	proj_mat.mat[2][0] = 0.0f;
	proj_mat.mat[2][1] = 0.0f;
	proj_mat.mat[2][2] = fFar / (fFar - fNear);
	proj_mat.mat[3][0] = 0.0f;
	proj_mat.mat[3][1] = 0.0f;
	proj_mat.mat[3][2] = (-fFar * fNear) / (fFar - fNear);
	proj_mat.mat[2][3] = 1.0f;
	proj_mat.mat[3][3] = 0.0f;

	cube = Graphics_CreateSizeCube(1.0f);
}
cube_mesh Graphics_CreateSizeCube(float size) {
	cube_mesh return_cube = { 0.0f, 0.0f, 0.0f, 0.0f, size, 0.0f, size, size,
			0.0f, 0.0f, 0.0f, 0.0f, size, size, 0.0f, size, 0.0f, 0.0f,

			size, 0.0f, 0.0f, size, size, 0.0f, size, size, size, size, 0.0f,
			0.0f, size, size, size, size, 0.0f, size,

			size, 0.0f, size, size, size, size, 0.0f, size, size, size, 0.0f,
			size, 0.0f, size, size, 0.0f, 0.0f, size,

			0.0f, 0.0f, size, 0.0f, size, size, 0.0f, size, 0.0f, 0.0f, 0.0f,
			size, 0.0f, size, 0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, size, 0.0f, 0.0f, size, size, size, size, size, 0.0f, size,
			0.0f, size, size, size, size, size, 0.0f,

			size, 0.0f, size, 0.0f, 0.0f, size, 0.0f, 0.0f, 0.0f, size, 0.0f,
			size, 0.0f, 0.0f, 0.0f, size, 0.0f, 0.0f };
	return return_cube;
}
void Graphics_DrawLine(int x0, int y0, int x1, int y1,uint16_t colour) {
	int dx = fabsf(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -fabsf(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	for (;;) { /* loop */
		ST7789_WritePixel_Buffer(x0, y0,colour);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		} /* e_xy+e_x > 0 */
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		} /* e_xy+e_y < 0 */
	}
}
void Graphics_Draw() {
	triangle triProjected, triTranslated;

	mat4x4 matRotZ, matRotX;
	vector3d camera = { 0.0f, 0.0f, 0.0f };
	vector3d light = {1.0f/sqrtf(3),1.0f/sqrtf(3),-1.0f/sqrtf(3)};
	static float fTheta = 0;

	matRotZ.mat[0][0] = cosf(fTheta);
	matRotZ.mat[0][1] = sinf(fTheta);
	matRotZ.mat[0][2] = 0;
	matRotZ.mat[0][3] = 0;
	matRotZ.mat[1][0] = -sinf(fTheta);
	matRotZ.mat[1][1] = cosf(fTheta);
	matRotZ.mat[1][2] = 0;
	matRotZ.mat[1][3] = 0;
	matRotZ.mat[2][0] = 0;
	matRotZ.mat[2][1] = 0;
	matRotZ.mat[2][2] = 1;
	matRotZ.mat[2][3] = 0;
	matRotZ.mat[3][0] = 0;
	matRotZ.mat[3][1] = 0;
	matRotZ.mat[3][2] = 0;
	matRotZ.mat[3][3] = 1;

	// Rotation X
	matRotX.mat[0][0] = 1;
	matRotX.mat[0][1] = 0;
	matRotX.mat[0][2] = 0;
	matRotX.mat[0][3] = 0;
	matRotX.mat[1][0] = 0;
	matRotX.mat[1][1] = cosf(fTheta * 0.5f);
	matRotX.mat[1][2] = sinf(fTheta * 0.5f);
	matRotX.mat[1][3] = 0;
	matRotX.mat[2][0] = 0;
	matRotX.mat[2][1] = -sinf(fTheta * 0.5f);
	matRotX.mat[2][2] = cosf(fTheta * 0.5f);
	matRotX.mat[2][3] = 0;
	matRotX.mat[3][0] = 0;
	matRotX.mat[3][1] = 0;
	matRotX.mat[3][2] = 0;
	matRotX.mat[3][3] = 1;

	ST7789_FillBuffer(0x0000);

	for (int i = 0; i < 12; i++) {

		triangle triRotatedZ, triRotatedZX;

		vector3d normal, line10, line20;

		// Rotate in Z-Axis
		MultiplyMatrixVector(&cube.triangles[i].p[0], &triRotatedZ.p[0],
				&matRotZ);
		MultiplyMatrixVector(&cube.triangles[i].p[1], &triRotatedZ.p[1],
				&matRotZ);
		MultiplyMatrixVector(&cube.triangles[i].p[2], &triRotatedZ.p[2],
				&matRotZ);

		// Rotate in X-Axis
		MultiplyMatrixVector(&triRotatedZ.p[0], &triRotatedZX.p[0], &matRotX);
		MultiplyMatrixVector(&triRotatedZ.p[1], &triRotatedZX.p[1], &matRotX);
		MultiplyMatrixVector(&triRotatedZ.p[2], &triRotatedZX.p[2], &matRotX);

		triTranslated = triRotatedZX;
		triTranslated.p[0].z += 3.0f;
		triTranslated.p[1].z += 3.0f;
		triTranslated.p[2].z += 3.0f;

		line10.x = triTranslated.p[1].x - triTranslated.p[0].x;
		line10.y = triTranslated.p[1].y - triTranslated.p[0].y;
		line10.z = triTranslated.p[1].z - triTranslated.p[0].z;

		line20.x = triTranslated.p[2].x - triTranslated.p[0].x;
		line20.y = triTranslated.p[2].y - triTranslated.p[0].y;
		line20.z = triTranslated.p[2].z - triTranslated.p[0].z;

		normal.x = line10.y * line20.z - line10.z * line20.y;
		normal.y = line10.z * line20.x - line10.x * line20.z;
		normal.z = line10.x * line20.y - line10.y * line20.x;

		float l = sqrtf(
				normal.x * normal.x + normal.y * normal.y
						+ normal.z * normal.z);
		normal.x /= l;
		normal.y /= l;
		normal.z /= l;

		if (((normal.x * triTranslated.p[0].x - camera.x)
				+ (normal.y * triTranslated.p[0].y - camera.y)
				+ (normal.z * triTranslated.p[0].z - camera.z)) < 0.0f) {

			MultiplyMatrixVector(&triTranslated.p[0], &triProjected.p[0],
					&proj_mat);
			MultiplyMatrixVector(&triTranslated.p[1], &triProjected.p[1],
					&proj_mat);
			MultiplyMatrixVector(&triTranslated.p[2], &triProjected.p[2],
					&proj_mat);


			float lum = normal.x*light.x + normal.y*light.y + normal.z*light.z;
			uint16_t colour = 0x0000;
			colour += ((uint16_t)(lum*2.0f*2.0f*2.0f*2.0f*2.0f-1.0f)) << 11;
			colour += (uint16_t)(lum*2.0f*2.0f*2.0f*2.0f*2.0f-1.0f) ;
			colour += ((uint16_t)(lum*2.0f*2.0f*2.0f*2.0f*2.0f*2.0f-1.0f)) << 5;

			triProjected.p[0].x += 1.0f;
			triProjected.p[0].y += 1.0f;
			triProjected.p[1].x += 1.0f;
			triProjected.p[1].y += 1.0f;
			triProjected.p[2].x += 1.0f;
			triProjected.p[2].y += 1.0f;

			triProjected.p[0].x *= 0.5f * 240.0f;
			triProjected.p[0].y *= 0.5f * 240.0f;
			triProjected.p[1].x *= 0.5f * 240.0f;
			triProjected.p[1].y *= 0.5f * 240.0f;
			triProjected.p[2].x *= 0.5f * 240.0f;
			triProjected.p[2].y *= 0.5f * 240.0f;
			Graphics_Draw_FilledTriangle((int) triProjected.p[0].x,
					(int) triProjected.p[1].x, (int) triProjected.p[2].x,
					(int) triProjected.p[0].y, (int) triProjected.p[1].y,
					(int) triProjected.p[2].y,colour);
			/*Graphics_Draw_Triangle((int) triProjected.p[0].x,
								(int) triProjected.p[1].x, (int) triProjected.p[2].x,
								(int) triProjected.p[0].y, (int) triProjected.p[1].y,
								(int) triProjected.p[2].y,0x0000);*/


		}
	}
	fTheta += 0.1f;
}
void Graphics_Draw_Triangle(int x0, int x1, int x2, int y0, int y1, int y2,uint16_t colour) {
	Graphics_DrawLine(x0, y0, x1, y1,colour);
	Graphics_DrawLine(x0, y0, x2, y2,colour);
	Graphics_DrawLine(x1, y1, x2, y2,colour);
}
void swap(int * x0, int* x1)
{
	int temp;
	temp = *x0;
	*x0 = *x1;
	*x1 = temp;
}
void Graphics_Draw_FilledTriangle(int x0, int x1, int x2, int y0, int y1,
		int y2, uint16_t colour) {

	int width = 240;
	    int height = 240;
	    // sort the points vertically
	    if (y1 > y2)
	    {
	        swap(&x1, &x2);
	        swap(&y1,&y2);
	    }
	    if (y0 > y1)
	    {
	        swap(&x0,&x1);
	        swap(&y0,&y1);
	    }
	    if (y1 > y2)
	    {
	        swap(&x1,&x2);
	        swap(&y1,&y2);
	    }

	    float dx_far =(float) (x2 - x0) / (y2 - y0 + 1);
	    float dx_upper = (float) (x1 - x0) / (y1 - y0 + 1);
	    float dx_low = (float) (x2 - x1) / (y2 - y1 + 1);
	    float xf = x0;
	    float xt = x0 + dx_upper; // if y0 == y1, special case
	    for (int y = y0; y <= (y2 > height-1 ? height-1 : y2); y++)
	    {
	        if (y >= 0)
	        {
	            for (int x = (xf > 0 ? (int)(xf) : 0);
	                 x <= (xt < width ? xt : width-1) ; x++)
	                ST7789_WritePixel_Buffer(x, y,colour);
	            for (int x = (xf < width ? (int)(xf) : width-1);
	                 x >= (xt > 0 ? xt : 0); x--)
	            	ST7789_WritePixel_Buffer(x, y,colour);
	        }
	        xf += dx_far;
	        if (y < y1)
	            xt += dx_upper;
	        else
	            xt += dx_low;
	    }

}
void MultiplyMatrixVector(vector3d *i, vector3d *o, mat4x4 *m) {
	o->x = i->x * m->mat[0][0] + i->y * m->mat[1][0] + i->z * m->mat[2][0]
			+ m->mat[3][0];
	o->y = i->x * m->mat[0][1] + i->y * m->mat[1][1] + i->z * m->mat[2][1]
			+ m->mat[3][1];
	o->z = i->x * m->mat[0][2] + i->y * m->mat[1][2] + i->z * m->mat[2][2]
			+ m->mat[3][2];
	float w = i->x * m->mat[0][3] + i->y * m->mat[1][3] + i->z * m->mat[2][3]
			+ m->mat[3][3];

	if (w != 0.0f) {
		o->x /= w;
		o->y /= w;
		o->z /= w;
	}
}
