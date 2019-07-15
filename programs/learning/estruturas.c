#include <stdio.h>



struct horario {
    int hora;
    int minuto;
    int segundo;
};
int main() {
    void receberHorarios(struct horario list[5]);
    void printHorarios(struct horario list[5]);
    struct horario agora[5];

    receberHorarios(agora);
    printHorarios(agora);
    printf("\n");

    system("pause");
    return 0;
}


void receberHorarios(struct horario list[5]) {
    int i;
    for (i = 0; i < 5; ++i) {
        printf("Digite os valores do horario %i\n", (i+1));
        scanf("%i:%i:%i", &list[i].hora, &list[i].minuto, &list[i].segundo);
        printf("\n");
    }
}

void printHorarios(struct horario list[5]) {
    int i;
    for (i = 0; i < 5; ++i) {
        printf("Lista %i\n", (i+1));
        printf("%i:%i:%i", list[i].hora, list[i].minuto, list[i].segundo);
        printf("\n");
    }
}













