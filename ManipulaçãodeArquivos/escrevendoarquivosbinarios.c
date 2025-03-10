#include<stdio.h>

int main(){
    FILE *arquivo = fopen("dados.bin", "wb");

    int numeros[] = {10, 20, 30, 40, 50};
    fwrite(numeros, sizeof(int), 5, arquivo);

    fclose(arquivo);
    printf("Dados gravados com sucesso!\n");
    return 0;
}