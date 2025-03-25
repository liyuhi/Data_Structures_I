//Assumindo que o endereço da variável x foi atribuído a um ponteiro px, escreva uma expressão que não usa x e divida x por 3.

#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    
    int x = 15;
    int * px = &x;

    * px = * px / 3;

    printf("O valor de x é %d", x);

    return(0);
}

