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

void exibir2(struct jogador j){
    printf("Nome: %s\n", j.nome);
    printf("Salário: %.2f\n", j.salario);
    printf("Gols: %u\n", j.gols);
    j.salario = 0; 
}

int main(){
    setlocale(LC_ALL, "portuguese");
    struct jogador time[11]; 

    struct jogador novato = {"Pedro", 150000, 19}; 
    
    
    exibir(&novato);
    exibir2(novato);

    printf("\nO novo salário de Pedro: %.2f", novato.salario);  // O salário de 'novato' não mudou
    return(0);
}
