#ifndef GPIO_ABSTRACTION_H
#define GPIO_ABSTRACTION_H

#include "stdint.h"

#define PIN_SET 1
#define PIN_RESET 0

void gpio_rst_write(uint8_t state);
void gpio_dc_write(uint8_t state);
void gpio_cs_write(uint8_t state);

#endif // GPIO_ABSTRACTION_H