/*
 * ST7789.c
 *
 *  Created on: Jan 14, 2022
 *      Author: kgerg
 */

#include "ST7789.h"

// extern LL_SPI_HandleTypeDef hspi1;
uint8_t *current_buffer;
extern SPI_HandleTypeDef hspi1;

void ST7789_WriteCommand(uint8_t pData)
{
	ST7789_DC_Reset();
	ST7789_CS_Reset();
	//LL_SPI_TransmitData8(SPI1, pData);
	//while (!LL_SPI_IsActiveFlag_EOT(SPI1))
	//{
	//	;
	//}
	 HAL_SPI_Transmit/*_DMA*/(&hspi1, &pData, 1,HAL_MAX_DELAY); // Just sending a byte
	// ST7789_DMA_Wait();
	ST7789_CS_Set();
}
void ST7789_WritePixel_Buffer(int x, int y, uint16_t colour)
{
	if ((0 <= x && x < 240) && (0 <= y && y < 240))
	{
		display_next[y * 480 + 2 * x] = (uint8_t)((colour & 0xFF00) >> 8);
		display_next[y * 480 + 2 * x + 1] = (uint8_t)colour & 0xFF;
	}
}
void ST7789_DMA_Wait()
{
	// while(HAL_DMA_GetState(hspi1.hdmatx) != HAL_DMA_STATE_READY);
}
void ST7789_FillBuffer(uint16_t colour)
{
	for (int i = 0; i < 115200; i += 2)
	{
		display_next[i] = (uint8_t)((colour & 0xFF00) >> 8);
		display_next[i + 1] = (uint8_t)(colour & 0xFF);
	}
}
void ST7789_WriteSmallData(uint8_t pData)
{
	ST7789_DC_Set();
	ST7789_CS_Reset();
	//LL_SPI_TransmitData8(SPI1, pData);
	//while (!LL_SPI_IsActiveFlag_EOT(SPI1))
	//{
	//	;
	//}
	 HAL_SPI_Transmit/*_DMA*/(&hspi1, &pData, 1,HAL_MAX_DELAY); // Just sending a byte
	// ST7789_DMA_Wait();
	ST7789_CS_Set();
}
void ST7789_WriteData(uint8_t *pData, uint16_t length)
{
	ST7789_DC_Set();
	ST7789_CS_Reset();
	//for (uint16_t i = 0; i < length; i++)
	//{
	//	LL_SPI_TransmitData8(SPI1, pData[i]);
	//	while (!LL_SPI_IsActiveFlag_EOT(SPI1))
	//	{
	//		;
	//	}
	//}
	 HAL_SPI_Transmit/*_DMA*/(&hspi1, pData, length,HAL_MAX_DELAY); // Just sending a byte
	// ST7789_DMA_Wait();
	ST7789_CS_Set();
}
void ST7789_SetRotation(uint8_t m)
{
	ST7789_WriteCommand(ST7789_MADCTL); // MADCTL
	switch (m)
	{
	case 0:
		ST7789_WriteSmallData(ST7789_MADCTL_MX | ST7789_MADCTL_MY | ST7789_MADCTL_RGB);
		break;
	case 1:
		ST7789_WriteSmallData(ST7789_MADCTL_MY | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
		break;
	case 2:
		ST7789_WriteSmallData(ST7789_MADCTL_RGB);
		break;
	case 3:
		ST7789_WriteSmallData(ST7789_MADCTL_MX | ST7789_MADCTL_MV | ST7789_MADCTL_RGB);
		break;
	default:
		break;
	}
}
// void ST7789_Refresh_Display(DMA_HandleTypeDef *_hdma)
//{
//		if(ST7789_Refresh_State == ST7789_DMA_Ready)
//		{
//			current_buffer = display;
//			ST7789_CS_Reset();
//			ST7789_DC_Set();
//			if(HAL_OK != HAL_SPI_Transmit_DMA(&hspi1, current_buffer, 57600)) while(1){continue;}
//			ST7789_Refresh_State = ST7789_DMA_Busy_FirstHalf;
//		}
//
//		else if(ST7789_Refresh_State == ST7789_DMA_Busy_FirstHalf)
//		{
//			ST7789_CS_Set();
//			ST7789_DC_Set();
//			ST7789_Refresh_State = ST7789_DMA_Busy_FirstHalf_Done;
//		}
//		else if(ST7789_Refresh_State == ST7789_DMA_Busy_SecondHalf)
//		{
//			ST7789_CS_Set();
//			ST7789_Refresh_State = ST7789_DMA_Ready;
//		}
// }
void ST7789_Draw_VerticalScanningLines()
{

	static int k = 0;

	for (int i = 0; i < 115200; i += 2)
	{
		if ((i / 2) % 240 == k)
		{
			display_next[i] = 0xFF;
			display_next[i + 1] = 0xFF;
		}
		else
		{
			display_next[i] = 0x00;
			display_next[i + 1] = 0x00;
		}
	}

	if (k == 239)
		k = 0;
	else
		k++;
}
void ST7789_Draw_MovingCircle()
{
	static int k = 0;
	for (int i = 0; i < 115200; i += 2)
	{
		int x = (i / 2) % 240 - 120;
		int y = (i / 2) / 240 - 120;
		if (((x * x + y * y - k * k) <= 100) && ((x * x + y * y - k * k) >= -100))
		{
			display_next[i] = 0xFF;
			display_next[i + 1] = 0xFF;
		}
		else
		{
			display_next[i] = 0x00;
			display_next[i + 1] = 0x00;
		}
	}
	if (k >= 119)
		k = 0;
	else
	{
		if (k <= 21)
			k += 7;
		else if (k <= 42)
			k += 6;
		else if (k <= 63)
			k += 5;
		else if (k <= 84)
			k += 4;
		else if (k <= 105)
			k += 3;
		else
			k += 2;
	}
}
void ST7789_SwitchBuffer()
{
	uint8_t *temp;
	temp = display_next;
	display_next = display;
	display = temp;
}
void ST7789_Init()
{
	//LL_SPI_Enable(SPI1);
	HAL_Delay(25);
	ST7789_RST_Reset();
	HAL_Delay(25);
	ST7789_RST_Set();
	HAL_Delay(50);

	ST7789_WriteCommand(ST7789_COLMOD); //	Set color mode
	ST7789_WriteSmallData(ST7789_COLOR_MODE_16bit);
	ST7789_WriteCommand(0xB2); //	Porch control
	{
		uint8_t data[] = {0x0C, 0x0C, 0x00, 0x33, 0x33};
		ST7789_WriteData(data, sizeof(data));
	}
	ST7789_SetRotation(ST7789_ROTATION); //	MADCTL (Display Rotation)

	/* Internal LCD Voltage generator settings */
	ST7789_WriteCommand(0XB7);	 //	Gate Control
	ST7789_WriteSmallData(0x35); //	Default value
	ST7789_WriteCommand(0xBB);	 //	VCOM setting
	ST7789_WriteSmallData(0x19); //	0.725v (default 0.75v for 0x20)
	ST7789_WriteCommand(0xC0);	 //	LCMCTRL
	ST7789_WriteSmallData(0x2C); //	Default value
	ST7789_WriteCommand(0xC2);	 //	VDV and VRH command Enable
	ST7789_WriteSmallData(0x01); //	Default value
	ST7789_WriteCommand(0xC3);	 //	VRH set
	ST7789_WriteSmallData(0x12); //	+-4.45v (default +-4.1v for 0x0B)
	ST7789_WriteCommand(0xC4);	 //	VDV set
	ST7789_WriteSmallData(0x20); //	Default value
	ST7789_WriteCommand(0xC6);	 //	Frame rate control in normal mode
	ST7789_WriteSmallData(0x0F); //	Default value (60HZ)
	ST7789_WriteCommand(0xD0);	 //	Power control
	ST7789_WriteSmallData(0xA4); //	Default value
	ST7789_WriteSmallData(0xA1); //	Default value
	/**************** Division line ****************/

	ST7789_WriteCommand(0xE0);
	{
		uint8_t data[] = {0xD0, 0x04, 0x0D, 0x11, 0x13, 0x2B, 0x3F, 0x54, 0x4C, 0x18, 0x0D, 0x0B, 0x1F, 0x23};
		ST7789_WriteData(data, sizeof(data));
	}

	ST7789_WriteCommand(0xE1);
	{
		uint8_t data[] = {0xD0, 0x04, 0x0C, 0x11, 0x13, 0x2C, 0x3F, 0x44, 0x51, 0x2F, 0x1F, 0x1F, 0x20, 0x23};
		ST7789_WriteData(data, sizeof(data));
	}
	ST7789_WriteCommand(ST7789_INVON);	//	Inversion ON
	ST7789_WriteCommand(ST7789_SLPOUT); //	Out of sleep mode
	ST7789_WriteCommand(ST7789_NORON);	//	Normal Display on
	ST7789_WriteCommand(ST7789_DISPON); //	Main screen turned on

	ST7789_WriteCommand(ST7789_CASET);
	{
		uint8_t data[] = {0, 0, 0, 239};
		ST7789_WriteData(data, sizeof(data));
	}

	ST7789_WriteCommand(ST7789_RASET);
	{
		uint8_t data[] = {0, 0, 0, 239};
		ST7789_WriteData(data, sizeof(data));
	}
	ST7789_WriteCommand(ST7789_RAMWR);

	for (int i = 0; i < 230400; i++)
	{
		ST7789_WriteSmallData(0xFF);
	}

	ST7789_Refresh_State = ST7789_DMA_Ready;
}
