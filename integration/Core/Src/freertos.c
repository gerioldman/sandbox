/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "ST7789.h"
#include "graphics.h"
#include "MPU6050_Driver.h"
#include "Complementary_Filter.h"
#include "i2c_detect.h"
#include "string.h"
#include "stdio.h"
#include "math.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */
extern uint8_t display_buffer0[115200];
extern uint8_t display_buffer1[115200];
extern I2C_HandleTypeDef hi2c4;
extern UART_HandleTypeDef huart3;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
MPU6050_AccelData accelerometer;
MPU6050_GyroData gyroscope;
Orientation_Data_t orientation_data;
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
uint32_t defaultTaskBuffer[1024];
osStaticThreadDef_t defaultTaskControlBlock;
const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .cb_mem = &defaultTaskControlBlock,
    .cb_size = sizeof(defaultTaskControlBlock),
    .stack_mem = &defaultTaskBuffer[0],
    .stack_size = sizeof(defaultTaskBuffer),
    .priority = (osPriority_t)osPriorityNormal,
};
/* Definitions for ST7789 */
osThreadId_t ST7789Handle;
uint32_t ST7789Buffer[1024];
osStaticThreadDef_t ST7789ControlBlock;
const osThreadAttr_t ST7789_attributes = {
    .name = "ST7789",
    .cb_mem = &ST7789ControlBlock,
    .cb_size = sizeof(ST7789ControlBlock),
    .stack_mem = &ST7789Buffer[0],
    .stack_size = sizeof(ST7789Buffer),
    .priority = (osPriority_t)osPriorityAboveNormal,
};
/* Definitions for MPU6050OsTask */
osThreadId_t MPU6050OsTaskHandle;
uint32_t MPU6050OsTaskBuffer[1024];
osStaticThreadDef_t MPU6050OsTaskControlBlock;
const osThreadAttr_t MPU6050OsTask_attributes = {
    .name = "MPU6050OsTask",
    .cb_mem = &MPU6050OsTaskControlBlock,
    .cb_size = sizeof(MPU6050OsTaskControlBlock),
    .stack_mem = &MPU6050OsTaskBuffer[0],
    .stack_size = sizeof(MPU6050OsTaskBuffer),
    .priority = (osPriority_t)osPriorityAboveNormal1,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void ST7789OsTask(void *argument);
void MPU6050OsTaskFunc(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{
}

__weak unsigned long getRunTimeCounterValue(void)
{
  return 0;
}
/* USER CODE END 1 */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of ST7789 */
  ST7789Handle = osThreadNew(ST7789OsTask, NULL, &ST7789_attributes);

  /* creation of MPU6050OsTask */
  MPU6050OsTaskHandle = osThreadNew(MPU6050OsTaskFunc, NULL, &MPU6050OsTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  (void)argument;
  for (;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_ST7789OsTask */
/**
 * @brief Function implementing the ST7789 thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_ST7789OsTask */
void ST7789OsTask(void *argument)
{
  /* USER CODE BEGIN ST7789OsTask */
  /* Infinite loop */
  (void)argument;
  for (;;)
  {
    ST7789_WriteData(display_buffer0, 57600u);
    ST7789_WriteData(display_buffer0 + 57600u, 57600u);
    Graphics_Draw();
    osDelay(40);
  }
  /* USER CODE END ST7789OsTask */
}

/* USER CODE BEGIN Header_MPU6050OsTaskFunc */
/**
 * @brief Function implementing the MPU6050OsTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_MPU6050OsTaskFunc */
void MPU6050OsTaskFunc(void *argument)
{
  /* USER CODE BEGIN MPU6050OsTaskFunc */
  (void)argument;
  MPU6050_Init(0);
  Complementary_Filter_InitFilter();
  /* Infinite loop */
  for (;;)
  {
    MPU6050_Read_Accelerometer(&accelerometer);
    MPU6050_Read_Gyroscope(&gyroscope);

    float acc[3];
    float gyro[3];

    acc[0] = ((float)accelerometer.X) / 32768.0f * 2.0f * 9.81f;
    acc[1] = ((float)accelerometer.Y) / 32768.0f * 2.0f * 9.81f;
    acc[2] = ((float)accelerometer.Z) / 32768.0f * 2.0f * 9.81f;

    gyro[0] = ((float)gyroscope.X) / 32768.0f * 250.0f * 3.14f / 180.0f;
    gyro[1] = ((float)gyroscope.Y) / 32768.0f * 250.0f * 3.14f / 180.0f;
    gyro[2] = ((float)gyroscope.Z) / 32768.0f * 250.0f * 3.14f / 180.0f;

    Complementary_Filter_UpdateFilter(acc, gyro);

    orientation_data = Complementary_Filter_GetOrientationData();

    char buffer[100];
    sprintf(buffer, "%f %f %f %f %f %f %f %f\r\n", acc[0], acc[1], acc[2], gyro[0], gyro[1], gyro[2], orientation_data.phiHat, orientation_data.thetaHat);

    HAL_UART_Transmit(&huart3, buffer, strlen(buffer), 1000);

    osDelay(10);
  }
  /* USER CODE END MPU6050OsTaskFunc */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
