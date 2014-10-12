/*
 * Prácticas 1 y 2 IC
 * Problema de los N cuerpos.
 * Lenguaje: C
 */



#include "coordenadas.h"
#include "gravedad.h"
#include "fichero.h"
#include "interfaz.h"
#include "cuerpo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





typedef struct
{
	float velocidad; //Velocidad inicial
	int numeroCuerpos; //Número de cuerpos
	int numeroMovimientos; //Número de movimientos de los cuerpos
	TCuerpo* cuerpos; //Posiciones de los cuerpos
	TGravedad gravedad; //Punto de gravedad
	int tam; //Tamaño del tablero

}TParametros;



void rellenar_parametros(TParametros*);
void ejecutar(TParametros*, int);
void liberar(TParametros*);
void imprimir_parametros(TParametros*);



/*
 * Función principal
 */
int main(int argc, char *argv[]){

	int opcion=0;
	if(argc>1)
		opcion= 1;
	printf("Se ha elegido la opcion %d\n",opcion);
	TParametros param;
	rellenar_parametros(&param);

	//TODO Imprime los parámetros iniciales para comprobar que funciona bien
	imprimir_parametros(&param);

	ejecutar(&param, opcion);







	liberar(&param); //Libera memoria dinámica de parámetros

	return 0;
}







/*
 * Ejecución principal del programa
 */
void ejecutar(TParametros* param, int fich)
{
	//int tam = 0;
	char *linea = ""; //Texto de prueba
	FILE* fichero;
	int repeticiones = 1,r;
	int movimientos;
	if(fich){
		fichero = fopen ( "posiciones.txt", "w");

		linea = malloc(1000);
	}


	clock_t inicio;
	clock_t fin, tiempo = 0.0;


	 //--------------------------------Número de cuerpos---------------------------
	if(fich){
		itoa(param->numeroCuerpos,linea,10);
		guardar_en_fichero(fichero,linea);
		guardar_en_fichero(fichero,"\n");


		strcpy(linea,imprimir(&(param->gravedad.posicion)));

		 //------------------------Posición del punto de gravedad----------------------
		guardar_en_fichero(fichero,linea);
		guardar_en_fichero(fichero,"\n");
		movimientos = param->numeroMovimientos;
	}else{
		printf("\nNUMERO DE CUERPOS: %d\n", param->numeroCuerpos);
		movimientos = 64;
		repeticiones = 18;
	}

	//Si queremos hacer muchas ejecuciones con diferente numero de movimientos, repeticiones
	//será el número de repeticiones que se harán, comenzando por 64 y multiplicando por 2
	//en cada iteracion.
	for(r=0; r<repeticiones; r++){
		int i,c;
		for(i=0; i<movimientos;i++)
		{
			if(fich)
				strcpy(linea,"");
			for (c=0; c<param->numeroCuerpos; c++){

				if(fich){
					strcat(linea,imprimir(&(param->cuerpos[c].posicion)));


				}


				inicio = clock();
				aplicar_gravedad(&(param->cuerpos[c]), &(param->gravedad), param->tam);
				fin = clock();
				tiempo += fin-inicio;

			}
			if(fich){

				guardar_en_fichero(fichero,linea);
				guardar_en_fichero(fichero,"\n");
			}
		}
		if(!fich)
		{
			printf("\nMOVIMIENTOS: %d\n", movimientos);
			movimientos *=2;
		}
		printf("\tEl algoritmo ha tardado %f segundos\n", (double)tiempo/CLOCKS_PER_SEC);
	}

	if(fich){
	 //------------------------------Tamaño del tablero----------------------------
		strcpy(linea, "");
		itoa(1000,linea,10);

		guardar_en_fichero(fichero,linea);
		guardar_en_fichero(fichero,"\n");

		free(linea);

		fclose(fichero);
	}


}




void imprimir_parametros(TParametros* param)
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
	int numeroCuerpos, numeroMovimientos, i, pos_mayor=1;
	float velocidad;
	TGravedad gravedad;
	TCuerpo* cuerpos;
	TCuerpo cuerpo;


	//Número de cuerpos
	numeroCuerpos = numero_cuerpos();

	//Velocidad inicial
	velocidad = velocidad_inicial();

	//Array dinámico de posiciones de los cuerpos
	cuerpos = (TCuerpo *)malloc (numeroCuerpos * sizeof(TCuerpo));

	//Establecer posición de cada cuerpo
	for(i=0; i<numeroCuerpos; i++)
	{
		cuerpo.posicion = coordenada_cuerpo(i);

		cuerpo.vector.y = velocidad; //Inicializa vector movimiento
		cuerpo.vector.x = 0;

		if(pos_mayor < abs(cuerpo.posicion.x))
			pos_mayor = abs(cuerpo.posicion.x);
		cuerpos[i]=cuerpo;
	}




	//Número de iteraciones
	numeroMovimientos = numero_movimientos();


	//Fuerza de gravedad
	gravedad.fuerza = fuerza_gravedad();
	gravedad.posicion.y = 250;
	gravedad.posicion.x = 500;



	//Vuelca los valores en la estructura de tipo TParametros.
	param->numeroCuerpos = numeroCuerpos;
	param->velocidad = velocidad;
	param->cuerpos = cuerpos;
	param->numeroMovimientos = numeroMovimientos;
	param->gravedad = gravedad;
	param->tam = pos_mayor*3*2;
}
