#include <stdio.h>
#include<stdlib.h>

int main() {
    FILE *arquivo = fopen("arquivo_texto.txt", "r"); // Declara um ponteiro para arquivo

    printf("Conteúdo do arquivo:\n");

    char c;
    while ((c = fgetc(arquivo)) != EOF) { // Lê caractere por caractere
        putchar(c); // Exibe o caractere na tela
    }

    printf("\n");

    fclose(arquivo); // Fecha o arquivo após a leitura
    return 0;
}
