#ifndef SPI_ABSTRACTION_H
#define SPI_ABSTRACTION_H

#include <stdint.h>

typedef enum
{
    SPI_OK = 0x00u,
    SPI_BUSY = 0x01u,
    SPI_ERROR = 0xFFu
} SPI_StatusTypeDef;

SPI_StatusTypeDef SPI_Write(uint8_t *pData, uint16_t Size, uint32_t Timeout);

SPI_StatusTypeDef SPI_Read(uint8_t *pData, uint16_t Size, uint32_t Timeout);

SPI_StatusTypeDef SPI_Write_DMA(uint8_t *pData, uint16_t Size);

#endif // SPI_ABSTRACTION_H