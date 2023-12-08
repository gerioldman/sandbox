#include "gpio_abstraction.h"
#include "main.h"
#include "stm32h7xx_hal.h"

void gpio_rst_write(uint8_t state)
{
    if (state == 0)
    {
        HAL_GPIO_WritePin(ST7789_RST_GPIO_Port, ST7789_RST_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(ST7789_RST_GPIO_Port, ST7789_RST_Pin, GPIO_PIN_SET);
    }
}

void gpio_dc_write(uint8_t state)
{
    if (state == 0)
    {
        HAL_GPIO_WritePin(ST7789_DC_GPIO_Port, ST7789_DC_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(ST7789_DC_GPIO_Port, ST7789_DC_Pin, GPIO_PIN_SET);
    }
}

void gpio_cs_write(uint8_t state)
{
    if (state == 0)
    {
        HAL_GPIO_WritePin(ST7789_CS_GPIO_Port, ST7789_CS_Pin, GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(ST7789_CS_GPIO_Port, ST7789_CS_Pin, GPIO_PIN_SET);
    }
}
