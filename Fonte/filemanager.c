#include "filemanager.h"
#include <stdio.h> // para entrada e saida
//#include <stdlib.h>

int novo_indice(const char * nome, int indice, int offset){

	FILE *arq_indice;
	arq_indice = fopen("/caminho/pro/arquivo.index","r+"); // r+ (leitura e escrita)
	if (arq_indice){
    	printf("O arquivo de índices já existe\n");
	} else {
    	printf("Falha ao abrir o arquivo de índices\n");
	}

	if (fwrite(&indice, sizeof(int), 1, arq_indice) != 1
	|| fwrite(&offset, sizeof(int), 1, arq_indice) != 1) {
		printf("Erro na escrita do arquivo\n");
	}

	fclose(arq_indice); // pode ser colocado no sqlcommands.c para abrir e fechar o aquivo lá
	return 0;
}