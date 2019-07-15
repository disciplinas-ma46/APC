//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Cadastrar informa��es de cidades
    Entrada:  DDD e nome das cidades
    Sa�da:    lista com DDD e nome das cidades em formato tabelar
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define MAX 30

void mostraRegistros(FILE *p_arq);
int validaDdd(int ddd);
void validaNomeCidade(char *nomeCidade);

struct dados {
	char nome[MAX];
	int ddd;
};

int main (void) {
	//Declara��es
	char continuar;
	struct dados cidade;
	FILE *p_arq;
	//Instru��es
	setlocale(LC_ALL, "Portuguese");

	if ((p_arq=fopen("Local.bin","wb")) == NULL) {
		puts("Arquivo n�o pode ser aberto.");
		getch();
		exit(1);
	}
	else {
		do {
			puts("Informe o nome da cidade: ");
			fgets(cidade.nome,MAX,stdin);
			fflush(stdin);
			if(cidade.nome[strlen(cidade.nome)-1] == '\n')
				cidade.nome[strlen(cidade.nome)-1] = '\0';
			validaNomeCidade(&cidade.nome);
			system("cls");
			
			puts("Informe o DDD da cidade: ");
			scanf("%d",&cidade.ddd);
			fflush(stdin);
			cidade.ddd = validaDdd(cidade.ddd);
			system("cls");

			fwrite(&cidade,sizeof(cidade),1, p_arq);
			
			printf("\nPressione 't' para terminar cadastros ou outra tecla para cadastrar mais: ");
			continuar = getch();
			continuar = tolower(continuar);
			system("cls");
		}while(continuar != 't');
		
		//fclose(p_arq);
		mostraRegistros(p_arq);
	} // fim do else
} // fim do programa

//===========  SUBALGORITMOS  ================

//    Objetivo:   Mostrar registros das cidades
//    Par�metros: DDD e nome das cidades
//    Retorno:    Nenhum
void mostraRegistros(FILE *p_arq) {
	//Declara��es
	struct dados cidade;
	int fimArquivo = 1;
	//Instru��es
	//if((p_arq=fopen("Local.bin","rb")) == NULL) {
	//	printf("N�o foi poss�vel mostrar registros.");
	//} else {
		printf("========  REGISTROS  ========\n\n\n");
		printf("Cidade              DDD\n\n");
		fseek(p_arq, 0, SEEK_SET);
		while(fimArquivo) {
			fread(&cidade,sizeof(cidade),1, p_arq);
			if(feof(p_arq) != 0)
				fimArquivo = 0;
			else
				printf("%-20s%d\n", cidade.nome, cidade.ddd);
		}
	//}
	fclose(p_arq);
}



//    Objetivo:   Validar DDD
//    Par�metros: DDD
//    Retorno:    DDD v�lido
int validaDdd(int ddd) {
	//Instru��es
	while(ddd <= 10 || ddd >= 99) {
		puts("DDD inv�lido! Digite um DDD maior que 10 e menor que 99:");
		scanf("%d",&ddd);
		fflush(stdin);
	}
}

//    Objetivo:   Validar nome da cidade
//    Par�metros: nome da cidade
//    Retorno:    Nenhum
void validaNomeCidade(char *nomeCidade) {
	//Instru��es
	while(strlen(nomeCidade) <= 1) {
		puts("inv�lido!informe nome maior que 1: ");
		fgets(nomeCidade,MAX,stdin);
		fflush(stdin);
		if(nomeCidade[strlen(nomeCidade)-1] == '\n')
			nomeCidade[strlen(nomeCidade)-1] ='\0';
	}
}






