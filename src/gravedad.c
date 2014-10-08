
#include "vector.h"
#include <math.h>
#include "gravedad.h"

#include "vector.h"
#include <stdio.h>

void aplicar_gravedad(TCuerpo* cuerpo, TGravedad* gravedad, int tam)
{
	//Calcula vector de gravedad con respecto al cuerpo
	gravedad->vector.coordenadas.x = -cuerpo->posicion.x + gravedad->posicion.x;
	gravedad->vector.coordenadas.y = -cuerpo->posicion.y + gravedad->posicion.y;





	TVector v = sumar_vectores(cuerpo->vector, gravedad->vector);

	cuerpo->vector.coordenadas.x = v.coordenadas.x;
	cuerpo->vector.coordenadas.y = v.coordenadas.y;

	float incremento_x = gravedad_x(cuerpo, gravedad, tam);
	float incremento_y = gravedad_y(cuerpo, gravedad, tam);

	cuerpo->posicion.x = cuerpo->posicion.x + incremento_x;
	cuerpo->posicion.y = cuerpo->posicion.y + incremento_y;



}



float gravedad_x(TCuerpo* cuerpo, TGravedad* gravedad, int tam){
	int incremento;

	incremento = cuerpo->vector.coordenadas.x/tam;



	return incremento;
}



float gravedad_y(TCuerpo* cuerpo, TGravedad* gravedad, int tam)
{
	int incremento;

	incremento = cuerpo->vector.coordenadas.y/tam;


	return incremento;

}
