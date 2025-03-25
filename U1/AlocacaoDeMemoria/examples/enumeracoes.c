#include<stdio.h>
#include<locale.h>

enum Posicao { GOLEIRO, ZAGUEIRO, MEIOCAMPO, ATACANTE };

struct jogador{
    char nome[20];
    float salario;
    int gols;
    enum Posicao posicao;
};

int main(){
    setlocale(LC_ALL, "portuguese");
    struct jogador j1 = {"Cristiano", 80000.0, 45, ATACANTE};
    
    if(j1.posicao == ATACANTE){
        printf("%s é atacante.\n", j1.nome);
    }

    return 0;
}