//Nome: Marcelo Ara�jo dos Santos     Data da prova: 29/06/2017

//Objetivo: Cadastrar pol�ticos indicados na lava jato
//Entrada : Nome e ano de in�cio da investiga��o
//Sa�da :    Nomes e ano de in�cio da investiga��o dos pol�ticos

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define ATUAL 2017
#define INICIO_LAVAJATO 2014
#define MIN_NOME 4
#define TAMANHO_NOME 40
#define NOMEARQUIVO "cadastroPoliticos.bin"

void mostraMenu(void);
void cadastraCorrupto(void);
void trataTerminador(char *string);
void mostraCorruptos(void);
void validaNomePolitico(char *nome);
int validaAnoIndicLavaJato(int anoInicioInvestig);

typedef struct {
	char nome[TAMANHO_NOME];
	int anoInicioInvestig;
}infoPolitico;



int main(void) {
	//Declara��es
	char opcao;
	
	//Instru��es
	setlocale(LC_ALL,"Portuguese");
	do {
		mostraMenu();
		opcao = getch();
		opcao = toupper(opcao);
		switch(opcao) {
			case 'A':
				cadastraCorrupto();
				break;
			case 'B':
				mostraCorruptos();
				break;
			case 'S':
				system("cls");
				printf("Saindo do programa, aperte qualquer tecla");
				getch();
				break;
			default:
				printf("'%c': Op��o inv�lida!",opcao);
				getch();
		}
		
	} while(opcao != 'S');
}


// =================  SUBALGORITMOS ==========================

//Objetivo:    Mostrar menu de op��es
//Parametros : Nenhum
//Retorno :    Nenhum
void mostraMenu(void) {
	system("cls");
	printf("\n\t'A' Cadastrar Novo Corrupto\n");
	printf("\t'B' Mostra todos Pol�ticos Corruptos\n");
	printf("\t'S' Salvar dados e sair do programa\n\n\n\n");
	printf("Escolha uma op��o: ");
}


//Objetivo:    Cadastrar novo pol�tico na Lava Jato
//Parametros : Nenhum
//Retorno :    Nenhum
void cadastraCorrupto(void) {
	//Declara��es locais
	infoPolitico politico;
	FILE *pArq;
	//Instru��es
	
	if(pArq == NULL) {
		system("cls");
		printf("Erro ao abrir arquivo!");
		getch();
	} else {
		do {
			system("cls");
			printf("Digite nome do pol�tico: ");
			fgets(politico.nome, TAMANHO_NOME, stdin);
			fflush(stdin);
			trataTerminador(politico.nome);
			validaNomePolitico(politico.nome);
			
			system("cls");
			printf("Digite o ano que esse pol�tico foi indicado na Lava Jato: ");
			scanf("%d",&politico.anoInicioInvestig);
			fflush(stdin);
			politico.anoInicioInvestig = validaAnoIndicLavaJato(politico.anoInicioInvestig);
			
			pArq = fopen(NOMEARQUIVO,"a+b");
			if(pArq == NULL) {
				printf("Erro ao abrir arquivo!");
				getch();
			} else {
				if(fwrite(&politico, sizeof(politico), 1, pArq) != 1) {
					printf("Erro ao salvar dados do candidato!");
					getch();
				}
			}
			fclose(pArq);
			system("cls");
			printf("Digite 's' para sair do cadastro de pol�ticos ou outra tecla para cadastrar mais um: ");
		} while (tolower(getch()) != 's');
	}
}

//Objetivo:    Mostrar lista dos pol�ticos investigados na Lava Jato
//Parametros : Nenhum
//Retorno :    Nenhum
void mostraCorruptos(void) {
	//Declara��es locais
	int aux = 1;
	infoPolitico politico;
	FILE *pArq;
	//Instru��es
	
	pArq = fopen(NOMEARQUIVO,"rb");
	if(pArq == NULL) {
		system("cls");
		printf("Erro ao abrir arquivo!");
		getch();
	} else {
		system("cls");
		printf("#    ANO       POLITICO CORRUPTO\n");
		printf("====================================\n");
		while(fread(&politico, sizeof(politico), 1, pArq) == 1) {
			printf("%03d  %-9d %s\n",aux, politico.anoInicioInvestig, politico.nome);
			aux++;
		}
		fclose(pArq);
		printf("\n\n\nPressione qualquer tecla para continuar: ");
		getch();
	}
}

//Objetivo:    Validar ano do in�cio da investiga��o na lava jato do politico
//Parametros : ano do in�cio da investiga��o
//Retorno :    ano do in�cio da investiga��o v�lido
int validaAnoIndicLavaJato(int anoInicioInvestig) {
	while (anoInicioInvestig < INICIO_LAVAJATO || anoInicioInvestig > ATUAL) {
		printf("\n\nInv�lido! Digite ano entre %d e %d: ",INICIO_LAVAJATO,ATUAL);
		scanf("%d",&anoInicioInvestig);
		fflush(stdin);
	}
	return anoInicioInvestig;
}

//Objetivo:    Validar nome do pol�tico
//Parametros : nome do pol�tico
//Retorno :    Nenhum
void validaNomePolitico(char *nome) {
	while(nomeInvalido(nome)) {
		fgets(nome, TAMANHO_NOME, stdin);
		fflush(stdin);
		trataTerminador(nome);
		system("cls");
	}
}

//Objetivo:    Verificar se nome do pol�tico � v�lido
//Parametros : nome do pol�tico
//Retorno :    se nome do pol�tico � v�lido ou n�o
int nomeInvalido(char *nome) {
	int aux = 0;
	if(*nome == ' ') {
		printf("\n\nInv�lido! Nome n�o deve conter espa�o no in�cio\n\ndigite novamente: ",INICIO_LAVAJATO,ATUAL);
		return 1;
	}
	if(strlen(nome) < MIN_NOME) {
		printf("\n\nInv�lido! Nome deve conter no m�nimo %d caracteres\n\ndigite novamente: ",MIN_NOME);
		return 1;
	}
	while(*(nome+aux)) {
		if( !isalpha(*(nome+aux)) && *(nome+aux) != '\n') {
			printf("\n\nInv�lido! Nome deve conter somente letras \n\n digite novamente: ");
			return 1;
		}
		aux++;
	}
	return 0;
}


//Objetivo:    Trata terminador de uma string
//Parametros : string
//Retorno :    Nenhum
void trataTerminador(char *string) {
	if(string[strlen(string)-1] == '\n')
		string[strlen(string)-1] == '\0';
}



