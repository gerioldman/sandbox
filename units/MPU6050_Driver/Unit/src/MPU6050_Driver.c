/**
 * @file MPU6050_Driver.c
 * @brief TODO - Add description
 * @date 4/28/2023
 */

/* Generated includes - Do not modify ----------------------------------------*/

/* Private includes ----------------------------------------------------------*/
// #define STM32H753xx
#include <stdint.h>
#include "i2c_abstraction.h"
#include "MPU6050_Driver.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

static uint8_t MPU6050_IsConnected();

/* Private functions ---------------------------------------------------------*/

static uint8_t MPU6050_IsConnected()
{
    WHO_AM_I_Type who_am_i = {0};

    // Read WHO_AM_I register
    if (I2C_Read(MPU6050_ADDRESS << 1, WHO_AM_I_ADDRESS, 1, &who_am_i.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    if (who_am_i.Byte == 0x68u)
    {
        return MPU6050_OK;
    }
    else
    {
        return MPU6050_ERROR;
    }
}

/* Public functions ----------------------------------------------------------*/

MPU6050_StatusTypeDef MPU6050_Init()
{
    // Test if MPU6050 is connected

    if (MPU6050_IsConnected() != MPU6050_OK)
    {
        return MPU6050_ERROR;
    }

    // Set sample rate to 1kHz

    SMPLRT_DIV_Type smplrt_div = {
        .Byte = 0x00u // Sample rate = Gyroscope output rate / (1 + SMPLRT_DIV) = 1kHz
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, SMPLRT_DIV_ADDRESS, 1, &smplrt_div.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Set configuration register

    CONFIG_Type config = {
        .DLPF_CFG = 0x01u,     // 1kHz sampling rate with ~188Hz bandwidth for both gyro and accelerometer
        .EXT_SYNC_SET = 0x00u, // No external sync
        .RESERVED = 0x00u      // Reserved
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, CONFIG_ADDRESS, 1, &config.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Set gyro configuration register to 250dps

    GYRO_CONFIG_Type gyro_config = {
        .FS_SEL = 0x00u, // 250dps
        .ZG_ST = 0x00u,  // do not run Z axis gyroscope self test
        .YG_ST = 0x00u,  // do not run Y axis gyroscope self test
        .XG_ST = 0x00u   // do not run X axis gyroscope self test
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, GYRO_CONFIG_ADDRESS, 1, &gyro_config.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Set accelerometer configuration register to 2g

    ACCEL_CONFIG_Type accel_config = {
        .AFS_SEL = 0x00u, // 2g
        .ZA_ST = 0x00u,   // do not run Z axis accelerometer self test
        .YA_ST = 0x00u,   // do not run Y axis accelerometer self test
        .XA_ST = 0x00u    // do not run X axis accelerometer self test
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, ACCEL_CONFIG_ADDRESS, 1, &accel_config.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Set FIFO enable register

    FIFO_EN_Type fifo_en = {
        .SLV0_FIFO_EN = 0x00u,  // disable slave 0 FIFO
        .SLV1_FIFO_EN = 0x00u,  // disable slave 1 FIFO
        .SLV2_FIFO_EN = 0x00u,  // disable slave 2 FIFO
        .ACCEL_FIFO_EN = 0x00u, // disable accelerometer FIFO
        .ZG_FIFO_EN = 0x00u,    // disable Z axis gyroscope FIFO
        .YG_FIFO_EN = 0x00u,    // disable Y axis gyroscope FIFO
        .XG_FIFO_EN = 0x00u,    // disable X axis gyroscope FIFO
        .TEMP_FIFO_EN = 0x00u   // disable temperature FIFO
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, FIFO_EN_ADDRESS, 1, &fifo_en.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    I2C_MST_CTRL_Type i2c_mst_ctrl = {
        .I2C_MST_CLK = 0x0Du,   // 400kHz
        .I2C_MST_P_NSR = 0x00u, // restart between reads
        .SLV_3_FIFO_EN = 0x00u, // disable slave 3
        .WAIT_FOR_ES = 0x00u,   // disable wait for external sensor data
        .MULT_MST_EN = 0x00u    // disable multi-master
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, I2C_MST_CTRL_ADDRESS, 1, &i2c_mst_ctrl.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Not using I2C slaves connected to MPU6050 so skip I2C_SLV0_ADDR to I2C_SLV4_DI
    // Skip I2C_SLV0_ADDR
    // Skip I2C_SLV0_REG
    // Skip I2C_SLV0_CTRL
    // Skip I2C_SLV1_ADDR
    // Skip I2C_SLV1_REG
    // Skip I2C_SLV1_CTRL
    // Skip I2C_SLV2_ADDR
    // Skip I2C_SLV2_REG
    // Skip I2C_SLV2_CTRL
    // Skip I2C_SLV3_ADDR
    // Skip I2C_SLV3_REG
    // Skip I2C_SLV3_CTRL
    // Skip I2C_SLV4_ADDR
    // Skip I2C_SLV4_REG
    // Skip I2C_SLV4_DO
    // Skip I2C_SLV4_CTRL
    // Skip I2C_SLV4_DI

    // Skip I2C_MST_STATUS, it is read only

    // Skip INT_PIN_CFG as interrupt is not used
    // TODO use interrupt later on

    // Skip INT_ENABLE as interrupt is not used

    // Skip INT_STATUS, it is read only

    // Skip ACCEL_XOUT_H as it is read only
    // Skip ACCEL_XOUT_L as it is read only
    // Skip ACCEL_YOUT_H as it is read only
    // Skip ACCEL_YOUT_L as it is read only
    // Skip ACCEL_ZOUT_H as it is read only
    // Skip ACCEL_ZOUT_L as it is read only

    // Skip TEMP_OUT_H as it is read only
    // Skip TEMP_OUT_L as it is read only

    // Skip GYRO_XOUT_H as it is read only
    // Skip GYRO_XOUT_L as it is read only
    // Skip GYRO_YOUT_H as it is read only
    // Skip GYRO_YOUT_L as it is read only
    // Skip GYRO_ZOUT_H as it is read only
    // Skip GYRO_ZOUT_L as it is read only

    // Skip EXT_SENS_DATA_00 to EXT_SENS_DATA_23 as they are read only

    // Skip I2C_SLV0_DO as slave 0 is not used
    // Skip I2C_SLV1_DO as slave 1 is not used
    // Skip I2C_SLV2_DO as slave 2 is not used
    // Skip I2C_SLV3_DO as slave 3 is not used

    // Skip I2C_MST_DELAY_CTRL as delay is not used

    // Skip SIGNAL_PATH_RESET as reset is not needed

    // Set user control register

    USER_CTRL_Type user_ctrl = {
        .SIG_COND_RESET = 0x00u, // do not reset signal paths
        .I2C_MST_RESET = 0x00u,  // do not reset I2C master
        .FIFO_RESET = 0x00u,     // do not reset FIFO
        .I2C_IF_DIS = 0x00u,     // DO NOT EVER DISABLE I2C INTERFACE
        .I2C_MST_EN = 0x00u,     // disable I2C master
        .FIFO_EN = 0x00u,        // disable FIFO
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, USER_CTRL_ADDRESS, 1, &user_ctrl.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Skip PWR_MGMT_1 as it is not used
    // TODO use power management later on -> sleep mode, clock source, etc.
    PWR_MGMT_1_Type pwr_mgmt_1 = {
        .DEVICE_RESET = 0x00u, // do not reset device
        .SLEEP = 0x00u,        // do not sleep
        .CYCLE = 0x00u,        // do not cycle
        .TEMP_DIS = 0x00u,     // do not disable temperature sensor
        .CLKSEL = 0x00u,        // use internal 8MHz oscillator
        .UNUSED = 0x00u        // unused
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, PWR_MGMT_1_ADDRESS, 1, &pwr_mgmt_1.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    // Skip PWR_MGMT_2 as it is not used
    PWR_MGMT_2_Type pwr_mgmt_2 = {
        .LP_WAKE_CTRL = 0x00u, // do not use low power wake up
        .STBY_XA = 0x00u,      // do not disable accelerometer X axis
        .STBY_YA = 0x00u,      // do not disable accelerometer Y axis
        .STBY_ZA = 0x00u,      // do not disable accelerometer Z axis
        .STBY_XG = 0x00u,      // do not disable gyroscope X axis
        .STBY_YG = 0x00u,      // do not disable gyroscope Y axis
        .STBY_ZG = 0x00u,      // do not disable gyroscope Z axis
    };

    if (I2C_Write(MPU6050_ADDRESS << 1, PWR_MGMT_2_ADDRESS, 1, &pwr_mgmt_2.Byte, 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    

    // Skip FIFO_COUNT_H as it is read only
    // Skip FIFO_COUNT_L as it is read only

    // Skip FIFO_R_W as FIFO is not used

    // Skip WHO_AM_I as it is read only

    return MPU6050_OK;
}

MPU6050_StatusTypeDef MPU6050_Read_Accelerometer(MPU6050_AccelData *accelerometer)
{
    if (accelerometer == (MPU6050_AccelData *)0u)
    {
        return MPU6050_ERROR;
    }

    uint8_t buffer[6];

    if (I2C_Read(MPU6050_ADDRESS << 1, ACCEL_XOUT_H_ADDRESS, 1, &buffer[0], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, ACCEL_XOUT_L_ADDRESS, 1, &buffer[1], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, ACCEL_YOUT_H_ADDRESS, 1, &buffer[2], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, ACCEL_YOUT_L_ADDRESS, 1, &buffer[3], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, ACCEL_ZOUT_H_ADDRESS, 1, &buffer[4], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, ACCEL_ZOUT_L_ADDRESS, 1, &buffer[5], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    accelerometer->X = (int16_t)(((buffer[0] << 8)&0xFF00u) | (buffer[1]&0x00FFu));
    accelerometer->Y = (int16_t)(((buffer[2] << 8)&0xFF00u) | (buffer[3]&0x00FFu));
    accelerometer->Z = (int16_t)(((buffer[4] << 8)&0xFF00u) | (buffer[5]&0x00FFu));

    return MPU6050_OK;
}

MPU6050_StatusTypeDef MPU6050_Read_Gyroscope(MPU6050_GyroData *gyro)
{
    if (gyro == (MPU6050_GyroData *)0u)
    {
        return MPU6050_ERROR;
    }

    uint8_t buffer[6];

    if (I2C_Read(MPU6050_ADDRESS << 1, GYRO_XOUT_H_ADDRESS, 1, &buffer[0], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, GYRO_XOUT_L_ADDRESS, 1, &buffer[1], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, GYRO_YOUT_H_ADDRESS, 1, &buffer[2], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, GYRO_YOUT_L_ADDRESS, 1, &buffer[3], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, GYRO_ZOUT_H_ADDRESS, 1, &buffer[4], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }
    if (I2C_Read(MPU6050_ADDRESS << 1, GYRO_ZOUT_L_ADDRESS, 1, &buffer[5], 1, 1000) != I2C_OK)
    {
        return MPU6050_ERROR;
    }

    gyro->X = (int16_t)(((buffer[0] << 8)&0xFF00u) | (buffer[1]&0x00FFu));
    gyro->Y = (int16_t)(((buffer[2] << 8)&0xFF00u) | (buffer[3]&0x00FFu));
    gyro->Z = (int16_t)(((buffer[4] << 8)&0xFF00u) | (buffer[5]&0x00FFu));

    return MPU6050_OK;
}