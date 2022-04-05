#include "estructuras.h"
#include "interaccion.h"
#include <stdlib.h>

#define LECTURA_INTERACCIONES "%[^;];%[^;];%[^;];%[^;];\n"

//NOMBRE_OBJETO;VERBO;NOMBRE_OBJETO2;ACCION
//if(OBJETO2 != '_' => TIPO_ACCION:NOMBRE_OBJETO:MENSAJE

struct interaccion *interaccion_crear_desde_string(const char *string)
{
	return NULL;
}
