//NOME DO ALUNO:  Marcelo Ara�jo dos Santos
/*
  S�ntese
    Objetivo: Cadastrar dados de pessoas
    Entrada:  Nome, cidade, bairro, rua, n� da casa, telefone e altura
    Sa�da:    Lista das pessoas cadastradas com seus dados, n� de cadastros
*/

#include <locale.h>
#include <stdio.h>
#include <conio.c>

#define LIMITE 5
#define MAXIMONOME 50

void validaString(char *nome, int nroLetras);
void validaNumeroCasa(int *numeroCasa);
void validaTelefone(long int *telefone);
void validaAltura(long int *altura);
void mostraCadastros(struct infoPessoa *pessoa, int aux);

struct infoEndereco {
	char cidade[MAXIMO];
	char bairro[MAXIMO];
	char rua[MAXIMO];
	int numeroCasa;
};

struct infoPessoa {
	char nome[MAXIMO];
	struct infoEndereco endereco;
	long int telefone;
	float altura;
};

int  main(void) {
	//Declara��es
	char controle;
	int nroCadastros = 1, aux = 0, continuar = 1;
	struct infoPessoa pessoas[LIMITE];
	
	//Instru��es
	setlocale(LC_ALL, "Portuguese");
	
	do {
		
		do {
			printf("Digite o nome da %d� pessoa: ",aux+1);
			fgets(pessoas[aux].nome, MAXIMONOME, stdin);
			fflush(stdin);
			if(pessoas[aux].nome[ strlen(pessoas[aux].nome)-1 ] == '\n')
				pessoas[aux].nome[ strlen(pessoas[aux].nome)-1 ] = '\0';
			validaString(&pessoas[aux].nome, 3);
			system("cls");
	
			printf("Digite o bairro da %d� pessoa: ",aux+1);
			fgets(pessoas[aux].endereco.bairro, MAXIMONOME, stdin);
			fflush(stdin);
			if(pessoas[aux].endereco.bairro[ strlen(pessoas[aux].endereco.bairro)-1 ] == '\n')
				pessoas[aux].endereco.bairro[ strlen(pessoas[aux].endereco.bairro)-1 ] = '\0';
			validaString(&pessoas[aux].endereco.bairro, 4);
			system("cls");
	
			printf("Digite a cidade da %d� pessoa: ",aux+1);
			fgets(pessoas[aux].endereco.cidade, MAXIMONOME, stdin);
			fflush(stdin);
			if(pessoas[aux].endereco.cidade[ strlen(pessoas[aux].endereco.cidade)-1 ] == '\n')
				pessoas[aux].endereco.cidade[ strlen(pessoas[aux].endereco.cidade)-1 ] = '\0';
			validaString(&pessoas[aux].endereco.cidade, 4);
			system("cls");
	
			printf("Digite a rua da %d� pessoa: ",aux+1);
			fgets(pessoas[aux].endereco.rua, MAXIMONOME, stdin);
			fflush(stdin);
			if(pessoas[aux].endereco.rua[ strlen(pessoas[aux].endereco.rua)-1 ] == '\n')
				pessoas[aux].endereco.rua[ strlen(pessoas[aux].endereco.rua)-1 ] = '\0';
			alidaString(&pessoas[aux].endereco.rua, 4);
			system("cls");
	
			printf("Digite o n�mero da casa da %d� pessoa: ",aux+1);
			scanf("%d",&pessoas[aux].endereco.numeroCasa);
			fflush(stdin);
			validaNumeroCasa(&pessoas[aux].endereco.numeroCasa);
			system("cls");
	
			printf("Digite o telefone da casa da %d� pessoa: ",aux+1);
			scanf("%ld",&pessoas[aux].telefone);
			fflush(stdin);
			validaTelefone(&pessoas[aux].telefone);
			system("cls");
	
			printf("Digite a altura da %d� pessoa: ",aux+1);
			scanf("%f",&pessoas[aux].altura);
			fflush(stdin);
			validaAltura(&pessoas[aux].altura);
			system("cls");
			
			printf("\n\nDeseja cadastrar mais uma pessoa?: \n");
			printf("Digite 's' para sim ou outra tecla para mostrar resultados: ");
			controle = getch();
			controle = tolower(controle);
			system("cls");
			if(controle != 's' && aux < LIMITE) {
				continuar = 1;
				aux++;
			} else {
				continuar = 0;
			}
		}while(continuar);
		
		mostraCadastros(&pessoas, aux);
		
		gotoxy(1,20);
		printf("Deseja fazer nova coleta de dados para um novo cadastro?\n");
		printf("Digite 's' para sim ou outra tecla para n�o e finalizar o programa");
		controle = getch();
		controle = tolower(controle);
		system("cls");
		
		if(controle != 's') {
			continuar = 1;
			nroCadastros++;
		}
		else {
			continuar = 0;
			printf("Quantidade de cadastros realizados: %d",nroCadastros);
		}
	}while(continuar);
	
	getch();
	return 0;
}

//===========  SUBALGORITMOS  ================

//    Objetivo:   Mostra dados das pessoas cadastradas
//    Par�metros: dados das pessoas
//    Retorno:   nenhum
void mostraCadastros(struct infoPessoa *pessoa, int aux) {
	system("cls");
	int contador;
	for(contador = 0; contador<aux; contador++) {
		printf("nome da %d� pessoa: \n",contador+1,pessoas.nome);
		printf("Digite o bairro da %d� pessoa: \n",contador+1,pessoas.endereco.bairro);
		printf("Digite a cidade da %d� pessoa: \n",contador+1, pessoas.endereco.cidade);
		printf("Digite a rua da %d� pessoa: \n",contador+1, pessoas.endereco.rua);
		printf("Digite o n�mero da casa da %d� pessoa: \n",contador+1, pessoas.endereco.numeroCasa);
		printf("Digite o telefone da casa da %d� pessoa: \n",contador+1), pessoas.telefone;
		printf("Digite a altura da %d� pessoa: ",contador+1, pessoas.altura);
	}
}

//    Objetivo:   Validar uma informa��o string (como palavra, frase...)
//    Par�metros: string
//    Retorno:   nenhum
void validaString(char *nome, int nroLetras) {
	while (strlen(nome) < 3) {
		printf("Inv�lido! Deve conter %d letras ou mais: ",nroLetras);
		fgets(nome, MAXIMO, stdin);
		fflush(stdin);
		if(nome[ strlen(nome)-1 ] == '\n')
			nome[ strlen(nome)-1 ] = '\0';
	}
}

//    Objetivo:   validar n�mero da casa
//    Par�metros: n�mero da casa
//    Retorno:   nenhum
void validaNumeroCasa(int *numeroCasa) {
	while (*numeroCasa <= 0) {
		printf("Inv�lido Digite um n�mero maior que zero: ");
		scanf("%d",numeroCasa);
		fflush(stdin);
	}
}

//    Objetivo:   validar telefone
//    Par�metros: telefone
//    Retorno:   nenhum
void validaTelefone(long int *telefone) {
	while (*telefone <= 0) {
		printf("Inv�lido Digite um n�mero maior que zero: ");
		scanf("%ld",telefone);
		fflush(stdin);
	}
}

//    Objetivo:   validar altura
//    Par�metros: altura
//    Retorno:   nenhum
void validaAltura(long int *altura) {
	while ((*altura <= 0) || (*altura >= 3)) {
		printf("Inv�lido Digite um n�mero maior que zero e menor que 3: ");
		scanf("%f",altura);
		fflush(stdin);
	}
}





