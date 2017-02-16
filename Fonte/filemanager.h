#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <stdio.h> // para entrada e saida
//	#include <stdlib.h>	// alocação de memória
#include <string.h> // manipulação de string

void limpa_arquivo (const char * nome);
// funciona recebendo tupla por tupla da árvore
// recebe o nome do arquivo .index, se este não existe então deve ser criado,
// recebe o indice e o offset a ser adicionado (chave - valor)
// o arquivo que guarda a (chave - valor) / (indice - offset)
// o formato será sizeof(int) para a chave, sizeof(int) para o valor
// este formato se extenderá conforme a quantidade de tuplas até o final do arquivo.
int novo_indice(const char * nome, int indice, int offset);

#endif
