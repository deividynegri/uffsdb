#ifndef FILEMANAGER_H

struct (
int chave;
int offset;
) typedef entradaIndice;



int criaIndice(const char * nome);

entradaIndice lerEntrada(FILE * file);



#endif
