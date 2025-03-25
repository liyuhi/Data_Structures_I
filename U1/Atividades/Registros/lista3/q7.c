//Declare um ponteiro para inteiro, aloque memória dinamicamente para ele e armazene o número 100 nessa memória. Mostre o conteúdo apontado. Peça que o usuário digite um novo número inteiro e armazene-o na memória previamente alocada. Libere o espaço alocado dinamicamente ao final do programa.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int *p;

    p = (int *)malloc(sizeof(int));

    if (p == NULL){
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    *p = 100;

    printf("Conteúdo armazenado: %d\n", *p);

    printf("Digite novo valor para esse bloco de memória: ");
    scanf("%d", p);

    free(p);

    return 0;
}
