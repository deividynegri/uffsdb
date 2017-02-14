#include <stdio.h>
#ifndef FILEMANAGER_H

typedef struct _entrada_indice {
	int index;
	int offset;
} Tpindex;

// funciona recebendo tupla por tupla da árvore
// recebe o nome do arquivo .index, se este não existe então deve ser criado,
// recebe o indice e o offset a ser adicionado (chave - valor)
// o arquivo que guarda a (chave - valor) / (indice - offset)
// o formato será sizeof(int) para a chave, sizeof(int) para o valor
// este formato se extenderá conforme a quantidade de tuplas até o final do arquivo.
int novo_indice(const char * nome, int indice, int offset);

// serve para ler todas as entradas gravadas no .index e alimentar a árvore
void le_entradas(const char * nome);

#endif
