//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Exibir um caractere em diferentes formas
    Entrada:  Um caractere
    Sa�da:    caractere na forma de caractere, decimal (inteiro), octal e hexadecimal
*/

#include <stdio.h>

int  main(void)
{
	//DECLARA��ES
	char caractere;
	
	//INSTRU��ES
	printf("Digite algum caractere: ");
	caractere = getch();
	system("cls");
	printf("O caractere que voce digitou... \n\n");
	printf("Na forma de caractere: %c \n",caractere);
	printf("Na forma decimal (inteiro): %d \n",caractere);
	printf("Na forma octal: %o \n",caractere);
	printf("Na forma hexadecimal: %X \n",caractere);
	getch();
	return 0;
}
