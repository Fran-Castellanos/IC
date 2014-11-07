
#ifndef NCUERPOSPROJECTOPENMP_LIB_GRAVEDAD_H_
#define NCUERPOSPROJECTOPENMP_LIB_GRAVEDAD_H_


#include "coordenadas.h"
#include "cuerpo.h"




typedef struct{
	TCoordenada posicion;
	TVector vector;
	float fuerza;
}TGravedad;




void aplicar_gravedad(TCuerpo*, TGravedad*);
float gravedad_x(TCuerpo*, TGravedad*);
float gravedad_y(TCuerpo*, TGravedad*);
int calcular_gravedad_x(TCuerpo*, TGravedad*, double, float);
int calcular_gravedad_y(TCuerpo*, TGravedad*, double, float);

#endif /* NCUERPOSPROJECTOPENMP_LIB_GRAVEDAD_H_ */
