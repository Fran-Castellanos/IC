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

	v3.coordenadas.x = v1.coordenadas.x + v2.coordenadas.y;
	v3.coordenadas.y = v1.coordenadas.y + v2.coordenadas.y;

	return v3;
}



float obtener_modulo(TVector v)
{
	return sqrt(pow(v.coordenadas.x,2) + pow(v.coordenadas.y,2));
}





