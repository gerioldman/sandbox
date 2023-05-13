#ifndef MPU6050_REGISTERMAP_H
#define MPU6050_REGISTERMAP_H

#include <stdint.h>

#define SELF_TEST_X_ADDRESS ((uint8_t)0x0D)
#define SELF_TEST_Y_ADDRESS ((uint8_t)0x0E)
#define SELF_TEST_Z_ADDRESS ((uint8_t)0x0F)
#define SELF_TEST_A_ADDRESS ((uint8_t)0x10)
#define SMPLRT_DIV_ADDRESS ((uint8_t)0x19)
#define CONFIG_ADDRESS ((uint8_t)0x1A)
#define GYRO_CONFIG_ADDRESS ((uint8_t)0x1B)
#define ACCEL_CONFIG_ADDRESS ((uint8_t)0x1C)
#define FIFO_EN_ADDRESS ((uint8_t)0x23)
#define I2C_MST_CTRL_ADDRESS ((uint8_t)0x24)
#define I2C_SLV0_ADDR_ADDRESS ((uint8_t)0x25)
#define I2C_SLV0_REG_ADDRESS ((uint8_t)0x26)
#define I2C_SLV0_CTRL_ADDRESS ((uint8_t)0x27)
#define I2C_SLV1_ADDR_ADDRESS ((uint8_t)0x28)
#define I2C_SLV1_REG_ADDRESS ((uint8_t)0x29)
#define I2C_SLV1_CTRL_ADDRESS ((uint8_t)0x2A)
#define I2C_SLV2_ADDR_ADDRESS ((uint8_t)0x2B)
#define I2C_SLV2_REG_ADDRESS ((uint8_t)0x2C)
#define I2C_SLV2_CTRL_ADDRESS ((uint8_t)0x2D)
#define I2C_SLV3_ADDR_ADDRESS ((uint8_t)0x2E)
#define I2C_SLV3_REG_ADDRESS ((uint8_t)0x2F)
#define I2C_SLV3_CTRL_ADDRESS ((uint8_t)0x30)
#define I2C_SLV4_ADDR_ADDRESS ((uint8_t)0x31)
#define I2C_SLV4_REG_ADDRESS ((uint8_t)0x32)
#define I2C_SLV4_DO_ADDRESS ((uint8_t)0x33)
#define I2C_SLV4_CTRL_ADDRESS ((uint8_t)0x34)
#define I2C_SLV4_DI_ADDRESS ((uint8_t)0x35)
#define I2C_MST_STATUS_ADDRESS ((uint8_t)0x36)
#define INT_PIN_CFG_ADDRESS ((uint8_t)0x37)
#define INT_ENABLE_ADDRESS ((uint8_t)0x38)
#define INT_STATUS_ADDRESS ((uint8_t)0x3A)
#define ACCEL_XOUT_H_ADDRESS ((uint8_t)0x3B)
#define ACCEL_XOUT_L_ADDRESS ((uint8_t)0x3C)
#define ACCEL_YOUT_H_ADDRESS ((uint8_t)0x3D)
#define ACCEL_YOUT_L_ADDRESS ((uint8_t)0x3E)
#define ACCEL_ZOUT_H_ADDRESS ((uint8_t)0x3F)
#define ACCEL_ZOUT_L_ADDRESS ((uint8_t)0x40)
#define TEMP_OUT_H_ADDRESS ((uint8_t)0x41)
#define TEMP_OUT_L_ADDRESS ((uint8_t)0x42)
#define GYRO_XOUT_H_ADDRESS ((uint8_t)0x43)
#define GYRO_XOUT_L_ADDRESS ((uint8_t)0x44)
#define GYRO_YOUT_H_ADDRESS ((uint8_t)0x45)
#define GYRO_YOUT_L_ADDRESS ((uint8_t)0x46)
#define GYRO_ZOUT_H_ADDRESS ((uint8_t)0x47)
#define GYRO_ZOUT_L_ADDRESS ((uint8_t)0x48)
#define EXT_SENS_DATA_00_ADDRESS ((uint8_t)0x49)
#define EXT_SENS_DATA_01_ADDRESS ((uint8_t)0x4A)
#define EXT_SENS_DATA_02_ADDRESS ((uint8_t)0x4B)
#define EXT_SENS_DATA_03_ADDRESS ((uint8_t)0x4C)
#define EXT_SENS_DATA_04_ADDRESS ((uint8_t)0x4D)
#define EXT_SENS_DATA_05_ADDRESS ((uint8_t)0x4E)
#define EXT_SENS_DATA_06_ADDRESS ((uint8_t)0x4F)
#define EXT_SENS_DATA_07_ADDRESS ((uint8_t)0x50)
#define EXT_SENS_DATA_08_ADDRESS ((uint8_t)0x51)
#define EXT_SENS_DATA_09_ADDRESS ((uint8_t)0x52)
#define EXT_SENS_DATA_10_ADDRESS ((uint8_t)0x53)
#define EXT_SENS_DATA_11_ADDRESS ((uint8_t)0x54)
#define EXT_SENS_DATA_12_ADDRESS ((uint8_t)0x55)
#define EXT_SENS_DATA_13_ADDRESS ((uint8_t)0x56)
#define EXT_SENS_DATA_14_ADDRESS ((uint8_t)0x57)
#define EXT_SENS_DATA_15_ADDRESS ((uint8_t)0x58)
#define EXT_SENS_DATA_16_ADDRESS ((uint8_t)0x59)
#define EXT_SENS_DATA_17_ADDRESS ((uint8_t)0x5A)
#define EXT_SENS_DATA_18_ADDRESS ((uint8_t)0x5B)
#define EXT_SENS_DATA_19_ADDRESS ((uint8_t)0x5C)
#define EXT_SENS_DATA_20_ADDRESS ((uint8_t)0x5D)
#define EXT_SENS_DATA_21_ADDRESS ((uint8_t)0x5E)
#define EXT_SENS_DATA_22_ADDRESS ((uint8_t)0x5F)
#define EXT_SENS_DATA_23_ADDRESS ((uint8_t)0x60)
#define I2C_SLV0_DO_ADDRESS ((uint8_t)0x63)
#define I2C_SLV1_DO_ADDRESS ((uint8_t)0x64)
#define I2C_SLV2_DO_ADDRESS ((uint8_t)0x65)
#define I2C_SLV3_DO_ADDRESS ((uint8_t)0x66)
#define I2C_MST_DELAY_CTRL_ADDRESS ((uint8_t)0x67)
#define SIGNAL_PATH_RESET_ADDRESS ((uint8_t)0x68)
#define USER_CTRL_ADDRESS ((uint8_t)0x6A)
#define PWR_MGMT_1_ADDRESS ((uint8_t)0x6B)
#define PWR_MGMT_2_ADDRESS ((uint8_t)0x6C)
#define FIFO_COUNTH_ADDRESS ((uint8_t)0x72)
#define FIFO_COUNTL_ADDRESS ((uint8_t)0x73)
#define FIFO_R_W_ADDRESS ((uint8_t)0x74)
#define WHO_AM_I_ADDRESS ((uint8_t)0x75)

