// Aluno : Guilherme de Oliveira Aguiar

/*
 Sintese
   Objetivo: Apresentar informações do desempenho de alunos de uma turma

   Entrada : nome e quatro notas parciais

   Saida   :  nome, media final e situação

*/

#include <stdio.h>
#include <conio.c>
#include <string.h>
#include <locale.h>
#define MAXNOME 31
#define QTDNOTAS 4

typedef struct
{
	char nome[MAXNOME];
	float notaParcial[QTDNOTAS];
}infor_aluno;

void validaNome(char *);
float validaNota(float);
void tiraBarraN(char *);
void apresentaResultado(infor_aluno aluno);


int main(void)
{
	setlocale(LC_ALL,"Portuguese");
// Declaracoes
	infor_aluno aluno;
	int aux;
    char opcao;
// Instrucoes
    do{
        puts("Digite o nome do aluno: ");
        fgets(aluno.nome,MAXNOME,stdin);
        tiraBarraN(aluno.nome);
        validaNome(aluno.nome);
        for(aux = 0; aux < QTDNOTAS; aux++){
            printf("Digite a %d º nota do aluno %s: ",aux+1,aluno.nome);
            scanf("%f",&aluno.notaParcial[aux]);
            fflush(stdin);
            aluno.notaParcial[aux] = validaNota(aluno.notaParcial[aux]);
        }
        system("cls");
        apresentaResultado(aluno);
        puts("Deseja continuar a cadastrar alunos?");
        puts("Digite 'S' caso sim ou qualquer outra tecla caso não:");
        opcao = getche();
        opcao = toupper(opcao);
        system("cls");
    }while(opcao == 'S');
	getch();
	return 0;
}

///SUBALGORITMOS///

//Objetivo: validar o nome
//Entrada: nome
//Saida: nome valido
void validaNome(char *nome){
	while(strlen(nome) < 4){
		puts("Nome deve ter no minimo 4 caracteres. Digite novamente: ");
		fgets(nome,MAXNOME,stdin);
		tiraBarraN(nome);
	}
	strupr(nome);
	system("cls");
}


//Objetivo: validar a nota
//Entrada: nota
//Saida: nota valida
float validaNota(float nota){
	while(nota < 0 || nota > 10){
		puts("Nota não pode ser menor que zero ou maior que dez. Digite novamente: ");
		scanf("%f",&nota);
		fflush(stdin);
	}
	return nota;
}

//Objetivo: Retirar o \n da string
//Entrada: String
//Saida: String sem \n
void tiraBarraN(char *nome){
	if(nome[strlen(nome)-1] == '\n')
			nome[strlen(nome)-1] = '\0';
}

//Objetivo: calcular a media
//Parametro: 4 notas
//Retorno: media
float calculaMedia(float *notas){
	int aux;
	float total = 0;
	for(aux =0;aux < QTDNOTAS;aux++){
		total += *(notas+aux);
	}
	return (total/QTDNOTAS);
}


//Objetivo: Mostrar o resultado
//Entrada: nome do aluno, notas do aluno
void apresentaResultado(infor_aluno aluno){
	float media;
	media = calculaMedia(aluno.notaParcial);
	printf("Nome do aluno: %s \n",aluno.nome);
	printf("Media final: %.2f \n",media);
	if( media >= 7)
		puts("Situação: Aprovado.");		
	else
		puts("Situação: Reprovado.");
}
