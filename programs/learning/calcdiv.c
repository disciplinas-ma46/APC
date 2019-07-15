#include <stdio.h>

int main()
{
    int n1, n2;
    printf("digite um numero: ");
    scanf("%i",&n1);
    printf("digite outro numero: ");
    scanf("%i",&n2);




    if (n2 != 0) {

    if (n1%n2 == 0) {
        printf("\nsao divisiveis!");
        printf("\n %i / %i = %i", n1, n2, (n1/n2));
        } else {printf("\nnao sao divisiveis!");}
    } else {
        printf("\nnao pode dividir por zero!");
    }




    return 0;
}
