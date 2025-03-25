//Qual é a maneira correta de referenciar ch, assumindo que o endereço de ch foi atribuído ao ponteiro indica?

#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    
    int ch = 10;
    int * indica = &ch; //O endereço de ch é atribuído ao ponteiro indica

    printf("Endereço de ch = %p", indica);
    printf("Valor de ch = %d", *indica);

    return(0);
}

