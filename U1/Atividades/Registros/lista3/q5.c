/*Construa um vetor dinâmico de alunos. O registro aluno deve ser composto por nome (ou matrícula), código da disciplina (número inteiro sem sinal), e situação da disciplina. A situação da disciplina deve ser uma enumeração com os valores: Aprovado, Trancado, Reprovado. Peça ao usuário para digitar o número de alunos do vetor e em seguida leia os dados do primeiro aluno.
Para finalizar mostre os dados do primeiro aluno usando uma função que recebe um ponteiro para aluno.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef enum { Aprovado, Trancado, Reprovado } Situacao;

struct aluno {
    char nome[50];
    unsigned int cod_disciplina;
    Situacao situacao;
};

void dadosalunos(struct aluno *ptr) {
    const char *situacaos[] = {"Aprovado", "Trancado", "Reprovado"};
    printf("\n--- Dados do Aluno ---\n");
    printf("Nome do Aluno: %s\n", ptr->nome);
    printf("Código da Disciplina: %u\n", ptr->cod_disciplina);
    printf("Situação da Disciplina: %s\n", situacaos[ptr->situacao]);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int quantidade;

    printf("Digite o número de alunos: ");
    scanf("%d", &quantidade);
    getchar(); 

    struct aluno *alunos = (struct aluno *)malloc(quantidade * sizeof(struct aluno));

    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\nDigite os dados do aluno %d:\n", i + 1);

        printf("Nome: ");
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';

        printf("Código da disciplina: ");
        scanf("%u", &alunos[i].cod_disciplina);
        getchar();

        printf("Situação da Disciplina:\n (0) Aprovado \n (1) Trancado \n (2) Reprovado\n");

        int situacao;
        while (1) {
            printf("Escolha a opção: ");
            if (scanf("%d", &situacao) == 1 && situacao >= 0 && situacao <= 2) {
                alunos[i].situacao = (Situacao)situacao;
                getchar();
                break;
            } else {
                printf("Opção inválida. Tente novamente.\n");
                while (getchar() != '\n');
            }
        }
    }

    printf("\n=== Lista de Alunos ===\n");
    for (int i = 0; i < quantidade; i++) {
        dadosalunos(&alunos[i]);
    }

    free(alunos);

    return 0;
}
