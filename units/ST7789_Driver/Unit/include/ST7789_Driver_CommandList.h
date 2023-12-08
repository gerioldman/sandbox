/**
 * @file ST7789_Driver_CommandList.h
 * @author gerioldman (k.gergo49@gmail.com)
 * @brief This file contains the command list definitions for the ST7789 driver and their respective data types.
 * @details https://www.waveshare.com/w/upload/a/ae/ST7789_Datasheet.pdf
 * @version 0.1
 * @date 2023-07-02
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ST7789_DRIVER_COMMANDLIST_H
#define ST7789_DRIVER_COMMANDLIST_H

/* Includes ------------------------------------------------------------------*/

#include <stdint.h>

/* Type definitions ----------------------------------------------------------*/

typedef struct
{
    uint8_t manufacturerID;
    uint8_t moduleDriverVersionID;
    uint8_t moduleDriverID;
} ST7789_RDDID_Type;

typedef struct
{
    union
    {
        struct
        {
            uint8_t ST24 : 1;  /* For future use, always 0 */
            uint8_t MH : 1;    /* Horizontal order 0 = Decrement/Left to Right refresh, 1 = Increment/Right to Left refresh */
            uint8_t RGB : 1;   /* RGB/BGR Order 1 = BGR, 0 = RGB */
            uint8_t ML : 1;    /* Scan Address Order 0 = Decrement/Top to Bottom, 1 = Increment/Bottom to Top */
            uint8_t MV : 1;    /* Row/Column Exchange 0 = Normal, 1 = Row/Column exchange */
            uint8_t MX : 1;    /* Column Address Order 0 = Increment/Left to Right, 1 = Decrement/Right to Left */
            uint8_t MY : 1;    /* Row Address Order 0 = Increment/Top to Bottom, 1 = Decrement/Bottom to Top */
            uint8_t BSTON : 1; /* Booster Voltage Status 0 = Booster off, 1 = Booster on */
        };
        uint8_t byte;
    } parameter1;

    union
    {
        struct
        {
            uint8_t NORON : 1;  /* Normal Display Mode on/off 0 = partial, 1 = Normal Display */
            uint8_t SLPOUT : 1; /* Sleep In/Out 1 = Out, 0 = In */
            uint8_t PTLON : 1;  /* Partial Mode On/Off 1 = On, 0 = Off */
            uint8_t IDMON : 1;  /* Idle Mode On/Off, 1 = On, 0 = Off */
            uint8_t IFPF0 : 1;  /* Interface Color Pixel Format Definition */
            uint8_t IFPF1 : 1;  /* 011 = 12 bit/pixel 101 = 16 bit/pixel */
            uint8_t IFPF2 : 1;  /* 110 = 18 bit/pixel 111 = 16M truncated */
            uint8_t ST23 : 1;   /* For future use, always 0 */
        };
        uint8_t byte;
    } parameter2;

    union
    {
        struct
        {
            uint8_t GCS2 : 1;  /* Gamma Curve Selection */
            uint8_t TEON : 1;  /* Tearing Effect Line On/Off 1 = On, 0 = Off */
            uint8_t DISON : 1; /* Display On/Off 1 = On, 0 = Off */
            uint8_t ST11 : 1;  /* All pixels off, always 0 */
            uint8_t ST12 : 1;  /* All pixels on, always 0 */
            uint8_t INVON : 1; /* Inversion On/Off 1 = On, 0 = Off */
            uint8_t ST14 : 1;  /* Horizontal scroll status, always 0 */
            uint8_t ST15 : 1;  /* Vertical scroll status, 1 = scroll on, 0 = scroll off */
        };
        uint8_t byte;
    } parameter3;

    union
    {
        struct
        {
            uint8_t ST0 : 1;  /* For future use, always 0 */
            uint8_t ST1 : 1;  /* For future use, always 0 */
            uint8_t ST2 : 1;  /* For future use, always 0 */
            uint8_t ST3 : 1;  /* For future use, always 0 */
            uint8_t ST4 : 1;  /* For future use, always 0 */
            uint8_t TEM : 1;  /* Tearing Effect Line Mode 0 = V-blanking only, 1 = V-blanking and H-blanking */
            uint8_t GCS0 : 1; /* Gamma Curve Selection */
            uint8_t GCS1 : 1; /* Gamma Curve Selection */
        };
        uint8_t byte;
    } parameter4;

} ST7789_RDDST_Type;

