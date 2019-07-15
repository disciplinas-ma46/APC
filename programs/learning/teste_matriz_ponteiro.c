//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Ler números para uma matriz 3x3 e calcular média e soma total
    Entrada:  8 números
    Saída:    8 números, junto com a soma total na forma de matriz 3x3, e a média
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
	//Declarações
	int matriz[TAMMATRIZ][TAMMATRIZ];
	int linha, coluna, ano, soma;
	float media;
	char continuar;
	
	//Instruções
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
		printf("Deseja informar novos anos? Digite 's' para sim ou 'n' para não: ");
		continuar = getche();
		continuar = tolower(continuar);
		continuar = validaContinuar(continuar);
		system("cls");
	}while(continuar != 'n');
	
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Validar ano
//    Parâmetros: Ano
//    Retorno:    Ano válido
int validaAno(int ano) {
	while ((ano <= ANOBASE) || (ano >= ANOATUAL)) {
		printf("\n\nInválido! Digite um ano entre %d e %d : ", ANOBASE, ANOATUAL);
		scanf("%d",&ano);
	}
	return ano;
}

//    Objetivo:   Calcular média dos anos
//    Parâmetros: Soma dos anos
//    Retorno:    Média
int fazMedia(int soma) {
	return (soma/8);
}

//    Objetivo:   Validar opção de continuar
//    Parâmetros: opção de continuar
//    Retorno:    opção de continuar válido
char validaContinuar(char continuar) {
	while ((continuar != 's') && (continuar != 'n')) {
		printf("\nInválido! Digite 's' para sim ou 'n' para não: ");
		continuar = getche();
		continuar = tolower(continuar);
	}
	return continuar;
}

//    Objetivo:   Mostrar resultado das operações com os anos informados
//    Parâmetros: Anos armazenados, soma dos anos e média
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
















