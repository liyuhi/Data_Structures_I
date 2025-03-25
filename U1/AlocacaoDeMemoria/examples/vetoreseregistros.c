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
    struct jogador jogadores[3] = {
        {"Ronaldo", 50000.0, 30},
        {"Messi", 75000.0, 40},
        {"Neymar", 60000.0, 25}
    };
    
    for(int i = 0; i < 3; i++){
        printf("Nome: %s, Salário: %.2f, Gols: %d\n",
        jogadores[i].nome, jogadores[i].salario, jogadores[i].gols);
    }
    return 0;
}