typedef union
{
    struct
    {
        uint8_t D0 : 1;     /* Dummy bit, always 0 */
        uint8_t D1 : 1;     /* Dummy bit, always 0 */
        uint8_t DISON : 1;  /* Display On/Off 1 = On, 0 = Off */
        uint8_t NORON : 1;  /* Normal Display Mode on/off 0 = partial, 1 = Normal Display */
        uint8_t SLPOUT : 1; /* Sleep In/Out 1 = Out, 0 = In */
        uint8_t PTLON : 1;  /* Partial Mode On/Off 1 = On, 0 = Off */
        uint8_t IDMON : 1;  /* Idle Mode On/Off, 1 = On, 0 = Off */
        uint8_t BSTON : 1;  /* Booster Voltage Status 0 = Booster off, 1 = Booster on */
    };
    uint8_t byte;
} ST7789_RDDPM_Type;

typedef union
{
    struct
    {
        uint8_t D0 : 1;  /* Dummy bit, always 0 */
        uint8_t D1 : 1;  /* Dummy bit, always 0 */
        uint8_t MH : 1;  /* Horizontal order 0 = Decrement/Left to Right refresh, 1 = Increment/Right to Left refresh */
        uint8_t RGB : 1; /* RGB/BGR Order 1 = BGR, 0 = RGB */
        uint8_t ML : 1;  /* Scan Address Order 0 = Decrement/Top to Bottom, 1 = Increment/Bottom to Top */
        uint8_t MV : 1;  /* Row/Column Exchange 0 = Normal, 1 = Row/Column exchange */
        uint8_t MX : 1;  /* Column Address Order 0 = Increment/Left to Right, 1 = Decrement/Right to Left */
        uint8_t MY : 1;  /* Row Address Order 0 = Increment/Top to Bottom, 1 = Decrement/Bottom to Top */
    };
    uint8_t byte;
} ST7789_RDDMADCTL_Type;

typedef union
{
    struct
    {
        uint8_t D0 : 1; /* RGB interface color format */
        uint8_t D1 : 1; /* 101 = 16 bit/pixel */
        uint8_t D2 : 1; /* 110 = 18 bit/pixel */
        uint8_t D3 : 1; /* Dummy bit, always 0 */
        uint8_t D4 : 1; /* Control interface color format */
        uint8_t D5 : 1; /* 101 = 16 bit/pixel */
        uint8_t D6 : 1; /* 110 = 18 bit/pixel */
        uint8_t D7 : 1; /* Dummy bit, always 0 */
    };
    uint8_t byte;
} ST7789_RDDCOLMOD_Type;

typedef union
{
    struct
    {
        uint8_t GC0 : 1;   /* Gamma Curve Selection */
        uint8_t GC1 : 1;   /* 000 = Curve 1 001 = Curve 2 */
        uint8_t GC2 : 1;   /* 010 = Curve 3 011 = Curve 4 */
        uint8_t D3 : 1;    /* Dummy bit, always 0 */
        uint8_t D4 : 1;    /* Dummy bit, always 0 */
        uint8_t INVON : 1; /* Inversion on/off */
        uint8_t D5 : 1;    /* Dummy bit, always 0 */
        uint8_t VSSON : 1; /* Vertical scrolling on/off */
    };
    uint8_t byte;
} ST7789_RDDIM_Type;

typedef union
{
    struct
    {
        uint8_t D0 : 1;   /* Dummy bit, always 0 */
        uint8_t D1 : 1;   /* Dummy bit, always 0 */
        uint8_t D2 : 1;   /* Dummy bit, always 0 */
        uint8_t D3 : 1;   /* Dummy bit, always 0 */
        uint8_t D4 : 1;   /* Dummy bit, always 0 */
        uint8_t D5 : 1;   /* Dummy bit, always 0 */
        uint8_t TEM : 1;  /* Tearing effect line mode */
        uint8_t TEON : 1; /* Tearing effect line on/off */
    };
    uint8_t byte;
} ST7789_RDDSM_Type;

typedef union
{
    struct
    {
        uint8_t D0 : 1; /* Dummy bit, always 0 */
        uint8_t D1 : 1; /* Dummy bit, always 0 */
        uint8_t D2 : 1; /* Dummy bit, always 0 */
        uint8_t D3 : 1; /* Dummy bit, always 0 */
        uint8_t D4 : 1; /* Dummy bit, always 0 */
        uint8_t D5 : 1; /* Dummy bit, always 0 */
        uint8_t D6 : 1; /* Functionality detection */
        uint8_t D7 : 1; /* Register loading detection */
    };
    uint8_t byte;
} ST7789_RDDSDR_Type;

