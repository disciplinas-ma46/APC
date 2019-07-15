#include <stdio.h>

int main () {
	int fat;
	int resp = 1;
	printf("digite um numero: ");
	scanf("%i",&fat);
	
	for ( ;fat >= 1; --fat) {
	resp *= fat;
	}
	
	printf("\n%i",resp);
	
	return 0;
}



























/*
#include <stdio.h>

int main(){
    int numero;
    int contagem = 1;
    printf("digite um numero: ");
    scanf("%i",&numero);
    int ateEsse = numero;
    int antecessor = numero;
    
    while (contagem < ateEsse ) {
    	numero = numero * (antecessor - 1);
    	++contagem;
    	--antecessor;
	}
	printf("\n%i! = %i\n", ateEsse, numero);
	
}

#include <stdio.h>
int main()
{
    float n1, n2;
    printf("digite dois numeros: ");
    scanf("%f %f",&n1,&n2);

    printf("o produto de %.2f e %.2f eh %.2f\n\n\n", n1, n2, (n1 * n2));
getchar();
}

#include <stdio.h>
int main()
{
    int n1, n2, soma;
    printf("digite um numero: ");
    scanf("%d",&n1);
    printf("digite outro numero: ");
    scanf("%d",&n2);
    soma = n1 + n2;
    printf("a soma de %d e %d eh %d\n\n\n", n1, n2, soma);

}


#include <stdio.h>
int main()
{
    int nota;
    printf("quanto tirou na prova? ");
    scanf("%d",&nota);
    if(nota>5)
    {
        printf("voce passou\n\n\n");
    }
    else{
        printf("voce reprovou\n\n\n");
    }

}

#include <stdio.h>

int main()
{
    printf("%c%c%c%c%c%c%c",77,65,82,67,69,76,79);
}
*/
