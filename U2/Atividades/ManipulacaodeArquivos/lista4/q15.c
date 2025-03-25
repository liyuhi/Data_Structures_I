//Crie um programa que grave os 100 primeiros números naturais ao mesmo tempo em um arquivo texto e em um arquivo binário. Compare os tamanhos dos arquivos e explique como os tipos escolhidos para guardar os números podem tornar o arquivo binário menor ou maior que o arquivo texto.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo_bin = fopen("numeros.bin", "wb");
    FILE *arquivo_txt = fopen("numeros.txt", "w");
    if (arquivo_bin == NULL || arquivo_txt == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }
    int *vet = (int*)malloc(100 * sizeof(int));
    for(int i = 0; i < 100; i++){
        vet[i] = i;
    }
    fwrite(vet, sizeof(int), 100, arquivo_bin);
    for(int i = 0; i < 100; i++){
        fprintf(arquivo_txt, "%d ", vet[i]);
    }
    int *v = (int*)malloc(100 * sizeof(int));
    fclose(arquivo_txt);
    fclose(arquivo_bin);
    free(vet);
    free(v);
    return 0;
}