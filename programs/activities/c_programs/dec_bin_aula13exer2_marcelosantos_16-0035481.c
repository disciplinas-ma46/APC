//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Fazer convers�o de caracter para outras bases
    Entrada:  um caracter
    Sa�da:    mostrar caracter correspondente em base decimal e bin�ria
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int  main(void)
{
	//Declara��es
	int numero, quociente, aux ;
	long int binario;
	char caracter;

	//Instru��es
	setlocale(LC_ALL, "Portuguese");

    do {
        aux = 1;
        binario = 0;
        printf("Digite um caracter: ");
        caracter = getch();
        numero = (int)caracter;
        quociente = numero;

        while (quociente != 0) {
            binario = binario + aux*(quociente%2);
            quociente /= 2;
            aux *= 10;
        }

        system("cls");
        printf("Caracter digitado: '%c'\n",caracter);
        printf("   correspondente na base decimal: %d \n",numero);
        printf("   correspondente na base bin�ria: %08ld \n\n",binario);

        printf("\n\n\n\n");
        printf("Pressione 's' para sair ou outra tecla para continuar o programa: ");
        caracter = getch();
        caracter = tolower(caracter);
        system("cls");
    }while(caracter != 's');

	return 0;
}



