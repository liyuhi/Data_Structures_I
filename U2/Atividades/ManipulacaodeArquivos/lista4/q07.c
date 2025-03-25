/*Uma palavra é um palíndromo se a sequência de letras que a forma é a mesma quando lida da esquerda para a direita ou da direita para a esquerda (ex: raiar). Escreva uma função que seja capaz de descobrir se uma palavra é um palíndromo. Nesta verificação desconsidere maiúsculas e minúsculas (i.e. Ana é um palíndromo).
O programa deve ler um número indefinido de palavras de um arquivo texto e,
para cada palavra, verificar se ela é ou não um palíndromo. Exiba a quantidade de palíndromos encontrados no texto, bem como as palavras que são palíndromos, como mostrado abaixo:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define max 100

int eh_palindromo(char *palavra){
    int i, j;
    int len = strlen(palavra);
    
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (tolower(palavra[i]) != tolower(palavra[j])) {
            return 0;
        }
    }
    return 1;
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo;
    char palavra[max];
    int contador = 0;
    arquivo = fopen("palindromos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    printf("Arquivo: palindromos.txt\n");
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        if (eh_palindromo(palavra)){
            printf("%s\n", palavra);
            contador++;
        }
    }
    printf("Foram encontrados %d palíndromos neste arquivo.\n", contador);
    fclose(arquivo);
    return 0;
}


