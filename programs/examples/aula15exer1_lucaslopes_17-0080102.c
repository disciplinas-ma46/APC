// Aluno : Lucas Gomes Lopes

/*
 Sintese
   Objetivo: Criar arquivo no disco r�gido da m�quina
   Entrada : Nome do arquivo e op��o
   Saida   :  Resultado da opera��o(se a cria��o do arquivo foi bem sucedida ou n�o).
*/

#include <stdio.h>
#include <conio.c>
#include <string.h>
#include <ctype.h>
#include <locale.h>


void simbolos();

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	//simbolos();
	//setlocale(LC_ALL,"C");
	//simbolos();
	
	char texto[30] = "numero ";
	
	strcat(texto,itoa(123));
	printf("%s",texto);
	
	getch();
	return 0;
}

//==========SUBPROGRAMAS==========


void simbolos() {
	int i;
	for(i=200; i<=206; i++)
		printf("%c\n",i);
	printf("\n\n");
}