typedef union
{
    struct
    {
        /* Set selected curve bit to 1, set the rest to 0 */
        uint8_t GC0 : 1; /* Gamma curve 1 (G2.2) */
        uint8_t GC1 : 1; /* Gamma curve 2 (G1.8) */
        uint8_t GC2 : 1; /* Gamma curve 3 (G2.5) */
        uint8_t GC3 : 1; /* Gamma curve 4 (G1.0) */
        uint8_t D4 : 1;  /* Dummy bit, set to 0 */
        uint8_t D5 : 1;  /* Dummy bit, set to 0 */
        uint8_t D6 : 1;  /* Dummy bit, set to 0 */
        uint8_t D7 : 1;  /* Dummy bit, set to 0 */
    };
    uint8_t byte;
} ST7789_GAMSET_Type;

typedef union
{
    struct
    {
        union
        {
            struct
            {
                uint8_t XS8 : 1;  /* X start address bit 8 */
                uint8_t XS9 : 1;  /* X start address bit 9 */
                uint8_t XS10 : 1; /* X start address bit 10 */
                uint8_t XS11 : 1; /* X start address bit 11 */
                uint8_t XS12 : 1; /* X start address bit 12 */
                uint8_t XS13 : 1; /* X start address bit 13 */
                uint8_t XS14 : 1; /* X start address bit 14 */
                uint8_t XS15 : 1; /* X start address bit 15 */
            };
            uint8_t byte;
        } XS_H;
        union
        {
            struct
            {
                uint8_t XS0 : 1; /* X start address bit 0 */
                uint8_t XS1 : 1; /* X start address bit 1 */
                uint8_t XS2 : 1; /* X start address bit 2 */
                uint8_t XS3 : 1; /* X start address bit 3 */
                uint8_t XS4 : 1; /* X start address bit 4 */
                uint8_t XS5 : 1; /* X start address bit 5 */
                uint8_t XS6 : 1; /* X start address bit 6 */
                uint8_t XS7 : 1; /* X start address bit 7 */
            };
            uint8_t byte;
        } XS_L;
        union
        {
            struct
            {
                uint8_t XE8 : 1;  /* X end address bit 8 */
                uint8_t XE9 : 1;  /* X end address bit 9 */
                uint8_t XE10 : 1; /* X end address bit 10 */
                uint8_t XE11 : 1; /* X end address bit 11 */
                uint8_t XE12 : 1; /* X end address bit 12 */
                uint8_t XE13 : 1; /* X end address bit 13 */
                uint8_t XE14 : 1; /* X end address bit 14 */
                uint8_t XE15 : 1; /* X end address bit 15 */
            };
            uint8_t byte;
        } XE_H;
        union
        {
            struct
            {
                uint8_t XE0 : 1; /* Y end address bit 0 */
                uint8_t XE1 : 1; /* Y end address bit 1 */
                uint8_t XE2 : 1; /* Y end address bit 2 */
                uint8_t XE3 : 1; /* Y end address bit 3 */
                uint8_t XE4 : 1; /* Y end address bit 4 */
                uint8_t XE5 : 1; /* Y end address bit 5 */
                uint8_t XE6 : 1; /* Y end address bit 6 */
                uint8_t XE7 : 1; /* Y end address bit 7 */
            };
            uint8_t byte;
        } XE_L;
    };
    uint8_t bytes[4];
} ST7789_CASET_Type;

typedef union
{
    struct
    {
        union
        {
            struct
            {
                uint8_t YS8 : 1;  /* Y start address bit 8 */
                uint8_t YS9 : 1;  /* Y start address bit 9 */
                uint8_t YS10 : 1; /* Y start address bit 10 */
                uint8_t YS11 : 1; /* Y start address bit 11 */
                uint8_t YS12 : 1; /* Y start address bit 12 */
                uint8_t YS13 : 1; /* Y start address bit 13 */
                uint8_t YS14 : 1; /* Y start address bit 14 */
                uint8_t YS15 : 1; /* Y start address bit 15 */
            };
            uint8_t byte;
        } YS_H;
        union
        {
            struct
            {
                uint8_t YS0 : 1; /* Y start address bit 0 */
                uint8_t YS1 : 1; /* Y start address bit 1 */
                uint8_t YS2 : 1; /* Y start address bit 2 */
                uint8_t YS3 : 1; /* Y start address bit 3 */
                uint8_t YS4 : 1; /* Y start address bit 4 */
                uint8_t YS5 : 1; /* Y start address bit 5 */
                uint8_t YS6 : 1; /* Y start address bit 6 */
                uint8_t YS7 : 1; /* Y start address bit 7 */
            };
            uint8_t byte;
        } YS_L;
        union
        {
            struct
            {
                uint8_t YE8 : 1;  /* Y end address bit 8 */
                uint8_t YE9 : 1;  /* Y end address bit 9 */
                uint8_t YE10 : 1; /* Y end address bit 10 */
                uint8_t YE11 : 1; /* Y end address bit 11 */
                uint8_t YE12 : 1; /* Y end address bit 12 */
                uint8_t YE13 : 1; /* Y end address bit 13 */
                uint8_t YE14 : 1; /* Y end address bit 14 */
                uint8_t YE15 : 1; /* Y end address bit 15 */
            };
            uint8_t byte;
        } YE_H;
        union
        {
            struct
            {
                uint8_t YE0 : 1; /* Y end address bit 0 */
                uint8_t YE1 : 1; /* Y end address bit 1 */
                uint8_t YE2 : 1; /* Y end address bit 2 */
                uint8_t YE3 : 1; /* Y end address bit 3 */
                uint8_t YE4 : 1; /* Y end address bit 4 */
                uint8_t YE5 : 1; /* Y end address bit 5 */
                uint8_t YE6 : 1; /* Y end address bit 6 */
                uint8_t YE7 : 1; /* Y end address bit 7 */
            };
            uint8_t byte;
        } YE_L;
    };
    uint8_t bytes[4];
} ST7789_RASET_Type;

