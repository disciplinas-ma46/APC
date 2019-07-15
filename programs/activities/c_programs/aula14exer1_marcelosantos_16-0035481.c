//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Calcular ajustes dos preços de produtos
    Entrada:  Preço atual e percentual de ajuste
    Saída:    Novo preço e valor do ajuste que sofreu
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
	//DECLARAÇÕES
	float preco, novoPreco, reajuste;
	float *ponteiroPreco=0;
	float *ponteiroNovoPreco=0;
	float *ponteiroReajuste=0;
	
	//INSTRUÇÕES
	ponteiroPreco = &preco;
	ponteiroNovoPreco = &novoPreco;
	ponteiroReajuste = &reajuste;
	do {
		printf("Digiteeeee um preço ou 0 para sair: ");
		scanf("%f",&preco);
		preco = validaPreco(preco);
		if(preco != 0) {
			printf("Digiteaaeae o reajuste em porcentagem: ");
			scanf("%f",&reajuste);
			reajuste = validaReajuste(reajuste);
			
			system("cls");
			
			fazPorcentagem(ponteiroPreco, ponteiroReajuste, ponteiroNovoPreco);
			printf("Novo preço = %.2f  Valor de Reajuste = %.2f  \n", *ponteiroNovoPreco,(*ponteiroNovoPreco-preco));
			printf("\n\n\n\nAperte qualquer tecla para continuar.");
			getch();
			system("cls");
		}
		
	}while(preco != 0);
	
	return 0;
}

//===========  SUBALGORITMOS  ================

/*
 Síntese
    Objetivo:   Calcular novo preço e o valor do ajuste
    Parâmetros: Preço do produto e percentual de ajuste
    Retorno:    Nenhum
*/
void fazPorcentagem(float *ponteiroPreco, float *ponteiroReajuste, float *ponteiroNovoPreco) {
	*ponteiroNovoPreco = *ponteiroPreco + (*ponteiroPreco * (*ponteiroReajuste/100));
}

/*
 Síntese
    Objetivo:   Validar preço
    Parâmetros: Preço
    Retorno:    Preço válido
*/
float validaPreco(float preco) {
	while(preco < 0) {
		printf("Preço inválido! Digite um valor positivo: ");
		scanf("%f",&preco);
	}
}

/*
 Síntese
    Objetivo:   Validar reajuste
    Parâmetros: Reajuste
    Retorno:    Reajuste válido
*/
float validaReajuste(float reajuste) {
	while(reajuste <= 0) {
		printf("Reajuste inválido! Digite um valor maior que 0: ");
		scanf("%f",&reajuste);
	}
}





