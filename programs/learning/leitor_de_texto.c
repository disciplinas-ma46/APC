#include <locale.h>
#include <stdio.h>
#include <conio.h>

int  main(void) {
	setlocale(LC_ALL, "Portuguese");
	char nome[50], comida[50], juntar[200] = "Eu me chamo ";
	//INSTRUÇÕES
	FILE *arquivo;
	arquivo = fopen("TEXTO.txt", "w");
	printf("Qual é seu nome? ");
	gets(nome);
	system("cls");
	printf("Olá %s, qual sua comida favorita? ",nome);
	gets(comida);
	system("cls");
	printf("Agora feche esse programa, vá na área de trabalho\ne abre um arquivo chamado TEXTO");
	
	strcat(juntar,nome);
	strcat(juntar," e gosto de comer ");
	strcat(juntar,comida);
	
	fprintf(arquivo, juntar);
	fclose(arquivo);
	
	getch();
	return 0;
}

//===========  SUBALGORITMOS  ================













