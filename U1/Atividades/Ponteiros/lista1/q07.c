/*Desenvolva uma função que receba como parâmetro os ponteiros de
dois vetores de 5 posições. O procedimento deverá imprimir na tela os
valores contidos nos dois vetores de forma crescente (Utilize ponteiros).
Exemplo:
Vetor 1 = 2, 5, 9, 8, 3
Vetor 2 = 7, 4, 1, 10, 6
Saída: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10*/

#include<stdio.h>
#include<locale.h>

void ordenarimprimir(int *vetor1, int *vetor2) {
    int vetorc[10];  //armazenar os valores dos dois vetores
    int i, j, temp;

    //valores do vetor1 e vetor2 para vetorc
    for(i = 0; i < 5; i++) {
        vetorc[i] = *(vetor1 + i);  //valores do vetor1 usando ponteiro
        vetorc[i + 5] = *(vetor2 + i);  //valores do vetor2 usando ponteiro
    }

    //ordenando em ordem crescente
    for(i = 0; i < 9; i++) {
        for(j = i + 1; j < 10; j++) {
            if(vetorc[i] > vetorc[j]) {
                temp = vetorc[i];
                vetorc[i] = vetorc[j];
                vetorc[j] = temp;
            }
        }
    }

    //imprimindo os valores ordenados
    printf("Valores ordenados: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", vetorc[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int vetor1[5] = {2, 5, 9, 8, 3};
    int vetor2[5] = {7, 4, 1, 10, 6};

    ordenarimprimir(vetor1, vetor2);

    return 0;
}
