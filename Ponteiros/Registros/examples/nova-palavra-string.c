#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "portuguese"); 
    char animal[10] = "Gato";  
    printf("Animal: %s\n", animal);  

    char *ptr = animal;
    *ptr = 'P';  //muda o primeiro caractere de 'G' para 'P'
    printf("Animal: %s\n", animal);  //imprime a string modificada, "Pato"

    ptr = &animal[1];  //faz ptr apontar para o segundo caractere da string ("a")
    printf("Animal: %s\n", ptr);  //imprime a string começando do segundo caractere ("ato")

    return(0);
}
