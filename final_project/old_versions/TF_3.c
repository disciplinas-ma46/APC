//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Cadastrar informa��es de candidatos a presidente
    Entrada:  Nome, N�mero da legenda, Sigla do partido e situa��o na Lava Jato de cada candidato
    Sa�da:    Lista com Nome, N�mero da legenda, Sigla do partido e situa��o na Lava Jato de cada candidato
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#define MAXNOME 45
#define MAXPARTIDO 10
#define POSMENU 10
#define NROLINHASTELA 35
#define NROCOLUNASTELA 100
#define LINHADOSAVISOS 2


typedef struct {
	char nome[MAXNOME];
	int numeroLegenda;
	char siglaCandidato[MAXPARTIDO];
	char lavaJato;
}infoCandidato;

// Prot�tipos de subprogramas referentes � a��es do menu
//void cadastrarCandidato(void);
void listarCandidatos(char modo);
void modificarCandidato(void);
void ordenaSalvaCandidato(void);
// Prot�tipos de subprogramas referentes � valida��o de dados
void validaNomeCandidato(char *nomeArquivo);
void validaSiglaCandidato(char *sigla);
void validaNumeroLegenda(int *numeroLegenda);
void validaLavaJato(char *lavaJato);
//int validaEscolhaLegenda(int nroLegendaCand, FILE *arquivoCandidato);

void lerNomeCandidato( char *nome );
void lerNroLegenda( int *numeroLegenda );
void lerSiglaPartido( char *siglaCandidato );
void lerSitacaoLavaJato ( char *lavaJato );

int indentCandProLegenda(int nroLegendaCand, FILE *arquivoCandidato);
// Outros Prot�tipos
void mostrarMenu(void);
void imprimeAviso(char aviso[], int linha);
void imprimeCabecalho(char cabecalho[]);
void imprimeMoldura(void);
void imprimeLinha(int localDaLinha, char posicao );
void fecharArquivo(FILE *arquivoCandidato);
void mudaTamanhoTela(void);
void ajustaTerminador(char *string);
void moverCursor(int coluna, int linha);
void apagarArquivo(void);
int  calculaQtdRegistros(void);


int main (void) {
	//Declara��es
	char opcao;
	FILE *arquivoCandidato;
	//Instru��es
	printf("numero de registros: %d",calculaQtdRegistros());
	getch();
	mudaTamanhoTela();

	setlocale(LC_ALL, "Portuguese");
	do {
		mostrarMenu();

		opcao = getch();
		fflush(stdin);

		switch(opcao) {
			case '1':
				//cadastrarCandidato();
				break;
			case '2':
				modificarCandidato();
				break;
			case '3':
				listarCandidatos('p');
				break;
			case '4':
				//selecionarLavaJato();
				break;
			case '5':
				apagarArquivo();
				break;
			case '0':
				imprimeAviso("Programa finalizado!", NROLINHASTELA-1);
				//getch();  // fix ******************************************************************************************************
				break;
			default:
				imprimeAviso("Op��o inv�lida! Digite outra op��o: ",LINHADOSAVISOS);
				opcao = getch();
		}
	}while(opcao != '0');
}

//===========  SUBALGORITMOS  ================
/*
//    Objetivo:   Realizar cadastro de um candidato
//    Par�metros: Defini��es de dados para candidato
//    Retorno:    Nenhum
void cadastrarCandidato(void) {
	infoCandidato candidato;
	FILE *arquivoCandidato;
	arquivoCandidato = fopen("eleicao.bin","a+b");
	if (arquivoCandidato == NULL) {
		imprimeAviso("Erro ao abrir arquivo.",NROLINHASTELA-1);
		getch();
	} else {
		lerNomeCandidato(&candidato.nome);
		lerNroLegenda(&candidato.numeroLegenda);
		lerSiglaPartido(&candidato.siglaCandidato);
		lerSitacaoLavaJato(&candidato.lavaJato);

		fseek(arquivoCandidato, sizeof(arquivoCandidato), 2);
		fwrite(&candidato,sizeof(candidato),1, arquivoCandidato);
		fecharArquivo(arquivoCandidato);
	}
}
*/
// fix por s�ntese (e nos de baixos)
void lerNomeCandidato( char *nome ) {
	system("cls");
	imprimeMoldura();
	imprimeAviso("Digite o nome do candidato: ", LINHADOSAVISOS);
	moverCursor(3, 5);
	fgets(nome, MAXNOME, stdin);
	fflush(stdin);
	ajustaTerminador(nome);
	validaNomeCandidato(nome);
}

