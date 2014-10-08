
#ifndef LIB_GRAVEDAD_H_
#define LIB_GRAVEDAD_H_


#include "coordenadas.h"
#include "cuerpo.h"
#include "gravedad.h"



typedef struct{
	TCoordenada posicion;
	TVector vector;
	float fuerza;
}TGravedad;




void aplicar_gravedad(TCuerpo*, TGravedad*, int);
float gravedad_x(TCuerpo*, TGravedad*, int);
float gravedad_y(TCuerpo*, TGravedad*, int);


#endif /* LIB_GRAVEDAD_H_ */
