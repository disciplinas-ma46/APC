//NOME DO ALUNO:  Marcelo Araújo dos Santos
//Matrícula 16/0035481
//Tema 1

//  Síntese
//    Objetivo: Cadastrar informações de candidatos a presidente
//    Entrada:  Nome, Número da legenda, Sigla do partido e situação na Lava Jato de cada candidato
//    Saída:    Lista com Nome, Número da legenda, Sigla do partido e situação na Lava Jato de cada candidato

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#define MAXNOME 45
#define MAXPARTIDO 10
#define POSMENU 10 // distância que menu ficará da borda esquerda
#define NROLINHASTELA 35
#define NROCOLUNASTELA 106
#define LINHADOSAVISOS 2
#define NOMEARQUIVO "eleicao.bin"
#define MINLEGENDA 10
#define MAXLEGENDA 100
#define NROREGPORPAG 25 // n° de registros mostrado por pág.
#define LOCAL_LEITURA 3, 5

// estrutura de dados para candidatos
typedef struct {
	char nome[MAXNOME];
	int numeroLegenda;
	char siglaCandidato[MAXPARTIDO];
	char lavaJato;
}infoCandidato;

// Protótipos de subprogramas referentes à ações do menu
void cadastrarCandidato(void);
void listarCandidatos(char modo);
void modificarCandidato(void);

// Protótipos de subprogramas referentes à validação de dados
void validaNomeCandidato(char *nomeArquivo);
void validaSiglaCandidato(char *sigla);
void validaNumeroLegenda(int *numeroLegenda);
void validaLavaJato(char *lavaJato);
char validaOpcaoOrdem(char modo);
int validaPagAtual(int pagAtual, int nroPaginas);
int validaEscolhaCand(int nroLegCand);
char validaEscolhaExcluir(char resposta);

// Protótipos de subprogramas para leitura de dados
void lerNomeCandidato( char *nome );
void lerNroLegenda( int *numeroLegenda );
void lerSiglaPartido( char *siglaCandidato );
void lerSitacaoLavaJato ( char *lavaJato );

// Outros Protótipos
void mostrarMenu(void);
void mostraCandidato(infoCandidato *candidato);
void mostraCandidatoPorLinha(infoCandidato *candidato, int linha);
void mostrarLinhasListagem(void);
void imprimeAviso(char aviso[], int linha);
void imprimeMoldura(void);
void imprimeLinha(int localDaLinha, char posicao );
void ordenaCandidato(char ordem);
void fecharArquivo(FILE *arquivoCandidato);
void mudaTamanhoTela(void);
void ajustaTerminador(char *string);
void moverCursor(int coluna, int linha);
void apagarArquivo(void);
void apagarCandidato(int qualCand);
int  calculaQtdRegistros(void);
void limparLinha(int linha);
int nomeInvalido(char *nomeCandidato);
void stringParaMinuscula(char *string);
void stringParaMaiuscula(char *string);
int numeroLegendaValido(int numeroLegenda);
int siglaCandInvalido(char *sigla);
int escolhaCandInvalida(int nroLegCand);


int main (void) {
	//Declarações
	char opcao;

	//Instruções
	mudaTamanhoTela();
	setlocale(LC_ALL, "Portuguese");
	do {
		mostrarMenu();

		opcao = getch();
		fflush(stdin);

		switch(opcao) {
			case '1':
				cadastrarCandidato();
				break;
			case '2':
				modificarCandidato();
				break;
			case '3':
				listarCandidatos('p');
				break;
			case '4':
				listarCandidatos('l');
				break;
			case '5':
				apagarArquivo();
				break;
			case '0':
				imprimeAviso("Programa finalizado! Aperte qualquer tecla para fechar", NROLINHASTELA-1);
				getch();
				break;
			default:
				imprimeAviso("Opção inválida: ",NROLINHASTELA-1);
				putch(opcao);
				getch();
		}
	}while(opcao != '0');
}


// =============================    SUBALGORITMOS    =============================


