//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: 
    Entrada:  nome completo, as 4 notas parciais
    Saída:    nome e somente a média aritmética
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
	//Declarações
	int aux = 1;
	char controle;
	//Instruções
	
	aluno alunos[NROMAXALUNOS];
	
	do {
		printf("Digite o nome do %d° aluno: ", aux);
		fgets(alunos[aux].nome, TAMANHONOME, stdin);
		fflush(stdin);
		if(alunos[aux].nome[strlen(alunos[aux].nome)-1] == '\n')
			alunos[aux].nome[strlen(alunos[aux].nome)-1] == '\0';
		validaNome(alunos[aux].nome);
	}while(controle != 's' || aux < NROMAXALUNOS);
	
	
	
	
	
	
	
	
	
	/*
	Entrada:  nome completo, as 4 notas parciais
	Saída:    nome e somente a média aritmética
	
	média será um vetor (ou matriz)
	sempre existir um nome sendo apresentado sempre totalmente em maiúsculo
	uma função que apresente para cada aluno o termo APROVADO ou REPROVADO
	*/
	
	getch();
	return 0;
}

//==============  SUBALGORITMOS  ================

// Síntese
//    Objetivo:   Validar nome
//    Parâmetros: Nome
//    Retorno:    Nenhum
void validaNome(char *nome) {
	while(strlen(nome) < 2 || *nome)
}