typedef union
{
    struct
    {
        uint8_t PSL_H; /* Partial Start Line high byte*/
        uint8_t PSL_L; /* Partial Start Line low byte*/
        uint8_t PEL_H; /* Partial End Line high byte*/
        uint8_t PEL_L; /* Partial End Line low byte*/
    };
    uint8_t bytes[4];
} ST7789_PTLAR_Type;

typedef union
{
    struct
    {
        uint8_t TFA_H; /* Top Fixed Area high byte */
        uint8_t TFA_L; /* Top Fixed Area low byte */
        uint8_t VSA_H; /* Vertical Scrolling Area high byte */
        uint8_t VSA_L; /* Vertical Scrolling Area low byte */
        uint8_t BFA_H; /* Bottom Fixed Area high byte */
        uint8_t BFA_L; /* Bottom Fixed Area low byte */
    };
    uint8_t bytes[6];
} ST7789_VSCRDEF_Type;

typedef union
{
    struct
    {
        uint8_t TEM : 1;      /* Tearing Effect Mode 0 = V-blanking information only, 1 = V-blanking and H-blanking information */
        uint8_t RESERVED : 7; /* Reserved */
    };
    uint8_t byte;
} ST7789_TEON_Type;

typedef union
{
    struct
    {
        uint8_t RESERVED : 2; /* Reserved */
        uint8_t MH : 1;       /* Display Data Latch Order 0 = Horizontal refresh, 1 = Vertical refresh */
        uint8_t RGB : 1;      /* RGB/BGR Order 0 = RGB, 1 = BGR */
        uint8_t ML : 1;       /* Line Address Order 0 = Top to Bottom, 1 = Bottom to Top */
        uint8_t MV : 1;       /* Page/Column Order 0 = Normal, 1 = Reverse */
        uint8_t MX : 1;       /* Column Address Order 0 = Left to Right, 1 = Right to Left */
        uint8_t MY : 1;       /* Page Address Order 0 = Top to Bottom, 1 = Bottom to Top */
    };
    uint8_t byte;
} ST7789_MADCTL_Type;

typedef union
{
    struct
    {
        uint8_t VSP_H; /* Vertical Scrolling Start Address high byte */
        uint8_t VSP_L; /* Vertical Scrolling Start Address low byte */
    };
    uint8_t bytes[2];
} ST7789_VSCSAD_Type;

typedef enum
{
    ST7789_COLMOD_12bit = 0b011u,
    ST7789_COLMOD_16bit = 0b101u,
    ST7789_COLMOD_18bit = 0b110u,
    ST7789_COLMOD_16M   = 0b111u
} ST7789_PixelFormat_Type;

typedef enum
{
    ST7789_COLMOD_65K = 0b101u,
    ST7789_COLMOD_262K = 0b110u,
} ST7789_ColorFormat_Type;

typedef union
{
    struct
    {
        uint8_t control_format : 3; /* Pixel Format 011 = 12-bit/pixel, 101 = 16-bit/pixel, 110 = 18-bit/pixel, 111 = 16M truncated */
        uint8_t D3 : 1;             /* Reserved set to 0 */
        uint8_t rgb_format : 3;     /* RGB Interface Color Format 101 = 65K of RGB interface, 110 = 262K of RGB interfaces */
        uint8_t D7 : 1;             /* Reserved, set to 0 */
    };
    uint8_t byte;
} ST7789_COLMOD_Type;

typedef union
{
    uint8_t STE_H; /* Set tear scanline to line N */
    uint8_t STE_L;
} ST7789_STE_Type;

