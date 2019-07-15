/*
algoritmo aula9exer6;
// Síntese
//  Objetivo: Ler e apresentar sexo de uma pessoa
//  Entrada : Sexo da pessoa
//  Saída   : O sexo informado em uma moldura


principal
	// Declarações
	caracter sexo;

	// Instruções
	escreva("Qual o seu sexo? Digite 'm' para masculino e 'f' para femenino: ");
	leiaCaracter(sexo);
	limpaTela();
	desenharLinha(20, '#', '#', '#');
	desenharLinha(20, '#', ' ', '#');
	se (sexo != 'm' e sexo != 'f') entao
		escreval("# Sexo inválido!   #");
	senao
		se (sexo == 'm') entao
			escreval("# Sexo: masculino  #");
		senao
			escreval("# Sexo: feminino   #");
		fimSe
	fimSe
	desenharLinha(20, '#', ' ', '#');
	desenharLinha(20, '#', '#', '#');
fimPrincipal

// =====================    SUBALGORITMOS    =====================

//  Objetivo   : Desenhar uma linha usando símbolos
//  Parâmetros : Tamanho da linha, símbolo da borda esquerda, do meio e direita
//  Retorno    : Nenhum
procedimento desenharLinha(inteiro tamanho, caracter esquerda, caracter meio, caracter direita)
	inteiro aux;
	escreva(esquerda);
	para (aux de 1 ate tamanho-2 passo 1) faca
		escreva(meio);
	fimPara
	escreva(direita);
	escreval("");
fimProcedimento
*/

#include <stdio.h>
#include <conio.h>

void desenharLinha(int tamanho, char esquerda, char meio, char direita);

int main (void)
{
	// Declarações
	char sexo;

	// Instruções
	puts("Qual o seu sexo? Digite 'm' para masculino e 'f' para femenino: ");
	sexo = getch();
	system("cls");
	desenharLinha(20, 0xC9, 0xCD, 0xBB);
	desenharLinha(20, 0xBA, ' ', 0xBA);
	printf("%c",0xBA);
	(sexo != 'm' && sexo != 'f') ? printf(" Sexo invalido!   ") : (sexo == 'm') ? printf(" Sexo: masculino  ") : printf(" Sexo: feminino   ");
	printf("%c\n",0xBA);
	desenharLinha(20, 0xBA, ' ', 0xBA);
	desenharLinha(20, 0xC8, 0xCD, 0xBC);
	getch();
	return 0;
}

// =====================    SUBALGORITMOS    =====================

//  Objetivo   : Desenhar uma linha usando símbolos
//  Parâmetros : Tamanho da linha, símbolo da borda esquerda, do meio e direita
//  Retorno    : Nenhum
void desenharLinha(int tamanho, char esquerda, char meio, char direita)
{
	int aux;
	putchar(esquerda);
	for (aux = 1; aux <= tamanho-2; aux++)
	{
		putchar(meio);
	}
	putchar(direita);
	printf("\n");
}

