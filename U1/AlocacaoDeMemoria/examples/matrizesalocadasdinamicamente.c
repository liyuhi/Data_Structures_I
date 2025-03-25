#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int linhas = 3, colunas = 4;
    int i, j;

    int **matriz = (int **)malloc(linhas * sizeof(int*));
    if (matriz == NULL){
        printf("Erro ao alocar memória para as linhas.\n", i);
        return 1;
    }

    for(i=0; i<linhas; i++){
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if(matriz[i] == NULL){
            printf("Erro ao alocar memória para a linha %d.\n", i);
            for (j=0; j<i; j++){
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
    }

    for (i = 0; i<linhas; i++){
        for (j=0; j<colunas; j++){
            matriz[i][j] = i * colunas + j;
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    for (i=0; i<linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}