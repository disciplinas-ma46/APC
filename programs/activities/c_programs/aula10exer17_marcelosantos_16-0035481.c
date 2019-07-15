//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Cadastrar nomes e idades de uma pessoa
    Entrada:  Nome completo de uma pessoa e sua idade
    Sa�da:    Nome cadastrado e idade
*/

#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <conio.c>
#include <string.h>
#define TAMANHO 50

void validaNome(char nome[]);
int espacoEmBranco(char nome[]);
int validaIdade(int idade);
char validaOpcao(char opcao);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARA��ES
	char nome[TAMANHO], opcao;
	int idade;
	
	//INSTRU��ES
	do {
		printf("Digite seu nome completo: ");
		fgets(nome, TAMANHO, stdin);
		fflush(stdin);
		if(nome[strlen(nome)-1] == '\n')
			nome[strlen(nome)-1] = '\0';
		validaNome(nome);
		system("cls");
		printf("Digite sua idade: ");
		scanf("%d",&idade);
		idade = validaIdade(idade);
		system("cls");
		printf("%s = %d anos", nome, idade);
		gotoxy(1,10);
		printf("Deseja terminar o cadastro?\n");
		printf("Digite 'S' para sim ou 'N' para n�o: ");
		opcao = getch();
		opcao = validaOpcao(opcao);
		system("cls");
	} while(opcao != 'S');
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Validar nome
//    Par�metros: Nome
//    Retorno:    Nenhum
void validaNome(char nome[]) {
	//Instru��es
	while ((strlen(nome) <= 3) || !espacoEmBranco(nome)) {
		printf("\nInv�lido!Digite um nome maior que 3 \n e com espa�o entre as palavras: ");
		fgets(nome, TAMANHO, stdin);
		fflush(stdin);
		if(nome[strlen(nome)-1] == '\n')
			nome[strlen(nome)-1] = '\0';
	}
}

//    Objetivo:   Verificar se tem espa�o em branco no nome
//    Par�metros: Nome
//    Retorno:    Se tem ou n�o espa�o em branco
int espacoEmBranco(char nome[]) {
	//Declara��es locais
	int aux = 0;
	//Instru��es
	if(nome[aux] != ' ')
		while (aux < strlen(nome)) {
			if(nome[aux] == ' ')
				return 1;
			aux++;
		}
	return 0;
}

//    Objetivo:   Validar idade
//    Par�metros: Idade
//    Retorno:    Idade v�lida
int validaIdade(int idade) {
	//Instru��es
	fflush(stdin);
	while(idade <= 0 || idade >= 130) {
		printf("Idade inv�lida! Digite uma idade maior que 0 e menor que 130: ");
		scanf("%d",&idade);
	}
	return idade;
}

//    Objetivo:   Validar op��o de continuar ou n�o
//    Par�metros: Op��o
//    Retorno:    Op��o v�lida
char validaOpcao(char opcao) {
	//Instru��es
	opcao = toupper(opcao);
	if((opcao != 'S') && (opcao != 'N')) {
		printf("\nInv�lido! Digite 'S' para sim ou 'N' para n�o: ");
		opcao = getch();
		opcao = validaOpcao(opcao);
	}
	return opcao;
}

