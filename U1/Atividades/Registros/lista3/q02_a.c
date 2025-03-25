//Como criar uma variável de tipo peixe.

#include<stdio.h>
#include<stdlib.h>

struct peixe{
    char tipo[20];
    float peso;
    int comprimento;
};

int main(){

    struct peixe peixe1 = {"Atum", 680, 300};  

    return 0;
}

