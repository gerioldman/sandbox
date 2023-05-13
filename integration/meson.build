# This file is the Meson build file where you can add your target specific source files and include directories.
# The file will not be overwritten by the generator once it has been created, so you can add your own code here.

platform_source_bareMinimum += files(
    [
        # Add all the source files here, that are needed to run anything on the platform, like the main function, or the startup file
        'Core/Src/system_stm32h7xx.c',
        'startup_stm32h753xx.s'
    ]
)

platform_source += files(
    [
        # Add all the source files here, that you do not want to test with unittests
        'Core/Src/main.c',
        'Core/Src/gpio.c',
        'Core/Src/dma.c',
        'Core/Src/spi.c',
        'Core/Src/tim.c',
        'Core/Src/usart.c',
        'Core/Src/stm32h7xx_it.c',
        'Core/Src/stm32h7xx_hal_msp.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c',
        'Core/Src/system_stm32h7xx.c',
        'Core/Src/freertos.c',
        'Core/Src/stm32h7xx_hal_timebase_tim.c',
        'Middlewares/Third_Party/FreeRTOS/Source/croutine.c',
        'Middlewares/Third_Party/FreeRTOS/Source/event_groups.c',
        'Middlewares/Third_Party/FreeRTOS/Source/list.c',
        'Middlewares/Third_Party/FreeRTOS/Source/queue.c',
        'Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c',
        'Middlewares/Third_Party/FreeRTOS/Source/tasks.c',
        'Middlewares/Third_Party/FreeRTOS/Source/timers.c',
        'Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c',
        'Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c',
        'Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c',
        'Core/Src/i2c.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_spi_ex.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c',
        'Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c',
        'Core/Src/ST7789.c',
        'Core/Src/graphics.c',
        'Core/Src/i2c_abstraction.c',
        'Core/Src/i2c_detect.c',
   ]
)

platform_include += include_directories(
    [
        # Add all the include directories from the integration folder here
        'Core/Inc',
        'Drivers/STM32H7xx_HAL_Driver/Inc',
        'Drivers/STM32H7xx_HAL_Driver/Inc/Legacy',
        'Drivers/CMSIS/Device/ST/STM32H7xx/Include',
        'Drivers/CMSIS/Include',
        'Middlewares/Third_Party/FreeRTOS/Source/include',
        'Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2',
        'Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F'
    ]
)

unittest_platform_source     += files(
    [
        # Add all the source files here, that are needed to run the unittests on the target
    ]
)

unittest_platform_include    += include_directories(
    [
        # Add all the include directories specific for running unittests on target here
    ]
)

ld_script = files(
    [
        # Add all the linker scripts here that are needed to link the target
        'STM32H753ZITx_FLASH.ld',
        #'STM32H753ZITx_RAM.ld'
    ]
)

# Do not change this line, for now, there is no way to add a linker script to the meson build file, so we have to add it to the linker arguments
foreach link_file : ld_script
    link_args += '-T@0@/@1@'.format(meson.global_source_root(),link_file)
endforeach


platform_cflags += [
    # Add all the custom compiler flags here
    '-DSTM32H753xx',
    '-DUSE_HAL_DRIVER',
    #'-DUSE_FULL_LL_DRIVER'
]


# PyCParser doesn't support extensions to the C99 standard, add defines so GNU extensions like __attribute__(x) are thrown out by the preprocessor.
# In the future, I might create an extension for the PyCParser module to be able to process GNU extensions, but for now this is the solution, 
# recommended by the creator of the module. https://github.com/eliben/pycparser/wiki/FAQ#what-do-i-do-about-__attribute

stub_args += '-D__attribute__(x)='
stub_args += '-D__ASM='
stub_args += '-D__IO=volatile'
stub_args += '-D__STATIC_INLINE=static inline'
stub_args += '-D__NOP()'
stub_args += '-D__RAM_FUNC'
stub_args += '-D__NOINLINE'
stub_args += '-D__ALIGN_BEGIN'
stub_args += '-D__ALIGN_END'
stub_args += '-D__packed'
stub_args += '-D__weak'
stub_args += '-DUNUSED(X)'
stub_args += '-Dvolatile(x)='
stub_args += '-D__restrict='

# Some headers might cause errors during stub generation, you can create fake headers, look up PyCParser fake include headers

stub_include += include_directories([
    'C:\Program Files\Python310\Lib\site-packages\pycparser_fake_libc'
])