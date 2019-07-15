#include <stdio.h>
#include <conio.c>
#define NROLINHASTELA "35"
#define NROCOLUNASTELA "100"

int main (void) {
	
	char novaTela[40] = "";
	//Instruções
	strcat(novaTela, "mode con:cols=");
	strcat(novaTela, NROCOLUNASTELA);
	strcat(novaTela, " lines=");
	strcat(novaTela, NROLINHASTELA);
	system(novaTela);
	
	printf("%s",novaTela);
	printf("\n\nOla mundo!");
	
	getch();
	return 0;
}

