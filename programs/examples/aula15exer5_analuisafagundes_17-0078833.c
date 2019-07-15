//NOME DO ALUNO: Ana Lu�sa de Brito
/*
  S�ntese
    Objetivo: Cadastrar dados pessoais do usu�rio
    Entrada:  Casa,bairro,cidade,Estado, pa�s,nome,telefone e altura do usu�rio
    Sa�da: Casa,bairro,cidade,Estado, pa�s,nome,telefone e altura do usu�rio e quantidade de cadastros
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
//Prot�tipos
int validaString(char *string);
void ajustaTerminador(char *nome);
float validaAltura(float altura);
int validaTelefone(char *telefone);
int validaCasa(int casa);
void mostraResultado(pessoa cadastro);
int  main()
{
	setlocale(LC_ALL,"Portuguese");
    
	//Declara��es
    pessoa cadastro[LIMITE];
    int aux=0;
    char continua;
    //Instru��es
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
            puts("Digite o seu n�mero de telefone:");
            fgets(cadastro[aux].telefone,10,stdin);
        }while(validaTelefone(cadastro[aux].telefone));

        system("cls");
        puts("Digite o n�mero de sua resid�ncia:");
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
        	puts("Digite o seu Pa�s:");
        	fgets(cadastro[aux].ender.pais,MAX,stdin);
        }while(validaString(cadastro[aux].ender.pais));
        system("cls");
		mostraResultado(cadastro[aux]);
		gotoxy(1,22);
        puts("Deseja cadastrar outra pessoa? se sim digite 'S', se n�o pressione qualquer tecla:");
        continua=getch();
        continua=toupper(continua);
        aux++;
        fflush(stdin);
        system("cls");
        if(aux==LIMITE)
        	puts("Limite de cadastro alcan�ado.");
    }while(continua=='S' && aux<LIMITE);
	printf("Pessoas cadastradas: %d",aux);
    
	return 0;
}


/*
  S�ntese
    Objetivo:Validar texto digitado pelo usu�rio
    Par�metro: Texto
    Retorno:Texto v�lido ou n�o
*/
int validaString(char *string)
{
    //Declara��es locais
    int aux;
    //Intru��es
    fflush(stdin);
    ajustaTerminador(string);
    if(strlen(string)<=0)
	{
        puts("O texto que voc� digitou est� incorreto.");
        return 1;
    }else
    	for(aux=0;aux<strlen(string);aux++){
        	if(!isalpha(string[aux]) && !isspace(string[aux])){
            	puts("O texto que voc� digitou est� incorreto.");
           		return 1;
        	}
    	}
    return 0;
}


/*
  S�ntese
    Objetivo:Validar a altura digitada pelo usu�rio
    Par�metro: Altura
    Retorno: Altura v�lida
*/
float validaAltura(float altura)
{
    //Instru��es
    while(altura<=0 || altura>=5)
    {
        puts("Altura inv�lida, digite novamente:");
        scanf("%f",&altura);
    }
    system("cls");
    return altura;
}


/*
  S�ntese
    Objetivo:Validar o telefone digitado pelo usu�rio
    Par�metro: Telefone
    Retorno: Telefone v�lido ou n�o
*/
int validaTelefone(char *telefone)
{
   //Declara��es locais
    int aux;
    //Intru��es
    fflush(stdin);
    ajustaTerminador(telefone);
    if(strlen(telefone)<8)
    {
        puts("N�mero inv�lido.");
        return 1;
    }
        for(aux=0;aux<strlen(telefone);aux++){
            if(!isdigit(telefone[aux]))
			{
                puts("N�mero inv�lido.");
                return 1;
            }
        }
    return 0;
}


/*
  S�ntese
    Objetivo:Validar o n�mero da casa do usu�rio
    Par�metro: Casa
    Retorno: Casa v�lida
*/
int validaCasa(int casa)
{
    //Instru��es
    while(casa<=0)
    {
        puts("N�mero inv�lido,digite novamente.");
        scanf("%d",&casa);
    }
    system("cls");
    return casa;
}


/*
  S�ntese
    Objetivo:Ajustar o terminador da string
    Par�metro: Texto
    Retorno: Sem retorno
*/
void ajustaTerminador(char *nome)
{
    //Instru��es
    if(nome[strlen(nome)-1]=='\n')
    	nome[strlen(nome)-1]='\0';
}


/*
  S�ntese
    Objetivo:Mostrar os dados cadastrais ao usu�rio
	Par�metro: Nome,altura,telefone,casa,bairro,cidade,Estado e pa�s cadastrados
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
	printf("Pa�s: %s",cadastro.ender.pais);
}

