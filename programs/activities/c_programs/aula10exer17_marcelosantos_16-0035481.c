//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Cadastrar nomes e idades de uma pessoa
    Entrada:  Nome completo de uma pessoa e sua idade
    Saída:    Nome cadastrado e idade
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
	//DECLARAÇÕES
	char nome[TAMANHO], opcao;
	int idade;
	
	//INSTRUÇÕES
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
		printf("Digite 'S' para sim ou 'N' para não: ");
		opcao = getch();
		opcao = validaOpcao(opcao);
		system("cls");
	} while(opcao != 'S');
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Validar nome
//    Parâmetros: Nome
//    Retorno:    Nenhum
void validaNome(char nome[]) {
	//Instruções
	while ((strlen(nome) <= 3) || !espacoEmBranco(nome)) {
		printf("\nInválido!Digite um nome maior que 3 \n e com espaço entre as palavras: ");
		fgets(nome, TAMANHO, stdin);
		fflush(stdin);
		if(nome[strlen(nome)-1] == '\n')
			nome[strlen(nome)-1] = '\0';
	}
}

//    Objetivo:   Verificar se tem espaço em branco no nome
//    Parâmetros: Nome
//    Retorno:    Se tem ou não espaço em branco
int espacoEmBranco(char nome[]) {
	//Declarações locais
	int aux = 0;
	//Instruções
	if(nome[aux] != ' ')
		while (aux < strlen(nome)) {
			if(nome[aux] == ' ')
				return 1;
			aux++;
		}
	return 0;
}

//    Objetivo:   Validar idade
//    Parâmetros: Idade
//    Retorno:    Idade válida
int validaIdade(int idade) {
	//Instruções
	fflush(stdin);
	while(idade <= 0 || idade >= 130) {
		printf("Idade inválida! Digite uma idade maior que 0 e menor que 130: ");
		scanf("%d",&idade);
	}
	return idade;
}

//    Objetivo:   Validar opção de continuar ou não
//    Parâmetros: Opção
//    Retorno:    Opção válida
char validaOpcao(char opcao) {
	//Instruções
	opcao = toupper(opcao);
	if((opcao != 'S') && (opcao != 'N')) {
		printf("\nInválido! Digite 'S' para sim ou 'N' para não: ");
		opcao = getch();
		opcao = validaOpcao(opcao);
	}
	return opcao;
}

