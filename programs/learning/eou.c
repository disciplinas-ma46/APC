#include <stdio.h>
int main(void) {
    _Bool stringsIguais(char s1[], char s2[]);
    char p1[20];
    char p2[20];
    scanf("%s", &p1);
    scanf("%s", &p2);
    printf("\n");
    if (stringsIguais(p1, p2)) {
        printf("Sao iguais\n");
    }
    else {
        printf("Nao sao iguais\n");
    }
    system("pause");
    return 0;
}

_Bool stringsIguais(char s1[], char s2[]) {
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') {
        ++i;
    }
    if (s1[i] == '\0' && s2[i] == '\0') {
        return 1;
    }
    else {
        return 0;
    }
}