//    Objetivo:   Realizar cadastro de um candidato
//    Parâmetros: Definições de dados para candidato
//    Retorno:    Nenhum
void cadastrarCandidato(void) {
	//Instruções
	char modificar = 'x';
	int salvarCandidato;
	infoCandidato candidato;
	FILE *arquivoCandidato;
	do {
		arquivoCandidato = fopen(NOMEARQUIVO,"a+b");
		salvarCandidato = 1;
		if (arquivoCandidato == NULL) {
			imprimeAviso("Erro ao abrir arquivo.",NROLINHASTELA-1);
			getch();
		} else {
			do {
				if(modificar == 'x') {
					lerNomeCandidato(candidato.nome);
					lerNroLegenda(&candidato.numeroLegenda);
					lerSiglaPartido(candidato.siglaCandidato);
					lerSitacaoLavaJato(&candidato.lavaJato);
				} else {
					switch(modificar) {
						case '1':
							lerNomeCandidato(candidato.nome);
							break;
						case '2':
							imprimeAviso("Tem certeza que quer apagar candidato? Digite 's' para sim ou outra tecla para cancelar",LINHADOSAVISOS);
							if(tolower(getch()) == 's') {
								salvarCandidato = 0;
								modificar = '0';
							}
							break;
						case '3':
							lerSiglaPartido(candidato.siglaCandidato);
							break;
						case '4':
							lerSitacaoLavaJato(&candidato.lavaJato);
							break;
						default:
							imprimeAviso("Escolha inválida! digite '1' '2' '3' '4' ou '0' para sair.",LINHADOSAVISOS);
							getch();
					}
				}
				if(salvarCandidato) {
					imprimeMoldura();
					mostraCandidato(&candidato);
					imprimeAviso("Deseja modificar algum dos dados cadastrados? digite o valor correspondente ou 0 para sair e salvar",LINHADOSAVISOS);
					modificar = getch();
				}
			}while(modificar != '0');
			if(salvarCandidato)
				if(fwrite(&candidato,sizeof(candidato),1, arquivoCandidato) != 1) {
					imprimeAviso("Erro ao salvar informações do candidato.",LINHADOSAVISOS);
					getch();
				}
			fecharArquivo(arquivoCandidato);
		}
		modificar = 'x';
		imprimeMoldura();
		imprimeAviso("Deseja cadastrar mais candidatos? Digite 's' para sim ou outra tecla para sair ",LINHADOSAVISOS);
	}while(tolower(getch()) == 's');
}

//    Objetivo:   ler Nome do Candidato
//    Parâmetros: Onde será armazenado o nome lido
//    Retorno:    Nenhum
void lerNomeCandidato( char *nome ) {
	//Instruções
	imprimeMoldura();
	imprimeAviso("Digite o nome do candidato: ", LINHADOSAVISOS);
	moverCursor(LOCAL_LEITURA);
	fgets(nome, MAXNOME, stdin);
	fflush(stdin);
	ajustaTerminador(nome);
	validaNomeCandidato(nome);
	stringParaMinuscula(nome);
	*nome = toupper(*nome);
}

//    Objetivo:   ler Número de Legenda do Candidato
//    Parâmetros: Onde será armazenado o Número de Legenda lido
//    Retorno:    Nenhum
void lerNroLegenda(int *numeroLegenda) {
	//Instruções
	imprimeMoldura();
	imprimeAviso("Digite número de legenda: ", LINHADOSAVISOS);
	moverCursor(LOCAL_LEITURA);
	scanf("%d",numeroLegenda);
	fflush(stdin);
	validaNumeroLegenda(numeroLegenda);
}

//    Objetivo:   ler Sigla do Partido do Candidato
//    Parâmetros: Onde será armazenado a Sigla do Partido lido
//    Retorno:    Nenhum
void lerSiglaPartido(char *siglaCandidato) {
	//Instruções
	imprimeMoldura();
	imprimeAviso("Digite sigla do partido do candidato: ", LINHADOSAVISOS);
	moverCursor(LOCAL_LEITURA);
	fgets(siglaCandidato,MAXNOME,stdin);
	fflush(stdin);
	ajustaTerminador(siglaCandidato);
	validaSiglaCandidato(siglaCandidato);
	stringParaMaiuscula(siglaCandidato);
}

//    Objetivo:   ler Sitação na LavaJato do Candidato
//    Parâmetros: Onde será armazenado a Sitação na LavaJato lido
//    Retorno:    Nenhum
void lerSitacaoLavaJato (char *lavaJato) {
	//Instruções
	imprimeMoldura();
	imprimeAviso("O candidato está sendo investigado pela Lava Jato?: ",LINHADOSAVISOS);
	moverCursor(LOCAL_LEITURA);
	printf("Digite 's' para sim ou 'n' para não: ");
	*lavaJato = getch();
	validaLavaJato(lavaJato);
	fflush(stdin);
}

