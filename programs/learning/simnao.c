#include <stdio.h>

int main()
{
    int n1 = 1;
    int n2 = 20;

    int resp;

    n1 < n2 ? printf("sim\n") : printf("nao\n");
    n1 < n2 ? (resp = 10) : (resp = -10);
    printf("\n%i",resp);

    return 0;
}
