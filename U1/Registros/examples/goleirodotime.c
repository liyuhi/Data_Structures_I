#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct jogador {
    char nome[20];
    float salario;
    unsigned gols;
};

int main() {
    setlocale(LC_ALL, "portuguese");
    struct jogador time[11]; 
    struct jogador * goleiro = &time[0];  //ponteiro para o goleiro (primeiro jogador)


    printf("Digite o nome, salário e gols de dois jogadores:\n");
    //leitura dos dados do primeiro jogador (time[0])
    printf("Jogador 1:\n");
    scanf("%s", time[0].nome);
    scanf("%f", &time[0].salario);
    scanf("%u", &time[0].gols);

    //leitura dos dados do segundo jogador (time[1])
    printf("Jogador 2:\n");
    scanf("%s", time[1].nome);
    scanf("%f", &time[1].salario);
    scanf("%u", &time[1].gols);

    printf("\nO goleiro do time é: %s\n", goleiro->nome);

    return 0;
}
