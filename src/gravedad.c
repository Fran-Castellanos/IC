
#include "vector.h"
#include <math.h>
#include "gravedad.h"

#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

void aplicar_gravedad(TCuerpo* cuerpo, TGravedad* gravedad, int tam)
{

	double m = ((float)(gravedad->posicion.y - cuerpo->posicion.y ) / (float)(gravedad->posicion.x - cuerpo->posicion.x));
	double angulo = atan(m);



	gravedad->vector.x = (gravedad->posicion.x< cuerpo->posicion.x ) ? -1 : +1;


	gravedad->vector.y = (gravedad->posicion.y<cuerpo->posicion.y )? -1 : +1;

	float distancia = sqrt(pow(gravedad->vector.x,2 )+pow(gravedad->vector.y,2 ));

	gravedad->vector.x *=  abs(gravedad->fuerza * sin(angulo));
	gravedad->vector.y *=  abs(gravedad->fuerza * cos(angulo));



	printf("cuerpo.x= %d\n", cuerpo->posicion.x);
	printf("cuerpo.y= %d\n", cuerpo->posicion.y);
	printf("cuerpo.vector.x= %f\n", cuerpo->vector.x);
	printf("cuerpo.vector.y= %f\n", cuerpo->vector.y);
	printf("gravedad.vector.x= %f\n", gravedad->vector.x);
	printf("gravedad.vector.y= %f\n", gravedad->vector.y);
	printf("angulo= %f\n", angulo);
	printf("m= %f\n", m);
	printf("Dist= %f\n", distancia);



	TVector v = sumar_vectores(cuerpo->vector, gravedad->vector);

	cuerpo->vector.x = v.x;
	cuerpo->vector.y = v.y;


	cuerpo->posicion.x = cuerpo->posicion.x + cuerpo->vector.x;
	cuerpo->posicion.y = cuerpo->posicion.y + cuerpo->vector.y;

	printf("gravedad.vector.x= %f\n", gravedad->vector.x);
	printf("gravedad.vector.y= %f\n", gravedad->vector.y);
	printf("v.x= %f\n", v.x);
	printf("v.y= %f\n", v.y);
	printf("nuevo cuerpo.x= %d\n", cuerpo->posicion.x);
	printf("nuevo cuerpo.y= %d\n", cuerpo->posicion.y);

	printf("\n");
}



float gravedad_x(TCuerpo* cuerpo, TGravedad* gravedad, int tam){
	int incremento;

	incremento = cuerpo->vector.x;



	return incremento;
}



float gravedad_y(TCuerpo* cuerpo, TGravedad* gravedad, int tam)
{
	int incremento;

	incremento = cuerpo->vector.y;


	return incremento;

}
