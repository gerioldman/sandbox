#include "i2c_abstraction.h"
#include "stm32h7xx_hal.h"

extern I2C_HandleTypeDef hi2c4;

I2C_StatusTypeDef I2C_Write(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Write(&hi2c4, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);
    switch (status)
    {
    case HAL_OK:
        return I2C_OK;
    case HAL_BUSY:
        return I2C_BUSY;
    default:
        return I2C_ERROR;
    }
}

I2C_StatusTypeDef I2C_Read(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_StatusTypeDef status = HAL_I2C_Mem_Read(&hi2c4, DevAddress, MemAddress, MemAddSize, pData, Size, Timeout);
    switch (status)
    {
    case HAL_OK:
        return I2C_OK;
    case HAL_BUSY:
        return I2C_BUSY;
    default:
        return I2C_ERROR;
    }
}

I2C_StatusTypeDef I2C_IsDeviceConnected(uint16_t DevAddress, uint32_t Trials, uint32_t Timeout)
{
    HAL_StatusTypeDef status = HAL_I2C_IsDeviceReady(&hi2c4, DevAddress, Trials, Timeout);
    switch (status)
    {
    case HAL_OK:
        return I2C_OK;
    case HAL_BUSY:
        return I2C_BUSY;
    default:
        return I2C_ERROR;
    }
}