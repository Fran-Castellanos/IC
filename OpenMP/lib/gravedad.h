
#ifndef NCUERPOSPROJECTSECUENCIAL_LIB_GRAVEDAD_H_
#define NCUERPOSPROJECTSECUENCIAL_LIB_GRAVEDAD_H_


#include "coordenadas.h"
#include "cuerpo.h"




typedef struct{
	TCoordenada posicion;
	TVector vector;
	float fuerza;
}TGravedad;




void aplicar_gravedad(TCuerpo*, TGravedad*, int);
float gravedad_x(TCuerpo*, TGravedad*, int);
float gravedad_y(TCuerpo*, TGravedad*, int);


#endif /* NCUERPOSPROJECTSECUENCIAL_LIB_GRAVEDAD_H_ */
