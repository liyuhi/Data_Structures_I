//Inicie o programa perguntando ao usuário quantos inteiros ele deseja armazenar em um vetor. Use a informação digitada para criar um vetor dinâmico com o espaço necessário para armazenar a quantidade de inteiros desejada. Depois disso, deixe que o próprio usuário preencha o vetor, utilizando o tamanho do vetor como condição de parada de um laço for. Mostre o vetor que foi preenchido através de outro laço e libere o espaço alocado dinamicamente ao final do programa.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int n;
    int *vet;

    printf("Quantos valores deseja guardar? ");
    scanf("%d", &n);

    vet= (int *)malloc(n *sizeof(int));

    if(vet == NULL){
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Quais valores?\n");
    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    printf("Os valores ");
    for (int i = 0; i < n; i++) {
        printf("%d", vet[i]);
        if (i == n - 2) {
            printf(" e "); 
        } else if (i < n - 2) {
            printf(", "); 
        }
    }
    printf(" foram armazenados.\n");
    

    free(vet);

    return 0;
}