typedef union
{
    uint8_t GSCAN_H; /* Get tear scanline to line N */
    uint8_t GSCAN_L;
} ST7789_GSCAN_Type;

typedef struct
{
    uint8_t byte; /* Display Brightness */
} ST7789_DISBV_Type;

typedef union
{
    struct
    {
        uint8_t D0 : 1;    /* unused, set to 0 */
        uint8_t D1 : 1;    /* unused, set to 0 */
        uint8_t BL : 1;    /* Backlight Control On/Off */
        uint8_t DD : 1;    /* Display dimming On/Off */
        uint8_t D4 : 1;    /* unused, set to 0 */
        uint8_t BCTRL : 1; /* Backlight Control On/Off */
        uint8_t D6 : 1;    /* unused, set to 0 */
        uint8_t D7 : 1;    /* unused, set to 0 */
    };
    uint8_t byte; /* Write CTRL Display */
} ST7789_CTRLD_Type;

typedef union
{
    struct
    {
        uint8_t C0 : 1;     /* Content Adaptive Brightness Mode */
        uint8_t C1 : 1;     /* 00 = Off, 01 = User Interface Mode, 10 = Still Picture, 11 = Moving Image */
        uint8_t D2 : 1;     /* Not used */
        uint8_t D3 : 1;     /* Not used */
        uint8_t CE0 : 1;    /* Colour enhancement levels */
        uint8_t CE1 : 1;    /* 00 = Low enhancement, 01 = Medium enhancement, 11 = High enhancement */
        uint8_t D6 : 1;     /* Not used */
        uint8_t CECTRL : 1; /* Color Enhancement bit, 0 = off, 1 = on */
    };
    uint8_t byte;
} ST7789_WRCACE_Type;

typedef union
{
    struct
    {
        uint8_t C0 : 1; /* Content Adaptive Brightness Mode */
        uint8_t C1 : 1; /* 00 = Off, 01 = User Interface Mode, 10 = Still Picture, 11 = Moving Image */
        uint8_t D2 : 1; /* Not used */
        uint8_t D3 : 1; /* Not used */
        uint8_t D4 : 1; /* Not used */
        uint8_t D5 : 1; /* Not used */
        uint8_t D6 : 1; /* Not used */
        uint8_t D7 : 1; /* Not used */
    };
    uint8_t byte;
} ST7789_RDCABC_Type;

typedef struct
{
    uint8_t byte; /* Write Content Adaptive Brightness Control */
} ST7789_CABCMB_Type;

typedef union
{
    struct
    {
        uint8_t C0 : 1; /* Not used */
        uint8_t C1 : 1; /* Not used */
        uint8_t D2 : 1; /* Not used */
        uint8_t D3 : 1; /* Not used */
        uint8_t D4 : 1; /* Not used */
        uint8_t D5 : 1; /* Not used */
        uint8_t D6 : 1; /* Functionality detection */
        uint8_t D7 : 1; /* Register loading detection */
    };
    uint8_t byte;
} ST7789_RDABCSDR_Type;

typedef union
{
    uint8_t byte;
} ST7789_RDID1_Type;

typedef union
{
    uint8_t byte;
} ST7789_RDID2_Type;

typedef union
{
    uint8_t byte;
} ST7789_RDID3_Type;

/**
 * Datatypes for the extended command set are not provided, so as to discourage their use.
 */

/* Defines -------------------------------------------------------------------*/

/**
 * @brief This command is an empty command.
 *
 */
#define ST7789_NOP ((uint8_t)0x00u)

/**
 * @brief This commands requests the devide to reset.
 * All registers are set to their default values.
 * The content of the frame buffer is not changed.
 * After the reset, the MCU has to wait 5ms before sending any new commands.
 * If software reset is send during sleep-in mode, it is necessary to wait 120ms before sending sleep-out command.
 * Software reset cannot be executed during sleep-out sequence.
 * 
 */
#define ST7789_SWRESET ((uint8_t)0x01u)

/**
 * @brief This read byte returns 24-bit display identification information
 * After sending this command, the MCU has to read 4 bytes from the display.
 * The first byte is a dummy byte, the next 3 bytes are the manufacturer ID, module/driver version ID and module/driver ID.
 * 
 */
#define ST7789_RDDID ((uint8_t)0x04u)

/**
 * @brief This commands reads the display status.
 *
 */
#define ST7789_RDDST ((uint8_t)0x09u)

/**
 * @brief This command reads the display power mode.
 *
 */
#define ST7789_RDDPM ((uint8_t)0x0Au)

