#include "monta_arvore.h"


node * le_entradas(const char * nome) {
	node * raiz=NULL;
	int err = 0; // flag para de erros de leitura
	FILE *arq_indice;

	char dat[7] = ".index";
	char nome_arq[(strlen(nome)+7)];

	//nome real do .index
	strcpy(nome_arq, nome); //talvez deva ser em lowercase letras (nao consegui compilar strcpylower)
	strcat(nome_arq, dat); //adiciona ".index\0"
	//printf("O nome do arquivo é: %s\n", nome_arq);
	arq_indice = fopen(nome_arq,"r+"); // r+ (leitura e escrita), o arquivo deve existir nesse modo
	
	if (arq_indice == NULL) { 
    	return NULL;
    }

	Tpindex dupla;
	fseek(arq_indice, 0, SEEK_SET); // início do arquivo .index
	

	while (1) {
		if (fread(&dupla.index, sizeof(int), 1, arq_indice) != 1) {err++; break;};
		if (fread(&dupla.offset, sizeof(int), 1, arq_indice) != 1) {err++; break;};

		raiz=insertBP(raiz, dupla.index, dupla.offset);
		
	}
	fclose(arq_indice);
	print_leaves(raiz);
	return raiz;
}