/*
 * magdwick.c
 *
 *  Created on: Feb 22, 2026
 *      Author: husey
 */

#ifndef SRC_MAGDWICK_C_
#define SRC_MAGDWICK_C_

#include "magdwick.h"
#include "math.h"

#define MAGDWICK_BETA 0.1f


void MadgwichAHRSUpdateIMU(BNO055_AccelData_t* accelold , BNO055_GyroData_t* gyroold , BNO055_QuatData_t* quat , float dt)
{
	float gyro_quat[4] =
	{
			0,
			gyroold->gyro_x,
			gyroold->gyro_y,
			gyroold->gyro_z
	};

	BNO055_QuatData_t newquat;

	newquat.quat_w = -0.5f*((gyro_quat[1]*quat->quat_x) + (gyro_quat[2]*quat->quat_y) + (gyro_quat[3]*quat->quat_z));
	newquat.quat_x =  0.5f*((gyro_quat[1]*quat->quat_w) + (gyro_quat[3]*quat->quat_y) - (gyro_quat[2]*quat->quat_z));
	newquat.quat_y =  0.5f*((gyro_quat[2]*quat->quat_w) - (gyro_quat[3]*quat->quat_x) + (gyro_quat[1]*quat->quat_z));
	newquat.quat_z =  0.5*((gyro_quat[3]*quat->quat_w) + (gyro_quat[2]*quat->quat_x) - (gyro_quat[1]*quat->quat_y));

	float sigma2 = accelold->acc_x + 2*quat->quat_w*quat->quat_y - 2*quat->quat_y*quat->quat_z;
	float sigma1 = 2*quat->quat_x*quat->quat_w - accelold->acc_y + 2*quat->quat_y*quat->quat_z;
	float sigma3 = 4*quat->quat_x*(2*quat->quat_x*quat->quat_x + 2*quat->quat_y*quat->quat_y + accelold->acc_z - 1);

	float GradientDescent[4] =
	{
			2*sigma2*quat->quat_y + 2*quat->quat_x*sigma1,
			2*quat->quat_w*sigma1 - 2*quat->quat_y*sigma2 + sigma3,
			2*quat->quat_w*sigma2 + 2*quat->quat_z*sigma1 + sigma3,
			2*quat->quat_y*sigma1 - 2*quat->quat_x*sigma2
	};

	float norm = sqrtf(GradientDescent[0]*GradientDescent[0] +
					   GradientDescent[1]*GradientDescent[1] +
					   GradientDescent[2]*GradientDescent[2] +
					   GradientDescent[3]*GradientDescent[3]);

	if(norm > 0.0f)
	{
		float recipNorm = 1.0f / norm;

		for(int i = 0 ; i < 3 ; i ++) GradientDescent[i] *= recipNorm;
	}


	float qDot_w = newquat.quat_w - MAGDWICK_BETA*GradientDescent[0];
	float qDot_x = newquat.quat_x - MAGDWICK_BETA*GradientDescent[1];
	float qDot_y = newquat.quat_y - MAGDWICK_BETA*GradientDescent[2];
	float qDot_z = newquat.quat_z - MAGDWICK_BETA*GradientDescent[3];


	quat->quat_w += qDot_w * dt;
	quat->quat_x += qDot_x * dt;
	quat->quat_y += qDot_y * dt;
	quat->quat_z += qDot_z * dt;


	norm = sqrtf(quat->quat_w*quat->quat_w +
		             quat->quat_x*quat->quat_x +
		             quat->quat_y*quat->quat_y +
		             quat->quat_z*quat->quat_z);


	if(norm > 0.0f)
	{
		float recipNorm = 1.0f / norm;

		quat->quat_w *= recipNorm;
		quat->quat_x *= recipNorm;
		quat->quat_y *= recipNorm;
		quat->quat_z *= recipNorm;

	}

}






void QuaternionToEuler(BNO055_QuatData_t* quat  , BNO055_EulerData_t* euler)
{

	float roll 	= atan2f(2*(quat->quat_x*quat->quat_w + quat->quat_y*quat->quat_z) , (1 - 2*(quat->quat_x*quat->quat_x + quat->quat_y*quat->quat_y)));
	float pitch = asinf(2*(quat->quat_w*quat->quat_y - quat->quat_z*quat->quat_x));
	float yaw	= atan2f(2*(quat->quat_w*quat->quat_z + quat->quat_x*quat->quat_y) , (1 - 2*(quat->quat_y*quat->quat_y + quat->quat_z*quat->quat_z)));


	euler->heading 	= yaw;
	euler->pitch	= pitch;
	euler->roll		= roll;


}




















#endif /* SRC_MAGDWICK_C_ */
