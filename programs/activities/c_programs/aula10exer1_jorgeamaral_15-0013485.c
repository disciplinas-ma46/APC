/*
algoritmo aula10exer1;
// S�ntese
//	Jorge Guilherme Bezerra Amaral
//  Objetivo:	Apresentar todos os valores pares at� 2000
//  Entrada :	N�mero
//  Sa�da   :	Todos n�meros pares at� 2000

principal
	// Declara��es
	inteiro numero,pares;
	inteiro limite;     // CONSTANTE

	// Instru��es
	limite = 2000;
	escreval("Digite um n�mero para apresentarmos todos os n�meros pares at� 2000");
	leia(numero);
	limpaTela();
	se (numero > limite) entao 
		escreval(numero, " LIMITE DE C�LCULO FOI EXCEDIDO!");
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
  // Declara��es
  int numero, pares;
  const int limite = 2000;
  
  // Instru��es
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
