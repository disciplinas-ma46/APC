//NOME DO ALUNO: Ana Luísa de Brito
/*
  Síntese
    Objetivo: Cadastrar dados pessoais do usuário
    Entrada:  Casa,bairro,cidade,Estado, país,nome,telefone e altura do usuário
    Saída: Casa,bairro,cidade,Estado, país,nome,telefone e altura do usuário e quantidade de cadastros
*/
#include <stdio.h>
#include <conio.c>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define LIMITE 100
#define MAX 30

typedef struct {
    int casa;
    char bairro[MAX];
    char cidade[MAX];
    char estado[MAX];
    char pais[MAX];
}endereco;
typedef struct {
    char nome[MAX];
    float altura;
    char telefone[10];
    endereco ender;
}pessoa;
//Protótipos
int validaString(char *string);
void ajustaTerminador(char *nome);
float validaAltura(float altura);
int validaTelefone(char *telefone);
int validaCasa(int casa);
void mostraResultado(pessoa cadastro);
int  main()
{
	setlocale(LC_ALL,"Portuguese");
    
	//Declarações
    pessoa cadastro[LIMITE];
    int aux=0;
    char continua;
    //Instruções
    do{
        do{
            puts("Digite seu nome completo:");
            fgets(cadastro[aux].nome,MAX,stdin);
        }while(validaString(cadastro[aux].nome));
    
        system("cls");
        puts("Digite sua altura:");
        scanf("%f",&cadastro[aux].altura);
        cadastro[aux].altura=validaAltura(cadastro[aux].altura);
        do{
        	fflush(stdin);
            puts("Digite o seu número de telefone:");
            fgets(cadastro[aux].telefone,10,stdin);
        }while(validaTelefone(cadastro[aux].telefone));

        system("cls");
        puts("Digite o número de sua residência:");
        scanf("%d",&cadastro[aux].ender.casa);
        cadastro[aux].ender.casa=validaCasa(cadastro[aux].ender.casa);

        do{
        	fflush(stdin);
	        puts("Digite o seu bairro:");
	        fgets(cadastro[aux].ender.bairro,MAX,stdin);
        }while (validaString(cadastro[aux].ender.bairro));
        system("cls");

        do{
        	fflush(stdin);
	        puts("Digite o sua cidade:");
	        fgets(cadastro[aux].ender.cidade,MAX,stdin);
        }while(validaString(cadastro[aux].ender.cidade));
        system("cls");

        do{
        	fflush(stdin);
        	puts("Digite o seu Estado:");
        	fgets(cadastro[aux].ender.estado,MAX,stdin);
        }while(validaString(cadastro[aux].ender.estado));
        system("cls");

        do{
        	fflush(stdin);
        	puts("Digite o seu País:");
        	fgets(cadastro[aux].ender.pais,MAX,stdin);
        }while(validaString(cadastro[aux].ender.pais));
        system("cls");
		mostraResultado(cadastro[aux]);
		gotoxy(1,22);
        puts("Deseja cadastrar outra pessoa? se sim digite 'S', se não pressione qualquer tecla:");
        continua=getch();
        continua=toupper(continua);
        aux++;
        fflush(stdin);
        system("cls");
        if(aux==LIMITE)
        	puts("Limite de cadastro alcançado.");
    }while(continua=='S' && aux<LIMITE);
	printf("Pessoas cadastradas: %d",aux);
    
	return 0;
}


/*
  Síntese
    Objetivo:Validar texto digitado pelo usuário
    Parâmetro: Texto
    Retorno:Texto válido ou não
*/
int validaString(char *string)
{
    //Declarações locais
    int aux;
    //Intruções
    fflush(stdin);
    ajustaTerminador(string);
    if(strlen(string)<=0)
	{
        puts("O texto que você digitou está incorreto.");
        return 1;
    }else
    	for(aux=0;aux<strlen(string);aux++){
        	if(!isalpha(string[aux]) && !isspace(string[aux])){
            	puts("O texto que você digitou está incorreto.");
           		return 1;
        	}
    	}
    return 0;
}


/*
  Síntese
    Objetivo:Validar a altura digitada pelo usuário
    Parâmetro: Altura
    Retorno: Altura válida
*/
float validaAltura(float altura)
{
    //Instruções
    while(altura<=0 || altura>=5)
    {
        puts("Altura inválida, digite novamente:");
        scanf("%f",&altura);
    }
    system("cls");
    return altura;
}


/*
  Síntese
    Objetivo:Validar o telefone digitado pelo usuário
    Parâmetro: Telefone
    Retorno: Telefone válido ou não
*/
int validaTelefone(char *telefone)
{
   //Declarações locais
    int aux;
    //Intruções
    fflush(stdin);
    ajustaTerminador(telefone);
    if(strlen(telefone)<8)
    {
        puts("Número inválido.");
        return 1;
    }
        for(aux=0;aux<strlen(telefone);aux++){
            if(!isdigit(telefone[aux]))
			{
                puts("Número inválido.");
                return 1;
            }
        }
    return 0;
}


/*
  Síntese
    Objetivo:Validar o número da casa do usuário
    Parâmetro: Casa
    Retorno: Casa válida
*/
int validaCasa(int casa)
{
    //Instruções
    while(casa<=0)
    {
        puts("Número inválido,digite novamente.");
        scanf("%d",&casa);
    }
    system("cls");
    return casa;
}


/*
  Síntese
    Objetivo:Ajustar o terminador da string
    Parâmetro: Texto
    Retorno: Sem retorno
*/
void ajustaTerminador(char *nome)
{
    //Instruções
    if(nome[strlen(nome)-1]=='\n')
    	nome[strlen(nome)-1]='\0';
}


/*
  Síntese
    Objetivo:Mostrar os dados cadastrais ao usuário
	Parâmetro: Nome,altura,telefone,casa,bairro,cidade,Estado e país cadastrados
    Retorno: Sem retorno
*/
void mostraResultado(pessoa cadastro)
{
	puts("Dados cadastrais:\n");
	printf("Nome: %s\n",cadastro.nome);
	printf("Altura: %.2f\n",cadastro.altura);
	printf("Telefone: %s\n",cadastro.telefone);
	printf("Casa: %d\n",cadastro.ender.casa);
	printf("Bairro: %s\n",cadastro.ender.bairro);
	printf("Cidade %s\n",cadastro.ender.cidade);
	printf("Estado: %s\n",cadastro.ender.estado);
	printf("País: %s",cadastro.ender.pais);
}

