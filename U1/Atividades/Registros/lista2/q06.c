//Crie uma variável do tipo char inicializada para o caractere 'A' e um ponteiro que aponte para esta variável. Modifique a variável criada usando o ponteiro, de forma que seu conteúdo agora seja 'B'. Por fim, mostre o conteúdo da variável e o conteúdo apontado pelo ponteiro.

#include<stdio.h>
#include<locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    char var = 'A';  
    char *ptr = &var;  

    *ptr = 'B';

    printf("Conteúdo da variável: %c\n", var);
    printf("Conteúdo apontado pelo ponteiro: %c\n", *ptr);

    return (0);
}

