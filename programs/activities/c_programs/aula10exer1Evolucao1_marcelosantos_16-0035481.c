/*
algoritmo aula10exer1;
// Síntese
//	Marcelo Araújo dos Santos
//  Objetivo:	Apresentar todos os valores contagem até 2000
//  Entrada :	Número
//  Saída   :	Todos números contagem até 2000

principal
	// Declarações
	caracter continuar;
	inteiro numero,contagem;
	inteiro limite;     // CONSTANTE

	// Instruções
	limite = 2000;
	escreval("Digite um número para apresentarmos todos os números pares até ",limite);
	leia(numero);
	se (numero > limite) entao
		escreval(numero, " LIMITE DE CÁLCULO FOI EXCEDIDO!");
	senao
		se ((numero % 2) != 0) entao
			numero++;
		fimSe
		escreval("Será mostrado de 350 em 350 números!");
		escreval("Aperte qualquer tecla começar");
		leiaCaracter(continuar);
		limpaTela();
		faca
			contagem = 1;
			enquanto(contagem <= 350 e numero <= limite)faca
				escreva(numero, " ");
				numero += 2;
				contagem++;
			fimEnquanto
			escreval("");
			se(numero <= limite)entao
				escreval("Aperte qualquer tecla para mostrar mais números pares");
			senao
				escreval("Todos os números pares foram mostrados!");
				escreval("Aperte qualquer tecla para finalizar.");
			fimSe
			leiaCaracter(continuar);
			limpaTela();
		enquanto(numero <= limite);
	fimSe
fimPrincipal
*/

#include <locale.h>
#include <stdio.h>
#include <ctype.h>

int main (void)
{
	setlocale(LC_ALL, "Portuguese");
	// Declarações
	char continuar;
	int numero, contagem;
	const int limite = 2000;     // CONSTANTE

	// Instruções
	printf("Digite um número para apresentarmos todos os números pares até %d: ",limite);
	scanf("%i",&numero);
	if (numero > limite){
        printf("%d LIMITE DE CÁLCULO FOI EXCEDIDO!",numero);
	}
	else
    {
		if ((numero % 2) != 0){
			numero++;
		}
		printf("Será mostrado de 350 em 350 números!");
		printf("\nAperte qualquer tecla começar");
		continuar = getch();
		system("cls");
		do
		{
			contagem = 1;
			while ((contagem <= 350) && (numero <= limite))
			{
				printf("%d ",numero);
				numero += 2;
				contagem = contagem + 1;
			}
			if(numero <= limite) {
				printf("\n\nAperte qualquer tecla para mostrar mais números pares");
			}
			else {
				printf("\nTodos os números pares foram mostrados!");
				printf("\nAperte qualquer tecla para finalizar.");
			}
			continuar = getch();
			system("cls");
		} while(numero <= limite);
	}
	getch();
	return 0;
}

