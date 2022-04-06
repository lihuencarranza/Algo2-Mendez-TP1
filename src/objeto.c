#include "objeto.h"
#include "estructuras.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LECTURA_OBJETOS "%[^;];%[^;];%[^;];\n"
#define FALSE 'false'
#define TRUE 'true'
#define MAX_BOOL 6


struct objeto *objeto_crear_desde_string(const char *string)
{
	struct objeto *objeto = malloc(sizeof(struct objeto));

	if(objeto == NULL){
		return NULL;
	}

	char buleano[MAX_BOOL];

	sscanf(string, LECTURA_OBJETOS, objeto->nombre, objeto->descripcion, buleano);

	if(buleano[0] == 'f'){
		objeto->es_asible = false;
	}else if(buleano[0] == 't'){
		objeto->es_asible = true;
	}

	return objeto;

}
