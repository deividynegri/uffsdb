#include <stdio.h>
#include "filemanager.h"

int main () {
	// cria um .index com esse nome
	novo_indice("teste", 10, 20);
	novo_indice("teste", 4, 20);
	novo_indice("teste", 310, 20);
	novo_indice("teste", 120, 20);
	novo_indice("teste", 140, 20);
	le_entradas("teste");
	le_entradas("testeerr");


	//printf("Fim\n");
	return 0;
}