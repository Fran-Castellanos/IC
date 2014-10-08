/*
 * Prácticas 1 y 2 IC
 * Problema de los N cuerpos.
 * Lenguaje: C
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	int tam; //Tamaño del tablero

}TParametros;



void rellenar_parametros(TParametros*);
void ejecutar(TParametros*);
void liberar(TParametros*);
void imprimir_parametros(TParametros*);



/*
 * Función principal
 */
int main(int argc, char *argv[]){

	TParametros param;
	rellenar_parametros(&param);

	//TODO Imprime los parámetros iniciales para comprobar que funciona bien
	imprimir_parametros(&param);

	ejecutar(&param);







	liberar(&param); //Libera memoria dinámica de parámetros

	return 0;
}







/*
 * Ejecución principal del programa
 */
void ejecutar(TParametros* param)
{
	int tam = 0;
	char *linea = ""; //Texto de prueba
	FILE* fichero;
	fichero = fopen ( "posiciones.txt", "w");

	linea = malloc(100);





	 //--------------------------------Número de cuerpos---------------------------
	itoa(param->numeroCuerpos,linea,10);

	guardar_en_fichero(fichero,linea);
	guardar_en_fichero(fichero,"\n");


	strcpy(linea, imprimir(&(param->gravedad.posicion)));

	 //------------------------Posición del punto de gravedad----------------------
	guardar_en_fichero(fichero,linea);
	guardar_en_fichero(fichero,"\n");

	tam = (abs(param->gravedad.posicion.x) > abs(param->gravedad.posicion.y))? abs(param->gravedad.posicion.x) : abs(param->gravedad.posicion.y);

	int i,c;
	for(i=0; i<param->numeroMovimientos;i++)
	{
		strcpy(linea,"");
		for (c=0; c<param->numeroCuerpos; c++){

			tam = (abs(param->cuerpos[c].posicion.x) > tam)? abs(param->cuerpos[c].posicion.x) : tam;
			tam = (abs(param->cuerpos[c].posicion.y) > tam)? abs(param->cuerpos[c].posicion.y) : tam;

			strcat(linea, imprimir(&(param->cuerpos[c].posicion)));
			if(strlen(linea) > 100)
				linea = malloc(sizeof(linea)+100);

			aplicar_gravedad(&(param->cuerpos[c]), &(param->gravedad), param->tam);
		}

		guardar_en_fichero(fichero,linea);
		guardar_en_fichero(fichero,"\n");

	}

	 //------------------------------Tamaño del tablero----------------------------
	strcpy(linea, "");
	itoa(tam*1.20,linea,10);

	guardar_en_fichero(fichero,linea);
	guardar_en_fichero(fichero,"\n");

	free(linea);



	fclose(fichero);
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

		cuerpo.vector.coordenadas.x = velocidad; //Inicializa vector movimiento
		cuerpo.vector.coordenadas.y = 0;

		if(pos_mayor < abs(cuerpo.posicion.x))
			pos_mayor = abs(cuerpo.posicion.x);
		cuerpos[i]=cuerpo;
	}




	//Número de iteraciones
	numeroMovimientos = numero_movimientos();


	//Fuerza de gravedad
	gravedad.fuerza = fuerza_gravedad();
	gravedad.posicion.y = pos_mayor*3;
	gravedad.posicion.x = pos_mayor*3;



	//Vuelca los valores en la estructura de tipo TParametros.
	param->numeroCuerpos = numeroCuerpos;
	param->velocidad = velocidad;
	param->cuerpos = cuerpos;
	param->numeroMovimientos = numeroMovimientos;
	param->gravedad = gravedad;
	param->tam = pos_mayor*3*2;
}
