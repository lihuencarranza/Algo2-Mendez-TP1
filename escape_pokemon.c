#include "src/sala.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
			return -1;
	
	//Los archivos deben venir como parámetros del main
	sala_t *sala = sala_crear_desde_archivos(argv[1], argv[2]);

	if (sala == NULL) {
		printf("Error al crear la sala de escape\n");
		return -1;
	}

	//Mostrar todos los objetos en la sala

	printf("Objetos...\n");

	//Mostrar si son válidas las siguientes interacciones
	//1. examinar habitacion
	//2. abrir pokebola
	//3. usar llave cajon
	//4. quemar mesa

	printf("Interacciones...\n");

	sala_destruir(sala);

	free(sala);

	return 0;
}

//gcc ./escape_pokemon.c ./src/*.c ./src/*.h -o pokemon -std=c99 -Wall -Wconversion -Werror -lm
//valgrind ./pokemon ./ejemplo/objetos.txt ./ejemplo/interacciones.txt 