//    Objetivo:   Modificar cadastro de um candidato
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void modificarCandidato(void) {
	//Declarações locais
	int aux, qualCand, continuar = 1, nroLegCand;
	int nroRegistros = calculaQtdRegistros();
	char escolha = 'x';
	infoCandidato candidato, candidatos[nroRegistros-1];
	long int tamEstrutCand = sizeof(candidatos[0]);
	FILE *arquivoCandidato;
	//Instruções
	arquivoCandidato = fopen(NOMEARQUIVO,"a+b");
	if(arquivoCandidato == NULL || nroRegistros == 0) {
		imprimeAviso("Nenhum candidato foi cadastrado ou arquivo não foi encontrado!",LINHADOSAVISOS);
		getch();
	} else if(fread(&candidatos, tamEstrutCand, nroRegistros, arquivoCandidato) != nroRegistros) {
		imprimeAviso("Erro ao ler arquivos!",LINHADOSAVISOS);
		getch();
		fecharArquivo(arquivoCandidato);
	} else {
		fecharArquivo(arquivoCandidato);
		imprimeMoldura();
		imprimeAviso("Digite o n° de legenda do candidato que deseja modificar: ", LINHADOSAVISOS);
		scanf("%d",&nroLegCand);
		fflush(stdin);
		qualCand = validaEscolhaCand(nroLegCand);

		while (escolha != '0' && continuar) {
			mostraCandidato(&candidatos[qualCand]);
			imprimeAviso("Qual dado do candidato deseja alterar? Digite o valor correspondente: ",LINHADOSAVISOS);
			escolha = getch();
			escolha = tolower(escolha);
			fflush(stdin);

			switch(escolha) {
				case '1':
					lerNomeCandidato(candidatos[qualCand].nome);
					break;
				case '2':
					imprimeAviso("Atenção! Deseja APAGAR o candidato? Pressione 's' para sim ou outra tecla para cancelar",LINHADOSAVISOS);
					if(tolower(getch()) == 's') {
						apagarCandidato(qualCand);
						continuar = 0;
					}
					break;
				case '3':
					lerSiglaPartido(candidatos[qualCand].siglaCandidato);
					break;
				case '4':
					lerSitacaoLavaJato(&candidatos[qualCand].lavaJato);
					break;
				case '0':
					arquivoCandidato = fopen(NOMEARQUIVO,"wb");
					if(arquivoCandidato == NULL) {
						imprimeAviso("Erro ao abrir arquivo",LINHADOSAVISOS);
						escolha = getch();
					} else {
						if(fwrite(&candidatos, tamEstrutCand, nroRegistros, arquivoCandidato) != nroRegistros) {
							imprimeAviso("Erro ao salvar dados no arquivo",LINHADOSAVISOS);
							escolha = getch();
						} else {
							fecharArquivo(arquivoCandidato);
							continuar = 0;
						}
					}
					break;
				default:
					imprimeAviso("Opção inválida!",LINHADOSAVISOS);
					getch();
			}
		}
	}
}

//    Objetivo:   valida a escolha de candidato
//    Parâmetros: escolha de candidato
//    Retorno:    escolha de candidato válido
int validaEscolhaCand(int nroLegCand) {
	//Declarações locais
	int qualCand;
	//Instruções
	while(!(qualCand=escolhaCandInvalida(nroLegCand))) {
		scanf("%d",&nroLegCand);
		fflush(stdin);
	}
}

//    Objetivo:   Verifica se escolha de candidatovalida é válido
//    Parâmetros: escolha de candidato
//    Retorno:    escolha de candidato válido é válido ou não
int escolhaCandInvalida(int nroLegCand) {
	//Declarações locais
	FILE *arquivo;
	infoCandidato candidato;
	int aux = 0;
	//Instruções
	arquivo = fopen(NOMEARQUIVO,"rb");
	if(arquivo == NULL) {
		imprimeAviso("Erro ao abrir arquivo!",LINHADOSAVISOS);
		getch();
		return 0;
	} else {
		if(nroLegCand <= MINLEGENDA || nroLegCand >= MAXLEGENDA) {
			imprimeAviso("Inválido! Informe valor maior que ",LINHADOSAVISOS);
			printf("%d e menor %d! ",MINLEGENDA,MAXLEGENDA);
			fecharArquivo(arquivo);
			return 0;
		}
		while(fread(&candidato,sizeof(candidato),1, arquivo) == 1) {
			if(nroLegCand == candidato.numeroLegenda) {
				fecharArquivo(arquivo);
				return aux;
			}
			else
				aux++;
		}
		imprimeAviso("Inválido! Digite o n° de legenda existente: ", LINHADOSAVISOS);
		fecharArquivo(arquivo);
		return 0;
	}
}

