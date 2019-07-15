//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Cadastrar informações de cidades
    Entrada:  DDD e nome das cidades
    Saída:    lista com DDD e nome das cidades em formato tabelar
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
	//Declarações
	char continuar;
	struct dados cidade;
	FILE *p_arq;
	//Instruções
	setlocale(LC_ALL, "Portuguese");

	if ((p_arq=fopen("Local.bin","wb")) == NULL) {
		puts("Arquivo não pode ser aberto.");
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
//    Parâmetros: DDD e nome das cidades
//    Retorno:    Nenhum
void mostraRegistros(FILE *p_arq) {
	//Declarações
	struct dados cidade;
	int fimArquivo = 1;
	//Instruções
	//if((p_arq=fopen("Local.bin","rb")) == NULL) {
	//	printf("Não foi possível mostrar registros.");
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
//    Parâmetros: DDD
//    Retorno:    DDD válido
int validaDdd(int ddd) {
	//Instruções
	while(ddd <= 10 || ddd >= 99) {
		puts("DDD inválido! Digite um DDD maior que 10 e menor que 99:");
		scanf("%d",&ddd);
		fflush(stdin);
	}
}

//    Objetivo:   Validar nome da cidade
//    Parâmetros: nome da cidade
//    Retorno:    Nenhum
void validaNomeCidade(char *nomeCidade) {
	//Instruções
	while(strlen(nomeCidade) <= 1) {
		puts("inválido!informe nome maior que 1: ");
		fgets(nomeCidade,MAX,stdin);
		fflush(stdin);
		if(nomeCidade[strlen(nomeCidade)-1] == '\n')
			nomeCidade[strlen(nomeCidade)-1] ='\0';
	}
}






