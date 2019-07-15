/*
algoritmo aula10exer1;
//  Síntese
//  Objetivo :  Mostrar números pares até valor limite
//  Entrada  :  Um número
//  Saída   :  Números pares do número dado pelo usuário até 2000 ou mensagem de erro


principal
	// Declarações
	inteiro limite; // CONSTANTE
	inteiro numero, aux;
	
	// Instruções
	limite = 2000;
	escreva("Digite um valor de no máximo ",limite,": ");
	leia(numero);
	limpaTela();
	se (numero > limite) entao
		escreval("Limite de cálculo foi excedido!");
		escreval("Valor digitado: ",numero);
	senao
		escreval("Números pares de ",numero," até ",limite);
		escreval("");
		se (numero%2 != 0) entao
			numero = numero + 1;
		fimSe
		para (aux de numero ate limite passo 2) faca
			escreval(aux);
		fimPara
	fimSe
fimPrincipal
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>

int main (void)
{
	setlocale(LC_ALL, "Portuguese");
	// Declarações
	const int limite = 2000;   // CONSTANTE
	int numero, aux;

	// Instruções
	printf("Digite um valor de no máximo %d: ",limite);
	scanf("%d",&numero);
	system("cls");
	if (numero > limite)
	{
		puts("Limite de cálculo foi excedido!");
		printf("Valor digitado: %d",numero);
	}
	else
	{
		printf("Números pares de %d até %d \n\n", numero, limite);
		if (numero%2 != 0)
		{
			numero = numero + 1;
		}
		for (aux = numero; aux <= limite; aux+=2)
		{
			printf("%d\n", aux);
		}
	}
	getch();
	return 0;
}

