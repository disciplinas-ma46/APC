#include <stdio.h>

int main() {
    float somaNum(float x, float y);
    float a, b, soma;

    printf("digite 2 valores:\n");
    scanf("%f%f", &a, &b);
    soma = somaNum(a, b);

    printf("\na soma dos modulos de %f e %f eh: %f\n", a, b, soma);

    system("pause");
    return 0;
}

float somaNum(float x, float y) {
    float modulo(float mod);
    if (x < 0)
        x = modulo(x);
    if (y < 0)
        y = modulo(y);
    return x + y;
}

float modulo(float mod) {
    mod *= -1;
    return mod;
}
