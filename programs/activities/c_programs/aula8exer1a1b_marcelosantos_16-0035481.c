//NOME DO ALUNO:  Marcelo Ara�jo dos Santos

/*
  S�ntese
    Objetivo: Mostrar m�dia de tr�s valores
    Entrada:  Nenhuma entrada
    Sa�da: Mensagem dizendo a m�dia
*/

#include <stdio.h>

int  main(void)
{
	// Declara��es
	const float numero1 = 5.5;   // CONSTANTE
	const float numero2 = 7.2;   // CONSTANTE
	const float numero3 = 8.3;   // CONSTANTE
	float media;
	
	// Instru��es
	media = (numero1 + numero2 + numero3) / 3;
	printf("Valor da media = %.2f",media);
    getch( );
    return 0;
}
