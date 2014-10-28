/*
 * vector.c
 *
 *  Created on: 7/10/2014
 *      Author: Paco
 */

#include "vector.h"
#include <math.h>



TVector sumar_vectores(TVector v1, TVector v2)
{
	TVector v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;

	return v3;
}



float obtener_modulo(TVector v)
{
	return sqrt(pow(v.x,2) + pow(v.y,2));
}





