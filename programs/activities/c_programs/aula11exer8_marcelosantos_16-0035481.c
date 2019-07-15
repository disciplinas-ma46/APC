//NOME DO ALUNO:  Marcelo Araújo dos Santos
/*
  Síntese
    Objetivo: Calcular termos da sequência de Fibbonaci
    Entrada:  Valor do termo da sequência
    Saída:    Valor correspondente na sequência de Fibbonaci
*/

#include <locale.h>
#include <stdio.h>

int validaNumero(int numero);
int termoFibbonaci(int numero);

int  main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//DECLARAÇÕES
	int numero;
	
	//INSTRUÇÕES
	printf("Digite um número maior que zero: ");
	scanf("%d",&numero);
	numero = validaNumero(numero);
	system("cls");
	printf("termo da sequência: %d\nTermo correspondente em Fibbonaci: %d",numero, termoFibbonaci(numero));
	
	getch();
	return 0;
}

// ============== SUBALGORITMOS ==================

/*
  Síntese
    Objetivo: Validar um número
    Entrada:  Número
    Saída:    Número válido
*/
int validaNumero(int numero) {
	while(numero <= 0) {
		printf("\nNúmero inválido! Digite um número maior que zero: ");
		scanf("%d",&numero);
	}
	return numero;
}

/*
  Síntese
    Objetivo: Calcular um termo da sequência de Fibbonaci
    Entrada:  Valor
    Saída:    Termo correspondente
*/
int termoFibbonaci(int numero) {
	if((numero == 1) || (numero == 2))
		return 1;
	else
		return (termoFibbonaci(numero-1) + termoFibbonaci(numero-2));
}


