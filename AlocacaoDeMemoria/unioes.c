#include<stdio.h>
#include<locale.h>

union info{
    float salario;
    int gols;
};

int main(){
    setlocale(LC_ALL, "portuguese");
    union info jogador;

    jogador.salario = 55000.0;
    printf("Salário: %.2f\n", jogador.salario);

    jogador.gols = 35;
    printf("Gols: %d\n", jogador.gols);
    return 0;
}