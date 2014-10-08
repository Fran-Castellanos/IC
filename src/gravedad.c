
#include "vector.h"
#include <math.h>
#include "gravedad.h"

#include <stdio.h>

void aplicar_gravedad(TCuerpo* cuerpo, TGravedad* gravedad)
{
	float m = (cuerpo->posicion.y - gravedad->posicion.y)
				  /
				  (cuerpo->posicion.x - gravedad->posicion.x);

	//printf("\nm: %f", m);
	float fuerza_x = gravedad_x(cuerpo, gravedad, m);
	float fuerza_y = gravedad_y(cuerpo, gravedad, m);

	//printf("\nx: %f", fuerza_x);
	//printf("\ny: %f", fuerza_y);
	cuerpo->posicion.x = cuerpo->posicion.x*fuerza_x*0.001;
	cuerpo->posicion.y = cuerpo->posicion.y*fuerza_y*0.001;

	//printf("\nCuerpox: %d", cuerpo->posicion.x);
	//printf("\nCuerpoy: %d", cuerpo->posicion.y);

}



float gravedad_x(TCuerpo* cuerpo, TGravedad* gravedad, float m){
	float G = gravedad->fuerza;


	float fuerza = sqrt(pow(gravedad->posicion.x - cuerpo->posicion.x,2)
				+
				(pow(gravedad->posicion.y - cuerpo->posicion.y,2))) * cos(atan(0-m)) *G;


	return fuerza;
}



float gravedad_y(TCuerpo* cuerpo, TGravedad* gravedad, float m)
{
	float G = gravedad->fuerza;

	float fuerza = sqrt(pow(gravedad->posicion.x - cuerpo->posicion.x,2)
			+
			(pow(gravedad->posicion.y - cuerpo->posicion.y,2))) * cos(atan(-2-m))*G;

	return fuerza;

}
