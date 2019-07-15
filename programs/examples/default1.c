//NOME DO ALUNO:  Marcelo Ara�jo dos Santos

//  S�ntese
//    Objetivo: 
//    Entrada:  
//    Sa�da:    

int main (void) {
	//Declara��es
	
	
	//Instru��es
	
}


































/* fax
				fgets(sigla,MAXPARTIDO,stdin);
				fread(&candidato,sizeof(candidato),1, arquivo);
				fclose(arquivoCandidato)  0 = erro
				isalpha


*/




typedef struct {
	//blablabla();
}nomeStruct;



















































 fex

FILE *arquivo;
arquivoCandidato = fopen("nomearquivo","a+b"); // abre e cria caso � E
setlocale(LC_ALL, "Portuguese");




fix fix fix fix fix fix fix fix 

//    Objetivo:   Validar sigla do partido do candidato
//    Par�metros: Sigla do partido do candidato
//    Retorno:    Nenhum
void validaSiglaCandidato(char *sigla) {
	//Instru��es
	while(siglaCandInvalido(sigla)) {   //  a mensagem que aparece informando em que o 
		limparLinha(5);//                    candidato errou est� na fun��o "siglaCandidatoInvalido"
		moverCursor(3, 5);
		fgets(sigla,MAXPARTIDO,stdin);
		fflush(stdin);
		ajustaTerminador(sigla);
	}
}

//    Objetivo:   Verifica se sigla do candidato � v�lido
//    Par�metros: Sigla do candidato
//    Retorno:    se a sigla � v�lido ou n�o
int siglaCandInvalido(char *sigla) {
	//Declara��es locais
	int aux;
	//Instru��es
	if(strlen(sigla) <= 1) {
		imprimeAviso("Inv�lido! Sigla do partido deve ser maior que 1. Digite novamente: ",LINHADOSAVISOS);
		return 1;
	}
	for(aux = 0; *(sigla+aux); aux++) {
		if(!isalpha(*(sigla+aux))) {
			imprimeAviso("Inv�lido! Sigla deve conter somente letras e n�o haver espa�os. Digite novamente: ",LINHADOSAVISOS);
			return 1;
		}
	}
	return 0;
}




















































#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

#define 





































void ajustaTerminador(char *string);
int calculaQtdRegistros(void);
void ordenaCandidato(char ordem);
void stringParaMaiuscula(char *string);






































//Objetivo: Ajustar o terminador de uma string
//Par�metro: String
//Retorno: Nenhum
void ajustaTerminador(char *string) {
	//Instru��es
    if(string[strlen(string)-1]=='\n')
    	string[strlen(string)-1]='\0';
}






































//    Objetivo:   Contar quantos registros foram feitos
//    Par�metros: Nenhum
//    Retorno:    Nenhum
int calculaQtdRegistros(void) {
	//Declara��es locais
	FILE *arquivo;
	int qtdRegistros = 0;
	nomeStruct cand;
	//Instru��es
	arquivo = fopen("nomearquivo","rb");
	if(arquivo == NULL) {
		return 0;
	} else {
		fseek(arquivo,0,SEEK_END);
		qtdRegistros = ftell(arquivo) / sizeof(candidato);
		fclose(arquivo);
		return qtdRegistros;
	}
}







































void ordenaCandidato(char ordem) {
	//Declara��es locais
	int nroRegistros = calculaQtdRegistros(), aux1, aux2;
	infoCandidato candidato[nroRegistros], candidatoTroca;
	long int tamEstrutura = sizeof(candidatoTroca);
	FILE *arquivoCandidato;
	//Instru��es
	arquivoCandidato = fopen(NOMEARQUIVO,"a+b");
	if (arquivoCandidato == NULL) {
		printf("Ocorreu um erro ao tentar abrir arquivo!",LINHADOSAVISOS);
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
			for (aux1 = 0; aux1<nroRegistros-1; aux1++)
				for (aux2 = aux1+1; aux2<nroRegistros; aux2++)
					if (strcmp(candidato[aux1].nome , candidato[aux2].nome) == 1) {
						candidatoTroca = candidato[aux1];
						candidato[aux1] = candidato[aux2];
						candidato[aux2] = candidatoTroca;
					}
			
			
			fecharArquivo(arquivoCandidato);
			arquivoCandidato = fopen(NOMEARQUIVO,"wb");
			if(arquivoCandidato == NULL) {
				imprimeAviso("N�o foi encontrado arquivo para gravar dados",LINHADOSAVISOS);
				getch();
			} else {
				if(fwrite(&candidato, tamEstrutura, nroRegistros, arquivoCandidato) != nroRegistros) {
					imprimeAviso("Erro ao salvar arquivos!",LINHADOSAVISOS);
					getch();
				}
				fecharArquivo(arquivoCandidato);
			}
		}
	}
}

// fix **************************************************************************************************************************












//Objetivo: Faz uma string ficar toda mai�scula
//Par�metro: String
//Retorno: Nenhum
void stringParaMaiuscula(char *string) {
	//Declara��es locais
	int aux;
	//Instru��es
    for(aux = 0; *(string+aux); aux++)
    	*(string+aux) = toupper(*(string+aux));
}




















void ordenaCandidato(char ordem) {
	//Declara��es locais
	int nroRegistros = calculaQtdRegistros(), aux1, aux2;
	infoCandidato candidato[nroRegistros], candidatoTroca;
	long int tamEstrutura = sizeof(candidato[0]);
	FILE *arquivoCandidato;
	//Instru��es
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
				imprimeAviso("N�o foi encontrado arquivo para ser removido",LINHADOSAVISOS);
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
