#include<stdio.h>

int main(){
    FILE *arquivo = fopen("dados.bin", "rb");

    int numeros[5];
    fread(numeros, sizeof(int), 5, arquivo);

    fclose(arquivo);

    printf("Dados lidos do arquivo:\n");
    int i;
    for(i = 0; i<5; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
    return 0;
}