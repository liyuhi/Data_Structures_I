//a) Construa um programa que leia do usuário os dados de um único peixe e salve-os em um arquivo binário. Cada execução do programa deve acrescentar um peixe ao arquivo.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char nome[20];
    unsigned peso;
    float comp;
} peixe;

int main() {
    setlocale(LC_ALL, "Portuguese");

    peixe *p = malloc(sizeof(peixe));
    if (p == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    FILE *arquivo = fopen("arquivo.txt", "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(p);
        return 1;
    }

    printf("Digite o nome do peixe: ");
    fgets(p->nome, 20, stdin);
    setbuf(stdin, NULL);
    p->nome[strcspn(p->nome, "\n")] = 0;

    printf("Digite o peso: ");
    scanf("%u", &p->peso);
    setbuf(stdin, NULL);

    printf("Digite o comprimento: ");
    scanf("%f", &p->comp);
    setbuf(stdin, NULL);

    fwrite(p, sizeof(peixe), 1, arquivo);

    fclose(arquivo);
    free(p);

    printf("Peixe salvo com sucesso!\n");
    return 0;
}


/*a) Construa um programa que 
leia do usuário
os dados de um único peixe e
salve-os em um arquivo binário. 
Cada execução do programa deve 
acrescentar um peixe ao arquivo.*/