void lerNroLegenda( int *numeroLegenda ) {
	system("cls");
	imprimeMoldura();
	imprimeAviso("Digite n�mero de legenda: ", LINHADOSAVISOS);
	scanf("%d",numeroLegenda);
	fflush(stdin);
	validaNumeroLegenda(numeroLegenda);
}

void lerSiglaPartido( char *siglaCandidato ) {
	system("cls");
	imprimeMoldura();
	imprimeAviso("Digite sigla do partido do candidato: ", LINHADOSAVISOS);
	fgets(siglaCandidato,MAXNOME,stdin);
	fflush(stdin);
	ajustaTerminador(siglaCandidato);
	validaSiglaCandidato(siglaCandidato);
}

void lerSitacaoLavaJato ( char *lavaJato ) {
	system("cls");
	imprimeMoldura();
	imprimeAviso("O candidato est� sendo investigado pela Lava Jato?: ",LINHADOSAVISOS);
	moverCursor(3, 5);
	printf("Digite 's' para sim ou 'n' para n�o: ");
	*lavaJato = getch();
	validaLavaJato(lavaJato);
	fflush(stdin);
}

//    Objetivo:   Modificar cadastro de um candidato
//    Par�metros: Nenhum
//    Retorno:    Nenhum
void modificarCandidato(void) {
	
	int nroLegendaCand, aux, identifCandidato;
	
	int nroRegistros = calculaQtdRegistros();
	
	char escolha = 'x';
	
	infoCandidato candidatos[nroRegistros];
	
	FILE *arquivoCandidato;
	
	arquivoCandidato = fopen("eleicao.bin","a+b");
	
	if(arquivoCandidato == NULL) { // fix ***************** nessa parte falta verificar se tam arq == 0 ***************************
		imprimeAviso("Nenhum candidato foi cadastrado!",LINHADOSAVISOS);
		getch();
	} else {
		listarCandidatos('c');
		imprimeAviso("Digite o n� da legenda do candidato que deseja modificar: ",NROLINHASTELA-1);
		scanf("%d",&nroLegendaCand);
		//validaEscolhaLegenda
		identifCandidato = indentCandProLegenda(nroLegendaCand, arquivoCandidato);
		////////////////////
		imprimeAviso("Identif cand: ",2);
		printf("%d",identifCandidato);
		getch();
		////////////////////
		fread(&candidatos, sizeof(candidatos[0]), nroRegistros, arquivoCandidato);
		//
		
		//candidato = candidatos[identifCandidato];
		
		//
		while (escolha != '0') {
			aux = 6;
			system("cls");
			imprimeMoldura();
			
			moverCursor(POSMENU, ++aux);
			printf("1. Nome:                  %s",candidatos[identifCandidato].nome);
			moverCursor(POSMENU, ++aux);
			printf("2. n�mero de legenda:     %d",candidatos[identifCandidato].numeroLegenda);
			moverCursor(POSMENU, ++aux);
			printf("3. sigla do partido:      %s",candidatos[identifCandidato].siglaCandidato);
			moverCursor(POSMENU, ++aux);
			printf("4. Situa��o na Lava Jato: %s",candidatos[identifCandidato].lavaJato == 's' ? "Lava Jato" : "Ficha limpa");
			moverCursor(POSMENU, aux+2);
			printf("0. Sair da altera��o de candidatos: ");

			imprimeAviso("Qual dado do candidato deseja alterar? Digite o valor correspondente: ",LINHADOSAVISOS);
			escolha = getch();

			switch(escolha) {
				case '1':
					lerNomeCandidato(&candidatos[identifCandidato].nome);
					break;
				case '2':
					lerNroLegenda(&candidatos[identifCandidato].numeroLegenda);
					break;
				case '3':
					lerSiglaPartido(&candidatos[identifCandidato].siglaCandidato);
					break;
				case '4':
					lerSitacaoLavaJato(&candidatos[identifCandidato].lavaJato);
					break;
				case '0':
					imprimeAviso("Quem foi o candidato lido: ",LINHADOSAVISOS);//*************************
					printf("%d",identifCandidato);//*************************
					getch();//*************************
					
					//candidatos[identifCandidato] = candidato;
					rewind(arquivoCandidato);
					fwrite(&candidatos, sizeof(candidatos[0]), nroRegistros, arquivoCandidato); // fix fazer candidatos[0] vari�vel
					fecharArquivo(arquivoCandidato);
					imprimeAviso("Saindo da altera��o de candidatos. Aperte qualquer tecla",LINHADOSAVISOS);
					getch();
					break;
				default:
					imprimeAviso("Inv�lido! Digite uma op��o v�lida. ",NROLINHASTELA-1);
			}
		}
	}
}

