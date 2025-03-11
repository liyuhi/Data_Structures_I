#include<stdio.h>
#include<stdlib.h>

// Definindo o registro
struct peixe{
    char tipo[20];
    float peso;
    int comprimento;
};

int main(){

    // a) Criando uma variável de tipo peixe
    struct peixe peixe1 = {"Atum", 680.0f, 300};  // peso é um float e comprimento é um inteiro

    // b) Criando um ponteiro para variável de tipo peixe
    struct peixe *ptrpeixe = &peixe1;

    return 0;
}
