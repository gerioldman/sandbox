/**
 * @file Complementary_Filter.c
 * @brief TODO
 * @date 2022-11-28-02:08:18
 */

/* Includes ------------------------------------------------------------------*/

#include "Complementary_Filter.h"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

static float phiHat = 0.0f;
static float thetaHat = 0.0f;

/* Local function declarations -----------------------------------------------*/

/* Local function definitions ------------------------------------------------*/

/* Global function definitions -----------------------------------------------*/

/**
 * @brief Clears local variables to zero to init the filter
 * 
 */
void Complementary_Filter_InitFilter()
{
    phiHat = 0.0f;
    thetaHat = 0.0f;
}

/**
 * @brief Updates the filter with the new data
 * 
 * @param accelerometer 3 axis input from the accelerometer in m/s^2
 * @param gyroscope 3 axis input from the gyroscope in radian/s
 */
void Complementary_Filter_UpdateFilter(const float accelerometer[3], const float gyroscope[3])
{
    float phiHat_acc_rad = atan2f(accelerometer[1], accelerometer[2]); // atanf(facc[1] / facc[2]
    float thetaHat_acc_rad = asinf(accelerometer[0] / 10.0f);

    // Body rates -> Euler rates, transform into Earth frame
    float phiDot_rps = gyroscope[0] + tanf(thetaHat) * (sinf(phiHat) * gyroscope[1] + cosf(phiHat) * gyroscope[2]);
    float thetaDot_rps = cosf(phiHat) * gyroscope[1] - sinf(phiHat) * gyroscope[2];

    // Save old data if error occurs
    float oldphi = phiHat;

    // Estimation
    phiHat = COMP_FILT_ALPHA * phiHat_acc_rad + (1.0f - COMP_FILT_ALPHA) * (phiHat + (1 / DATA_FREQUENCY) * phiDot_rps);

    // Check if error occured and discard data if error occured
    if (isnan(phiHat))
        phiHat = oldphi;

    // Save old data if error occurs
    float oldtheta = thetaHat;

    // Estimation
    thetaHat = COMP_FILT_ALPHA * thetaHat_acc_rad + (1.0f - COMP_FILT_ALPHA) * (thetaHat + (1.0f / DATA_FREQUENCY) * thetaDot_rps);

    // Check if error occured and discard data if error occured
    if (isnan(thetaHat))
        thetaHat = oldtheta;
}


/**
 * @brief Returns the current estimated orientation data
 * 
 * @return Orientation_Data_t 
 */
Orientation_Data_t Complementary_Filter_GetOrientationData()
{
    return ((Orientation_Data_t){ .phiHat = phiHat , .thetaHat = thetaHat });
}
