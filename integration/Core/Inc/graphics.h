/*
 * graphics.h
 *
 *  Created on: 2022. jan. 31.
 *      Author: kgerg
 */

#ifndef INC_GRAPHICS_H_
#define INC_GRAPHICS_H_

#include <stdint.h>
#include "Complementary_Filter.h"

//
typedef struct vector3d {
	float x, y, z;
} vector3d;

typedef struct triangle{
	vector3d p[3];
}triangle;

typedef struct cube_mesh
{
	triangle triangles[12];
}cube_mesh;

cube_mesh Graphics_CreateSizeCube(float size);

#endif /* INC_GRAPHICS_H_ */

typedef struct mat4x4
{
	float mat[4][4];
}mat4x4;

//Globals
extern float fNear;
extern float fFar;
extern float fFov;
extern float fAspectRatio;
extern float fFovRad;

extern mat4x4 proj_mat;
extern cube_mesh cube;

// Functions

void Graphics_Init();
void MultiplyMatrixVector(vector3d *i,vector3d *o, mat4x4 *m);
void Graphics_Draw(Orientation_Data_t orientation_data);
void Graphics_DrawLine(int x0,int y0, int x1,int y1,uint16_t colour);
void Graphics_Draw_Triangle(int x0,int x1,int x2,int y0,int y1,int y2,uint16_t colour);
void Graphics_Draw_FilledTriangle(int x0,int x1,int x2,int y0,int y1, int y2,uint16_t colour);
