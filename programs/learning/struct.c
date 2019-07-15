#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
	char texto[100];
}tipo_Livro;

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	int aux;
	
	tipo_Livro ddumb[2];
	ddumb[0].texto = "oi pessoal!";
	ddumb[1].texto = "tudo bem?";
	
	for(aux=0; aux<2; aux++)
		printf("%s\n",ddumb[aux].texto);
	
	
	
	getch();
	return 0;
}


/*
teste[0].hora = 10;
teste[0].minuto = 10;
teste[0].segundo = 10;
*/










