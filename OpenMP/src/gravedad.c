

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "../lib/gravedad.h"
#include "../lib/vector.h"


void aplicar_gravedad(TCuerpo* cuerpo, TGravedad* gravedad)
{

	double m = ((float)(gravedad->posicion.y - cuerpo->posicion.y ) / (float)(gravedad->posicion.x - cuerpo->posicion.x));
	double angulo = atan(m);



	gravedad->vector.x = (gravedad->posicion.x< cuerpo->posicion.x ) ? -1 : +1;


	gravedad->vector.y = (gravedad->posicion.y<cuerpo->posicion.y )? -1 : +1;

	float distancia = sqrt(pow(gravedad->posicion.x - cuerpo->posicion.x,2 )+pow(gravedad->posicion.y - cuerpo->posicion.y,2 ));

	gravedad->vector.x *=  abs(gravedad->fuerza * sin(angulo)) /distancia;
	gravedad->vector.y *=  abs(gravedad->fuerza * cos(angulo)) /distancia;



	TVector v = sumar_vectores(cuerpo->vector, gravedad->vector);

	cuerpo->vector.x = v.x;
	cuerpo->vector.y = v.y;


	cuerpo->posicion.x = cuerpo->posicion.x + cuerpo->vector.x;
	cuerpo->posicion.y = cuerpo->posicion.y + cuerpo->vector.y;

}



float gravedad_x(TCuerpo* cuerpo, TGravedad* gravedad){
	int incremento;

	incremento = cuerpo->vector.x;



	return incremento;
}



float gravedad_y(TCuerpo* cuerpo, TGravedad* gravedad)
{
	int incremento;

	incremento = cuerpo->vector.y;


	return incremento;

}