//    Objetivo:   Mostrar dados de um candidato na tela
//    Parâmetros: Nome, Número da legenda, Sigla do partido e situação na Lava Jato do candidato
//    Retorno:    Nenhum
void mostraCandidato(infoCandidato *candidato) {
	//Declarações locais
	int aux = 6;
	//Instruções
	imprimeMoldura();
	moverCursor(POSMENU, ++aux);
	printf("1. Nome:                  %s",candidato->nome);
	moverCursor(POSMENU, ++aux);
	printf("2. número de legenda:     %d (apagará o candidato)",candidato->numeroLegenda);
	moverCursor(POSMENU, ++aux);
	printf("3. sigla do partido:      %s",candidato->siglaCandidato);
	moverCursor(POSMENU, ++aux);
	printf("4. Situação na Lava Jato: %s",candidato->lavaJato == 's' ? "Lava Jato" : "Ficha limpa");
	moverCursor(POSMENU, aux+2);
	printf("0. Sair e salvar dados do candidatos: ");
}

//    Objetivo:   Apagar um candidato
//    Parâmetros: Qual candidato será apagado
//    Retorno:    Nenhum
void apagarCandidato(int qualCand) {
	//Declarações locais
	int nroRegistros = calculaQtdRegistros(), aux = 0;
	infoCandidato candidato;
	long int tamBitesEstrut = sizeof(candidato);
	FILE *arquivo, *novoArquivo;
	//Instruções
	arquivo = fopen(NOMEARQUIVO,"rb");
	if(arquivo == NULL || nroRegistros == 0) {
		imprimeAviso("Nenhum candidato foi cadastrado ou arquivo não foi encontrado!",LINHADOSAVISOS);
		getch();
	} else {
		novoArquivo = fopen("novoEleicao.bin","wb");
		if(novoArquivo == NULL) {
			imprimeAviso("Erro ao apagar candidato (não foi possível criar arquivo de suporte para deletar candidato)",LINHADOSAVISOS);
			getch();
		} else {
			while (fread(&candidato,tamBitesEstrut,1, arquivo) == 1) {
				if(aux != qualCand)
					fwrite(&candidato,tamBitesEstrut,1, novoArquivo);
				aux++;
			}
			fecharArquivo(arquivo);
			if(remove(NOMEARQUIVO)) {
				imprimeAviso("Erro ao deletar arquivo!",LINHADOSAVISOS);
				getch();
			}
			fecharArquivo(novoArquivo);
			if (rename("novoEleicao.bin", NOMEARQUIVO)) {
				imprimeAviso("Erro ao renomear arquivo!",LINHADOSAVISOS);
				getch();
			}
		}
	}
}

//    Objetivo:   Salvar cadastro de um funcionário em ordem crescente pelo nome
//    Parâmetros: Nome, Número da legenda, Sigla do partido e situação na Lava Jato do candidato, e arquivos de candidato
//    Retorno:    Nenhum
void ordenaCandidato(char ordem) {
	//Declarações locais
	int nroRegistros = calculaQtdRegistros(), aux1, aux2;
	infoCandidato candidato[nroRegistros], candidatoTroca;
	long int tamEstrutura = sizeof(candidato[0]);
	FILE *arquivoCandidato;
	//Instruções
	arquivoCandidato = fopen(NOMEARQUIVO,"a+b");
	if (arquivoCandidato == NULL) {
		imprimeAviso("Ocorreu um erro ao tentar abrir arquivo!",LINHADOSAVISOS);
		getch();
	} else if(nroRegistros == 0){
		imprimeAviso("Nenhum candidato foi cadastrado!",LINHADOSAVISOS);
		getch();
	} else {
		if(fread(&candidato, tamEstrutura, nroRegistros, arquivoCandidato) != nroRegistros) {
			imprimeAviso("Erro ao ler arquivos!",LINHADOSAVISOS);
			getch();
			fecharArquivo(arquivoCandidato);
		} else {
			if(ordem == 'c') {
				for (aux1 = 0; aux1<nroRegistros-1; aux1++) {
					for (aux2 = aux1+1; aux2<nroRegistros; aux2++) {
						if (strcmp(candidato[aux1].nome , candidato[aux2].nome) == 1) {
							candidatoTroca = candidato[aux1];
							candidato[aux1] = candidato[aux2];
							candidato[aux2] = candidatoTroca;
						}
					}
				}
			} else {
				for (aux1 = 0; aux1<nroRegistros-1; aux1++) {
					for (aux2 = aux1+1; aux2<nroRegistros; aux2++) {
						if (strcmp(candidato[aux1].nome , candidato[aux2].nome) == -1) {
							candidatoTroca = candidato[aux1];
							candidato[aux1] = candidato[aux2];
							candidato[aux2] = candidatoTroca;
						}
					}
				}
			}
			fecharArquivo(arquivoCandidato);
			arquivoCandidato = fopen(NOMEARQUIVO,"wb");
			if(arquivoCandidato == NULL) {
				imprimeAviso("Não foi encontrado arquivo para ser removido",LINHADOSAVISOS);
				getch();
			} else {
				rewind(arquivoCandidato);
				if(fwrite(&candidato, tamEstrutura, nroRegistros, arquivoCandidato) != nroRegistros) {
					imprimeAviso("Erro ao salvar arquivos!",LINHADOSAVISOS);
					getch();
				}
				fecharArquivo(arquivoCandidato);
			}
		}
	}
}

