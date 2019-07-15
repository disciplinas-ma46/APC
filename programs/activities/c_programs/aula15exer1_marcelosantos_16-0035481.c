//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Criar um arquivo
    Entrada:  Nome do arquivo
    Sa�da:    Mensagem informando o sucesso ou n�o na cria��o do arquivo
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 30

void validaNomeArquivo(char *nomeArquivo);

int main (void) {
	//Declara��es
	char nomeArquivo[MAX];
	FILE *p_arq;
	//Instru��es
	setlocale(LC_ALL, "Portuguese");
	
	puts("Escreva um nome para criar arquivo (n�o escreva a extens�o): ");
	fgets(nomeArquivo,MAX-4,stdin);
	if(nomeArquivo[strlen(nomeArquivo)-1] == '\n')
		nomeArquivo[strlen(nomeArquivo)-1] = '\0';
	validaNomeArquivo(&nomeArquivo);
	
	strcat(nomeArquivo, ".bin");
	
	p_arq = fopen(nomeArquivo,"wb");
	
	system("cls");
	if (p_arq == NULL) {
		puts("Arquivo n�o pode ser criado.");
		getch();
		exit(1);
	}
	else {
		fclose(p_arq);
		printf("Arquivo %s criado com sucesso!\n",nomeArquivo);
	}
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Validar nome do arquivo
//    Par�metros: nome do arquivo
//    Retorno:    Nenhum
void validaNomeArquivo(char *nomeArquivo) {
	//Instru��es
	while(strlen(nomeArquivo) < 3) {
		puts("inv�lido! Informe nome maior que 2 letras: ");
		fflush(stdin);
		fgets(nomeArquivo,MAX-4,stdin);
		if(nomeArquivo[strlen(nomeArquivo)-1] == '\n')
			nomeArquivo[strlen(nomeArquivo)-1] ='\0';
	}
}





