// Construa um programa que leia um arquivo texto contendo o nome e as três notas de vários alunos (uma quantidade indefinida de alunos). Escreva em outro arquivo texto o nome e a situação do aluno (aprovado, quarta prova ou reprovado).

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *entrada, *saida;
    char nome[50];
    float n1, n2, n3, media;

    entrada = fopen("notas.txt", "r");
    saida = fopen("situacao.txt", "w");

    while(fscanf(entrada, "%s %f %f %f", nome, &n1, &n2, &n3) == 4){
        media = (n1 + n2 + n3) / 3.0;
       
        if(media >= 7){
            fprintf(saida, "%s Aprovado\n", nome);
        }else if(media >= 4){
            fprintf(saida, "%s Quarta Prova\n", nome);
        }else{
            fprintf(saida, "%s Reprovado\n", nome);
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Situação dos alunos escrita em 'situacao.txt'.\n");

    return 0;
}