#include "estructuras.h"
#include "sala.h"
#include "objeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEA 1028


int verificar_apertura_archivos(FILE *arch_objetos, FILE *arch_interacciones)
{
	if(arch_objetos == NULL || arch_interacciones == NULL){
		perror("No se pudieron abrir los archivos\n");
		fclose(arch_objetos);
		fclose(arch_interacciones);
		return -1;
	}
	printf("Se abrieron los archivos\n"); //sacar
	return 0;
}


sala_t *sala_crear_desde_archivos(const char *objetos, const char *interacciones)
{

	FILE *arch_objetos = fopen(objetos, "r");
	FILE *arch_interacciones = fopen(interacciones, "r");

	if(verificar_apertura_archivos(arch_objetos, arch_interacciones) == -1)
		return NULL;
	

	sala_t *sala = malloc(sizeof(sala_t));
	
	if(sala == NULL){
		printf("No se reservó memoria para sala\n");
		return NULL;
	} else{
		printf("Se creó sala\n");
	}

	
	fclose(arch_objetos);
	fclose(arch_interacciones);
	return sala;

}

char **sala_obtener_nombre_objetos(sala_t *sala, int *cantidad)
{
	return NULL;
}

bool sala_es_interaccion_valida(sala_t *sala, const char *verbo, const char *objeto1, const char *objeto2)
{
	return false;
}

void sala_destruir(sala_t *sala)
{
}
