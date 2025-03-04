//Defina um registro que descreve um peixe. O registro deve incluir o tipo (string), o peso (ponto-flutuante) e o comprimento (inteiro) do peixe

#include<stdio.h>
#include<stdlib.h>

//definindo o registro
struct peixe{
    char tipo[20];
    float peso;
    int comprimento;
};

int main(){

//a) criando uma variável de tipo peixe
struct peixe peixe1 = {"Tambaqui", 1.4, 70};

//b) criando um ponteiro para variável de tipo peixe
struct peixe *ptrpeixe = &peixe1;

return(0);
}

