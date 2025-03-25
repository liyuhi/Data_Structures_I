
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char turno;
    int serie;
    char sexo; 
} aluno;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int num;
    FILE *arquivo = fopen("arquivo.txt", "w");

    printf("Quantos alunos você deseja cadastrar? ");
    scanf("%d", &num);
    setbuf(stdin, NULL);
    aluno *alunos = (aluno*)malloc(num * sizeof(aluno));
    aluno *p;

    for (int x = 0; x < num; x++) {
        p = &alunos[x];
        printf("Nome do %dº aluno: ", x + 1);
        fgets(p->nome, 50, stdin);
        p->nome[strcspn(p->nome, "\n")] = 0;
        setbuf(stdin, NULL);

        printf("Turno (M/T): ");
        scanf(" %c", &p->turno);
        setbuf(stdin, NULL);

        printf("Série: ");
        scanf("%d", &p->serie);
        setbuf(stdin, NULL);

        printf("Sexo (M/F): ");
        scanf(" %c", &p->sexo); // Leitura do sexo
        setbuf(stdin, NULL);
    }

    // Exibir alunos por sexo
    fprintf(arquivo, "\nAlunos Masculinos\n");
    fprintf(arquivo, "-----------------\n");
    for (int i = 0; i < num; i++) {
        p = &alunos[i];
        if (p->sexo == 'M') {
            fprintf(arquivo, "%-15s%c%d\n", p->nome, p->turno, p->serie);
        }
    }

    fprintf(arquivo, "\nAlunos Femininos\n");
    fprintf(arquivo, "-----------------\n");
    for (int i = 0; i < num; i++) {
        p = &alunos[i];
        if (p->sexo == 'F') {
            fprintf(arquivo, "%-15s%c%d\n", p->nome, p->turno, p->serie);
        }
    }

    fclose(arquivo);
    free(alunos);
    return 0;
}