//    Objetivo:   Contar quantos registros foram feitos
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
int calculaQtdRegistros(void) {
	//Declarações locais
	FILE *arquivo;
	int qtdRegistros = 0;
	infoCandidato candidato;
	//Instruções
	arquivo = fopen(NOMEARQUIVO,"rb");
	if(arquivo == NULL) {
		return 0;
	} else {
		fseek(arquivo,0,SEEK_END);
		qtdRegistros = ftell(arquivo) / sizeof(candidato);
		fecharArquivo(arquivo);
		return qtdRegistros;
	}
}

//    Objetivo:   Mostrar candidatos cadastrados
//    Parâmetros: Como será mostrados os candidatos (ordem crescente, decrescente ou os que estão na lavajato)
//    Retorno:    Nenhum
void listarCandidatos(char modo) {
	//Declarações locais
	char ordem = modo;
	int qtdRegistros = calculaQtdRegistros();
	int aux, contador, acumulador;
	int pagAtual = 1, nroPaginas = qtdRegistros/NROREGPORPAG;
	infoCandidato candidato;
	long int tamBitesEstrut = sizeof(candidato);
	FILE *arquivoParaListar;
	//Instruções
	arquivoParaListar = fopen(NOMEARQUIVO,"rb");
	if(qtdRegistros%NROREGPORPAG)
		nroPaginas++;

	if (arquivoParaListar == NULL) {
		imprimeAviso("Erro! Não foi encontrado arquivo para abrir!",LINHADOSAVISOS);
		getch();
	} else if(qtdRegistros == 0){
		imprimeAviso("Nenhum candidato foi cadastrado!",LINHADOSAVISOS);
		getch();
	} else if(NROREGPORPAG > (NROLINHASTELA-6)){
		imprimeAviso("Erro ao mostrar candidatos pois o n° de candidatos por pág. a ser mostrado é superior ao n° de linhas",LINHADOSAVISOS);
		getch();
	} else {
		imprimeMoldura();
		if(ordem == 'p') { // caso for 'p', é perguntado ao usuário qual ordem mostrar candidatos
			imprimeAviso("Pressione 'c' para ordem crescente ou 'd' para decrescente: ",LINHADOSAVISOS);
			ordem = getch();
			fflush(stdin);
			ordem = tolower(ordem);
			ordem = validaOpcaoOrdem(ordem);
		}
		ordenaCandidato(ordem);
		do {
			aux = 3;
			acumulador = aux;
			limparLinha(LINHADOSAVISOS);
			moverCursor(2,LINHADOSAVISOS);
			printf("  Nome                                           n° de legenda   Sigla do Partido     Envol. Lava Jato");
			if(ordem != 'l') { // lista candidatos em ordem crescente/decrescente
				fseek(arquivoParaListar, ((pagAtual-1)*NROREGPORPAG)*tamBitesEstrut, SEEK_SET);
				for(contador = 0; fread(&candidato,tamBitesEstrut,1, arquivoParaListar) && contador<NROREGPORPAG; contador++)
					mostraCandidatoPorLinha(&candidato, ++aux);
			}else { // lista candidatos na lava jato
				fseek(arquivoParaListar, (pagAtual-1)*tamBitesEstrut, SEEK_SET);
				for(contador = 0; fread(&candidato,tamBitesEstrut,1, arquivoParaListar) && contador<NROREGPORPAG; contador++)
					if(candidato.lavaJato == 's')
						mostraCandidatoPorLinha(&candidato, ++acumulador);
			}
			mostrarLinhasListagem();

			limparLinha(NROLINHASTELA-1);
			moverCursor(3,NROLINHASTELA-1);
			printf("Página %d de %d     Digite a pág. que deseja acessar ou 0 para sair: ",pagAtual,nroPaginas);
			scanf("%d",&pagAtual);
			fflush(stdin);
			pagAtual = validaPagAtual(pagAtual, nroPaginas);
			imprimeMoldura();
		}while(pagAtual != 0);

		fecharArquivo(arquivoParaListar);
	}
}

