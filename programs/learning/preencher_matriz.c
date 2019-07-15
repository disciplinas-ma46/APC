#include <locale.h>
#include <stdio.h>
#include <conio.c>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define LINHA 20
#define COLUNA 60

void preenche(char matriz[][COLUNA], int i, int j, char simb);
void printMatriz(char matriz[][COLUNA], int i, int j);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	char matriz[LINHA][COLUNA];
	
	
	preenche(matriz, LINHA, COLUNA, '*');
	gets(matriz[4][7]);
	printMatriz(matriz, LINHA, COLUNA);
	//gotoxy(5,10);
	//puts("olá mundo!");
	
	getch();
	return 0;
}
//======================================================================
void printMatriz(char matriz[][COLUNA], int i, int j) {
	for(i=0; i<LINHA; i++) {
		for(j=0; j<COLUNA; j++) {
			printf("%c",matriz[i][j]);
		}
		puts("");
	}
}
//======================================================================
void preenche(char matriz[][COLUNA], int i, int j, char simb) {
	for(i=0; i<LINHA; i++) {
		for(j=0; j<COLUNA; j++) {
			matriz[i][j] = simb;
		}
	}
}
