/*
algoritmo aula10exer1;
// S�ntese
//	Marcelo Ara�jo dos Santos
//  Objetivo:	Apresentar todos os valores contagem at� 2000
//  Entrada :	N�mero
//  Sa�da   :	Todos n�meros contagem at� 2000

principal
	// Declara��es
	caracter continuar;
	inteiro numero,contagem;
	inteiro limite;     // CONSTANTE

	// Instru��es
	limite = 2000;
	escreval("Digite um n�mero para apresentarmos todos os n�meros pares at� ",limite);
	leia(numero);
	se (numero > limite) entao
		escreval(numero, " LIMITE DE C�LCULO FOI EXCEDIDO!");
	senao
		se ((numero % 2) != 0) entao
			numero++;
		fimSe
		escreval("Ser� mostrado de 350 em 350 n�meros!");
		escreval("Aperte qualquer tecla come�ar");
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
				escreval("Aperte qualquer tecla para mostrar mais n�meros pares");
			senao
				escreval("Todos os n�meros pares foram mostrados!");
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
	// Declara��es
	char continuar;
	int numero, contagem;
	const int limite = 2000;     // CONSTANTE

	// Instru��es
	printf("Digite um n�mero para apresentarmos todos os n�meros pares at� %d: ",limite);
	scanf("%i",&numero);
	if (numero > limite){
        printf("%d LIMITE DE C�LCULO FOI EXCEDIDO!",numero);
	}
	else
    {
		if ((numero % 2) != 0){
			numero++;
		}
		printf("Ser� mostrado de 350 em 350 n�meros!");
		printf("\nAperte qualquer tecla come�ar");
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
				printf("\n\nAperte qualquer tecla para mostrar mais n�meros pares");
			}
			else {
				printf("\nTodos os n�meros pares foram mostrados!");
				printf("\nAperte qualquer tecla para finalizar.");
			}
			continuar = getch();
			system("cls");
		} while(numero <= limite);
	}
	getch();
	return 0;
}

