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

/*
 * Crea una sala de escape a partir de un par de archivos.
 *
 * El string objetos es el path a un archivo con la definicion de los objetos
 * mientras que interacciones es el path a un archivo con la definicion de las
 * interacciones de los objetos.
 *
 * Devuelve una sala de escape creada con los datos leidos de los archivos o
 * NULL en caso de encontrar algún error en el proceso.
 *
 * La sala de escape devuelta debe ser liberada con la función de destrucción de
 * la sala antes de finalizar el programa.
 */
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
		printf("Se creó la sala\n"); //sacar
	}

	sala->objetos = NULL;

	int tamanio_objetos = 0;

	char *string = malloc(LINEA * sizeof(char));
	if(string == NULL)
		return NULL;

	int elemento_leido = fscanf(arch_objetos, "%[^\n]\n", string);

	if(elemento_leido != 1)
		return NULL;

	struct objeto *objeto_auxiliar;
	struct objeto **aux;
	
	while(elemento_leido == 1){

		objeto_auxiliar = objeto_crear_desde_string(string);

		aux = realloc(sala->objetos, (((long unsigned int)(tamanio_objetos)+1) * sizeof(struct objeto*)));;
		if(aux == NULL)
			return NULL;

		aux[tamanio_objetos] = objeto_auxiliar;
		tamanio_objetos++;
		sala->objetos = aux;

		elemento_leido = fscanf(arch_objetos, "%[^\n]\n", string);
		
	}
	printf("%i\n", tamanio_objetos);
	
	fclose(arch_objetos);
	fclose(arch_interacciones);
	return sala;

}

/*
 * Devuelve un vector dinámico reservado con malloc que contiene los nombres de
 * todos los objetos existentes en la sala de escape.
 *
 * En la variable cantidad (si no es nula) se guarda el tamanio del vector de
 * nombres.
 *
 * El vector devuelto debe ser liberado con free.
 *
 * En caso de error devuelve NULL y pone cantidad en -1.
 */
char **sala_obtener_nombre_objetos(sala_t *sala, int *cantidad)
{
	return NULL;
}

/*
 * Devuelve true si existe una interacción válida utilizando el verbo en objeto1
 * y objeto2. Objeto1 siempre es el nombre de un objeto. Objeto2 puede ser un
 * string vacío para interacciones que no necesitan dos objetos.
 *
 * Devuelve false si la interacción no existe o si se encuentra algún error.
 */
bool sala_es_interaccion_valida(sala_t *sala, const char *verbo, const char *objeto1, const char *objeto2)
{
	return false;
}

/*
 * Destruye la sala de escape liberando toda la memoria reservada.
 */
void sala_destruir(sala_t *sala)
{
}


//= realloc(sala->objetos, (((long unsigned int)(tamanio_objetos)+1) * sizeof(struct objeto)));