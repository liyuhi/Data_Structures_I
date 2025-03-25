//Escreva um programa que peça ao usuário para digitar um nome de arquivo texto e uma palavra que ele deseja procurar neste arquivo. O programa deve dizer se a palavra está ou não presente no arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<locale.h>

#define MAX_LINHA 256

int main() {
    setlocale(LC_ALL, "portuguese");

    char nome_arquivo[100];
    char palavra[100];
    FILE *arquivo;
    char linha[MAX_LINHA];
    int encontrada = 0;

    printf("Nome do arquivo: ");
    scanf("%s", nome_arquivo);

    printf("Palavra: ");
    scanf("%s", palavra);

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, palavra) != NULL) {
            encontrada = 1;
            break; 
        }
    }

    fclose(arquivo);

    if (encontrada) {
        printf("A palavra \"%s\" está presente no texto.\n", palavra);
    } else {
        printf("A palavra \"%s\" não está presente no texto.\n", palavra);
    }

    return 0;
}