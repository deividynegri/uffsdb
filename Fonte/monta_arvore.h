#ifndef monta_arvore_H
#define monta_arvore_H
#include <stdio.h> // para entrada e saida
//	#include <stdlib.h>	// alocação de memória
#include <string.h> // manipulação de string
#include "bpTree.h"

typedef struct _entrada_indice {
	int index;
	int offset;
} Tpindex;

// serve para ler todas as entradas gravadas no .index e alimentar a árvore
node * le_entradas(const char * nome);

#endif
