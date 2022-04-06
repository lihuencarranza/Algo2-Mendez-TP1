#include "estructuras.h"
#include "interaccion.h"
#include <stdlib.h>

#define LECTURA_INTERACCIONES "%[^;];%[^;];%[^;];%[^;];\n"

//NOMBRE_OBJETO;VERBO;NOMBRE_OBJETO2;ACCION
//if(OBJETO2 != '_' => TIPO_ACCION:NOMBRE_OBJETO:MENSAJE


/*
 * Crea una interacción a partir del string.
 *
 * Esta función reserva memoria con malloc y la interacción devuelta debe ser
 * destruida con free.
 *
 * Devuelve la interacción creada o NULL en caso de error de memoria o formato
 * incorrecto del string.
 */
struct interaccion *interaccion_crear_desde_string(const char *string)
{
	return NULL;
}
