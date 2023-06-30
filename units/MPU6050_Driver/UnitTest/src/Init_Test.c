/**
 * @file Init_Test.c
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

void InitCase(){

}

void ConnectionTest(){
	// Connection test

	// Set up mock functions
	TEST_STUB.I2C_Read.returnValue = I2C_ERROR;
	TEST_STUB.I2C_Read.pData.stub_pArg_option = STUB_OPTION_PARG_COPY_TO;
	TEST_STUB.I2C_Read.pData.value = 0x69u;

	// Call MPU6050_Init with default init request
	MPU6050_StatusTypeDef returnValue = TEST_CALL_MPU6050_Init(NULL);

	// There should be error, due to the I2C_Read function returning error
	ASSERT_UINT8_EQUAL(MPU6050_ERROR, returnValue);

	// Called once to read the WHO_AM_I register
	ASSERT_UINT32_EQUAL(1u, TEST_STUB.I2C_Read.callcount);

	// Read with the correct addresses
	ASSERT_UINT16_EQUAL(MPU6050_ADDRESS << 1, TEST_STUB.I2C_Read.DevAddress);

	// Read the correct register
	ASSERT_UINT16_EQUAL(WHO_AM_I_ADDRESS, TEST_STUB.I2C_Read.MemAddress);

	// Read the correct number of bytes
	ASSERT_UINT16_EQUAL(1u, TEST_STUB.I2C_Read.Size);

	// Timeout set to 1000
	ASSERT_UINT32_EQUAL(1000u, TEST_STUB.I2C_Read.Timeout);

	// Set up mock to return success, but wrong value in WHO_AM_I register
	TEST_STUB.I2C_Read.returnValue = I2C_OK;

	// Call MPU6050_Init with default init request
	returnValue = TEST_CALL_MPU6050_Init(NULL);

	// There should be error, due to the I2C_Read function returning error
	ASSERT_UINT8_EQUAL(MPU6050_ERROR, returnValue);

}

/* @@TEST_CASES@@ */
/* Test Suite declaration - Do not modify ------------------------------------*/

TestSuite Init_Test = {
	.name = "Init_Test",
	.TestCases = 
	{
		TEST_CASE_ENTRY(InitCase),
		TEST_CASE_ENTRY(ConnectionTest),
		TEST_CASE_ENTRY(TEST_CASE_END),
	},
};