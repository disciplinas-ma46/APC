//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Cadastrar informações de candidatos a presidente
    Entrada:  Nome, Número da legenda, Sigla do partido e situação na Lava Jato de cada candidato
    Saída:    Lista com Nome, Número da legenda, Sigla do partido e situação na Lava Jato de cada candidato
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.c>
#include <ctype.h>
#include <string.h>

#define MAXNOME 28
#define MAXPARTIDO 10
#define POSMENU 10

typedef struct {
	char nome[MAXNOME];
	int numeroLegenda;
	char siglaCandidato[MAXPARTIDO];
	char lavaJato;
}infoCandidato;

void cadastrarCandidato(FILE *arquivoCandidato);
void listarCandidatos(FILE *arquivoCandidato);
void validaNomeCandidato(char *nomeArquivo);
void validaSiglaCandidato(char *sigla);
void validaNumeroLegenda(int *numeroLegenda);
void validaLavaJato(char *lavaJato);
void mostrarMenu(void);
void imprimeAviso(char aviso[]);
void imprimeMoldura(void);
void fecharArquivo(FILE *arquivoCandidato);


int main (void) {
	//Declarações
	char opcao;
	FILE *arquivoCandidato;
	//Instruções
	setlocale(LC_ALL, "Portuguese");
	
	do {
		mostrarMenu();
		
		opcao = getch();
		fflush(stdin);
		
		switch(opcao) {
			case '1':
				cadastrarCandidato(arquivoCandidato);
				break;
			case '2':
				//modificar();
				break;
			case '3':
				listarCandidatos(arquivoCandidato);
				break;
			case '4':
				//selecionarLavaJato();
				break;
			case '5':
				//apagarArquivo(arquivoCandidato);
				break;
			case '0':
				imprimeAviso("Programa encerrado!");
				break;
			default:
				imprimeAviso("Opção inválida! Digite outra opção: ");
				opcao = getch();
		}	
	}while(opcao != '0');
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Realizar cadastro de um candidato
//    Parâmetros: Definições de dados para candidato
//    Retorno:    Nenhum
void cadastrarCandidato(FILE *arquivoCandidato) {
	infoCandidato candidato;
	arquivoCandidato = fopen("eleicao.bin","a+b");
	if (arquivoCandidato == NULL) {
		imprimeAviso("Erro ao abrir arquivo.");
		getch();
	} else {
		fseek(arquivoCandidato, sizeof(arquivoCandidato), 2);
		system("cls");
		imprimeMoldura();
		gotoxy(3, 3);
		printf("Digite o nome do candidato: ");
		fgets(candidato.nome,MAXNOME,stdin);
		fflush(stdin);
		if(candidato.nome[strlen(candidato.nome)-1] == '\n')
			candidato.nome[strlen(candidato.nome)-1] ='\0';
		validaNomeCandidato(&candidato.nome);
		
		system("cls");
		imprimeMoldura();
		gotoxy(3, 3);
		printf("Digite número de legenda: ");
		scanf("%d",&candidato.numeroLegenda);
		validaNumeroLegenda(&candidato.numeroLegenda);
		
		system("cls");
		imprimeMoldura();
		gotoxy(3, 3);
		printf("Digite sigla do partido do candidato: ");
		fgets(candidato.siglaCandidato,MAXNOME,stdin);
		fflush(stdin);
		if(candidato.siglaCandidato[strlen(candidato.siglaCandidato)-1] == '\n')
			candidato.siglaCandidato[strlen(candidato.siglaCandidato)-1] ='\0';
		validaSiglaCandidato(&candidato.siglaCandidato);
		
		system("cls");
		imprimeMoldura();
		gotoxy(3, 3);
		printf("O candidato está sendo investigado pela operação Lava Jato?: ");
		gotoxy(3, 3);
		imprimeAviso("Digite 's' para sim ou 'n' para não: ");
		candidato.lavaJato = getch();
		validaLavaJato(&candidato.lavaJato);
		fflush(stdin);
		
		//salvaOrdena(&candidato, arquivoCandidato);
		
		fwrite(&candidato,sizeof(candidato),1, arquivoCandidato);
		
		fecharArquivo(arquivoCandidato);
	}
	
}

//    Objetivo:   Mostrar candidatos cadastrados
//    Parâmetros: Nome, Número da legenda, Sigla do partido e situação na Lava Jato dos candidatos
//    Retorno:    Nenhum
void listarCandidatos(FILE *arquivoCandidato) {
	infoCandidato candidatos;
	int aux = 3;
	
	system("cls");
	imprimeMoldura();
	
	arquivoCandidato = fopen("eleicao.bin","rb");
	if(arquivoCandidato == NULL) {
		imprimeAviso("Nenhum candidato foi cadastrado!");
		getch();
	} else {
		gotoxy(2, 2);
		printf(" Nome                        numero de legenda    Partido    Envol. Lava Jato");
		gotoxy(2, 3);
		printf("------------------------------------------------------------------------------");
		while( fread(&candidatos,sizeof(candidatos),1, arquivoCandidato) == 1 ) {
			//*********************************************************************************************************
			gotoxy(3,++aux);
			printf("%-28s", candidatos.nome);
			printf("%-21d", candidatos.numeroLegenda);
			printf("%-11s", candidatos.siglaCandidato);
			printf("%s", candidatos.lavaJato == 's' ? "Lava Jato" : "Ficha limpa");
		}
		fecharArquivo(arquivoCandidato);
		getch();
	}
}



//    Objetivo:   Valida situação na lava jato do candidato
//    Parâmetros: situaçãona lava jato do candidato
//    Retorno:    Nenhum
void validaLavaJato(char *lavaJato) {
	fflush(stdin);
	*lavaJato = tolower(*lavaJato);
	while (*lavaJato != 's' && *lavaJato != 'n') {
		imprimeAviso("Inválido! Digite 's' para sim ou 'n' para não: ");
		*lavaJato = getch();
	}
}

//    Objetivo:   Mostrar menu de opções
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void mostrarMenu(void) {
	int aux = 3;
	system("cls");
	imprimeMoldura();
	gotoxy(POSMENU, ++aux);
	printf("--xxxXXX  Bem vindo ao programa de cadastro de candidatos  XXXxxx--");
	aux += 3;
	gotoxy(POSMENU, ++aux);
	printf("1. Cadastrar novo candidato");
	gotoxy(POSMENU, ++aux);
	printf("2. Modificar dados do candidato");
	gotoxy(POSMENU, ++aux);
	printf("3. Listar todos os candidatos cadastrados");
	gotoxy(POSMENU, ++aux);
	printf("4. Selecionar os candidatos envolvidos com a Lava Jato");
	gotoxy(POSMENU, ++aux);
	printf("5. Apagar arquivo com cadastros de todos candidatos");
	gotoxy(POSMENU, ++aux);
	printf("0. Sair");
	imprimeAviso("Digite uma opção: ");
}

//    Objetivo:   Validar nome do candidato
//    Parâmetros: Nome do candidato
//    Retorno:    Nenhum
void validaNomeCandidato(char *nomeCandidato) {
	//Instruções
	while(strlen(nomeCandidato) <= 1) {
		imprimeAviso("Inválido! Informe nome maior que 1: ");
		gotoxy(3, 3);
		printf("%-76s"," ");
		gotoxy(3, 3);
		printf("Digite o nome do candidato: ");
		fgets(nomeCandidato,MAXNOME,stdin);
		fflush(stdin);
		if(nomeCandidato[strlen(nomeCandidato)-1] == '\n')
			nomeCandidato[strlen(nomeCandidato)-1] ='\0';
	}
	
}

//    Objetivo:   Validar sigla do partido do candidato
//    Parâmetros: Sigla do partido do candidato
//    Retorno:    Nenhum
void validaSiglaCandidato(char *sigla) {
	//Instruções
	while(strlen(sigla) <= 1) {
		imprimeAviso("Inválido! Informe nome maior que 1: ");
		gotoxy(3, 3);
		printf("%-76s"," ");
		gotoxy(3, 3);
		printf("Digite a sigla do partido do candidato: ");
		fgets(sigla,MAXPARTIDO,stdin);
		fflush(stdin);
		if(sigla[strlen(sigla)-1] == '\n')
			sigla[strlen(sigla)-1] ='\0';
	}
	
}

//    Objetivo:   Validar número de legenda do candidato
//    Parâmetros: legenda do candidato
//    Retorno:    Nenhum
void validaNumeroLegenda(int *numeroLegenda) {
	while(*numeroLegenda <= 10 || *numeroLegenda >= 100) {
		fflush(stdin);
		imprimeAviso("Inválido! Informe maior que 10 e menor 100! ");
		gotoxy(3, 3);
		printf("%-76s"," ");
		gotoxy(3, 3);
		printf("Digite número de legenda: ");
		scanf("%d",numeroLegenda);
	}
}

//    Objetivo:   Imprimir uma moldura
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void imprimeMoldura(void) {
	int aux;
	for(aux = 1; aux<=80; aux++)
		printf("%c",'#');
	gotoxy(1, 25);
	for(aux = 1; aux<=80; aux++)
		printf("%c",'#');
	gotoxy(1, 1);
	for(aux = 1; aux<=25; aux++) {
		printf("%c",'#');
		gotoxy(1, aux);
	}
	gotoxy(80, 1);
	for(aux = 1; aux<=25; aux++) {
		printf("%c",'#');
		gotoxy(80, aux);
	}
}

//    Objetivo:   Mostrar na tela um aviso
//    Parâmetros: Aviso
//    Retorno:    Nenhum
void imprimeAviso(char aviso[]) {
	gotoxy(25, 18);
	printf("%-054s"," ");
	gotoxy(25, 18);
	printf("%s",aviso);
	
}

//    Objetivo:   Fecha o arquivo que guarda informações dos candidatos
//    Parâmetros: Arquivo
//    Retorno:    Nenhum
void fecharArquivo(FILE *arquivoCandidato) {
	if (fclose(arquivoCandidato) != 0) {
		imprimeAviso("Erro ao fechar arquivo.");
		getch();
	}
}




