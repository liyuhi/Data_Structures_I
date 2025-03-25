//Escreva um programa para ler todos os números do texto e gravá-los em outro arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void numeros(const char *entrada, const char *saida) {
    FILE *arqentrada = fopen(entrada, "r");
    FILE *arqsaida = fopen(saida, "w");

    if (arqentrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    if (arqsaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(arqentrada); 
        return;
    }

    int c;
    while ((c = fgetc(arqentrada)) != EOF) {
        if (isdigit(c)) {
            ungetc(c, arqentrada); 
            int num;
            fscanf(arqentrada, "%d", &num); 
            fprintf(arqsaida, "%d\n", num); 
        }
    }

    fclose(arqentrada);
    fclose(arqsaida);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    const char *arqentrada = "entrada.txt"; 
    const char *arqsaida = "saida.txt";     

    numeros(arqentrada, arqsaida);

    printf("Números gravados em %s\n", arqsaida);

    return 0;
}