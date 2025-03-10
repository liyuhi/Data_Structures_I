#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int *pi = (int *)malloc(sizeof(int));
    if (pi == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }
    *pi = 1001;
    printf("Valor inteiro = %d\n", *pi);
    printf("Localização = %p\n\n", (void *)pi);

    double *pd = (double *)malloc(sizeof(double));
    if (pd == NULL) {
        printf("Falha na alocação de memória.\n");
            free(pi);
            return 1;
    }
    *pd = 500.35;
    printf("Valor ponto-flutuante = %.2f\n", *pd);
    printf("Localização = %p\n\n", (void *)pd);

    printf("Tamanho de pi = %zu\n", sizeof(pi));
    printf("Tamanho de *pi = %zu\n\n", sizeof(*pi));
    printf("Tamanho de pd = %zu\n", sizeof(pd));
    printf("Tamanho de *pd = %zu\n", sizeof(*pd));

    free(pi);
    free(pd);
    return 0;
}