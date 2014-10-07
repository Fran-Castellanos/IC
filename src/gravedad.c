
#include "vector.h"
#include <math.h>
#include "gravedad.h"

void aplicar_gravedad(TCuerpo* cuerpo, TGravedad* gravedad)
{
	float m = (cuerpo->posicion.y - gravedad->posicion.y)
				  /
				  (cuerpo->posicion.x - gravedad->posicion.x);

	float fuerza_x = gravedad_x(cuerpo, gravedad, m);
	float fuerza_y = gravedad_y(cuerpo, gravedad, m);

	cuerpo->posicion.x = cuerpo->posicion.x*fuerza_x;
	cuerpo->posicion.y = cuerpo->posicion.y*fuerza_y;


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
