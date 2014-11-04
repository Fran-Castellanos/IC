
#include "../lib/fichero.h"
#include <string.h>

void guardar_en_fichero(FILE* fichero, char* linea)
{

	fwrite (linea, sizeof(char), strlen(linea), fichero);


}
