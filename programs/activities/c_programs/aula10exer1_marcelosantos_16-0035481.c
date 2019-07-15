/*
algoritmo aula10exer1;
//  S�ntese
//  Objetivo :  Mostrar n�meros pares at� valor limite
//  Entrada  :  Um n�mero
//  Sa�da   :  N�meros pares do n�mero dado pelo usu�rio at� 2000 ou mensagem de erro


principal
	// Declara��es
	inteiro limite; // CONSTANTE
	inteiro numero, aux;
	
	// Instru��es
	limite = 2000;
	escreva("Digite um valor de no m�ximo ",limite,": ");
	leia(numero);
	limpaTela();
	se (numero > limite) entao
		escreval("Limite de c�lculo foi excedido!");
		escreval("Valor digitado: ",numero);
	senao
		escreval("N�meros pares de ",numero," at� ",limite);
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
	// Declara��es
	const int limite = 2000;   // CONSTANTE
	int numero, aux;

	// Instru��es
	printf("Digite um valor de no m�ximo %d: ",limite);
	scanf("%d",&numero);
	system("cls");
	if (numero > limite)
	{
		puts("Limite de c�lculo foi excedido!");
		printf("Valor digitado: %d",numero);
	}
	else
	{
		printf("N�meros pares de %d at� %d \n\n", numero, limite);
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

