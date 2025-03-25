/* Descubra o que acontece ao tentarmos acessar um ponteiro que contém umendereço inválido. Para isso tente mostrar o conteúdo apontado por um ponteiro
recém-criado:*/

#include<stdio.h>

int main() {
    int *ptr; 

    printf("Valor apontado = %d\n", *ptr);

    return (0);
}

