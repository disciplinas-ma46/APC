//NOME DO ALUNO:  Marcelo Ara�jo dos Santos

// S�ntese
//  Objetivo: Cadastrar os nomes de professores, suas turmas e media aritm�tica final dos alunos
//  Entrada : Nome do professor, quantidade de alunos, media aritm�tica final de cada aluno
//  Sa�da   : Nome do professor, quantidade de turmas cadastradas, media aritm�tica final da turma, 
//            quantidade de professores, quantidade de alunos em cada turma

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define TAMANHONOME 50

void validaNome (char *nome);
int validaAlunos (int alunos);
float validaMedia (float media);
char validaCaracter (char continua);
void mostraResultado(char *nomeProfessor, int qntdAlunos, float mediaFinal);

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	// Declara��es
	char nomeProfessor[TAMANHONOME];
	int qntdTurmas = 0, qntdAlunos, qntdProfessores = 1, aux;
	char continua;
	float media, mediaAlunos, acumulador;
	// Instru��es
	do {
		printf("Digite o nome do professor: ");
		gets(nomeProfessor);
		validaNome(nomeProfessor);
		do {
			acumulador = 0;
			printf("Digite a quantidade de alunos na %d� turma do professor %s: ", qntdTurmas+1, nomeProfessor);
			scanf("%d",&qntdAlunos);
			qntdAlunos = validaAlunos(qntdAlunos);
			
			for (aux = 1; aux<= qntdAlunos; aux++) {
				printf("Digite a m�dia final do %d� aluno: ",aux);
				scanf("%f",&media);
				media = validaMedia(media);
				acumulador += media;
			}
			system("cls");
			mediaAlunos = acumulador / qntdAlunos;
			mostraResultado(nomeProfessor, qntdAlunos, mediaAlunos);
			printf("\n\nH� uma nova turma deste professor? \n");
			printf("Digite 'S' para sim ou 'N' para N�O: ");
			continua = getch();
			continua = validaCaracter(continua);
			qntdTurmas++;
			system("cls");
		}while(continua == 'S');
		
		printf("Existe outro professor para cadastrar suas turmas no semestre atual?\n");
		printf("Digite 'S' para SIM ou 'N' para N�O: ");
		continua = getch();
		continua = validaCaracter(continua);
		if (continua == 'S')
			qntdProfessores++;
	}while(continua == 'S');
	
	system("cls");
	printf("N�mero de professores cadastrados = %d\n",qntdProfessores);
	printf("Quantidade de turmas cadastradas = %d\n\n",qntdTurmas);	
}

//=============  SUBALGORITMOS  =============

//  Objetivo  : Valida o nome
//  Par�metro : Nome
//  Retorno   : Sem retorno
void validaNome (char *nome) {
	while (strlen(nome) < 4) {
		printf("\nNome inv�lido! Digite pelo menos 4 caracteres para o nome: ");
		gets(nome);
	}
	strupr(nome);
	system("cls");
}

//  Objetivo  : Valida a quantidade de alunos
//  Par�metro : Quantidade de alunos
//  Retorno   :	Quantidade de alunos v�lida
int validaAlunos (int alunos) {
	while (alunos < 2 || alunos > 120) {
		printf("\nQuantidade inv�lida! Digite um valor entre 2 e 120: ");
		scanf("%d",&alunos);
	}
	system("cls");
	return alunos;
}

//  Objetivo  : Validar a media
//  Par�metro : Media
//  Retorno   : Media v�lida
float validaMedia (float media) {
	while (media < 0 || media > 10 ) {
		printf("\nM�dia inv�lida! Digite um valor entre 0 e 10: ");
		scanf("%d",&media);
	}
	return media;
}

//  Objetivo  : Validar caracter
//  Par�metro : Caracter
//  Retorno   : Caracter v�lido
char validaCaracter (char continua) {
	continua = toupper(continua);
	while (continua != 'S' && continua != 'N') {
		printf("\ncar�cter inv�lido! Digite somente 'S' ou 'N': ");
		continua = getch();
		continua = toupper(continua);
	}
	system("cls");
	return continua;
}

//  Objetivo  : Mostrar resultados 
//  Par�metro : Nome do professor, quantidade alunos, media final
//  Retorno   : Sem retorno
void mostraResultado(char *nomeProfessor, int qntdAlunos, float mediaFinal) {
	system("cls");
	printf("Nome do professor: %s\n", nomeProfessor);
	printf("Quantidade de alunos na turma = %d\n", qntdAlunos);
	printf("M�dia aritm�tica entre todas as m�dias finais dos alunos = %.2f\n", mediaFinal);
}






