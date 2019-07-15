//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Analisar dados de 10 pessoas e classificá-las
    Entrada: alturas e sexos
    Saída:  a maior e menor altura, média de altura das mulheres e número de homens
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
	//DECLARAÇÕES
	float altura[NROPESSOAS], maiorAltura, menorAltura, somaAlturaMulheres;
	char sexo[NROPESSOAS][TAMANHO], provisorio[TAMANHO]; 
	int aux, nroHomens;
	
	//INSTRUÇÕES
	nroHomens = 0;
	maiorAltura = 0;
	somaAlturaMulheres = 0;
	for (aux = 0; aux < NROPESSOAS; aux++) {
		printf("Digite a altura em metros da %d° pessoa: ",aux+1);
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
		
		printf("Escreva o sexo (\"feminino\" ou \"masculino\")\n da %d° pessoa: ",aux+1);
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
	printf("Média da altura das mulheres: %.2f\n",(somaAlturaMulheres/ (NROPESSOAS-nroHomens) ));
	printf("Número de homens: %d\n",nroHomens);
	
	getch();
	return 0;
}

//==========     SUBALGORITMOS     ==========//

//Objetivo: Lê e valida altura
//Parâmetro: Altura
//Retorno: Altura válida
float validaAltura(float altura) {
	// Instruções
	while ((altura <= 0) || (altura >= 3)) {
		puts("Inválido! Digite valor entre 0 e 3 metros:");
		scanf("%f",&altura);
	}
	return altura;
}

//Objetivo: valida sexo
//Parâmetro: sexo
//Retorno: Nenhum
void validaSexo(char provisorio[]) {
	// Instruções
	while ((strcmp(provisorio,"feminino")!=0) && (strcmp(provisorio,"masculino")!=0)) {
		puts("\nInválido! Digite 'feminino' ou 'masculino':");
		scanf("%s",&provisorio);
	}
}

