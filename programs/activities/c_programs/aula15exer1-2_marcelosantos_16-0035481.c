//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: 
    Entrada:  nome completo, as 4 notas parciais
    Sa�da:    nome e somente a m�dia aritm�tica
*/

#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define TAMANHONOME 50
#define NRONOTAS 4
#define NROMAXALUNOS 100

void validaNome(char *nome[]);

typedef struct {
	char nome[TAMANHONOME];
	float media[NRONOTAS];
}aluno;

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//Declara��es
	int aux = 1;
	char controle;
	//Instru��es
	
	aluno alunos[NROMAXALUNOS];
	
	do {
		printf("Digite o nome do %d� aluno: ", aux);
		fgets(alunos[aux].nome, TAMANHONOME, stdin);
		fflush(stdin);
		if(alunos[aux].nome[strlen(alunos[aux].nome)-1] == '\n')
			alunos[aux].nome[strlen(alunos[aux].nome)-1] == '\0';
		validaNome(alunos[aux].nome);
	}while(controle != 's' || aux < NROMAXALUNOS);
	
	
	
	
	
	
	
	
	
	/*
	Entrada:  nome completo, as 4 notas parciais
	Sa�da:    nome e somente a m�dia aritm�tica
	
	m�dia ser� um vetor (ou matriz)
	sempre existir um nome sendo apresentado sempre totalmente em mai�sculo
	uma fun��o que apresente para cada aluno o termo APROVADO ou REPROVADO
	*/
	
	getch();
	return 0;
}

//==============  SUBALGORITMOS  ================

// S�ntese
//    Objetivo:   Validar nome
//    Par�metros: Nome
//    Retorno:    Nenhum
void validaNome(char *nome) {
	while(strlen(nome) < 2 || *nome)
}











