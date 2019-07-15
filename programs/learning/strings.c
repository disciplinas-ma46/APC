#include <stdio.h>
int main(void) {
    int i;
    while (1==1) {
        for (i=1; i<80; ++i){
        if (i%2 == 0)
            printf("1");
        else
            printf("0");
        }

        printf("\n");
    }
}


/*#include <stdio.h>

int main(void) {
    int tampal(char string[]);
    char palavra[30];

    printf("escreva uma palavra: ");
    scanf("%s", palavra);

    int sizeword = tampal(palavra);

    printf("\na palavra %s tem %i letras\n",palavra, sizeword);

    system("pause");
    return 0;
}

int tampal(char string[]) {
    int tam = 0;
    while (string[tam] != '\0') {
        ++tam;
    }
    return tam;
}
*/
























/*#include <stdio.h>

int main(void) {
    void concatenar(char string1[], int t1, char string2[], int t2, char string[]);
    char palavra1[] = {'a','r','r','o','z',' '};
    char palavra2[] = {'c','a','r','n','e'};
    char palavra[11];

    concatenar(palavra1, 6, palavra2, 5, palavra);

    int i;
    for (i=0; i<11; ++i) {
        printf("%c", palavra[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}

void concatenar(char string1[], int t1, char string2[], int t2, char string[]) {
    int i, j;
    for (i=0; i<t1; ++i) {
        string[i] = string1[i];
    }
    for (j=0; j<t2; ++j) {
        string[t1+j] = string2[j];
    }
}
*/
