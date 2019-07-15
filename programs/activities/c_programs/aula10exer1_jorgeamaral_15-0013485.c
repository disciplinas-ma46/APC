/*
algoritmo aula10exer1;
// Síntese
//	Jorge Guilherme Bezerra Amaral
//  Objetivo:	Apresentar todos os valores pares até 2000
//  Entrada :	Número
//  Saída   :	Todos números pares até 2000

principal
	// Declarações
	inteiro numero,pares;
	inteiro limite;     // CONSTANTE

	// Instruções
	limite = 2000;
	escreval("Digite um número para apresentarmos todos os números pares até 2000");
	leia(numero);
	limpaTela();
	se (numero > limite) entao 
		escreval(numero, " LIMITE DE CÁLCULO FOI EXCEDIDO!");
	senao
		se ((numero % 2) != 0) entao
			numero = numero + 1;
		fimSe 
		para (pares de numero ate limite passo 2) faca 
				escreva(pares, " ");
		fimPara
	fimSe 			 
fimPrincipal

*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
  // Declarações
  int numero, pares;
  const int limite = 2000;
  
  // Instruções
  printf("Digite um numero para apresentarmos todos os numeros pares ate 2000\n");
  scanf("%d",&numero);
  system("cls");
  if (numero > limite)
  	printf("%d LIMITE DE CALCULO FOI EXCEDIDO!\n",numero); 
  else {
  		if ((numero % 2) != 0)
  			numero = numero + 1;
  		for (pares = numero; pares <= limite; pares+=2)
			 	printf("%d ",pares);
  }
  getch();
  return(0);
}
