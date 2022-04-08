#include "objeto.h"
#include "estructuras.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LECTURA_OBJETOS "%[^;];%[^;];%[^;];\n"
#define FALSE 'false'
#define TRUE 'true'
#define MAX_BOOL 7


struct objeto *objeto_crear_desde_string(const char *string)
{
	if(string == NULL)
		return NULL;

	struct objeto *objeto = malloc(sizeof(struct objeto));

	if(objeto == NULL){
		return NULL;
	}

	char buleano[MAX_BOOL];

	int elementos_leidos = sscanf(string, LECTURA_OBJETOS, objeto->nombre, objeto->descripcion, buleano);

	if(elementos_leidos != 3)
		return NULL;
	

	if(strcmp(buleano, "false") == 0){
		objeto->es_asible = false;
	}else if(strcmp(buleano, "true") == 0){
		objeto->es_asible = true;
	}else{
		return NULL;
	}

	return objeto;

}