/**
 * @brief This command reads the display MADCTL register.
 *
 */
#define ST7789_RDDMADCTL ((uint8_t)0x0Bu)

/**
 * @brief This command reads the display pixel format.
 *
 */
#define ST7789_RDDCOLMOD ((uint8_t)0x0Cu)

/**
 * @brief This command reads the display image mode.
 *
 */
#define ST7789_RDDIM ((uint8_t)0x0Du)

/**
 * @brief This command reads the display signal mode.
 *
 */
#define ST7789_RDDSM ((uint8_t)0x0Eu)

/**
 * @brief This command reads the display self-diagnostic result.
 *
 */
#define ST7789_RDDSDR ((uint8_t)0x0Fu)

/**
 * @brief This command requests sleep-in mode.
 * This causes the display to enter its minimum power consumption mode.
 * This means that the DC/DC converter is turned off and the internal oscillator is stopped and pannel scanning is stopped.
 * MCU interface and memory is still active and memory keeps its content.
 * The display can be woken up by sending the sleep-out command (0x11).
 * It is necessary to wait 5ms before sending any new commands.
 * It is necessary to wait 120ms after sending sleep-out command before sending a new sleep-in command.
 * 
 */
#define ST7789_SLPIN ((uint8_t)0x10u)

/**
 * @brief This command requests sleep-out mode.
 * This causes the display to exit its minimum power consumption mode.
 * This means that the DC/DC converter is turned on and the internal oscillator is started and pannel scanning is started.
 * MCU interface and memory is still active and memory keeps its content.
 * It is necessary to wait 5ms before sending any new commands.
 * It is necessary to wait 120ms after sending sleep-out command before sending a new sleep-in command.
 * Self-diagnostic is run after this command.
 * 
 */
#define ST7789_SLPOUT ((uint8_t)0x11u)

/**
 * @brief This command turns on Partial mode. The partial mode window is described by the Partial Area command (0x30).
 * To leave partial mode, the display has to be set to normal mode by the Normal Display Mode command (0x13).
 * 
 */
#define ST7789_PTLON ((uint8_t)0x12u)

/**
 * @brief This command turns on Normal mode.
 * This command is used to exit partial mode.
 */
#define ST7789_NORON ((uint8_t)0x13u)

/**
 * @brief This command sets the display inversion to off.
 *
 */
#define ST7789_INVOFF ((uint8_t)0x20u)

/**
 * @brief This command sets the display inversion to on.
 *
 */
#define ST7789_INVON ((uint8_t)0x21u)

/**
 * @brief This command sets the gamma curve.
 *
 */
#define ST7789_GAMSET ((uint8_t)0x26u)

/**
 * @brief This command sets the display off.
 *
 */
#define ST7789_DISPOFF ((uint8_t)0x28u)

/**
 * @brief This command sets the display on.
 *
 */
#define ST7789_DISPON ((uint8_t)0x29u)

/**
 * @brief This command sets the column address.
 *
 */
#define ST7789_CASET ((uint8_t)0x2Au)

/**
 * @brief This command sets the row address.
 *
 */
#define ST7789_RASET ((uint8_t)0x2Bu)

/**
 * @brief This command writes the memory.
 * This command resets the column and page registers to the start values.
 * The MCU can then send the pixel data to the display continuously.
 * Any other command will terminate the write memory command.
 * 
 */
#define ST7789_RAMWR ((uint8_t)0x2Cu)

/**
 * @brief This command reads the memory.
 * This command resets the column and page registers to the start values.
 * The MCU can then read the pixel data from the display continuously.
 * Any other command will terminate the read memory command.
 * The pixel data is fixed to 18-bit.
 * 
 */
#define ST7789_RAMRD ((uint8_t)0x2Eu)

/**
 * @brief This command defines the partial mode's display area.
 * There are 4 parameters for this command.
 * The first two paramters are the PSL(Partial Start Line).
 * The third and fourth parameters are the PEL(Partial End Line).
 * 
 */
#define ST7789_PTLAR ((uint8_t)0x30u)

/**
 * @brief This command sets the Vertical Scrolling Definition.
 * This command only defines the vertical scrolling area, and does not start scrolling.
 * The vertical scrolling area is defined by the TFA, VSA and BFA parameters.
 * The TFA parameter is the top fixed area number of lines.
 * The VSA parameter is the vertical scrolling area number of lines.
 * The BFA parameter is the bottom fixed area number of lines.
 * 
 */
#define ST7789_VSCRDEF ((uint8_t)0x33u)

/**
 * @brief This command is used to turn off the Tearing Effect output signal.
 *
 */
#define ST7789_TEOFF ((uint8_t)0x34u)

