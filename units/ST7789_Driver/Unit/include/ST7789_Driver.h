/**
 * @file ST7789_Driver.h
 * @brief Header file for the ST7789 driver, abstracts low level communication with the ST7789 display
 * providing a high level interface to the user.
 * @date 4/28/2023
*/
#ifndef ST7789_DRIVER_H
#define ST7789_DRIVER_H

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>
#include "ST7789_Driver_CommandList.h"

/* Type definitions ----------------------------------------------------------*/

typedef enum
{
    ST7789_OK = 0u,
    ST7789_ERROR = 1u
} ST7789_Status_Type;

typedef struct
{
    ST7789_COLMOD_Type COLMOD;
    ST7789_MADCTL_Type MADCTL;
    ST7789_CASET_Type CASET;
    ST7789_RASET_Type RASET;
} ST7789_InitStructure_Type;

/* Defines -------------------------------------------------------------------*/


/* Global variables ----------------------------------------------------------*/


/* Function declarations -----------------------------------------------------*/

ST7789_Status_Type ST7789_ReadID(ST7789_RDDID_Type *data);
ST7789_Status_Type ST7789_ReadStatus(ST7789_RDDST_Type *data);
ST7789_Status_Type ST7789_ReadPowerMode(ST7789_RDDPM_Type *data);
ST7789_Status_Type ST7789_ReadMemoryAccessControl(ST7789_RDDMADCTL_Type *data);
ST7789_Status_Type ST7789_ReadPixelFormat(ST7789_RDDCOLMOD_Type *data);
ST7789_Status_Type ST7789_ReadImageFormat(ST7789_RDDIM_Type *data);
ST7789_Status_Type ST7789_ReadSignalMode(ST7789_RDDSM_Type *data);
ST7789_Status_Type ST7789_ReadSelfDiagnosticResult(ST7789_RDDSDR_Type *data);
ST7789_Status_Type ST7789_ReadContentAdaptiveBrightnessControl(ST7789_RDCABC_Type *data);
ST7789_Status_Type ST7789_ReadAutomaticBrightnessControlSelfDiagnosticResult(ST7789_RDABCSDR_Type *data);
ST7789_Status_Type ST7789_ReadID1(ST7789_RDID1_Type *data);
ST7789_Status_Type ST7789_ReadID2(ST7789_RDID2_Type *data);
ST7789_Status_Type ST7789_ReadID3(ST7789_RDID3_Type *data);

ST7789_Status_Type ST7789_RequestSoftwareReset(void);
ST7789_Status_Type ST7789_Driver_Init(ST7789_InitStructure_Type init);

ST7789_Status_Type ST7789_WriteData(uint8_t *data, uint32_t length);
ST7789_Status_Type ST7789_WriteCommand(uint8_t command);
ST7789_Status_Type ST7789_WriteSmallData(uint8_t data);

#endif /* ST7789_DRIVER_H */