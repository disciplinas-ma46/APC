#include <stdio.h>

int main()
{
    int m, n;
    float matriz[4][4] = {0};
    float medias[4] = {0};

    for (m = 0; m < 4; ++m) {
        printf("insira as 4 notas do aluno %i \n", (m + 1));
        for (n = 0; n < 4; ++n) {
            scanf("%f", &matriz[m][n]);
        }
        printf("\n");
    }

    for (m = 0; m < 4; ++m) {
        for (n = 0; n < 4; ++n) {
            medias[m] = medias[m] + matriz[m][n];
        }
    }

    for (m = 0; m < 4; ++m)
        medias[m] /= 4;

    printf("\n");

    for (m = 0; m < 4; ++m)
        printf("media do aluno %i = %.2f \n", (m + 1), medias[m]);

    printf("\n");

   system("pause");

   return 0;
}