/* Type definitions for registers */

typedef union
{
    struct
    {
        uint8_t G_TEST : 5;
        uint8_t A_TEST : 3;
    };
    uint8_t Byte;
} SELF_TEST_Type;

typedef union
{
    struct
    {
        uint8_t ZA_TEST : 2;
        uint8_t YA_TEST : 2;
        uint8_t XA_TEST : 2;
        uint8_t RESERVED : 2;
    };
    uint8_t Byte;
} SELF_TEST_A_Type;

typedef union
{
    struct
    {
        uint8_t SMPLRT_DIV : 8;
    };
    uint8_t Byte;
} SMPLRT_DIV_Type;

typedef union
{
    struct
    {
        uint8_t DLPF_CFG : 3;
        uint8_t EXT_SYNC_SET : 3;
        uint8_t RESERVED : 2;
    };
    uint8_t Byte;
} CONFIG_Type;

typedef union
{
    struct
    {
        uint8_t UNUSED : 3;
        uint8_t FS_SEL : 2;
        uint8_t ZG_ST : 1;
        uint8_t YG_ST : 1;
        uint8_t XG_ST : 1;
    };
    uint8_t Byte;
} GYRO_CONFIG_Type;

typedef union
{
    struct
    {
        uint8_t UNUSED : 3;
        uint8_t AFS_SEL : 2;
        uint8_t ZA_ST : 1;
        uint8_t YA_ST : 1;
        uint8_t XA_ST : 1;
    };
    uint8_t Byte;
} ACCEL_CONFIG_Type;

