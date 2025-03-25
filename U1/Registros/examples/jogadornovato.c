#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct jogador{
    char nome[20];
    float salario;
    unsigned gols;
};

void exibir(struct jogador *ptr){
    printf("Nome: %s\n", ptr->nome);
    printf("Salário: %.2f\n", ptr->salario);
    printf("Gols: %u\n", ptr->gols);
}

int main(){
    setlocale(LC_ALL, "portuguese");

    struct jogador novato = {"Pedro", 100000, 19};
    exibir(&novato);

    return 0;
}
