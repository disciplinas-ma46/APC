//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Ler n�meros para uma matriz 3x3 e calcular m�dia e soma total
    Entrada:  8 n�meros
    Sa�da:    8 n�meros, junto com a soma total na forma de matriz 3x3, e a m�dia
*/

#include <locale.h>
#include <stdio.h>
#include <conio.c>
#define TAMMATRIZ 3
#define ANOATUAL 2017
#define ANOBASE 1900

int validaAno(int ano);
int fazMedia(int soma);
char validaContinuar(char continuar);
void mostraResultado(int *matriz, float media);

int  main(void)
{
	//Declara��es
	int matriz[TAMMATRIZ][TAMMATRIZ];
	int linha, coluna, ano, soma;
	float media;
	char continuar;
	
	//Instru��es
	setlocale(LC_ALL, "Portuguese");
	do{
		soma = 0;
		for(linha = 0; linha < TAMMATRIZ; linha++) {
			for(coluna = 0; coluna < TAMMATRIZ; coluna++) {
				matriz[linha][coluna] = soma;
				soma += 3;
			}
		}
		//matriz[1][1] = soma;
		media = fazMedia(soma);
		mostraResultado(matriz, media);
		
		gotoxy(1, 22);
		printf("Deseja informar novos anos? Digite 's' para sim ou 'n' para n�o: ");
		continuar = getche();
		continuar = tolower(continuar);
		continuar = validaContinuar(continuar);
		system("cls");
	}while(continuar != 'n');
	
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Validar ano
//    Par�metros: Ano
//    Retorno:    Ano v�lido
int validaAno(int ano) {
	while ((ano <= ANOBASE) || (ano >= ANOATUAL)) {
		printf("\n\nInv�lido! Digite um ano entre %d e %d : ", ANOBASE, ANOATUAL);
		scanf("%d",&ano);
	}
	return ano;
}

//    Objetivo:   Calcular m�dia dos anos
//    Par�metros: Soma dos anos
//    Retorno:    M�dia
int fazMedia(int soma) {
	return (soma/8);
}

//    Objetivo:   Validar op��o de continuar
//    Par�metros: op��o de continuar
//    Retorno:    op��o de continuar v�lido
char validaContinuar(char continuar) {
	while ((continuar != 's') && (continuar != 'n')) {
		printf("\nInv�lido! Digite 's' para sim ou 'n' para n�o: ");
		continuar = getche();
		continuar = tolower(continuar);
	}
	return continuar;
}

//    Objetivo:   Mostrar resultado das opera��es com os anos informados
//    Par�metros: Anos armazenados, soma dos anos e m�dia
//    Retorno:    Nenhum
void mostraResultado(int *matriz, float media) {
	int linha, coluna, aux = -1;
	printf("----------------------");
	for(linha = 0; linha < TAMMATRIZ; linha++) {
		printf("\n|");
		for(coluna = 0; coluna < TAMMATRIZ; coluna++) {
			printf("% -6d|",*(++aux+matriz));
		}
	}
	printf("\n----------------------");
}
















