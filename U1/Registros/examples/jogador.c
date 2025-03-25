#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct jogador{
    char nome[20];
    float salario;
    unsigned gols;
};

int main(){
    struct jogador pele = {"Pelé", 100000, 230};
    printf("Nome = %s\n", pele.nome);
    printf("Salário = %.2f\n", pele.salario);
    printf("Gols = %u\n", pele.gols);

    struct jogador * ptr = &pele;
    printf("Nome = %s\n", ptr->nome);
    printf("Salário = %.2f\n", ptr->salario);
    printf("Gols = %u\n", ptr->gols);

    return(0);
}