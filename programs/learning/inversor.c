#include <stdio.h>

int main()
{
    int numero, cifra;
    printf("digite um numero: ");
    scanf("%i", &numero);

    do {
        cifra = numero % 10;
        printf("%i", cifra);
        numero = numero / 10;

    } while (numero != 0);

    return 0;
}
