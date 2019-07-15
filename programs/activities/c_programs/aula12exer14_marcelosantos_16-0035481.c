//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Cadastrar e analizar marcas de carros
    Entrada:  Marcas dos carros
    Saída:    Classificação entre Astra, Omega, Vectra, Silverado
*/

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define QTDECARROS 10
#define TAMANHOMAXIMO 20

void apresentaResultado(char marcasCarros[][TAMANHOMAXIMO]);
void validaMarca(char provisorio[]);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARAÇÕES
	char marcasCarros[QTDECARROS][TAMANHOMAXIMO];
	char provisorio[TAMANHOMAXIMO];
	int aux;
	
	//INSTRUÇÕES
	for(aux = 0; aux < QTDECARROS; aux++) {
		printf("Digite o nome da %d° marca de carro: ",aux+1);
		fgets(provisorio, TAMANHOMAXIMO, stdin);
		fflush(stdin);
		validaMarca(provisorio);
		strcpy(marcasCarros[aux], provisorio);
		system("cls");
	}
	apresentaResultado(marcasCarros);
	
	getch();
	return 0;
}

//===========  SUBALGORITMOS  ================
/*
 Síntese
    Objetivo:   Apresentar resultados do cadastro das marcas
    Parâmetros: Marcas dos carros
    Retorno:    Nenhum
*/
void apresentaResultado(char marcasCarros[][TAMANHOMAXIMO]) {
	//declarações locais
	char identificacao[TAMANHOMAXIMO] = "Null";
	int aux;
	//instruções
	puts("CARROS SOLICITADOS	       	RELAÇÃO FINAL");
	for(aux = 0; aux < QTDECARROS; aux++) {
		if(strcmp(marcasCarros[aux], "Astra")==0)
			strcpy(identificacao, "Astra");
		else
			if(strcmp(marcasCarros[aux], "Omega")==0)
				strcpy(identificacao, "Omega");
			else
				if(strcmp(marcasCarros[aux], "Vectra")==0)
					strcpy(identificacao, "Vectra");
				else
					if(strcmp(marcasCarros[aux], "Silverado")==0)
						strcpy(identificacao, "Silverado");
					else
						strcpy(identificacao, "indisponivel");
		printf("%d- %s                    \%s\n",aux+1, marcasCarros[aux], identificacao);
	}
}

/*
 Síntese
    Objetivo:   Validar marca de carro
    Parâmetros: Marca
    Retorno:    Nenhum
*/
void validaMarca(char provisorio[]) {
	if(provisorio[strlen(provisorio)-1] == '\n')
		provisorio[strlen(provisorio)-1] = '\0';
	while(strlen(provisorio) < 2){
		printf("\nInválido!Digite um nome maior que 1: ");
		fgets(provisorio, TAMANHOMAXIMO, stdin);
		if(provisorio[strlen(provisorio)-1] == '\n')
			provisorio[strlen(provisorio)-1] = '\0';
		fflush(stdin);
	}
}