typedef union
{
    struct
    {
        uint8_t SLV0_FIFO_EN : 1;
        uint8_t SLV1_FIFO_EN : 1;
        uint8_t SLV2_FIFO_EN : 1;
        uint8_t ACCEL_FIFO_EN : 1;
        uint8_t ZG_FIFO_EN : 1;
        uint8_t YG_FIFO_EN : 1;
        uint8_t XG_FIFO_EN : 1;
        uint8_t TEMP_FIFO_EN : 1;
    };
    uint8_t Byte;
} FIFO_EN_Type;

typedef union
{
    struct
    {
        uint8_t I2C_MST_CLK : 4;
        uint8_t I2C_MST_P_NSR : 1;
        uint8_t SLV_3_FIFO_EN : 1;
        uint8_t WAIT_FOR_ES : 1;
        uint8_t MULT_MST_EN : 1;
    };
    uint8_t Byte;
} I2C_MST_CTRL_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLVX_ADDR : 7;
        uint8_t I2C_SLVX_RW : 1;
    };
    uint8_t Byte;
} I2C_SLVX_ADDR_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLVX_REG : 8;
    };
    uint8_t Byte;
} I2C_SLVX_REG_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLVX_LEN : 4;
        uint8_t I2C_SLVX_GRP : 1;
        uint8_t I2C_SLVX_REG_DIS : 1;
        uint8_t I2C_SLVX_BYTE_SW : 1;
        uint8_t I2C_SLVX_EN : 1;
    };
    uint8_t Byte;
} I2C_SLVX_CTRL_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLVX_DO : 8;
    };
    uint8_t Byte;
} I2C_SLVX_DO_Type;

typedef union
{
    struct
    {
        uint8_t I2C_MST_DLY : 5;
        uint8_t I2C_SLV4_REG_DIS : 1;
        uint8_t I2C_SLV4_INT_EN : 1;
        uint8_t I2C_SLV4_EN : 1;
    };
    uint8_t Byte;
} I2C_SLV4_CTRL_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLV4_DI : 8;
    };
    uint8_t Byte;
} I2C_SLV4_DI_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLV0_NACK : 1;
        uint8_t I2C_SLV1_NACK : 1;
        uint8_t I2C_SLV2_NACK : 1;
        uint8_t I2C_SLV3_NACK : 1;
        uint8_t I2C_SLV4_NACK : 1;
        uint8_t I2C_LOST_ARB : 1;
        uint8_t I2C_SLV4_DONE : 1;
        uint8_t PASS_THROUGH : 1;
    };
    uint8_t Byte;
} I2C_MST_STATUS_Type;

typedef union
{
    struct
    {
        uint8_t UNUSED : 1;
        uint8_t I2C_BYPASS_EN : 1;
        uint8_t FSYNC_INT_EN : 1;
        uint8_t FSYNC_INT_LEVEL : 1;
        uint8_t INT_RD_CLEAR : 1;
        uint8_t LATCH_INT_EN : 1;
        uint8_t INT_OPEN : 1;
        uint8_t INT_LEVEL : 1;
    };
    uint8_t Byte;
} INT_PIN_CFG_Type;

