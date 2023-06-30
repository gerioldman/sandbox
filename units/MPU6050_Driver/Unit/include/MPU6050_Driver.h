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

typedef struct
{
    SMPLRT_DIV_Type smplrt_div;
    CONFIG_Type config;
    GYRO_CONFIG_Type gyro_config;
    ACCEL_CONFIG_Type accel_config;
    FIFO_EN_Type fifo_en;
    I2C_MST_CTRL_Type i2c_mst_ctrl;
    USER_CTRL_Type user_ctrl;
    PWR_MGMT_1_Type pwr_mgmt_1;
    PWR_MGMT_2_Type pwr_mgmt_2;
}MPU6050_InitTypeDef;



/* Defines -------------------------------------------------------------------*/

#define MPU6050_ADDRESS 0x68u

/* Global variables ----------------------------------------------------------*/


/* Function declarations -----------------------------------------------------*/

/**
 * @brief MPU6050 initialization
 * 
 * @param init_struct Pointer to a MPU6050_InitTypeDef structure, if NULL default initialization is used
 * @return MPU6050_StatusTypeDef MPU6050_OK if initialization was successful, MPU6050_ERROR otherwise
 */
MPU6050_StatusTypeDef MPU6050_Init(MPU6050_InitTypeDef *init_struct);

/**
 * @brief Read accelerometer data from MPU6050
 * 
 * @param accelerometer 
 * @return MPU6050_StatusTypeDef 
 */
MPU6050_StatusTypeDef MPU6050_Read_Accelerometer(MPU6050_AccelData *accelerometer);

/**
 * @brief Read gyroscope data from MPU6050
 * 
 * @param gyro 
 * @return MPU6050_StatusTypeDef 
 */
MPU6050_StatusTypeDef MPU6050_Read_Gyroscope(MPU6050_GyroData *gyro);

#endif /* MPU6050_DRIVER_H */