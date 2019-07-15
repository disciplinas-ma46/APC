//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Criar um arquivo
    Entrada:  Nome do arquivo
    Saída:    Mensagem informando o sucesso ou não na criação do arquivo
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX 30

void validaNomeArquivo(char *nomeArquivo);

int main (void) {
	//Declarações
	char nomeArquivo[MAX];
	FILE *p_arq;
	//Instruções
	setlocale(LC_ALL, "Portuguese");
	
	puts("Escreva um nome para criar arquivo (não escreva a extensão): ");
	fgets(nomeArquivo,MAX-4,stdin);
	if(nomeArquivo[strlen(nomeArquivo)-1] == '\n')
		nomeArquivo[strlen(nomeArquivo)-1] = '\0';
	validaNomeArquivo(&nomeArquivo);
	
	strcat(nomeArquivo, ".bin");
	
	p_arq = fopen(nomeArquivo,"wb");
	
	system("cls");
	if (p_arq == NULL) {
		puts("Arquivo não pode ser criado.");
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
//    Parâmetros: nome do arquivo
//    Retorno:    Nenhum
void validaNomeArquivo(char *nomeArquivo) {
	//Instruções
	while(strlen(nomeArquivo) < 3) {
		puts("inválido! Informe nome maior que 2 letras: ");
		fflush(stdin);
		fgets(nomeArquivo,MAX-4,stdin);
		if(nomeArquivo[strlen(nomeArquivo)-1] == '\n')
			nomeArquivo[strlen(nomeArquivo)-1] ='\0';
	}
}





