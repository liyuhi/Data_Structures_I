#include<stdio.h>
#include<string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {
    struct Pessoa p1 = {"Alice", 15};
    struct Pessoa *ptr;

    ptr = &p1;  //ponteiro apontando para a struct p1

    //acessando membros da struct usando o ponteiro
    printf("Nome: %s\n", ptr->nome);
    printf("Idade: %d\n", ptr->idade);

    return 0;
}

