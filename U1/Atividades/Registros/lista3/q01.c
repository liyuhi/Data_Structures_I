//Crie um programa que peça ao usuário para digitar o número de alunos em uma turma. O programa deve usar essa informação para criar um vetor dinâmico que armazene as notas finais desses alunos. Peça ao usuário para entrar com a nota de dois alunos e em seguida mostre essas notas usando cout.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int qtdAlunos;
    float *notas;

    printf("Digite o número de alunos (mínimo 2): ");
    scanf("%d", &qtdAlunos);

    if (qtdAlunos < 2) {
        printf("O número de alunos deve ser pelo menos 2.\n");
        return 1;
    }

    notas = (float *)malloc(qtdAlunos * sizeof(float));
    if (notas == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite a nota de dois alunos:\n");
    scanf("%f %f", &notas[0], &notas[1]);

    printf("As notas digitadas foram %.1f e %.1f\n", notas[0], notas[1]);

    free(notas);

    return 0;
}
