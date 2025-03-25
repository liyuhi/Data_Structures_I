/*Construa uma função que receba um peixe e exiba o seu conteúdo.
a) Faça uma versão utilizando um parâmetro tipo peixe
b) Faça uma versão utilizando um parâmetro tipo ponteiro para peixe*/

#include<stdio.h>
#include<stdlib.h>

struct peixe {
    char tipo[20];
    float peso;
    int comprimento;
};

//função que utiliza um parâmetro tipo peixe
void exibirpeixe(struct peixe *t){
    printf("Tipo de peixe: %s\n", t->tipo);
    printf("Peso do peixe: %.2fkg\n", t->peso);
    printf("Comprimento do peixe: %dcm\n", t->comprimento);
}

int main(){
    struct peixe peixe1 = {"Atum", 680, 300};
    exibirpeixe(&peixe1);

    return(0);
}

