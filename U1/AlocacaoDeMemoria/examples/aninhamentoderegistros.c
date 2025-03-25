#include<stdio.h>
#include<locale.h>

struct jogador{
    char nome[20];
    float salario;
    int gols;
};

struct time{
    char nome[30];
    struct jogador capitao;
};

int main(){
    setlocale(LC_ALL, "portuguese");
    struct time time1 = {"Vasco", {"Coutinho", 1500000.0, 150}};
    printf("Time: %s\n", time1.nome);
    printf("Capitão: %s\n", time1.capitao.nome);
    printf("Salário do Capitão: %.2f\n", time1.capitao.salario);
    printf("Gols do Capitão: %d\n", time1.capitao.gols);

    return 0;
}
