#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int *p = (int *)malloc(sizeof(int));
    if (p == NULL){
        printf("Falha na alocação de memória.\n");
        return 1;
    }
    *p = 30;
    printf("%d\n", *p);
    free(p);

    p = (int *)malloc(sizeof(int));
    if (p == NULL){
        printf("Falha na alocação de memória.\n");
        return 1;
    }
    *p = 50;
    printf("%d\n", *p);
    free(p);

    return 0;
}