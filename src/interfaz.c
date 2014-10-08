/*
 * interfaz.c
 *
 *  Created on: 2/10/2014
 *
 */


#include "interfaz.h"
#include <stdio.h>
#include "stdlib.h"

/**
 * Pide numero de cuerpos al usuario
 */
int numero_cuerpos()
{
	int numeroCuerpos;
	do
	{
		printf("Numero de cuerpos (>0): ");
		scanf("%d",&numeroCuerpos);

		if(numeroCuerpos<=0)
			printf("El valor del numero de cuerpos no es correcto. Vuelva a intentarlo\n");

		}while(numeroCuerpos<=0);

	return numeroCuerpos;
}


/**
 * Pide coordenadas de un cuerpo al usuario
 */
TCoordenada coordenada_cuerpo(int i)
{
	TCoordenada coord;
	do{
		printf("Posicion inicial del cuerpo %d. Eje X: ",i);
		coord.x=0;
		scanf("%d",&coord.x);

		if(coord.x<0)
			printf("Valor de la posicion inicial incorrecto. Vuelva a intentarlo\n");

	}while(coord.x<0);

	return coord;
}



/**
 * Pide la velocidad inicial de los cuerpos al usuario.
 */
float velocidad_inicial()
{
	float velocidad;
	do{
		printf("Velocidad inicial de los cuerpos (>0): ");
		scanf("%f",&velocidad);

		if(velocidad<=0)
			printf("El valor de la velocidad no es correcto. Vuelva a intentarlo\n");

		}while(velocidad<=0);
	return velocidad;
}



/**
 * Pide el número de movimientos que se van a calcular al usuario.
 */
int numero_movimientos()
{
	int numeroMovimientos;
	do{
		printf("Numero de movimientos de los cuerpos (>0): ");
		scanf("%d",&numeroMovimientos);

		if(numeroMovimientos<=0)
			printf("El numero de movimientos no es correcto. Vuelva a intentarlo\n");

	}while(numeroMovimientos<=0);

	return numeroMovimientos;
}


float fuerza_gravedad()
{
	float fuerza;
	printf("Fuerza de gravedad: ");
	scanf("%f",&fuerza);
	return fuerza;
}




char* imprimir(TCoordenada* coord){

	char aux[100];
	char linea [100] = "";
	itoa(coord->x, linea, 10 );

	strcat(linea, ",");
	itoa(coord->y, aux, 10);
	strcat(linea,aux);
	strcat(linea, "\t");

	return linea;
}



