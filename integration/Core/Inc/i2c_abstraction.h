#ifndef I2C_ABSTRACTION_H
#define I2C_ABSTRACTION_H

#include <stdint.h>

typedef enum
{
    I2C_OK = 0x00u,
    I2C_BUSY = 0x01u,
    I2C_ERROR = 0xFFu
} I2C_StatusTypeDef;

I2C_StatusTypeDef I2C_Write(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
I2C_StatusTypeDef I2C_Read(uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);
I2C_StatusTypeDef I2C_IsDeviceConnected(uint16_t DevAddress, uint32_t Trials, uint32_t Timeout);

#endif // I2C_ABSTRACTION_H