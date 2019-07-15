//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Fazer conversão de caracter para outras bases
    Entrada:  um caracter
    Saída:    mostrar caracter correspondente em base decimal e binária
*/

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

int  main(void)
{
	//Declarações
	int numero, quociente, aux ;
	long int binario;
	char caracter;

	//Instruções
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
        printf("   correspondente na base binária: %08ld \n\n",binario);

        printf("\n\n\n\n");
        printf("Pressione 's' para sair ou outra tecla para continuar o programa: ");
        caracter = getch();
        caracter = tolower(caracter);
        system("cls");
    }while(caracter != 's');

	return 0;
}



