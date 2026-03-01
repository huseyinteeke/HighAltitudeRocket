/*
 * kalman.h
 *
 *  Created on: Feb 22, 2026
 *      Author: husey
 */

#ifndef KALMAN_H_
#define KALMAN_H_

#include "main.h"

typedef struct
{
	float x;
	float p;
	float q;
	float r;
	float k;
}Kalman1D_t;


#endif /* KALMAN_H_ */
