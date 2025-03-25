#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Digite quantos jogadores tem no seu time: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL){
        printf("Erro na alocação de memória!\n");
        return 1;
    }

    printf("Vetor inicial:\n");
    int i;
    for(i=0;i<n; i++){
        printf("%d ", vetor[i]);
    }
    return 0;
}