/**
 * @brief This command is used to turn on the Tearing Effect output signal.
 *
 */
#define ST7789_TEON ((uint8_t)0x35u)

/**
 * @brief This command sets the Memory Access Control.
 *
 */
#define ST7789_MADCTL ((uint8_t)0x36u)

/**
 * @brief This command sets the Vertical Scrolling Start Address.
 * This is used in combination with the Vertical Scrolling Definition command (0x33).
 * This defines the line which is the first line of the vertical scrolling area.
 * 
 */
#define ST7789_VSCSAD ((uint8_t)0x37u)

/**
 * @brief This command sets the Idle Mode Off.
 * This command is used to exit idle mode.
 * 
 */
#define ST7789_IDMOFF ((uint8_t)0x38u)

/**
 * @brief This command sets the Idle Mode On.
 * This command is used to enter idle mode.
 * 
 */
#define ST7789_IDMON ((uint8_t)0x39u)

/**
 * @brief This command sets the Pixel Format.
 *
 */
#define ST7789_COLMOD ((uint8_t)0x3Au)

/**
 * @brief This command writes the display memory.
 * This commmand does not reset the column and page registers.
 * 
 */
#define ST7789_WRMEMC ((uint8_t)0x3Cu)

/**
 * @brief This command reads the display memory.
 * This commmand does not reset the column and page registers.
 * 
 */
#define ST7789_RDMEMC ((uint8_t)0x3Eu)

/**
 * @brief This command sets the tear scanline.
 *
 */
#define ST7789_STE ((uint8_t)0x44u)

/**
 * @brief This command gets the tear scanline.
 *
 */
#define ST7789_GSCAN ((uint8_t)0x45u)

/**
 * @brief This command sets the write display brightness value.
 *
 */
#define ST7789_WRDISBV ((uint8_t)0x51u)

/**
 * @brief This command reads the display brightness value.
 *
 */
#define ST7789_RDDISBV ((uint8_t)0x52u)

/**
 * @brief This command sets the write CTRL display value.
 *
 */
#define ST7789_WRCTRLD ((uint8_t)0x53u)

/**
 * @brief This command reads the CTRL display value.
 *
 */
#define ST7789_RDCTRLD ((uint8_t)0x54u)

/**
 * @brief This command sets the write content adaptive brightness control value and colour enhancement.
 *
 */
#define ST7789_WRCACE ((uint8_t)0x55u)

/**
 * @brief This command reads the content adaptive brightness control value.
 *
 */
#define ST7789_RDCABC ((uint8_t)0x56u)

/**
 * @brief This command sets the write CABC minimum brightness.
 *
 */
#define ST7789_WRCABCMB ((uint8_t)0x5Eu)

/**
 * @brief This command reads the CABC minimum brightness.
 *
 */
#define ST7789_RDCABCMB ((uint8_t)0x5Fu)

/**
 * @brief This command reads the Automatic Brightness Control Self-Diagnostic Result.
 * 
 */
#define ST7789_RDABCSDR ((uint8_t)0x68u)

/**
 * @brief This command reads the ID1 value.
 *
 */
#define ST7789_RDID1 ((uint8_t)0xDAu)

/**
 * @brief This command reads the ID2 value.
 *
 */
#define ST7789_RDID2 ((uint8_t)0xDBu)

/**
 * @brief This command reads the ID3 value.
 *
 */
#define ST7789_RDID3 ((uint8_t)0xDCu)

/**
 * Extended Command Set
 * This command set is used to access the extended commands of the ST7789V.
 * Try to avoid using these commands as they are more complex and may cause unexpected behaviour.
 * These commands will not be used in this library, and will not be provided in the API.
 */

#ifdef ST7789_EXTENDED_COMMAND_SET

/**
 * @brief RAM Control
 * This command defines the behaviour of the internal RAM frame buffer.
 * RM: RAM access selection
 * DM: Display operation selection
 * ENDIAN: Data byte order
 * MDT: Method of pixel data transfer
 * RIM: RGB interface bus width
 * EPF: Data translate of 65k and 4k to frame data
 */
#define ST7789_RAMCTRL ((uint8_t)0xB0u)

/**
 * @brief RGB Interface Control
 * 
 */
#define ST7789_RGBCTRL ((uint8_t)0xB1u)

/**
 * @brief Porch Setting
 * 
 */
#define ST7789_PORCTRL ((uint8_t)0xB2u)

/**
 * @brief Frame Rate Control 1 (In partial mode/ idle colours)
 * 
 */
#define ST7789_FRCTRL1 ((uint8_t)0xB3u)

/**
 * @brief Partical Control  
 * 
 */