//    Objetivo:   Validar página da mostragem dos candidatos
//    Parâmetros: página e número de páginas total
//    Retorno:    página válida
int validaPagAtual(int pagAtual, int nroPaginas) {
	//Instruções
	while(pagAtual < 0 || pagAtual > nroPaginas) {
		limparLinha(NROLINHASTELA-1);
		moverCursor(3,NROLINHASTELA-1);
		printf("Inválido! Digite valor entre 1 e %d ou 0 para sair: ",nroPaginas);
		scanf("%d",&pagAtual);
		fflush(stdin);
	}
	return pagAtual;
}

//    Objetivo:   Mostra dados de um candidato
//    Parâmetros: Nome, Número da legenda, Sigla do partido e situação na Lava Jato do candidato e em que linha mostrar os dados
//    Retorno:    Nenhum
void mostraCandidatoPorLinha(infoCandidato *candidato, int linha) {
	//Instruções
	imprimeLinha(linha,'p');
	moverCursor(4,linha);
	printf(" %s ",candidato->nome);
	moverCursor(52,linha);
	printf(" %d ", candidato->numeroLegenda);
	moverCursor(68,linha);
	printf(" %s ", candidato->siglaCandidato);
	moverCursor(89,linha);
	printf(" %s ", candidato->lavaJato == 's' ? "Lava Jato" : "Ficha limpa");
}

//    Objetivo:   Mostrar linhas verticais da listagem dos candidatos
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void mostrarLinhasListagem(void) {
	//Instruções
	setlocale(LC_ALL,"C");
	imprimeLinha(49, 'v');
	imprimeLinha(65, 'v');
	imprimeLinha(86, 'v');
	setlocale(LC_ALL,"Portuguese");
}

//    Objetivo:   Valida opção de listagem dos candidatos
//    Parâmetros: opção de listagem dos candidatos
//    Retorno:    opção de listagem dos candidatos válido
char validaOpcaoOrdem(char modo) {
	//Instruções
	while(modo != 'c' && modo != 'd') {
		imprimeAviso("Inválido! Pressione 'c' para ordem crescente ou 'd' para decrescente: ",LINHADOSAVISOS);
		modo = getch();
		fflush(stdin);
		modo = tolower(modo);
	}
	return modo;
}

//    Objetivo:   Valida situação na lava jato do candidato
//    Parâmetros: situação na lava jato do candidato
//    Retorno:    Nenhum
void validaLavaJato(char *lavaJato) {
	//Instruções
	fflush(stdin);
	*lavaJato = tolower(*lavaJato);
	while (*lavaJato != 's' && *lavaJato != 'n') {
		limparLinha(5);
		moverCursor(LOCAL_LEITURA);
		printf("Inválido! Digite 's' para sim ou 'n' para não: ");
		*lavaJato = getch();
	}
}

//    Objetivo:   Mostrar menu de opções
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void mostrarMenu(void) {
	//Declarações locais
	int aux = 6;
	//Instruções
	imprimeMoldura();
	imprimeAviso("--xxXX Bem vindo ao programa de cadastro de candidatos à presidência XXxx--", LINHADOSAVISOS);
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
	moverCursor(3, NROLINHASTELA-1);
	printf("Total de registros: %d",calculaQtdRegistros());
	imprimeAviso("Digite uma opção: ",aux+4);
}

//    Objetivo:   Validar nome do candidato
//    Parâmetros: Nome do candidato
//    Retorno:    Nenhum
void validaNomeCandidato(char *nomeCandidato) {
	//Instruções
	while(nomeInvalido(nomeCandidato)) {   //  a mensagem que aparece informando o que o
		limparLinha(5);//                        candidato errou está na função "nomeInvalido"
		moverCursor(LOCAL_LEITURA);
		fgets(nomeCandidato,MAXNOME,stdin);
		fflush(stdin);
		ajustaTerminador(nomeCandidato);
	}
}

//    Objetivo:   Verifica se o nome é válido
//    Parâmetros: Nome do candidato
//    Retorno:    se nome é válido ou não
int nomeInvalido(char *nomeCandidato) {
	//Declarações locais
	int aux;
	//Instruções
	if(strlen(nomeCandidato) < 2) {
		imprimeAviso("Inválido! Nome deve ser maior que 1. Digite novamente: ",LINHADOSAVISOS);
		return 1;
	}
	if(*nomeCandidato == ' ') {
		imprimeAviso("Inválido! Nome não deve conter espaço no começo. Digite novamente: ",LINHADOSAVISOS);
		return 1;
	}
	for(aux = 0; *(nomeCandidato+aux); aux++) {
		if(!isalpha(*(nomeCandidato+aux)) && *(nomeCandidato+aux) != ' ') {
			imprimeAviso("Inválido! Nome deve conter somente letras. Digite novamente: ",LINHADOSAVISOS);
			return 1;
		}
	}
	return 0;
}

