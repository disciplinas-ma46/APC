// Aluno : Gabriel Vieira Fernandes

/*
 // Síntese
//  Objetivo: Mostrar os empregados com menos meses de trabalho de uma empresa
//  Entrada : Matricula e meses de trabalho dos funcionarios
//  Saída   : 3 funcionarios mais recentes


principal
	// Declarações
	inteiro aux,matricula[100],meses[100];
	inteiro tamanhoTotal;  //CONSTANTE
	inteiro totalEmpre;  //CONSTANTE
	// Instruções
	tamanhoTotal = 100;
	totalEmpre = 3;
	aux = 0;
	faca
		escreval("Digite a matrícula funcional inteira do ",aux+1," empregado(ou 0 para parar a entrada de dados): ");
		leia(matricula[aux]);
		matricula[aux] = validaMatricula(aux,matricula);
		limpaTela();
		se(matricula[aux] != 0)entao
			escreval("Digite o número de meses de trabalho do ",aux+1," empregado: ");
			leia(meses[aux]);
			meses[aux] = validaMeses(aux,meses);
			limpaTela();
		fimSe
		aux = aux + 1;
	enquanto(aux < tamanhoTotal e matricula[aux-1] != 0);
	ordenaEmpregados(matricula,meses,aux-1);
	mostraResultado(matricula,totalEmpre);
fimPrincipal
//==========SUBALGORITMOS==========//
//  Objetivo: Validar a matricula inserida pelo usuario
//  Parâmetro: Total de matriculas ate o momento e matriculas
//  Retorno: matricula válida

funcao inteiro validaMatricula(inteiro aux, inteiro matricula[])
	enquanto(matricula[aux] <0 ou verificaIgualdade(matricula,aux))faca
		escreval("Digite uma matricula diferente das anteriores e maior que 0(ou 0 para parar a entrada de dados): ");
		leia(matricula[aux]);
	fimEnquanto
	retorna matricula[aux];
fimFuncao

//  Objetivo: Verificar se há valores iguais no vetor
//  Parâmetro: Vetor de numeros inteiros e total de valores
//  Retorno: se há ou não valores iguais

funcao logico verificaIgualdade(inteiro vetor[],inteiro total)
	inteiro cont,aux;
	se(total != 0)entao
		para(cont de 0 ate total-1 passo 1)faca
			para(aux de cont+1 ate total passo 1)faca
				se(vetor[cont] == vetor[aux])entao
					retorna verdadeiro;
				fimSe
			fimPara
		fimPara
	fimSe
	retorna falso;
fimFuncao

//  Objetivo: Validar os numero meses inserido pelo usuario
//  Parâmetro: Meses ja cadastrados e total de cadastros ate o momento
//  Retorno: Numero valido

funcao inteiro validaMeses(inteiro aux,inteiro meses[])
	enquanto(meses[aux] <=0 ou verificaIgualdade(meses,aux))faca
		escreval("Digite um mes diferente dos anteriores e maior que 0: ");
		leia(meses[aux]);
	fimEnquanto
	retorna meses[aux];
fimFuncao

//  Objetivo: Mostrar os 3 empregados com menos meses na empresa
//  Parâmetro: Matriculas e total de empregados
//  Retorno: Nenhum

procedimento mostraResultado(inteiro matricula[],inteiro totalEmpre)
	inteiro aux;
	limpaTela();
	escreval("Empregados mais recentes");
	para(aux de 0 ate totalEmpre-1 passo 1)faca
		escreval(matricula[aux]);
	fimPara
fimProcedimento

//  Objetivo: Colocar os empregados em ordem crescente de meses de trabalho
//  Parâmetro: Matriculas, meses de cada empregado e total de empregados
//  Retorno: Nenhum

procedimento ordenaEmpregados(inteiro matricula[],inteiro meses[],inteiro total)
	inteiro aux,cont,troca;
	para(aux de 0 ate total-2 passo 1)faca
		para(cont de aux+1 ate total-1 passo 1)faca
			se(meses[aux] > meses[cont])entao
				troca = matricula[aux];
				matricula[aux] = matricula[cont];
				matricula[cont] = troca;
				troca = meses[aux];
				meses[aux] = meses[cont];
				meses[cont] = troca;
			fimSe
		fimPara
	fimPara
fimProcedimento

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>

int validaMatricula(int aux, int matricula[]);
int verificaIgualdade(int vetor[], int total);
int validaMeses(int aux,int meses[]);
void mostraResultado(int matricula[],int totalEmpre);
void ordenaEmpregados(int matricula[],int meses[],int total);

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
// Declaracoes
	
	const int tamanhoTotal = 100; 
	int aux = 0, matricula[tamanhoTotal], meses[tamanhoTotal];
	const int totalEmpre = 3;  

// Instrucoes

	do{
		printf("Digite a matrícula funcional inteira do %d° empregado(ou 0 para parar a entrada de dados): \n", aux+1);
		scanf("%d", &matricula[aux]);
		matricula[aux] = validaMatricula(aux, matricula);
		system("cls");
		if(matricula[aux] != 0){
			printf("Digite o número de meses de trabalho do %d° empregado: \n", aux+1);
			scanf("%d", &meses[aux]);
			meses[aux] = validaMeses(aux, meses);
			system("cls");
		}
		aux = aux + 1;
	}while(aux < tamanhoTotal && matricula[aux-1] != 0);
	ordenaEmpregados(matricula, meses, aux-1);
	mostraResultado(matricula, totalEmpre);

    getch();
    return 0;
}


//==========SUBALGORITMOS==========//

//  Objetivo: Validar a matricula inserida pelo usuario
//  Parâmetro: Total de matriculas ate o momento e matriculas
//  Retorno: matricula válida

int validaMatricula(int aux, int matricula[]){
	while(matricula[aux] <0 || verificaIgualdade(matricula,aux)){
		printf("Digite uma matricula diferente das anteriores e maior que 0(ou 0 para parar a entrada de dados): \n");
		scanf("%d", &matricula[aux]);
	}
	return matricula[aux];
}

//  Objetivo: Verificar se há valores iguais no vetor
//  Parâmetro: Vetor de numeros inteiros e total de valores
//  Retorno: se há ou não valores iguais

int verificaIgualdade(int vetor[], int total){
	int cont,aux;
	if(total != 0){
		for(cont = 0; cont <= total-1; cont++){
			for(aux = cont+1; aux <= total; aux++){
				if(vetor[cont] == vetor[aux]){
					return 1;
				}
			}
		}
	}
	return 0;
}

//  Objetivo: Validar os numero meses inserido pelo usuario
//  Parâmetro: Meses ja cadastrados e total de cadastros ate o momento
//  Retorno: Numero valido

int validaMeses(int aux,int meses[]){
	while(meses[aux] <=0 || verificaIgualdade(meses,aux)){
		printf("Digite um mes diferente dos anteriores e maior que 0: ");
		scanf("%d", &meses[aux]);
	}
	return meses[aux];
}

//  Objetivo: Mostrar os 3 empregados com menos meses na empresa
//  Parâmetro: Matriculas e total de empregados
//  Retorno: Nenhum

void mostraResultado(int matricula[],int totalEmpre){
	int aux;
	system("cls");
	puts("Empregados mais recentes");
	for(aux = 0; aux <= totalEmpre-1; aux++)
		printf("%d\n", matricula[aux]);
}

//  Objetivo: Colocar os empregados em ordem crescente de meses de trabalho
//  Parâmetro: Matriculas, meses de cada empregado e total de empregados
//  Retorno: Nenhum

void ordenaEmpregados(int matricula[],int meses[],int total){
	int aux, cont, troca;
	for(aux = 0; aux <= total-2; aux++){
		for(cont = aux+1; cont <= total-1; cont++){
			if(meses[aux] > meses[cont]){
				troca = matricula[aux];
				matricula[aux] = matricula[cont];
				matricula[cont] = troca;
				troca = meses[aux];
				meses[aux] = meses[cont];
				meses[cont] = troca;
			}
		}
	}
}
