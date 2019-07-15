//NOME DO ALUNO:  Marcelo Araújo dos Santos

/*
  Síntese
    Objetivo: Mostrar média de três valores
    Entrada:  Nenhuma entrada
    Saída: Mensagem dizendo a média
*/

#include <stdio.h>

int  main(void)
{
	// Declarações
	const float numero1 = 5.5;   // CONSTANTE
	const float numero2 = 7.2;   // CONSTANTE
	const float numero3 = 8.3;   // CONSTANTE
	float media;
	
	// Instruções
	media = (numero1 + numero2 + numero3) / 3;
	printf("Valor da media = %.2f",media);
    getch( );
    return 0;
}