//    Objetivo:   Validar sigla do partido do candidato
//    Parâmetros: Sigla do partido do candidato
//    Retorno:    Nenhum
void validaSiglaCandidato(char *sigla) {
	//Instruções
	while(siglaCandInvalido(sigla)) {   //  a mensagem que aparece informando em que o
		limparLinha(5);//                    candidato errou está na função "siglaCandidatoInvalido"
		moverCursor(LOCAL_LEITURA);
		fgets(sigla,MAXPARTIDO,stdin);
		fflush(stdin);
		ajustaTerminador(sigla);
	}
}

//    Objetivo:   Verifica se sigla do candidato é válido
//    Parâmetros: Sigla do candidato
//    Retorno:    se a sigla é válido ou não
int siglaCandInvalido(char *sigla) {
	//Declarações locais
	FILE *arquivo;
	infoCandidato candidato;
	int aux;
	//Instruções
	if(strlen(sigla) <= 1) {
		imprimeAviso("Inválido! Sigla do partido deve ser maior que 1. Digite novamente: ",LINHADOSAVISOS);
		return 1;
	}
	for(aux = 0; *(sigla+aux); aux++) {
		if(!isalpha(*(sigla+aux))) {
			imprimeAviso("Inválido! Sigla deve conter somente letras e não haver espaços. Digite novamente: ",LINHADOSAVISOS);
			return 1;
		}
	}


	arquivo = fopen(NOMEARQUIVO,"rb");
	if(arquivo == NULL) {
		imprimeAviso("Erro ao abrir arquivo!",LINHADOSAVISOS);
		getch();
		return 1;
	} else {
		stringParaMaiuscula(sigla);
		while(fread(&candidato,sizeof(candidato),1, arquivo) == 1) {
			if(strcmp(sigla, candidato.siglaCandidato) == 0) {
				imprimeAviso("Sigla do partido já existe. Informe outra Sigla: ",LINHADOSAVISOS);
				fecharArquivo(arquivo);
				return 1;
			}
		}
	}


	fecharArquivo(arquivo);
	return 0;
}
//    Objetivo:   Validar número de legenda do candidato
//    Parâmetros: legenda do candidato
//    Retorno:    Nenhum
void validaNumeroLegenda(int *numeroLegenda) {
	//Instruções
	while(numeroLegendaValido(*numeroLegenda)) {
		limparLinha(5);
		moverCursor(LOCAL_LEITURA);
		scanf("%d",numeroLegenda);
		fflush(stdin);
	}
}

//    Objetivo:   Verifica se um número de legenda é válido
//    Parâmetros: legenda do candidato
//    Retorno:    se número de legenda é válido ou não
int numeroLegendaValido(int numeroLegenda) {
	//Declarações locais
	FILE *arquivo;
	infoCandidato candidato;
	//Instruções
	if(numeroLegenda <= MINLEGENDA || numeroLegenda >= MAXLEGENDA) {
		imprimeAviso("Inválido! Informe valor maior que ",LINHADOSAVISOS);
		printf("%d e menor %d! ",MINLEGENDA,MAXLEGENDA);
		return 1;
	}
	arquivo = fopen(NOMEARQUIVO,"rb");
	if(arquivo == NULL) {
		imprimeAviso("Erro ao abrir arquivo!",LINHADOSAVISOS);
		getch();
		return 1;
	} else {
		while(fread(&candidato,sizeof(candidato),1, arquivo) == 1) {
			if(numeroLegenda == candidato.numeroLegenda) {
				imprimeAviso("Número de legenda já existe. Informe outro número: ",LINHADOSAVISOS);
				fecharArquivo(arquivo);
				return 1;
			}
		}
		fecharArquivo(arquivo);
		return 0;
	}
}

//    Objetivo:   Imprimir uma moldura
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void imprimeMoldura(void) {
	//Instruções
	setlocale(LC_ALL,"C");
	system("cls");
	imprimeLinha(1, 'h');
	imprimeLinha(3, 'h');
	imprimeLinha(NROLINHASTELA, 'h');
	imprimeLinha(NROLINHASTELA-2, 'h');
	imprimeLinha(1, 'v');
	imprimeLinha(NROCOLUNASTELA, 'v');
	setlocale(LC_ALL,"Portuguese");
}

//    Objetivo:   Imprimir uma linha
//    Parâmetros: Local do começo da linha e posição (horizontal ou vertical)
//    Retorno:    Nenhum
void imprimeLinha(int localDaLinha, char posicao ) {
	//Declarações locais
	int aux;
	//Instruções
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
		case 'p': // o caso para imprimir linha pontilhada
			moverCursor(2, localDaLinha);
			for(aux = 2; aux<NROCOLUNASTELA; aux++) {
				printf("_");
			}
			break;
		default:
			imprimeAviso("Erro ao imprimir linha!",LINHADOSAVISOS-2);
			getch();
	}
}

