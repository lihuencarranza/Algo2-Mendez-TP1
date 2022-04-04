#include "objeto.h"
#include "estructuras.h"
#include <stdlib.h>

#define LECTURA_OBJETOS "%[^;];%[^;];%[^;];\n"

//NOMBRE_OBJETO;VERBO;NOMBRE_OBJETO2;ACCION
//if(OBJETO2 != '_' => TIPO_ACCION:NOMBRE_OBJETO:MENSAJE


//d para descubrir objetos, r para reemplazar objetos, e para eliminar objetos y m para mostrar un mensaje.

struct objeto *objeto_crear_desde_string(const char *string)
{
	return NULL;
}
