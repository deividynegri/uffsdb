#include "filemanager.h"
#include <stdio.h> // para entrada e saida
#include <stdlib.h>	// alocação de memória
#include <string.h> // manipulação de string

int novo_indice(const char * nome, int indice, int offset) { // adiciona a nova tupla no final do arquivo

	FILE *arq_indice;

	char dat[7] = ".index";
	char nome_arq[20];

	//nome real do .index
	strcpy(nome_arq, nome); //talvez deva ser em lowercase letras (nao consegui compilar strcpylower)
	strcat(nome_arq, dat); //adiciona ".index\0"
	//printf("O nome do arquivo é: %s\n", nome_arq);
	arq_indice = fopen(nome_arq,"r+"); // r+ (leitura e escrita), o arquivo deve existir nesse modo
	
	// cria o arquivo necessário para a primeira inserção, se o mesmo não existir
	if (arq_indice == NULL) { 
    	printf("Falha ao abrir o arquivo de índices, criando novo .index\n");
    	arq_indice = fopen(nome_arq,"w+"); // w+ (leitura e escrita), o arquivo é criado
    	// aloca espaço para os dados a serem inseridos (2 inteiros, indice e offset da tupla no .dat)
    }
    fseek(arq_indice, 0, SEEK_END); // ponteiro no fim do arquivo
    // teste para saber se escreveu
	if (fwrite(&indice, sizeof(int), 1, arq_indice) != 1
	|| fwrite(&offset, sizeof(int), 1, arq_indice) != 1) {
		printf("Erro na escrita do arquivo\n");
	}

	// pode ser colocado no sqlcommands.c (junto com a parte do fopen) para abrir e fechar o aquivo lá,
	// possibilitando que o arquivo só seja aberto e fechado quando a database
	// é aberta e fechada
	fclose(arq_indice);
	return 0;
}

void le_entradas(const char * nome) {

	int err = 0; // flag para de erros de leitura
	FILE *arq_indice;

	char dat[7] = ".index";
	char nome_arq[20];

	//nome real do .index
	strcpy(nome_arq, nome); //talvez deva ser em lowercase letras (nao consegui compilar strcpylower)
	strcat(nome_arq, dat); //adiciona ".index\0"
	//printf("O nome do arquivo é: %s\n", nome_arq);
	arq_indice = fopen(nome_arq,"r+"); // r+ (leitura e escrita), o arquivo deve existir nesse modo
	
	if (arq_indice == NULL) { 
    	printf("Falha ao abrir o arquivo de índices para leitura.\n");
    	err++;
    	return;
    }

	Tpindex dupla;
	fseek(arq_indice, 0, SEEK_SET); // início do arquivo .index
	

	while (1) {
		if (fread(&dupla.index, sizeof(int), 1, arq_indice) != 1) {err++; break;};
		if (fread(&dupla.offset, sizeof(int), 1, arq_indice) != 1) {err++; break;};
		printf("%d\n", dupla.index);
		printf("%d\n", dupla.offset);

		/*
		 chamada de função que adiciona o nodo na árvore
		insert_arvore(dupla.index e dupla.offset)
		*/
	}
	fclose(arq_indice);
	printf("A alimentação da árvore terminou.\n");
	return;
}