//Implemente uma fila de prioridade, onde elementos com maior prioridade são atendidos primeiro.

#include <stdio.h>
#include <string.h>
#include <locale.h>


#define max 100


typedef struct {
    char nome[max];
    int prioridade;
} Paciente;


void adiciona(Paciente fila[], int *tam, char nome[], int prioridade) {
    strcpy(fila[*tam].nome, nome);
    fila[*tam].prioridade = prioridade;
    (*tam)++;
}
void orderna(Paciente fila[], int tam) {
    Paciente temp;
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (fila[i].prioridade < fila[j].prioridade ||
                (fila[i].prioridade == fila[j].prioridade && i > j)) {
                temp = fila[i];
                fila[i] = fila[j];
                fila[j] = temp;
            }
        }
    }
}
void atender(Paciente fila[], int *tam) {
    if (*tam > 0) {
        printf("Atendendo %s\n", fila[0].nome);
        for (int i = 1; i < *tam; i++) {
            fila[i - 1] = fila[i];
        }
        (*tam)--;
    } else{
        printf("Nenhum paciente na fila.\n");
    }
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    Paciente fila[max];
    int tam = 0;
    adiciona(fila, &tam, "Paciente A", 2);
    adiciona(fila, &tam, "Paciente B", 1);
    adiciona(fila, &tam, "Paciente C", 4);
    orderna(fila, tam);
    atender(fila, &tam);
    atender(fila, &tam);
    atender(fila, &tam);
    return 0;
}
