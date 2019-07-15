//NOME DO ALUNO:  Marcelo Ara�jo dos Santos

/*
algoritmo aula9exer1;
// S�ntese
//  Objetivo:  Realizar c�lculo de porcentagem
//  Entrada :  Um valor
//  Sa�da   :  Porcentagem

principal
	// Declara��es
	inteiro valorConstante; // CONSTANTE
	real numero, porcentagem;

	// Instru��es
	valorConstante = 555;
	escreva("Digite um valor maior que zero: ");
	leia(numero);
	enquanto (numero < 0) faca
		escreva("Valor inv�lido! Digite um valor maior que zero: ");
		leia(numero);
	fimEnquanto
	limpaTela();
	porcentagem = (numero / valorConstante)*100;
	escreva("O valor ",numero::2," corresponde a ",porcentagem::2,"% de ",valorConstante);
fimPrincipal
*/

#include <stdio.h>

int main (void)
{
	// Declara��es
	float validaNumero(float numero); //fun��o 
	const int valorConstante = 555; // CONSTANTE
	float numero, porcentagem;
	
	// Instru��es
	printf("Digite um valor maior que zero: ");
	scanf("%f",&numero);
	numero = validaNumero(numero);
	system("cls");
	porcentagem = (numero / valorConstante)*100;
	printf("O valor %.2f corresponde a %.2f%% de %i", numero, porcentagem, valorConstante);
	getch();
	return 0;
}

// ================= SUBALGORITMOS ================

// Objetivo: converter temperaturas
// Par�metros: temperatura em Faren.
// Retorno: temperatura em Celsius
float validaNumero(float numero)
{
	while (numero < 0)
	{
		printf("Valor invalido! Digite um valor maior que zero: ");
		scanf("%f",&numero);
	}
	return numero;
}