typedef union
{
    struct
    {
        uint8_t DATA_RDY_EN : 1;
        uint8_t UNUSED_0 : 2;
        uint8_t I2C_MST_INT_EN : 1;
        uint8_t FIFO_OFLOW_EN : 1;
        uint8_t UNUSED_1 : 3;
    };
    uint8_t Byte;
} INT_ENABLE_Type;

typedef union
{
    struct
    {
        uint8_t DATA_RDY_INT : 1;
        uint8_t UNUSED_0 : 2;
        uint8_t I2C_MST_INT : 1;
        uint8_t FIFO_OFLOW_INT : 1;
        uint8_t UNUSED_1 : 3;
    };
    uint8_t Byte;
} INT_STATUS_Type;

typedef union
{
    struct
    {
        uint8_t ACCEL_OUT : 8;
    };
    uint8_t Byte;
} ACCEL_OUT_X_Type;

typedef union
{
    struct
    {
        uint8_t TEMP_OUT : 8;
    };
    uint8_t Byte;
} TEMP_OUT_X_Type;

typedef union
{
    struct
    {
        uint8_t GYRO_OUT : 8;
    };
    uint8_t Byte;
} GYRO_OUT_X_Type;

typedef union
{
    struct
    {
        uint8_t EXT_SENS_DATA_XX : 8;
    };
    uint8_t Byte;
} EXT_SENS_DATA_XX_Type;

typedef union
{
    struct
    {
        uint8_t I2C_SLV0_DLY_EN : 1;
        uint8_t I2C_SLV1_DLY_EN : 1;
        uint8_t I2C_SLV2_DLY_EN : 1;
        uint8_t I2C_SLV3_DLY_EN : 1;
        uint8_t I2C_SLV4_DLY_EN : 1;
        uint8_t UNUSED : 2;
        uint8_t DELAY_ES_SHADOW : 1;
    };
    uint8_t Byte;
} I2C_MST_DELAY_CTRL_Type;

typedef union
{
    struct
    {
        uint8_t TEMP_RESET : 1;
        uint8_t ACCEL_RESET : 1;
        uint8_t GYRO_RESET : 1;
        uint8_t UNUSED : 5;
    };
    uint8_t Byte;
} SIGNAL_PATH_RESET_Type;

typedef union
{
    struct
    {
        uint8_t SIG_COND_RESET : 1;
        uint8_t I2C_MST_RESET : 1;
        uint8_t FIFO_RESET : 1;
        uint8_t UNUSED_0 : 1;
        uint8_t I2C_IF_DIS : 1;
        uint8_t I2C_MST_EN : 1;
        uint8_t FIFO_EN : 1;
        uint8_t UNUSED_1 : 1;
    };
    uint8_t Byte;
} USER_CTRL_Type;

typedef union
{
    struct
    {
        uint8_t CLKSEL : 3;
        uint8_t TEMP_DIS : 1;
        uint8_t UNUSED : 1;
        uint8_t CYCLE : 1;
        uint8_t SLEEP : 1;
        uint8_t DEVICE_RESET : 1;
    };
    uint8_t Byte;
} PWR_MGMT_1_Type;

typedef union
{
    struct
    {
        uint8_t STBY_ZG : 1;
        uint8_t STBY_YG : 1;
        uint8_t STBY_XG : 1;
        uint8_t STBY_ZA : 1;
        uint8_t STBY_YA : 1;
        uint8_t STBY_XA : 1;
        uint8_t LP_WAKE_CTRL : 2;
    };
    uint8_t Byte;
} PWR_MGMT_2_Type;

typedef union
{
    struct
    {
        uint8_t FIFO_COUNT : 8;
    };
    uint8_t Byte;
} FIFO_COUNTX_Type;

typedef union
{
    struct
    {
        uint8_t FIFO_DATA : 8;
    };
    uint8_t Byte;
} FIFO_R_W_Type;

typedef union
{
    struct
    {
        uint8_t UNUSED_0 : 1;
        uint8_t WHO_AM_I : 6;
        uint8_t UNUSED_1 : 1;
    };
    uint8_t Byte;
} WHO_AM_I_Type;

#endif // MPU6050_REGISTERMAP_H