#define ST7789_PARCTRL ((uint8_t)0xB5u)

/**
 * @brief Gate Control
 * 
 */
#define ST7789_GCTRL ((uint8_t)0xB7u)

/**
 * @brief Gate on Timing Adjustment
 * 
 */
#define ST7789_GTADJ ((uint8_t)0xB8u)

/**
 * @brief Digital Gamma Enable
 * 
 */
#define ST7789_DGMEN ((uint8_t)0xBAu)

/**
 * @brief VCOM Setting
 * 
 */
#define ST7789_VCOMS ((uint8_t)0xBBu)

/**
 * @brief Power Saving Mode
 * 
 */
#define ST7789_POWSAVE ((uint8_t)0xBCu)

/**
 * @brief Display off Power Saving
 * 
 */
#define ST7789_DLPOFFSAVE ((uint8_t)0xBDu)

/**
 * @brief LCM Control
 * 
 */
#define ST7789_LCMCTRL ((uint8_t)0xC0u)

/**
 * @brief ID Code Setting
 * 
 */
#define ST7789_IDSET ((uint8_t)0xC1u)

/**
 * @brief VDV and VRH Command Enable
 * 
 */
#define ST7789_VDVVRHEN ((uint8_t)0xC2u)

/**
 * @brief VRH Set
 * 
 */
#define ST7789_VRHS ((uint8_t)0xC3u)

/**
 * @brief VDV Set
 * 
 */
#define ST7789_VDVSET ((uint8_t)0xC4u)

/**
 * @brief VCOM Offset Set
 * 
 */
#define ST7789_VCMOFSET ((uint8_t)0xC5u)

/**
 * @brief  Frame Rate Control in Normal Mode
 * 
 */
#define ST7789_FRCTR2 ((uint8_t)0xC6u)

/**
 * @brief CABC Control
 * 
 */
#define ST7789_CABCCTRL ((uint8_t)0xC7u)

/**
 * @brief  Register Value Selection 1
 * Reserved for testing, do not use.
 * 
 */
#define ST7789_REGSEL1 ((uint8_t)0xC8u)

/**
 * @brief  Register Value Selection 2
 * Reserved for testing, do not use.
 * 
 */
#define ST7789_REGSEL2 ((uint8_t)0xCAu)

/**
 * @brief PWM Frequency Selection
 * 
 */
#define ST7789_PWMFRSEL ((uint8_t)0xCCu)

/**
 * @brief Power Control 1
 * 
 */
#define ST7789_PWCTRL1 ((uint8_t)0xD0u)

/**
 * @brief Enable VAP/VAN signal output
 * 
 */
#define ST7789_VAPVANEN ((uint8_t)0xD2u)

/**
 * @brief Command 2 Enable
 * 
 */
#define ST7789_CMD2EN ((uint8_t)0xDFu)

/**
 * @brief Positive Voltage Gamma Control
 * 
 */
#define ST7789_PVGAMCTRL ((uint8_t)0xE0u)

/**
 * @brief Negative Voltage Gamma Control
 * 
 */
#define ST7789_NVGAMCTRL ((uint8_t)0xE1u)

/**
 * @brief Digital Gamma Look-up Table for Red
 * 
 */
#define ST7789_DGMLUTR ((uint8_t)0xE2u)

/**
 * @brief Digital Gamma Look-up Table for Blue
 * 
 */
#define ST7789_DGMLUTB ((uint8_t)0xE3u)

/**
 * @brief Gate Control 
 * 
 */
#define ST7789_GATECTRL ((uint8_t)0xE4u)

/**
 * @brief SPI2 Enable
 * 
 */
#define ST7789_SPI2EN ((uint8_t)0xE7u)

/**
 * @brief Power Control 2
 * 
 */
#define ST7789_PWCTRL2 ((uint8_t)0xE8u)

/**
 * @brief Equalize time control
 * 
 */
#define ST7789_EQCTRL ((uint8_t)0xE9u)

/**
 * @brief Program Mode Control
 * 
 */
#define ST7789_PROMCTRL ((uint8_t)0xECu)

/**
 * @brief Program Mode Enable
 * 
 */
#define ST7789_PROMEN ((uint8_t)0xFAu)

/**
 * @brief NVM Setting
 * 
 */
#define ST7789_NVMSET ((uint8_t)0xFCu)

/**
 * @brief Program action
 * 
 */
#define ST7789_PROMACT ((uint8_t)0xFEu)

#endif // ST7789_EXTENDED_COMMAND_SET

/* Global variables ----------------------------------------------------------*/

/* Function declarations -----------------------------------------------------*/

#endif // ST7789_DRIVER_COMMANDLIST_H