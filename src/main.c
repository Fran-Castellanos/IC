/*
 * Prácticas 1 y 2 IC
 * Problema de los N cuerpos.
 * Lenguaje: C
 */


#include <stdio.h>
#include <stdlib.h>

#include "coordenadas.h"
#include "gravedad.h"
#include "fichero.h"
#include "interfaz.h"
#include "cuerpo.h"


typedef struct
{
	float velocidad; //Velocidad inicial
	int numeroCuerpos; //Número de cuerpos
	int numeroMovimientos; //Número de movimientos de los cuerpos
	TCuerpo* cuerpos; //Posiciones de los cuerpos
	TGravedad gravedad; //Punto de gravedad

}TParametros;



void rellenar_parametros(TParametros*);
void ejecutar(TParametros*);
void liberar(TParametros*);
void imprimir(TParametros*);



/*
 * Función principal
 */
int main(int argc, char *argv[]){

	TParametros param;
	rellenar_parametros(&param);




	ejecutar(&param);




	//TODO Imprime los parámetros iniciales para comprobar que funciona bien
	imprimir(&param);




	liberar(&param); //Libera memoria dinámica de parámetros

	return 0;
}



/*
 * Ejecución principal del programa
 */
void ejecutar(TParametros* param)
{
	char* linea = "prueba"; //Texto de prueba
	FILE* fichero;
	fichero = fopen ( "posiciones.txt", "w");


	int i;
	for(i=0; i<param->numeroMovimientos;i++)
	{
		guardar_en_fichero(fichero,linea);
		guardar_en_fichero(fichero,"\n");
	}





	fclose(fichero);
}




void imprimir(TParametros* param)
{
	int i;
	printf("\nDatos:\n");
	printf("La velocidad es: %f\n",param->velocidad);
	printf("El numero de cuerpos es: %d\n",param->numeroCuerpos);
	printf("Posicion de los cuerpos:\n");
	for(i=0;i<param->numeroCuerpos;i++)
	{
		printf("\tCuerpo %d: %d , %d\n",i, param->cuerpos[i].posicion.x, param->cuerpos[i].posicion.y);
	}
	printf("El numero de movimientos es: %d\n", param->numeroMovimientos);
	printf("La fuerza de gravedad es: %f\n", param->gravedad.fuerza);
}


/*
 * Libera memoria dinámica (cuerpos)
 */
void liberar(TParametros* param)
{
	free(param->cuerpos); //Libera memoria dinámica
}






/**
 * Rellena los parámetros necesarios para la ejecución del programa
 */
void rellenar_parametros(TParametros* param)
{
	int numeroCuerpos, numeroMovimientos, i;
	float velocidad, fuerza;
	TGravedad gravedad;
	TCoordenada coord;
	TCuerpo* cuerpos;
	TCuerpo cuerpo;
	coord.y = 0; //Inicializa coordenada 'y' de cuerpos a 0

	//Número de cuerpos
	numeroCuerpos = numero_cuerpos();

	//Array dinámico de posiciones de los cuerpos
	cuerpos = (TCuerpo *)malloc (numeroCuerpos * sizeof(TCuerpo));

	//Establecer posición de cada cuerpo
	for(i=0; i<numeroCuerpos; i++)
	{
		cuerpo.posicion = coordenada_cuerpo(i);
		cuerpos[i]=cuerpo;
	}

	//Velocidad inicial
	velocidad = velocidad_inicial();


	//Número de iteraciones
	numeroMovimientos = numero_movimientos();


	//Fuerza de gravedad
	gravedad.fuerza = fuerza_gravedad();


	//Vuelca los valores en la estructura de tipo TParametros.
	param->numeroCuerpos = numeroCuerpos;
	param->velocidad = velocidad;
	param->cuerpos = cuerpos;
	param->numeroMovimientos = numeroMovimientos;
	param->gravedad = gravedad;

}
