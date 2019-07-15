#include <stdio.h>

int main(void) {
    int matriz[3][3] = {1,2,3,4,5,6,7,8,9};
    void printMatriz(int matriz[3][3]);
    printMatriz(matriz);

    system("pause");
    return 0;
}

void printMatriz(int m[3][3]) {
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%i ", m[i][j]);
        }
        printf("\n");
    }
}








/*
void ordenar(int vetor[], int n) {
    int i, j, aux;
    for (i = 0; i < n; ++i) {
        for (j = i+1; j < n; ++j) {
            if (vetor[i] > vetor[j]) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
*/











/*
=================================================================================================================================

#include <stdio.h>
int main(){
    double num, resultado;
    double fatorial(double x);

    printf("Digite um numero: ");
    scanf("%f", &num);
    resultado = fatorial(num);
    printf("seu fatorial eh %.0f\n", resultado);

    system("pause");
    return 0;
}

double fatorial(double x) {
    double resp;
    if (x == 0) {
        resp = 1;
    } else {
        resp = x * fatorial(x - 1);
    }

    return resp;
}

=================================================================================================================================

#include <stdio.h>

int global = 3;

int main(void) {
    void teste(void);
    printf("var global eh %i\n\n\n", global);
    teste();
    teste();
    teste();

    return 0;
}

void teste(void) {
    int var = 5;
    var *= 2;

    static int varEstat = 2;
    varEstat *= 2;
    global *= 2;

    printf("var global eh %i\n", global);
    printf("var local eh %i\n", var);
    printf("var estat eh %i\n\n", varEstat);
}

=================================================================================================================================

#include <stdio.h>

int main(void)
{
    float calc(float x, float y);
    float area = calc(3, 4);
    printf("area do retang eh %.0f\n", area);


    return 0;
}

float calc(float base, float altura) {
    float area = base * altura;
    return area;
}

=================================================================================================================================
*/
