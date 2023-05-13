/**
 * @file MPU6050_Driver.h
 * @brief Contains the available functions for the MPU6050_Driver
 * @date 4/28/2023
*/
#ifndef MPU6050_DRIVER_H
#define MPU6050_DRIVER_H

/* Includes ------------------------------------------------------------------*/

#include "MPU6050_RegisterMap.h"

/* Type definitions ----------------------------------------------------------*/

typedef enum
{
    MPU6050_OK = 0x00u,
    MPU6050_ERROR = 0xFFu
} MPU6050_StatusTypeDef;

typedef struct
{
    int16_t X;
    int16_t Y;
    int16_t Z;
}MPU6050_AccelData;

typedef struct
{
    int16_t X;
    int16_t Y;
    int16_t Z;
}MPU6050_GyroData;


/* Defines -------------------------------------------------------------------*/

#define MPU6050_ADDRESS 0x68u

/* Global variables ----------------------------------------------------------*/


/* Function declarations -----------------------------------------------------*/

MPU6050_StatusTypeDef MPU6050_Init();

MPU6050_StatusTypeDef MPU6050_Read_Accelerometer(MPU6050_AccelData *accelerometer);

MPU6050_StatusTypeDef MPU6050_Read_Gyroscope(MPU6050_GyroData *gyro);

#endif /* MPU6050_DRIVER_H */