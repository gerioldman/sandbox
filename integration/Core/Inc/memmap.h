#ifndef MEMMAP_H
#define MEMMAP_H

// This file is used to define macros for memory mapping

// The following macros are used to define the memory map for the STM32H753ZI
// MCU.  The memory map is defined in the STM32H753ZI datasheet.

#define MAP_TO_DTCM_RAM_INIT __attribute__((section(".data")))
#define MAP_TO_DTCM_RAM_BSS __attribute__((section(".bss")))
#define MAP_TO_DTCM_RAM_D1_INIT __attribute__((section(".data_RAM_D1")))
#define MAP_TO_DTCM_RAM_D1_BSS __attribute__((section(".bss_RAM_D1")))
#define MAP_TO_DTCM_RAM_D2_INIT __attribute__((section(".data_RAM_D2")))
#define MAP_TO_DTCM_RAM_D2_BSS __attribute__((section(".bss_RAM_D2")))
#define MAP_TO_DTCM_RAM_D3_INIT __attribute__((section(".data_RAM_D3")))
#define MAP_TO_DTCM_RAM_D3_BSS __attribute__((section(".bss_RAM_D3")))


#endif // MEMMAP_H