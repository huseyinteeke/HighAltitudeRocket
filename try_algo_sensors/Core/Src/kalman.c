/*
 * kalman.c
 *
 *  Created on: Feb 22, 2026
 *      Author: husey
 */


#include "kalman.h"


void Kalman1D_Init(Kalman1D_t *kf, float init_x, float init_p, float q, float r)
{
	kf->x = init_x;
	kf->p = init_p;
	kf->q = q;
	kf->r = r;
}
float Kalman1D_Update(Kalman1D_t *kf, float measurement)
{
	kf->p = kf->p + kf->q;

	kf->k = kf->p / (kf->p + kf->r);
	kf->x = kf->x + kf->k * (measurement - kf->x);
	kf->p = (1.0f - kf->k) * (measurement - kf->x);

	return kf->x;
}
