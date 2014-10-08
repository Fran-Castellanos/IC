/*
 * interfaz.h
 *
 *  Created on: 2/10/2014
 */

#ifndef LIB_INTERFAZ_H_
#define LIB_INTERFAZ_H_


#include "cuerpo.h"
#include "coordenadas.h"

// Pide numero de cuerpos al usuario
int numero_cuerpos();


// Pide coordenadas de un cuerpo al usuario
TCoordenada coordenada_cuerpo(int);


// Pide la velocidad inicial de los cuerpos al usuario.
float velocidad_inicial();


// Pide el número de movimientos que se van a calcular al usuario.
int numero_movimientos();


// Pide fuerza de gravedad al usuario
float fuerza_gravedad();


char* imprimir(TCoordenada*);




#endif /* LIB_INTERFAZ_H_ */
