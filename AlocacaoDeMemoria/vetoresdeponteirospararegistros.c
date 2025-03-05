#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct jogador{
    char nome[20];
    float salario;
    int gols;
};

int main(){
    setlocale(LC_ALL, "portuguese");
    struct jogador *jogadores[3];

    int i;
    for(int i=0; i<3; i++){
        jogadores[i] = (struct jogador *)malloc(sizeof(struct jogador));
        sprintf(jogadores[i]->nome, "jogador %d", i+1);
        jogadores[i]->salario = 50000.0 + (i*1000);
        jogadores[i]->gols = 20 + (i*5);
    }

    for (int i = 0; i<3; i++){
        printf("Nome: %s, Salário: %.2f, Gols: %d\n",
                jogadores[i]->nome, jogadores[i]->salario, jogadores[i]->gols);
        free(jogadores[i]);
    }
    return 0;
}