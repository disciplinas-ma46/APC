#include <stdio.h>

int main(){
    
    int contador = 1;
    
    while (contador <= 5) {

        printf("Contador: %i\n",contador);

        ++contador;
    }
    
    printf("\n\nContador final: %i\n\n",contador);
}
