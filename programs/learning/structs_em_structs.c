#include<stdio.h>
#include<conio.c>

struct infor_end{
	char rua[30];
	int numero;
	char bairro[80];
	char complemento[15];
};

int main (void) {
	
	struct infor_empregado {
		int dependentes;
		int idade;
		struct infor_end endereco;
	} empregado;

	printf("Informe o endereco:");

	gets(empregado.endereco.rua);

	empregado.endereco.rua[0] = 'R';

	empregado.idade = 45;

	printf("Endereco: %s \tIdade:%d",

	empregado.endereco.rua,

	empregado.idade);

	getch( );

	return 0;
}
