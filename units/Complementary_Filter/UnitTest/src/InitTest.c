/**
 * @file InitTest.c
 * @brief TODO - Add description
 * @date 4/29/2023
 */

/* Generated includes - Do not modify ----------------------------------------*/

#include "TestSuites.h"
#include "UnitTestAssert.h"
/* It is normal for this to be not available right after project generation, this is created during the compilation process */
#include "Complementary_Filter.c_mock.h" 

/* Private includes ----------------------------------------------------------*/


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/* Private macro -------------------------------------------------------------*/


/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/


/* Public functions ----------------------------------------------------------*/

void TC2(){
		/* local variable to store read data */

	Orientation_Data_t data;
	float dummy_Accelerometer_data[3] = { 10.0f, 0.0f, 0.0f };
	float dummy_Gyroscope_data[3] = { 1.0f, 1.0f, 0.0f };
	
	/* Check initial value */
	
	data = TEST_CALL_Complementary_Filter_GetOrientationData();
	ASSERT_FLOAT_EQUAL(data.phiHat, 0.0f, 0.0f);
	ASSERT_FLOAT_EQUAL(data.thetaHat, 0.0f, 0.0f);

	/* Call UpdateFilter to change the internal variables */

	TEST_CALL_Complementary_Filter_UpdateFilter(dummy_Accelerometer_data, dummy_Gyroscope_data);

	/* Check if internal values changed */

	data = TEST_CALL_Complementary_Filter_GetOrientationData();
	ASSERT_FLOAT_NOT_EQUAL(data.phiHat, 0.0f, 0.0f);
	ASSERT_FLOAT_NOT_EQUAL(data.thetaHat, 0.0f, 0.0f);

	/* Call InitFilter function */

	TEST_CALL_Complementary_Filter_InitFilter();

	/* Check if internal values are back to zero */

	data = TEST_CALL_Complementary_Filter_GetOrientationData();
	ASSERT_FLOAT_EQUAL(data.phiHat, 0.0f, 0.0f);
	ASSERT_FLOAT_EQUAL(data.thetaHat, 0.0f, 0.0f);
}

/* @@TEST_CASES_UPDATE@@ */
/* Test Suite declaration - Do not modify ------------------------------------*/

TestSuite InitTest = {
	.name = "InitTest",
	.TestCases = 
	{
		TEST_CASE_ENTRY(TC2),
		TEST_CASE_ENTRY(TEST_CASE_END),
	},
};