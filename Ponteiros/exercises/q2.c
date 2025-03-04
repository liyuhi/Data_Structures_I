//Declare uma variável e “printe” o valor dela e o seu endereço.

#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int cafe = 20;

    printf("Valor de café = %d\n", cafe);
    printf("Endereço de café = %p", &cafe);

    return(0);
}

