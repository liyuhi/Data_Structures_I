#include<stdio.h>

int main(){
    FILE *arquivo = fopen("dados.txt", "wb");

    printf("Arquivo aberto com sucesso!\n");

    fclose(arquivo);
    return 0;
}