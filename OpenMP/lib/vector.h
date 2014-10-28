/*
 * vector.h
 *
 *  Created on: 7/10/2014
 *      Author: Paco
 */

#ifndef LIB_VECTOR_H_
#define LIB_VECTOR_H_


#include "coordenadas.h"

	typedef struct
	{
		float x;
		float y;

	}TVector;




	TVector sumar_vectores(TVector, TVector);

	float obtener_modulo(TVector);








#endif /* LIB_VECTOR_H_ */
