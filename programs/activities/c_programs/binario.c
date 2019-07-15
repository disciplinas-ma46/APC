//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Fazer conversão de caracter para outras bases
    Entrada:  um caracter
    Saída:    mostrar caracter correspondente em base decimal e binária
*/

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

//int decimalParaBinario(int numero);

int  main(void)
{
	//Declarações
	int numero, aux, resto;
	long int binario = 0;
	char caracter;

	//Instruções
	setlocale(LC_ALL, "Portuguese");

    //   5 % 2 = 1
    //   5 / 2 = 2

	printf("Digite um caracter: ");
	caracter = getch();
	numero = (int)caracter;

    resto = numero;
    aux = 1;


    while (resto != 0) {
        binario = binario*10 + resto%2;
        resto /= 2;
    }


	system("cls");
	printf("Caracter '%c' correspondente em decimal: %d\n",caracter, numero);
	printf("Caracter '%c' correspondente em binário: %08ld",caracter, binario);

	getch();
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:
//    Parâmetros:
//    Retorno:











