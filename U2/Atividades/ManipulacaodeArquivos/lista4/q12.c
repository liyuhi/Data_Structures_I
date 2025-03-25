// Construa um programa que leia do usuário uma sequência de números inteiros, até que o número zero seja lido. Os números devem ser armazenados em um arquivo binário chamado “vet.dat”. O primeiro número do arquivo deve ser a quantidade de números digitados. Na entrada do programa verifique se o arquivo existe e, caso positivo, exiba os valores do vetor.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int *vet = NULL;
    int tamanho = 0;
    int num = 0;

    while (1) {
        printf("Digite um número inteiro: ");
        scanf("%d", &num);
        setbuf(stdin, NULL);

        if (num == 0) {
            break;
        }

        vet = realloc(vet, (tamanho + 1) * sizeof(int));
        if (vet == NULL) {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        vet[tamanho] = num;
        tamanho++;

        printf("Número %d salvo com sucesso.\n\n", num);
    }

    FILE *arquivo = fopen("vet.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fwrite(&tamanho, sizeof(int), 1, arquivo);
    fclose(arquivo);

    arquivo = fopen("vet.dat", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para adicionar números.\n");
        return 1;
    }

    fwrite(vet, sizeof(int), tamanho, arquivo);
    fclose(arquivo);

    arquivo = fopen("vet.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    fread(&tamanho, sizeof(int), 1, arquivo);

    int *valores = (int *)malloc(tamanho * sizeof(int));
    if (valores == NULL) {
        printf("Erro ao alocar memória para leitura.\n");
        return 1;
    }

    fread(valores, sizeof(int), tamanho, arquivo);

    printf("Conteúdo do arquivo:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    free(vet);
    free(valores);
    fclose(arquivo);

    return 0;
}