//    Objetivo:   Valida escolha do n� de legenda do candidato
//    Par�metros: N� de legenda do candidato
//    Retorno:    N� de legenda do candidato v�lido
int indentCandProLegenda(int nroLegendaCand, FILE *arquivoCandidato) {
	int nroLegendaInvalido = 1, identifCandidato;
	infoCandidato candidato;
	while( nroLegendaInvalido ) {
		
		rewind(arquivoCandidato);
		identifCandidato = 0;
		while(nroLegendaInvalido && fread(&candidato,sizeof(candidato),1, arquivoCandidato) == 1)
			if(candidato.numeroLegenda == nroLegendaCand)
				nroLegendaInvalido = 0;
			else
				identifCandidato++;
		/*
		if(nroLegendaInvalido) {
			imprimeAviso("Digite n� de legenda de candidato existente: ",NROLINHASTELA-1);
			scanf("%d",&nroLegendaCand);
		}
		*/
	}
	return identifCandidato;
}

//    Objetivo:   Salvar cadastro de um funcion�rio em ordem crescente pelo nome
//    Par�metros: Nome, N�mero da legenda, Sigla do partido e situa��o na Lava Jato do candidato, e arquivos de candidato
//    Retorno:    Nenhum
void ordenaSalvaCandidato(void) {
	int nroRegistros = calculaQtdRegistros();
	infoCandidato candidato[nroRegistros];
	infoCandidato candidatoTroca;
	FILE *arquivoCandidato;
	arquivoCandidato = fopen("eleicao.bin","a+b");
	imprimeMoldura();
	if (arquivoCandidato == NULL) { // fix colocar parte em q ve se tem 0 cadastros
		imprimeAviso("Erro ao abrir arquivo!",LINHADOSAVISOS);
		getch();
	} else {
		int aux = 0;
		long int tamEstrutura = sizeof(candidato[0]);
		fread(&candidato, tamEstrutura, nroRegistros, arquivoCandidato);
		int aux1, aux2;
		aux = 2;
		for (aux1 = 0; aux1<nroRegistros-1; aux1++) {
			for (aux2 = aux1+1; aux2<nroRegistros; aux2++) {
				if (strcmp(candidato[aux1].nome , candidato[aux2].nome) == 1) {
					candidatoTroca = candidato[aux1];
					candidato[aux1] = candidato[aux2];
					candidato[aux2] = candidatoTroca;
				}
			}
		}
		fecharArquivo(arquivoCandidato);
		arquivoCandidato = fopen("eleicao.bin","wb");
		if(arquivoCandidato == NULL) {
			imprimeAviso("N�o foi encontrado arquivo para ser removido",LINHADOSAVISOS);
			getch();
		}
		rewind(arquivoCandidato);
		fwrite(&candidato, tamEstrutura, nroRegistros, arquivoCandidato);
		fecharArquivo(arquivoCandidato);
	}
}

//    Objetivo:   Contar quantos registros foram feitos
//    Par�metros: Nenhum
//    Retorno:    Nenhum
int calculaQtdRegistros(void) {
	FILE *arquivo;
	int qtdRegistros = 0;
	arquivo = fopen("eleicao.bin","rb"); // fix colocar mens erro
	infoCandidato candidato;
	while( fread(&candidato,sizeof(candidato),1, arquivo) == 1 ) {
		qtdRegistros++;
	}
	fclose(arquivo);
	return qtdRegistros;
}

