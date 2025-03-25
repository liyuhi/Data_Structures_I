#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "portuguese"); 
    char nome[20] = "Lilith";
    printf("%s\n", nome);

    char * ptr = &nome[1]; //aponta para o segundo caractere do nome ('i')
    *ptr = 'y'; //'i' vira 'y'
    printf("%s\n", ptr); //imprime a partir de ptr, que é o segundo caractere

    nome[3] = 'y'; //modifica o quarto caractere ('l'), virando 'y'
    printf("%s\n", nome);

    *ptr = 'i'; //troca o 'y' por 'i'
    printf("%s\n", nome);

    return(0);
}
