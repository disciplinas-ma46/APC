//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
algoritmo aula5exer9;
// S�ntese
//  Objetivo:  Calcular idade prov�vel do usu�rio a partir do seu ano de nascimento e ano atual
//  Entrada : Ano de nascimento e ano atual
//  Sa�da   : Idade calculada e classifica��o da idade

principal
	// Declara��es
	inteiro anoN,anoA;
	caracter continua;
	// Instru��es
	faca
		escreva("Digite o ano atual:");
		leia(anoA);
		anoA=validaAnoA(anoA);
		escreva("Digite o seu ano de nascimento:");
		leia(anoN);
	    anoN=validaAnoN(anoN,anoA);
		limpaTela();
		calculaIdade(anoA,anoN);
		escreva("Digite 'S' para informar outra idade ou qualquer tecla para finalizar:");
		leiaCaracter(continua);
		continua=maiusculoCaracter(continua);
		limpaTela();
	enquanto(continua=='S');
fimPrincipal

//==========SUBALGORITMOS==========//
//Objetivo: Validar ano atual
//Par�metro: Ano informado
//Retorno: Ano v�lido
funcao inteiro validaAnoA(inteiro ano)
	enquanto(ano<=0)faca
		escreva("Digite valor v�lido:");
		leia(ano);
	fimEnquanto
	retorna ano;
fimFuncao

//Objetivo: Validar ano de nascimento
//Par�metro: Ano de nascimento e ano atual
//Retorno: Ano v�lido
funcao inteiro validaAnoN(inteiro anoN,inteiro anoA)
	enquanto(anoN<=0 ou (anoA-anoN)<0)faca
		escreva("Digite um ano de nascimento menor ou igual ao ano atual:");
		leia(anoN);
	fimEnquanto
	retorna anoN;
fimFuncao

//Objetivo:Calcular idade prov�vel
//Par�metro: Ano de nascimento e ano atual
//Retorno: nenhum
procedimento calculaIdade(inteiro anoA,inteiro anoN)
	//Declara��es locais
	inteiro idade;
	inteiro nivel;
	//Instru��es locais
	idade=anoA-anoN;
	nivel=verificaNivel(idade,nivel);
	se(idade==0)entao
	  escreval("Pessoa viveu pelo menos um dia.");
	senao
	  escreval("Idade = ",idade);
	fimSe
	escolha (nivel)
	caso 1
	  escreval("==> CRIAN�A");
	  interrompa;
	caso 2
	  escreval("==> ADOLESCENTE");
	  interrompa;
	caso 3
	  escreval("==> JOVEM");
	  interrompa;
	caso 4
	  escreval("==> ADULTO");
	  interrompa;
	outroCaso
	  escreval("==> IDOSO");
	fimEscolha
fimProcedimento

//Objetivo:Identificar o n�vel da idade
//Par�metro: idade e n�vel
//Retorno: n�vel da idade
funcao inteiro verificaNivel(inteiro idade,inteiro nivel)
	se(idade <= 10)entao
		nivel=1;
	senao
		se(idade>10 e idade<18)entao
			nivel=2;
		senao
			se(idade>=18 e idade<25)entao
				nivel=3;
			senao
				se(idade>=25 e idade<=58)entao
					nivel=4;
				senao
					nivel=5;
				fimSe
			fimSe
		fimSe
	fimSe
	retorna nivel;
fimFuncao
*/

#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int validaAnoA(int ano);
int validaAnoN(int anoN,int anoA);
void calculaIdade(int anoA,int anoN);
int verificaNivel(int idade,int nivel);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARA��ES
	int anoN, anoA;
	char continua;
	
	//INSTRU��ES
	do {
		puts("Digite o ano atual:");
		scanf("%d",&anoA);
		anoA = validaAnoA(anoA);
		puts("Digite o seu ano de nascimento:");
		scanf("%d",&anoN);
	    anoN = validaAnoN(anoN, anoA);
		system("cls");
		calculaIdade(anoA,anoN);
		puts("\nDigite 'S' para informar outra idade ou qualquer tecla para finalizar:");
		continua = getch();
		continua = toupper(continua);
		system("cls");
	} while (continua == 'S');

	getch();
	return 0;
}

//==========     SUBALGORITMOS     ==========//

//Objetivo: Validar ano atual
//Par�metro: Ano informado
//Retorno: Ano v�lido
int validaAnoA(int ano) {
	while (ano <= 0) {
		puts("Digite valor v�lido:");
		scanf("%d",&ano);
	}
	return ano;
}

//Objetivo: Validar ano de nascimento
//Par�metro: Ano de nascimento e ano atual
//Retorno: Ano v�lido
int validaAnoN(int anoN,int anoA) {
	while(anoN<=0 || (anoA-anoN)<0) {
		puts("Digite um ano de nascimento menor ou igual ao ano atual:");
		scanf("%d",&anoN);
	}
	return anoN;
}

//Objetivo:Calcular idade prov�vel
//Par�metros: Ano de nascimento e ano atual
//Retorno: nenhum
void calculaIdade(int anoA,int anoN) {
	//Declara��es locais
	int idade;
	int nivel;
	//Instru��es locais
	idade = anoA - anoN;
	nivel = verificaNivel(idade,nivel);
	if(idade==0)
		puts("Pessoa viveu pelo menos um dia.");
	else
		printf("Idade = %d\n",idade);
	
	switch (nivel) {
	case 1:
		puts("==> CRIAN�A");
		break;
	case 2:
		puts("==> ADOLESCENTE");
		break;
	case 3:
		puts("==> JOVEM");
		break;
	case 4:
		puts("==> ADULTO");
		break;
	default:
		puts("==> IDOSO");
	}
}

//Objetivo:Identificar o n�vel da idade
//Par�metro: idade e n�vel
//Retorno: n�vel da idade
int verificaNivel(int idade,int nivel) {
	if(idade <= 10)
		nivel=1;
	else
		if(idade>10 && idade<18)
			nivel=2;
		else
			if(idade>=18 && idade<25)
				nivel=3;
			else
				if(idade>=25 && idade<=58)
					nivel=4;
				else
					nivel=5;
	return nivel;
}


