//    Objetivo:   Mostrar candidatos cadastrados
//    Par�metros: Como ser� mostrados os candidatos (ordem crescente, decrescente ou os que est�o na lavajato)
//    Retorno:    Nenhum
void listarCandidatos(char modo) {
	infoCandidato candidatos;
	int aux = 3;
	FILE *arquivoCandidato;

	arquivoCandidato = fopen("eleicao.bin","rb");
	if(arquivoCandidato == NULL) { // fix ***************** nessa parte falta verificar se tam arq == 0 ***************************
		imprimeAviso("Nenhum candidato foi cadastrado!",LINHADOSAVISOS-2);
		getch(); //fix n�o sei se precisa apag�lo
	} else {
		system("cls");
		imprimeMoldura();
		if(modo == 'p') {
			imprimeAviso("Pressione 'c' para ordem crescente ou 'd' para decrescente: ",LINHADOSAVISOS);
			modo = getch();
			//modo = validaOpcaoOrdem(modo); // fix
			imprimeAviso(" Nome                                             numero de legenda  Partido    Envol. Lava Jato",LINHADOSAVISOS);
		}

		ordenaSalvaCandidato(); // fix 123vai
		switch(modo) {
			case 'c': // lista candidatos em ordem crescente
				while( fread(&candidatos,sizeof(candidatos),1, arquivoCandidato) == 1 ) {
					moverCursor(3,++aux);
					printf("%-49s", candidatos.nome);
					printf("%-19d", candidatos.numeroLegenda);
					printf("%-11s", candidatos.siglaCandidato);
					printf("%s", candidatos.lavaJato == 's' ? "Lava Jato" : "Ficha limpa");
				}
				break;
			case 'd': // lista candidatos em ordem decrescente
				imprimeAviso("A ordem decrescente ser� feita em uma atualiza��o futura!",LINHADOSAVISOS); // fix
				getch();
				break;
			case 'l': // lista candidatos na lava jato
				imprimeAviso("Ainda falta fazer lista com quem est� na lava jato!",LINHADOSAVISOS); // fix
				getch();
				break;
			default:
				imprimeAviso("Op��o de listagem inv�lido!",LINHADOSAVISOS); // fix talvez fa�a como valida��o
				getch();
		}

		fecharArquivo(arquivoCandidato);
		//getch();
	}
}



//    Objetivo:   Valida situa��o na lava jato do candidato
//    Par�metros: situa��o na lava jato do candidato
//    Retorno:    Nenhum
void validaLavaJato(char *lavaJato) {
	fflush(stdin);
	*lavaJato = tolower(*lavaJato);
	while (*lavaJato != 's' && *lavaJato != 'n') {
		imprimeAviso("Inv�lido! Digite 's' para sim ou 'n' para n�o: ",LINHADOSAVISOS);
		*lavaJato = getch();
	}
}

//    Objetivo:   Mostrar menu de op��es
//    Par�metros: Nenhum
//    Retorno:    Nenhum
void mostrarMenu(void) {
	int aux = 6;
	system("cls");
	imprimeMoldura();
	imprimeAviso("--xxXX Bem vindo ao programa de cadastro de candidatos XXxx--", LINHADOSAVISOS);
	moverCursor(POSMENU, ++aux);
	printf("1. Cadastrar novo candidato");
	moverCursor(POSMENU, ++aux);
	printf("2. Modificar dados do candidato");
	moverCursor(POSMENU, ++aux);
	printf("3. Listar todos os candidatos cadastrados");
	moverCursor(POSMENU, ++aux);
	printf("4. Selecionar os candidatos envolvidos com a Lava Jato");
	moverCursor(POSMENU, ++aux);
	printf("5. Apagar arquivo com cadastros de todos candidatos");
	moverCursor(POSMENU, ++aux);
	printf("0. Sair");
	imprimeAviso("Digite uma op��o: ",aux+4);
}

//    Objetivo:   Validar nome do candidato
//    Par�metros: Nome do candidato
//    Retorno:    Nenhum
void validaNomeCandidato(char *nomeCandidato) {
	//Instru��es
	while(strlen(nomeCandidato) <= 1) {
		imprimeAviso("Inv�lido! Informe nome maior que 1: ",LINHADOSAVISOS);
		moverCursor(3, 5);
		printf("Digite o nome do candidato: ");
		fgets(nomeCandidato,MAXNOME,stdin);
		fflush(stdin);
		ajustaTerminador(nomeCandidato);
	}

}

//    Objetivo:   Validar sigla do partido do candidato
//    Par�metros: Sigla do partido do candidato
//    Retorno:    Nenhum
void validaSiglaCandidato(char *sigla) {
	//Instru��es
	while(strlen(sigla) <= 1) {
		imprimeAviso("Inv�lido! Sigla do partido deve ser maior que 1. Digite novamente: ",LINHADOSAVISOS);
		moverCursor(3, 5);
		fgets(sigla,MAXPARTIDO,stdin);
		fflush(stdin);
		ajustaTerminador(sigla);
	}

}

//    Objetivo:   Validar n�mero de legenda do candidato
//    Par�metros: legenda do candidato
//    Retorno:    Nenhum
void validaNumeroLegenda(int *numeroLegenda) {
	while(*numeroLegenda <= 10 || *numeroLegenda >= 100) {
		imprimeAviso("Inv�lido! Informe valor maior que 10 e menor 100! ",LINHADOSAVISOS);
		scanf("%d",numeroLegenda);
		fflush(stdin);
	}
}

