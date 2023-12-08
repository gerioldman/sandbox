/**
 * @file ST7789_Driver.c
 * @brief TODO - Add description
 * @date 4/28/2023
 */

/* Generated includes - Do not modify ----------------------------------------*/

#include "ST7789_Driver.h"
#include "spi_abstraction.h"
#include "gpio_abstraction.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

static ST7789_Status_Type ST7789_ReadData(uint8_t *data, uint32_t length);

/* Private functions ---------------------------------------------------------*/

/* static */ ST7789_Status_Type ST7789_WriteCommand(uint8_t command)
{
    gpio_dc_write(PIN_RESET);
    gpio_cs_write(PIN_RESET);
    if (SPI_Write(&command, 1, 0xFFFFFFFFu) != SPI_OK)
    {
        return ST7789_ERROR;
    }
    gpio_cs_write(PIN_SET);

    return ST7789_OK;
}

/* static */ ST7789_Status_Type ST7789_WriteData(uint8_t *data, uint32_t length)
{
    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    gpio_dc_write(PIN_SET);
    gpio_cs_write(PIN_RESET);
    if (SPI_Write(data, length, 0xFFFFFFFFu) != SPI_OK)
    {
        return ST7789_ERROR;
    }
    gpio_cs_write(PIN_SET);

    return ST7789_OK;
}

/* static */ ST7789_Status_Type ST7789_WriteSmallData(uint8_t data)
{

    gpio_dc_write(PIN_SET);
    gpio_cs_write(PIN_RESET);
    if (SPI_Write(&data, 1, 0xFFFFFFFFu) != SPI_OK)
    {
        return ST7789_ERROR;
    }
    gpio_cs_write(PIN_SET);

    return ST7789_OK;
}

static ST7789_Status_Type ST7789_ReadData(uint8_t *data, uint32_t length)
{
    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    gpio_dc_write(PIN_SET);
    gpio_cs_write(PIN_RESET);
    if (SPI_Read(data, length, 1000) != SPI_OK)
    {
        return ST7789_ERROR;
    }
    gpio_cs_write(PIN_SET);

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadID(ST7789_RDDID_Type *data)
{
    uint8_t data_buffer[3] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDID))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 3))
    {
        return ST7789_ERROR;
    }
    data->manufacturerID = data_buffer[0];
    data->moduleDriverID = data_buffer[1];
    data->moduleDriverVersionID = data_buffer[2];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadStatus(ST7789_RDDST_Type *data)
{
    uint8_t data_buffer[4] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDST))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 4))
    {
        return ST7789_ERROR;
    }
    data->parameter1.byte = data_buffer[0];
    data->parameter2.byte = data_buffer[1];
    data->parameter3.byte = data_buffer[2];
    data->parameter4.byte = data_buffer[3];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadPowerMode(ST7789_RDDPM_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDPM))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadMemoryAccessControl(ST7789_RDDMADCTL_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDMADCTL))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadPixelFormat(ST7789_RDDCOLMOD_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDCOLMOD))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadImageFormat(ST7789_RDDIM_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDIM))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadSignalMode(ST7789_RDDSM_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDSM))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadSelfDiagnosticResult(ST7789_RDDSDR_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDDSDR))
    {
        return ST7789_ERROR;
    }
    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadContentAdaptiveBrightnessControl(ST7789_RDCABC_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDCABC))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadAutomaticBrightnessControlSelfDiagnosticResult(ST7789_RDABCSDR_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDABCSDR))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadID1(ST7789_RDID1_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDID1))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadID2(ST7789_RDID2_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDID2))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

ST7789_Status_Type ST7789_ReadID3(ST7789_RDID3_Type *data)
{
    uint8_t data_buffer[1] = {0};

    if ((void *)0 == data)
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RDID3))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_ReadData(data_buffer, 1))
    {
        return ST7789_ERROR;
    }
    data->byte = data_buffer[0];

    return ST7789_OK;
}

/* Public functions ----------------------------------------------------------*/

/**
 * @brief Request software reset, the software reset will reset all registers to default values.
 * The display module won't be able to receive any commands during the reset, which takes 5ms.
 * It is the caller's responsibility to wait for the reset to complete.
 *
 * @return ST7789_Status_Type
 */
ST7789_Status_Type ST7789_RequestSoftwareReset(void)
{
    if (ST7789_OK != ST7789_WriteCommand(ST7789_SWRESET))
    {
        return ST7789_ERROR;
    }

    return ST7789_OK;
}

/**
 * @brief Initialize the ST7789 display driver, this function will send the initialization sequence
 * to the display module. The display won't be turned on after initialization, it only sets the registers
 * COLMOD, MADCTL, CASET and RASET.
 *
 * @param init
 * @return ST7789_Status_Type
 */
ST7789_Status_Type ST7789_Driver_Init(ST7789_InitStructure_Type init)
{

    if (ST7789_OK != ST7789_WriteCommand(ST7789_COLMOD))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteData(&init.COLMOD.byte, 1))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_MADCTL))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteData(&init.MADCTL.byte, 1))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_CASET))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteData(init.CASET.bytes, 4))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteCommand(ST7789_RASET))
    {
        return ST7789_ERROR;
    }

    if (ST7789_OK != ST7789_WriteData(init.RASET.bytes, 4))
    {
        return ST7789_ERROR;
    }

    ST7789_WriteCommand(ST7789_INVON);
    ST7789_WriteCommand(ST7789_SLPOUT);
    ST7789_WriteCommand(ST7789_NORON);
    ST7789_WriteCommand(ST7789_DISPON);

    ST7789_WriteCommand(ST7789_RAMWR);

    uint16_t YSize = (init.RASET.YE_L.byte + (init.RASET.YE_H.byte << 8)) - (init.RASET.YS_L.byte - (init.RASET.YS_H.byte << 8)) + 1;
    uint16_t XSize = (init.CASET.XE_L.byte + (init.CASET.XE_H.byte << 8)) - (init.CASET.XS_L.byte - (init.CASET.XS_H.byte << 8)) + 1;
    uint32_t size = XSize * YSize * 2;
    for (uint32_t i = 0; i < size; i++)
    {
        uint8_t data = 0xFF;
        ST7789_WriteData(&data, 1);
    }

    return ST7789_OK;
}