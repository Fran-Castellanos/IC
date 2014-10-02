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

#include "cuerpo.h"


typedef struct
{
	float velocidad; //Velocidad inicial
	int numeroCuerpos; //Número de cuerpos
	int numeroMovimientos; //Número de movimientos de los cuerpos
	TCuerpo* cuerpos; //Posiciones de los cuerpos

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
	printf("El numero de movimientos es: %d", param->numeroMovimientos);

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
	int numeroCuerpos, numeroMovimientos;
	float velocidad;
	TCoordenada coord;
	TCuerpo* cuerpos;
	TCuerpo cuerpo;
	coord.y = 0;
	int i;
	//Número de cuerpos
	do
	{
		printf("Numero de cuerpos (>0): ");

		scanf("%d",&numeroCuerpos);


		if(numeroCuerpos<=0)
		{
			printf("El valor del numero de cuerpos no es correcto. Vuelva a intentarlo\n");

		}
	}while(numeroCuerpos<=0);

	cuerpos = (TCuerpo *)malloc (numeroCuerpos * sizeof(TCuerpo)); //Array dinámico de posiciones de los cuerpos

	//Establecer posición de cada cuerpo
	for(i=0; i<numeroCuerpos; i++)
	{
		do{
			printf("Posicion inicial del cuerpo %d. Eje X: ",i);
			coord.x=0;
			scanf("%d",&coord.x);

			if(coord.x<0)
			{
				printf("Valor de la posicion inicial incorrecto. Vuelva a intentarlo\n");
			}

		}while(coord.x<0);
		cuerpo.posicion = coord;
		cuerpos[i]=cuerpo;

	}


	//Velocidad inicial
	do{
		printf("Velocidad inicial de los cuerpos (>0): ");

		scanf("%f",&velocidad);

		if(velocidad<=0){
			printf("El valor de la velocidad no es correcto. Vuelva a intentarlo\n");

		}

	}while(velocidad<=0);


	//Número de iteraciones
		do{
			printf("Numero de movimientos de los cuerpos (>0): ");

			scanf("%d",&numeroMovimientos);

			if(numeroMovimientos<=0){
				printf("El numero de movimientos no es correcto. Vuelva a intentarlo\n");

			}

		}while(numeroMovimientos<=0);

	//Vuelca los valores en la estructura de tipo TParametros.
	param->numeroCuerpos = numeroCuerpos;
	param->velocidad = velocidad;
	param->cuerpos = cuerpos;
	param->numeroMovimientos = numeroMovimientos;

}
