/*
 * magdwick.h
 *
 *  Created on: Feb 22, 2026
 *      Author: husey
 */

#ifndef INC_MAGDWICK_H_
#define INC_MAGDWICK_H_

#include "bno055_func_struct.h"

void MadgwichAHRSUpdateIMU(BNO055_AccelData_t* accelold , BNO055_GyroData_t* gyroold , BNO055_QuatData_t* quat , float dt);
void QuaternionToEuler(BNO055_QuatData_t* quat , BNO055_EulerData_t* euler);



#endif /* INC_MAGDWICK_H_ */
