// Aluno : Lucas Gomes Lopes

/*
 Sintese
   Objetivo: Calcular o ajuste do pre�o de um produto
 
   Entrada : Pre�o do produto e reajuste a ser calculado 

   Saida   :  Novo pre�o e valor do ajuste

*/

#include <stdio.h>
#include <conio.c>
#include <locale.h>
float validaProduto(float produto);
float validaPercentual(float percentual);
float fazPorcentagem(float *pro,float *perc);
int main(void)
{
    setlocale(LC_ALL,"Portuguese");
// Declaracoes
   float produto,percentual,ajuste;
// Instrucoes
  do{
        printf("Digite o pre�o do produto : ");
        scanf("%f",&produto);
        produto=validaProduto(produto);
        system("cls");
        if(produto!=0){
           printf("Digite o percentual de reajuste do pre�o do produto:");
           scanf("%f",&percentual);
           percentual=validaPercentual(percentual);   
           ajuste=fazPorcentagem(&produto,&percentual);
           system("cls");
           printf("Novo Pre�o = R$ %3.2f\n",produto);
           printf("Valor de ajuste sofrido = R$ %3.2f\n",ajuste);
        }
  }while(produto!=0);
  getch();
  return 0;
}
//===========SUBALGORITMOS==========
//Objetivo: Validar pre�o informado
//Par�metros: Pre�o do produto
//Retorno: Pre�o v�lido
float validaProduto(float produto){
      while(produto<0){
           printf("Valor deve ser positivo ou 0 para encerrar o programa.Digite novamente:");
           scanf("%f",&produto);
      }
      return produto;
}
//Objetivo: Validar percentual informado
//Par�metros: Percentual de ajuste do pre�o do produto
//Retorno: Percentual v�lido
float validaPercentual(float percentual){
      while(percentual<=0){
           printf("Valor deve ser positivo.Digite novamente:");
           scanf("%f",&percentual);
      }
      return percentual;
}
//Objetivo: Calcular o ajuste do pre�o do produto
//Par�metros: Pre�o do produto e ajuste
//Retorno: Novo pre�o
float fazPorcentagem(float *pro,float *perc){
      float ajuste;
      ajuste=(*pro*(*perc/100));
      *pro= *pro + ajuste;
      return ajuste;
}
