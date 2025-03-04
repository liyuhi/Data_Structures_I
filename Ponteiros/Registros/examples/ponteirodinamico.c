#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    int *p = (int *)malloc(sizeof(int));  //alocando espaço para um inteiro

    if (p == NULL) {
        printf("Falha na alocação de memória\n");
        return 1;
    }

    *p = 42;  //atribuindo um valor
    printf("Valor armazenado: %d\n", *p);

    free(p);  //liberando memória
    return 0;
}

