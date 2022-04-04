#include "estructuras.h"
#include "sala.h"
#include "objeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEA 1028


int abrir_archivos(FILE *arch_objetos, FILE *arch_interacciones, const char *objetos, const char *interacciones)
{
	arch_objetos = fopen(objetos, "r");
	arch_interacciones = fopen(interacciones, "r");

	if(!arch_objetos || !arch_interacciones){
		perror("No se pudieron abrir los archivos\n");
		fclose(arch_objetos);
		fclose(arch_interacciones);
		return -1;
	}
	return 0;
}

sala_t *sala_crear_desde_archivos(const char *objetos, const char *interacciones)
{

	FILE *arch_objetos;
	FILE *arch_interacciones;

	arch_objetos = fopen(objetos, "r");
	arch_interacciones = fopen(interacciones, "r");

	if(!arch_objetos || !arch_interacciones){
		perror("No se pudieron abrir los archivos\n");
		fclose(arch_objetos);
		fclose(arch_interacciones);
		return NULL;
	}
	
	


	/*if(abrir_archivos(arch_objetos, arch_interacciones, objetos, interacciones) == -1)
		return NULL;
	*/


	struct sala *sala_t = malloc(sizeof(struct sala));
	
	if(sala_t == NULL)
		return NULL;

	char **string = calloc(LINEA, (sizeof(char*)));

	int i = 0;

	int elemento_leido = fscanf(arch_objetos, "%[^\n]\n", (*string+i));

	while(elemento_leido == 1){
		objeto_crear_desde_string((*string+i));
		i++;
		elemento_leido = fscanf(arch_objetos, "%[^\n]\n", (*string+i));
	}

	sala_t->cantidad_objetos = i;
	
	
	free(sala_t);
	for(int j = 0; j < i; j++)
		free(string+j);

	return NULL;
	
}

char **sala_obtener_nombre_objetos(sala_t *sala, int *cantidad)
{
	return NULL;
}

bool sala_es_interaccion_valida(sala_t *sala, const char *verbo, const char *objeto1,
				const char *objeto2)
{
	return false;
}

void sala_destruir(sala_t *sala)
{
}
