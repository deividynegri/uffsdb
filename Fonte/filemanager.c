#include "filemanager.h"



void limpa_arquivo (const char * nome){
	FILE *arq_indice = NULL;

	char dat[7] = ".index";
	char nome_arq[(strlen(nome)+7)];

	//nome real do .index
	strcpy(nome_arq, nome); //talvez deva ser em lowercase letras (nao consegui compilar strcpylower)
	strcat(nome_arq, dat); //adiciona ".index\0"
	//printf("O nome do arquivo é: %s\n", nome_arq);
	arq_indice = fopen(nome_arq,"w");
	fclose(arq_indice);
}


int novo_indice(const char * nome, int indice, int offset) { // adiciona a nova tupla no final do arquivo

	FILE *arq_indice;

	char dat[7] = ".index";
	char nome_arq[(strlen(nome)+7)];

	//nome real do .index
	strcpy(nome_arq, nome); //talvez deva ser em lowercase letras (nao consegui compilar strcpylower)
	strcat(nome_arq, dat); //adiciona ".index\0"
	//printf("O nome do arquivo é: %s\n", nome_arq);
	arq_indice = fopen(nome_arq,"r+"); // r+ (leitura e escrita), o arquivo deve existir nesse modo
	
	// cria o arquivo necessário para a primeira inserção, se o mesmo não existir
	if (arq_indice == NULL) { 
    	printf("Criando arquivo %s.index\n", nome_arq);
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
