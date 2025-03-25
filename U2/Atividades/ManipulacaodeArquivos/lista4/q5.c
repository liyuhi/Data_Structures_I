//Escreva um programa em C que abra um arquivo texto, leia caractere a caractere até o fim do arquivo e exiba na tela o número total de caracteres, o número de vogais, o número de consoantes, e a quantidade de outros caracteres presentes no texto.

#include<stdio.h>
#include<ctype.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    FILE *arq;
    char ch;
    int totalcarac = 0, vogais = 0, consoantes = 0, outros = 0;

    const char *arqnome = "texto.txt"; 

    arq = fopen(arqnome, "r");
   
    while ((ch = fgetc(arq)) != EOF) {
        totalcarac++;

        if (isalpha(ch)) {
            ch = tolower(ch);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vogais++;
            } else {
                consoantes++;
            }
        } else {
            outros++;
        }
    }

    fclose(arq);

    printf("Total de caracteres: %d\n", totalcarac);
    printf("Número de vogais: %d\n", vogais);
    printf("Número de consoantes: %d\n", consoantes);
    printf("Número de outros caracteres: %d\n", outros);

    return 0;
}