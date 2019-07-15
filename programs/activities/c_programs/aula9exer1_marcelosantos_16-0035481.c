//NOME DO ALUNO:  Marcelo Araújo dos Santos

/*
algoritmo aula9exer1;
// Síntese
//  Objetivo:  Realizar cálculo de porcentagem
//  Entrada :  Um valor
//  Saída   :  Porcentagem

principal
	// Declarações
	inteiro valorConstante; // CONSTANTE
	real numero, porcentagem;

	// Instruções
	valorConstante = 555;
	escreva("Digite um valor maior que zero: ");
	leia(numero);
	enquanto (numero < 0) faca
		escreva("Valor inválido! Digite um valor maior que zero: ");
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
	// Declarações
	float validaNumero(float numero); //função 
	const int valorConstante = 555; // CONSTANTE
	float numero, porcentagem;
	
	// Instruções
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
// Parâmetros: temperatura em Faren.
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
