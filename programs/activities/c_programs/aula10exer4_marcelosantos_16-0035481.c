//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Analisar dados de 10 pessoas e classific�-las
    Entrada: alturas e sexos
    Sa�da:  a maior e menor altura, m�dia de altura das mulheres e n�mero de homens
*/

#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define NROPESSOAS 10
#define TAMANHO 20

float validaAltura(float altura);
void validaSexo(char sexo[]);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARA��ES
	float altura[NROPESSOAS], maiorAltura, menorAltura, somaAlturaMulheres;
	char sexo[NROPESSOAS][TAMANHO], provisorio[TAMANHO]; 
	int aux, nroHomens;
	
	//INSTRU��ES
	nroHomens = 0;
	maiorAltura = 0;
	somaAlturaMulheres = 0;
	for (aux = 0; aux < NROPESSOAS; aux++) {
		printf("Digite a altura em metros da %d� pessoa: ",aux+1);
		scanf("%f",&altura[aux]);
		altura[aux] = validaAltura(altura[aux]);
		if(aux == 0)
			menorAltura = altura[aux];
		if(altura[aux] > maiorAltura)
			maiorAltura = altura[aux];
		else
			if(altura[aux] < menorAltura)
				menorAltura = altura[aux];
		system("cls");
		fflush(stdin);
		
		printf("Escreva o sexo (\"feminino\" ou \"masculino\")\n da %d� pessoa: ",aux+1);
		scanf("%19s",&provisorio);
		validaSexo(provisorio);
		if(strcmp(provisorio,"masculino")==0)
			nroHomens += 1;
		else
			somaAlturaMulheres += altura[aux];
		strcpy(sexo[aux],provisorio);
		
		system("cls");
	}
	printf("maior altura: %.2f\n",maiorAltura);
	printf("menor altura: %.2f\n",menorAltura);
	printf("M�dia da altura das mulheres: %.2f\n",(somaAlturaMulheres/ (NROPESSOAS-nroHomens) ));
	printf("N�mero de homens: %d\n",nroHomens);
	
	getch();
	return 0;
}

//==========     SUBALGORITMOS     ==========//

//Objetivo: L� e valida altura
//Par�metro: Altura
//Retorno: Altura v�lida
float validaAltura(float altura) {
	// Instru��es
	while ((altura <= 0) || (altura >= 3)) {
		puts("Inv�lido! Digite valor entre 0 e 3 metros:");
		scanf("%f",&altura);
	}
	return altura;
}

//Objetivo: valida sexo
//Par�metro: sexo
//Retorno: Nenhum
void validaSexo(char provisorio[]) {
	// Instru��es
	while ((strcmp(provisorio,"feminino")!=0) && (strcmp(provisorio,"masculino")!=0)) {
		puts("\nInv�lido! Digite 'feminino' ou 'masculino':");
		scanf("%s",&provisorio);
	}
}

