#include "spi_abstraction.h"
#include "stm32h7xx_hal.h"

extern SPI_HandleTypeDef hspi1;
extern DMA_HandleTypeDef hdma_spi1_tx;

SPI_StatusTypeDef SPI_Write(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_StatusTypeDef status = HAL_OK;
    SPI_StatusTypeDef spi_status = SPI_OK;

    status = HAL_SPI_Transmit(&hspi1, pData, Size, Timeout);
    if (status != HAL_OK)
    {
        spi_status = SPI_ERROR;
    }

    return spi_status;
}

SPI_StatusTypeDef SPI_Read(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
    HAL_StatusTypeDef status = HAL_OK;
    SPI_StatusTypeDef spi_status = SPI_OK;

    status = HAL_SPI_Receive(&hspi1, pData, Size, Timeout);
    if (status != HAL_OK)
    {
        spi_status = SPI_ERROR;
    }

    return spi_status;
}

SPI_StatusTypeDef SPI_Write_DMA(uint8_t *pData, uint16_t Size)
{
    HAL_StatusTypeDef status = HAL_OK;
    SPI_StatusTypeDef spi_status = SPI_OK;

    status = HAL_SPI_Transmit_DMA(&hspi1, pData, Size);
    if (status != HAL_OK)
    {
        spi_status = SPI_ERROR;
    }

    return spi_status;
}