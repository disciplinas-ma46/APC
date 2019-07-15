// Aluno : Marcelo Araújo dos Santos

/*
algoritmo aula6exer12;
// Síntese
//  Objetivo: Mostrar os empregados com menos meses de trabalho de uma empresa
//  Entrada : Matricula e meses de trabalho dos funcionarios
//  Saída   : 3 funcionarios mais recentes


principal
// Declaracoes
	
	inteiro tamanhoTotal; // CONSTANTE
	inteiro totalEmpre;   // CONSTANTE
	inteiro aux;
	inteiro matriculaEMeses[100][2]; //   As linhas é a capacidade total de funcionários
	//                                         e as colunas (2 no total) é a matrícula e meses, respectivamente

// Instrucoes
	tamanhoTotal = 100;
	totalEmpre = 3;
	aux = 0;
	faca
		escreva("Digite a matrícula funcional inteira do ", aux+1,"° empregado(ou 0 para parar a entrada de dados): ");
		leia(matriculaEMeses[aux][0]);
		matriculaEMeses[aux][0] = validaMatricula(aux, matriculaEMeses);
		limpaTela();
		se(matriculaEMeses[aux][0] != 0)entao
			escreva("Digite o número de meses de trabalho do ", aux+1,"° empregado: ");
			leia(matriculaEMeses[aux][1]);
			matriculaEMeses[aux][1] = validaMeses(aux, matriculaEMeses);
			limpaTela();
		fimSe
		aux = aux + 1;
	enquanto(aux < tamanhoTotal e matriculaEMeses[aux-1][0] != 0);
	ordenaEmpregados(matriculaEMeses, aux-1);
	mostraResultado(matriculaEMeses, totalEmpre, aux-1);

fimPrincipal

//==========SUBALGORITMOS==========//

//  Objetivo: Validar a matricula inserida pelo usuario
//  Parâmetro: Total de matriculas ate o momento e matriculas
//  Retorno: matricula válida
funcao inteiro validaMatricula(inteiro aux, inteiro matriculaEMeses[][2])
	enquanto(matriculaEMeses[aux][0] <0 ou verseicaIgualdade(0,matriculaEMeses,aux))faca
		escreval("Digite uma matricula dseerente das anteriores e maior que 0");
		escreva("(ou 0 para parar a entrada de dados): ");
		leia(matriculaEMeses[aux][0]);
	fimEnquanto
	retorna matriculaEMeses[aux][0];
fimFuncao

//  Objetivo: Verseicar se há valores iguais no vetor
//  Parâmetro: Vetor de numeros inteiroeiros e total de valores
//  Retorno: se há ou não valores iguais
funcao inteiro verseicaIgualdade(inteiro tipoDado, inteiro vetor[][2], inteiro total)
	inteiro cont,aux;
	se(total != 0)entao
		para(cont de 0 ate total-1 passo 1)faca
			para(aux de cont+1 ate total passo 1)faca
				se(vetor[cont][tipoDado] == vetor[aux][tipoDado])entao
					retorna 1;
				fimSe
			fimPara
		fimPara
	fimSe
	retorna 0;
fimFuncao

//  Objetivo: Validar os numero meses inserido pelo usuario
//  Parâmetro: Meses ja cadastrados e total de cadastros ate o momento
//  Retorno: Numero valido
funcao inteiro validaMeses(inteiro aux,inteiro matriculaEMeses[][2])
	enquanto(matriculaEMeses[aux][1] <=0 ou verseicaIgualdade(1,matriculaEMeses,aux))faca
		escreva("Digite um mes dseerente dos anteriores e maior que 0: ");
		leia(matriculaEMeses[aux][1]);
	fimEnquanto
	retorna matriculaEMeses[aux][1];
fimFuncao

//  Objetivo: Mostrar os 3 empregados com menos meses na empresa
//  Parâmetro: Matriculas, total de empregados para mostrar, e quantos empregados cadastrados
//  Retorno: Nenhum
procedimento mostraResultado(inteiro matriculaEMeses[][2],inteiro totalEmpre, inteiro qntEmpregados)
	inteiro aux;
	limpaTela();
	se(qntEmpregados >= 3)entao
		escreval("Empregados mais recentes");
		para(aux de 0 ate totalEmpre-1 passo 1)faca
			escreval(matriculaEMeses[aux][0]);
		fimPara
	senao
		se(qntEmpregados == 0)entao
			escreval("Nenhum funcionário foi cadastrado!");
		senao
			escreval("Menos que 3 empregados paraam cadastrados, sendo eles os mais recentes:");
			para(aux de 0 ate qntEmpregados-1 passo 1)faca
				escreval(matriculaEMeses[aux][0]);
			fimPara
		fimSe
	fimSe
fimProcedimento

//  Objetivo: Colocar os empregados em ordem crescente de meses de trabalho
//  Parâmetro: Matriculas e meses de cada empregado e total de empregados
//  Retorno: Nenhum
procedimento ordenaEmpregados(inteiro matriculaEMeses[][2],inteiro total)
	inteiro aux, cont, troca;
	para(aux de 0 ate total-2 passo 1)faca
		para(cont de aux+1 ate total-1 passo 1)faca
			se(matriculaEMeses[aux][1] > matriculaEMeses[cont][1])entao
				troca = matriculaEMeses[aux][0];
				matriculaEMeses[aux][0] = matriculaEMeses[cont][0];
				matriculaEMeses[cont][0] = troca;
				
				troca = matriculaEMeses[aux][1];
				matriculaEMeses[aux][1] = matriculaEMeses[cont][1];
				matriculaEMeses[cont][1] = troca;
			fimSe
		fimPara
	fimPara
fimProcedimento

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>

int validaMatricula(int aux, int matriculaEMeses[][2]);
int verificaIgualdade(int tipoDado, int vetor[][2], int total);
int validaMeses(int aux,int matriculaEMeses[][2]);
void mostraResultado(int matriculaEMeses[][2],int totalEmpre, int qntEmpregados);
void ordenaEmpregados(int matriculaEMeses[][2],int total);

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
// Declaracoes
	
	const int tamanhoTotal = 100;
	int aux = 0;
	int matriculaEMeses[tamanhoTotal][2]; //   As linhas é a capacidade total de funcionários
	//                                         e as colunas (2 no total) é a matrícula e meses, respectivamente
	const int totalEmpre = 3;  

// Instrucoes

	do{
		printf("Digite a matrícula funcional inteira do %d° empregado\n(ou 0 para parar a entrada de dados): ", aux+1);
		scanf("%d", &matriculaEMeses[aux][0]);
		matriculaEMeses[aux][0] = validaMatricula(aux, matriculaEMeses);
		system("cls");
		if(matriculaEMeses[aux][0] != 0){
			printf("Digite o número de meses de trabalho do %d° empregado: ", aux+1);
			scanf("%d", &matriculaEMeses[aux][1]);
			matriculaEMeses[aux][1] = validaMeses(aux, matriculaEMeses);
			system("cls");
		}
		aux = aux + 1;
	}while(aux < tamanhoTotal && matriculaEMeses[aux-1][0] != 0);
	ordenaEmpregados(matriculaEMeses, aux-1);
	mostraResultado(matriculaEMeses, totalEmpre, aux-1);

    getch();
    return 0;
}


//==========SUBALGORITMOS==========//

//  Objetivo: Validar a matricula inserida pelo usuario
//  Parâmetro: Total de matriculas ate o momento e matriculas
//  Retorno: matricula válida
int validaMatricula(int aux, int matriculaEMeses[][2]){
	while(matriculaEMeses[aux][0] <0 || verificaIgualdade(0,matriculaEMeses,aux)){
		printf("Digite uma matricula diferente das anteriores e maior que 0(ou 0 para parar a entrada de dados): \n");
		scanf("%d", &matriculaEMeses[aux][0]);
	}
	return matriculaEMeses[aux][0];
}

//  Objetivo: Verificar se há valores iguais no vetor
//  Parâmetro: Vetor de numeros inteiros e total de valores
//  Retorno: se há ou não valores iguais
int verificaIgualdade(int tipoDado, int vetor[][2], int total){
	int cont,aux;
	if(total != 0){
		for(cont = 0; cont <= total-1; cont++){
			for(aux = cont+1; aux <= total; aux++){
				if(vetor[cont][tipoDado] == vetor[aux][tipoDado]){
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
int validaMeses(int aux,int matriculaEMeses[][2]){
	while(matriculaEMeses[aux][1] <=0 || verificaIgualdade(1,matriculaEMeses,aux)){
		printf("Digite um mes diferente dos anteriores e maior que 0: ");
		scanf("%d", &matriculaEMeses[aux][1]);
	}
	return matriculaEMeses[aux][1];
}

//  Objetivo: Mostrar os 3 empregados com menos meses na empresa
//  Parâmetro: Matriculas, total de empregados para mostrar, e quantos empregados cadastrados
//  Retorno: Nenhum
void mostraResultado(int matriculaEMeses[][2],int totalEmpre, int qntEmpregados){
	int aux;
	system("cls");
	if(qntEmpregados >= 3) {
		puts("Empregados mais recentes");
		for(aux = 0; aux <= totalEmpre-1; aux++)
			printf("%d\n", matriculaEMeses[aux][0]);
	}
	else {
		if(qntEmpregados == 0) {
			puts("Nenhum funcionário foi cadastrado!");
		}
		else {
			puts("Menos que 3 empregados foram cadastrados, sendo eles os mais recentes:");
			for(aux = 0; aux <= qntEmpregados-1; aux++)
				printf("%d\n", matriculaEMeses[aux][0]);
		}
	}
}

//  Objetivo: Colocar os empregados em ordem crescente de meses de trabalho
//  Parâmetro: Matriculas e meses de cada empregado e total de empregados
//  Retorno: Nenhum
void ordenaEmpregados(int matriculaEMeses[][2],int total){
	int aux, cont, troca;
	for(aux = 0; aux <= total-2; aux++){
		for(cont = aux+1; cont <= total-1; cont++){
			if(matriculaEMeses[aux][1] > matriculaEMeses[cont][1]){
				troca = matriculaEMeses[aux][0];
				matriculaEMeses[aux][0] = matriculaEMeses[cont][0];
				matriculaEMeses[cont][0] = troca;
				
				troca = matriculaEMeses[aux][1];
				matriculaEMeses[aux][1] = matriculaEMeses[cont][1];
				matriculaEMeses[cont][1] = troca;
			}
		}
	}
}
