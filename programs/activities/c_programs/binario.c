//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Fazer convers�o de caracter para outras bases
    Entrada:  um caracter
    Sa�da:    mostrar caracter correspondente em base decimal e bin�ria
*/

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

//int decimalParaBinario(int numero);

int  main(void)
{
	//Declara��es
	int numero, aux, resto;
	long int binario = 0;
	char caracter;

	//Instru��es
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
	printf("Caracter '%c' correspondente em bin�rio: %08ld",caracter, binario);

	getch();
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:
//    Par�metros:
//    Retorno:











