/**
 * @file Run_Test.c
 * @brief TODO - Add description
 * @date 4/28/2023
 */

/* Generated includes - Do not modify ----------------------------------------*/

#include "TestSuites.h"
#include "UnitTestAssert.h"
/* It is normal for this to be not available right after project generation, this is created during the compilation process */
#include "MPU6050_Driver.c_mock.h" 

/* Private includes ----------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/


/* Public functions ----------------------------------------------------------*/

void Read_Gyro(){
	/* Add test implementation */
}

void Read_Acc(){
	/* Add test implementation */
}

/* @@TEST_CASES_UPDATE@@ */
/* Test Suite declaration - Do not modify ------------------------------------*/

TestSuite Run_Test = {
	.name = "Run_Test",
	.TestCases = 
	{
		TEST_CASE_ENTRY(Read_Gyro),
		TEST_CASE_ENTRY(Read_Acc),
		TEST_CASE_ENTRY(TEST_CASE_END),
	},
};