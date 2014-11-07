

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


#include "../lib/gravedad.h"
#include "../lib/vector.h"


void aplicar_gravedad(TCuerpo* cuerpo, TGravedad* gravedad)
{

	double m = ((float)(gravedad->posicion.y - cuerpo->posicion.y ) / (float)(gravedad->posicion.x - cuerpo->posicion.x));
	double angulo = atan(m);




	double distX = 0, distY = 0;
	double D=0;

	D = gravedad->posicion.x - cuerpo->posicion.x;
	distX = D*D;

	D = gravedad->posicion.y - cuerpo->posicion.y;
	distY = D*D;

	float distancia = sqrt(distX+distY);

	int x=0,y=0;
	float d=0;


	d = (gravedad->posicion.x < cuerpo->posicion.x ) ? -1 : +1;
	d *=  abs(gravedad->fuerza * sin(angulo)) /distancia;
	x = cuerpo->vector.x + d;




	d = (gravedad->posicion.y < cuerpo->posicion.y ) ? -1 : +1;
	d *=  abs(gravedad->fuerza * cos(angulo)) /distancia;
	y = cuerpo->vector.y + d;





	cuerpo->vector.y = y;
	cuerpo->vector.x = x;

	cuerpo->posicion.x += x;
	cuerpo->posicion.y += y;



}







int calcular_gravedad_x(TCuerpo* cuerpo, TGravedad* gravedad, double angulo, float distancia)
{
	int salida = 0;

	gravedad->vector.x = (gravedad->posicion.x< cuerpo->posicion.x ) ? -1 : +1;

	gravedad->vector.x *=  abs(gravedad->fuerza * sin(angulo)) /distancia;

	salida = cuerpo->vector.x + gravedad->vector.x;


	return salida;




}




int calcular_gravedad_y(TCuerpo* cuerpo, TGravedad* gravedad, double angulo, float distancia)
{
	int salida = 0;


	gravedad->vector.y = (gravedad->posicion.y<cuerpo->posicion.y )? -1 : +1;
	gravedad->vector.y *=  abs(gravedad->fuerza * cos(angulo)) /distancia;
	salida = cuerpo->vector.y + gravedad->vector.x;


	return salida;




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