//    Objetivo:   Imprimir uma moldura
//    Par�metros: Nenhum
//    Retorno:    Nenhum
void imprimeMoldura(void) {
	setlocale(LC_ALL,"C");
	imprimeLinha(1, 'h');
	imprimeLinha(3, 'h');
	imprimeLinha(NROLINHASTELA, 'h');
	imprimeLinha(NROLINHASTELA-2, 'h');
	imprimeLinha(1, 'v');
	imprimeLinha(NROCOLUNASTELA, 'v');
	setlocale(LC_ALL,"Portuguese");
}

//    Objetivo:   Imprimir uma linha
//    Par�metros: Local do come�o da linha e posi��o (horizontal ou vertical)
//    Retorno:    Nenhum
void imprimeLinha(int localDaLinha, char posicao ) {
	int aux;
	switch(posicao) {
		case 'h': // o caso para imprimir linha horizontal
			for(aux = 2; aux<NROCOLUNASTELA; aux++) {
				moverCursor(aux, localDaLinha);
				printf("%c",205);
			}
			break;
		case 'v': // o caso para imprimir linha vertical
			for(aux = 2; aux<NROLINHASTELA; aux++) {
				moverCursor(localDaLinha, aux);
				printf("%c",186);
			}
			break;
		default:
			imprimeAviso("Erro ao imprimir linha!",LINHADOSAVISOS-2);
			getch();
	}
}

//    Objetivo:   Mostrar na tela um aviso
//    Par�metros: Aviso e em qual linha aparecer� o aviso
//    Retorno:    Nenhum
void imprimeAviso(char aviso[], int linha) {
	int aux;
	if(strlen(aviso) > NROCOLUNASTELA-2) {
		imprimeAviso("Erro grave ao mostrar mensagem! mensagem tem mais de ",linha);
		printf("%d caracteres.",NROCOLUNASTELA-2);
		getch();
	} else {
		moverCursor( 2 , linha);
		for(aux = 2; aux<NROCOLUNASTELA; aux++)
		printf(" ");
		moverCursor((NROCOLUNASTELA - strlen(aviso)) / 2 , linha);
		printf("%s",aviso);
	}
}

//    Objetivo:   Fecha o arquivo que guarda informa��es dos candidatos
//    Par�metros: Arquivo
//    Retorno:    Nenhum
void fecharArquivo(FILE *arquivoCandidato) {
	if (fclose(arquivoCandidato) != 0)
		imprimeAviso("Erro ao fechar arquivo.",LINHADOSAVISOS);
	getch();
}

//    Objetivo:   Apagar todos os registros dos candidatos
//    Par�metros: registros
//    Retorno:    Nenhum
void apagarArquivo(void) {
	FILE *arquivoCandidato;
	arquivoCandidato = fopen("eleicao.bin","wb");
	if(arquivoCandidato == NULL) {
		imprimeAviso("N�o foi encontrado arquivo para ser removido",LINHADOSAVISOS);
		getch();
	} else {
		//remove(arquivoCandidato); // fix arrumar isso
		imprimeAviso("Registros removidos com sucesso!",LINHADOSAVISOS);
		getch();
	}
	fecharArquivo(arquivoCandidato);
}

//    Objetivo:   Mudar o tamanho da tela do programa
//    Par�metros: Nenhum
//    Retorno:    Nenhum
void mudaTamanhoTela(void) {
	//Declara��es locais
	char novaTela[40] = "";
	char nroColunas[4] = "", nroLinhas[4] = "";

	//Instru��es
	sprintf(nroColunas, "%d", NROCOLUNASTELA);
	sprintf(nroLinhas, "%d", NROLINHASTELA);
	strcat(novaTela, "mode con:cols=");
	strcat(novaTela, nroColunas);
	strcat(novaTela, " lines=");
	strcat(novaTela, nroLinhas);
	system(novaTela);
}

//Objetivo: Ajustar o terminador de uma string
//Par�metro: String
//Retorno: Nenhum
void ajustaTerminador(char *string) {
    if(string[strlen(string)-1]=='\n')
    	string[strlen(string)-1]='\0';
}

//Objetivo: Mover cursor para um local da tela
//Par�metro: A linha e coluna para o qual deve mover
//Retorno: Nenhum
void moverCursor(int coluna, int linha) {
	COORD coord;
	coord.X = coluna-1;
	coord.Y = linha-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

