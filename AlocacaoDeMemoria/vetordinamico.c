#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int *vet = (int *)malloc(5*sizeof(int));
    if(vet == NULL){
        printf("Falha na alocação de memória.\n");
        return 1;
    }
    vet[0] = 15;
    vet[1] = 5;
    vet[2] = 30;
    vet[3] = 28;
    vet[4] = 40;

    printf("%d\n", vet[0]);
    printf("%d\n", *vet);

    free(vet);
    return(0);
}