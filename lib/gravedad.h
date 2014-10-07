
#ifndef LIB_GRAVEDAD_H_
#define LIB_GRAVEDAD_H_


#include "coordenadas.h"
#include "cuerpo.h"
#include "gravedad.h"



typedef struct{
	TCoordenada posicion;
	float fuerza;
}TGravedad;




void aplicar_gravedad(TCuerpo*, TGravedad*);
float gravedad_x(TCuerpo*, TGravedad*, float);
float gravedad_y(TCuerpo*, TGravedad*, float);


#endif /* LIB_GRAVEDAD_H_ */
