//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Calcular ajustes dos pre�os de produtos
    Entrada:  Pre�o atual e percentual de ajuste
    Sa�da:    Novo pre�o e valor do ajuste que sofreu
*/

#include <stdio.h>
#include <conio.h>
#include<locale.h>

void fazPorcentagem(float *ponteiroPreco, float *ponteiroReajuste, float *ponteiroNovoPreco);
float validaPreco(float preco);
float validaReajuste(float reajuste);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARA��ES
	float preco, novoPreco, reajuste;
	float *ponteiroPreco=0;
	float *ponteiroNovoPreco=0;
	float *ponteiroReajuste=0;
	
	//INSTRU��ES
	ponteiroPreco = &preco;
	ponteiroNovoPreco = &novoPreco;
	ponteiroReajuste = &reajuste;
	do {
		printf("Digiteeeee um pre�o ou 0 para sair: ");
		scanf("%f",&preco);
		preco = validaPreco(preco);
		if(preco != 0) {
			printf("Digiteaaeae o reajuste em porcentagem: ");
			scanf("%f",&reajuste);
			reajuste = validaReajuste(reajuste);
			
			system("cls");
			
			fazPorcentagem(ponteiroPreco, ponteiroReajuste, ponteiroNovoPreco);
			printf("Novo pre�o = %.2f  Valor de Reajuste = %.2f  \n", *ponteiroNovoPreco,(*ponteiroNovoPreco-preco));
			printf("\n\n\n\nAperte qualquer tecla para continuar.");
			getch();
			system("cls");
		}
		
	}while(preco != 0);
	
	return 0;
}

//===========  SUBALGORITMOS  ================

/*
 S�ntese
    Objetivo:   Calcular novo pre�o e o valor do ajuste
    Par�metros: Pre�o do produto e percentual de ajuste
    Retorno:    Nenhum
*/
void fazPorcentagem(float *ponteiroPreco, float *ponteiroReajuste, float *ponteiroNovoPreco) {
	*ponteiroNovoPreco = *ponteiroPreco + (*ponteiroPreco * (*ponteiroReajuste/100));
}

/*
 S�ntese
    Objetivo:   Validar pre�o
    Par�metros: Pre�o
    Retorno:    Pre�o v�lido
*/
float validaPreco(float preco) {
	while(preco < 0) {
		printf("Pre�o inv�lido! Digite um valor positivo: ");
		scanf("%f",&preco);
	}
}

/*
 S�ntese
    Objetivo:   Validar reajuste
    Par�metros: Reajuste
    Retorno:    Reajuste v�lido
*/
float validaReajuste(float reajuste) {
	while(reajuste <= 0) {
		printf("Reajuste inv�lido! Digite um valor maior que 0: ");
		scanf("%f",&reajuste);
	}
}





