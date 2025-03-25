//Construa um programa que leia um número desconhecido de peixes de um arquivo texto, chamado “pescado.txt”, e exiba a quantidade total de quilos de peixe pescado. O arquivo é formatado como no exemplo abaixo: o nome do peixe, o peso em gramas e o comprimento em centímetros.

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *arq;
    char nome[50];
    int pesoGramas;
    int comprimento;
    float pesototal = 0.0;

    arq = fopen("pescado.txt", "r");
    
    while(fscanf(arq, "%s %d %d", nome, &pesoGramas, &comprimento) == 3){
        pesototal += pesoGramas / 1000.0;
    }

    fclose(arq);

    printf("Peso total de peixe pescado: %.2fkg\n", pesototal);

    return 0;
}