//    Objetivo:   Mostrar na tela um aviso
//    Parâmetros: Aviso e em qual linha aparecerá o aviso
//    Retorno:    Nenhum
void imprimeAviso(char aviso[], int linha) {
	//Declarações locais
	int aux;
	//Instruções
	if(strlen(aviso) > NROCOLUNASTELA-2) {
		imprimeAviso("Erro grave ao mostrar mensagem! mensagem tem mais de ",linha);
		printf("%d caracteres.",NROCOLUNASTELA-2);
		getch();
	} else {
		limparLinha(linha);
		moverCursor((NROCOLUNASTELA - strlen(aviso)) / 2 , linha);
		printf("%s",aviso);
	}
}

//    Objetivo:   Limpar linha
//    Parâmetros: Qual linha será limpa
//    Retorno:    Nenhum
void limparLinha(int linha) {
	//Declarações locais
	int aux;
	//Instruções
	moverCursor( 2 , linha);
	for(aux = 2; aux<NROCOLUNASTELA; aux++)
		printf(" ");
}

//    Objetivo:   Fecha o arquivo que guarda informações dos candidatos
//    Parâmetros: Arquivo
//    Retorno:    Nenhum
void fecharArquivo(FILE *arquivoCandidato) {
	//Instruções
	if (fclose(arquivoCandidato) != 0) {
		imprimeAviso("Erro ao fechar arquivo.",LINHADOSAVISOS);
		getch();
	}
}

//    Objetivo:   Apagar todos os registros dos candidatos
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void apagarArquivo(void) {
	//Declarações locais
	char resposta;
	//Instruções
	imprimeMoldura();
	imprimeAviso("Tem certeza que quer apagar todos os registros?", LINHADOSAVISOS);
	imprimeAviso("Digite 's' para sim ou 'n' para não: ", LINHADOSAVISOS+5);
	resposta = getch();
	resposta = tolower(resposta);
	resposta = validaEscolhaExcluir(resposta);
	if(resposta == 's') {
		if(!remove(NOMEARQUIVO)) {
			imprimeAviso("Registros removidos com sucesso!",LINHADOSAVISOS);
        	getch();
		} else {
			imprimeAviso("Erro ao remover arquivos!",LINHADOSAVISOS);
        	getch();
		}
	} else {
		imprimeAviso("OPERAÇÃO CANCELADA !!!",LINHADOSAVISOS);
        getch();
	}
}

//    Objetivo:   Validar escolha de excluir arquivos
//    Parâmetros: escolha de excluir arquivos
//    Retorno:    escolha de excluir arquivos válido
char validaEscolhaExcluir(char resposta) {
	while(resposta != 's' && resposta != 'n') {
		imprimeAviso("Inválido! Digite 's' para sim ou 'n' para não: ", LINHADOSAVISOS+5);
		resposta = getch();
		resposta = tolower(resposta);
	}
	return resposta;
}
//    Objetivo:   Mudar o tamanho da tela do programa
//    Parâmetros: Nenhum
//    Retorno:    Nenhum
void mudaTamanhoTela(void) {
	//Declarações locais
	char novaTela[40] = "";
	//Instruções
	sprintf(novaTela, "mode con:cols=%d lines=%d", NROCOLUNASTELA, NROLINHASTELA);
	system(novaTela);

}

//Objetivo: Ajustar o terminador de uma string
//Parâmetro: String
//Retorno: Nenhum
void ajustaTerminador(char *string) {
	//Instruções
    if(string[strlen(string)-1]=='\n')
    	string[strlen(string)-1]='\0';
}


//Objetivo: Faz uma string ficar toda minúscula
//Parâmetro: String
//Retorno: Nenhum
void stringParaMinuscula(char *string) {
	//Declarações locais
	int aux;
	//Instruções
    for(aux = 0; *(string+aux); aux++)
    	*(string+aux) = tolower(*(string+aux));
}


//Objetivo: Faz uma string ficar toda maiúscula
//Parâmetro: String
//Retorno: Nenhum
void stringParaMaiuscula(char *string) {
	//Declarações locais
	int aux;
	//Instruções
    for(aux = 0; *(string+aux); aux++)
    	*(string+aux) = toupper(*(string+aux));
}


//Objetivo: Mover cursor para um local da tela
//Parâmetro: A linha e coluna para o qual deve mover
//Retorno: Nenhum
void moverCursor(int coluna, int linha) {
	//Instruções
	COORD coord;
	coord.X = coluna-1;
	coord.Y = linha-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

