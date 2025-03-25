//Modifique o programa obtido no item anterior para ler e exibir os peixes cadastrados no arquivo binário antes de permitir que o usuário faça um novo cadastro.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[20];
    unsigned peso;
    float comp;
} peixe;

int main() {
    setlocale(LC_ALL, "Portuguese");
    peixe p;
    FILE *arquivo = fopen("arquivo.txt", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    printf("Dados do arquivo:\n");
    while (fread(&p, sizeof(peixe), 1, arquivo) == 1) {
        printf("Nome: %s ", p.nome);
        printf("Peso: %u ", p.peso);
        printf("Comprimento: %.2f\n", p.comp);
    }
    fclose(arquivo);
    return 0;
}