//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Calcular termos da sequ�ncia de Fibbonaci
    Entrada:  Valor do termo da sequ�ncia
    Sa�da:    Valor correspondente na sequ�ncia de Fibbonaci
*/

#include <locale.h>
#include <stdio.h>

int validaNumero(int numero);
int termoFibbonaci(int numero);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARA��ES
	int numero;
	
	//INSTRU��ES
	printf("Digite um n�mero maior que zero: ");
	scanf("%d",&numero);
	numero = validaNumero(numero);
	system("cls");
	printf("termo da sequ�ncia: %d\nTermo correspondente em Fibbonaci: %d",numero, termoFibbonaci(numero));
	
	getch();
	return 0;
}

// ============== SUBALGORITMOS ==================

/*
  S�ntese
    Objetivo: Validar um n�mero
    Entrada:  N�mero
    Sa�da:    N�mero v�lido
*/
int validaNumero(int numero) {
	while(numero <= 0) {
		printf("\nN�mero inv�lido! Digite um n�mero maior que zero: ");
		scanf("%d",&numero);
	}
	return numero;
}

/*
  S�ntese
    Objetivo: Calcular um termo da sequ�ncia de Fibbonaci
    Entrada:  Valor
    Sa�da:    Termo correspondente
*/
int termoFibbonaci(int numero) {
	if((numero == 1) || (numero == 2))
		return 1;
	else
		return (termoFibbonaci(numero-1) + termoFibbonaci(numero-2));
}


