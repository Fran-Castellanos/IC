/*
 * interfaz.h
 *
 *  Created on: 2/10/2014
 */

#ifndef NCUERPOSPROJECTSECUENCIAL_LIB_INTERFAZ_H_
#define NCUERPOSPROJECTSECUENCIAL_LIB_INTERFAZ_H_


#include "cuerpo.h"
#include "coordenadas.h"

// Pide numero de cuerpos al usuario
int numero_cuerpos();


// Pide coordenadas de un cuerpo al usuario
TCoordenada coordenada_cuerpo(int);


// Pide la velocidad inicial de los cuerpos al usuario.
float velocidad_inicial();


// Pide el n�mero de movimientos que se van a calcular al usuario.
int numero_movimientos();


// Pide fuerza de gravedad al usuario
float fuerza_gravedad();


char* imprimir(TCoordenada*);




#endif /* NCUERPOSPROJECTSECUENCIAL_LIB_INTERFAZ_H_ */
