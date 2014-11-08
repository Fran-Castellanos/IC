/*
 * Prácticas 1 y 2 IC
 * Problema de los N cuerpos.
 * Lenguaje: C
 */



#include "../lib/coordenadas.h"
#include "../lib/gravedad.h"
#include "../lib/fichero.h"
#include "../lib/interfaz.h"
#include "../lib/cuerpo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <omp.h>





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

int **crear_matriz(unsigned long, unsigned long);
void destruir_matriz(TCoordenada **, unsigned long, unsigned long);


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
	unsigned long movimientos;
	unsigned long numeroCuerpos = param->numeroCuerpos;
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

	int procesadores = omp_get_num_procs();
	printf("Numero de procesadores disponibles: %d\n\n", procesadores);
	omp_set_num_threads (procesadores);

		for(r=0; r<repeticiones; r++){

			TCoordenada **coordenadas = crear_matriz(numeroCuerpos, movimientos);

			unsigned long c=0;
			unsigned long i=0;

			inicio = clock();


			//Paralelizamos el calculo de los movimientos de cada cuerpo
			#pragma omp parallel for private(i) shared(param,coordenadas)
			for(c=0; c<param->numeroCuerpos; c++)
			{
				for (i=0; i<movimientos;i++){
					aplicar_gravedad(&(param->cuerpos[c]), &(param->gravedad));
					if(fich)
						coordenadas[c][i] = param->cuerpos[c].posicion;

				}
			}

			fin = clock();
			tiempo = fin-inicio;


			if(fich){


				int f = 0;
				int cuerpo = 0;
				for(f=0; f<param->numeroMovimientos; f++){
					strcpy(linea,"");
					for(cuerpo=0; cuerpo<param->numeroCuerpos; cuerpo++){
						strcat(linea,imprimir(&(coordenadas[cuerpo][f])));
					}
					guardar_en_fichero(fichero,linea);
					guardar_en_fichero(fichero,"\n");
				}
			}

			//Libera memoria dinamica del array bidimensional de coordenadas
			destruir_matriz(coordenadas, numeroCuerpos, movimientos );

			if(!fich){
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



//Crea matriz dinamica
int **crear_matriz(unsigned long n, unsigned long m) {
    /**
     * Crea una matriz dinamica (malloc) de n por m
     */
    int i;
    int **matriz = (int **)malloc(sizeof(TCoordenada *) * n);

    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(sizeof(TCoordenada) * m);
    }

    return matriz;
}


//Libera memoria dinamica de una matriz
void destruir_matriz(TCoordenada **matriz, unsigned long n, unsigned long m) {
    /**
     * Destruye (libera la memoria dinamica) la matriz de n por m
     */
    int i;

    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }

    free(matriz);
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
