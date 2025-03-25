/*Crie um registro Soldado com os campos nome, eliminações, mortes, taxa de eliminação por morte (eliminações/mortes) e número de partidas jogadas. Na função principal leia um soldado de um arquivo binário. Se o arquivo não
Para existir, você deve direcionar o usuário para a criação de um novo soldado. Quando o soldado for lido (seja pelo arquivo ou pelo teclado), você deve dar as seguintes opções ao usuário:*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char nome[50];
    int elim;
    int mortes;
    float taxa;
    int partidas;
} soldado;

void cad_soldado(soldado *p) {
    printf("Nome do soldado: ");
    fgets(p->nome, 50, stdin);
    setbuf(stdin, NULL);
    p->nome[strcspn(p->nome, "\n")] = 0;

    printf("Quantas eliminações: ");
    scanf("%d", &p->elim);
    setbuf(stdin, NULL);

    printf("Quantas mortes: ");
    scanf("%d", &p->mortes);
    setbuf(stdin, NULL);

    if (p->mortes == 0) {
        p->taxa = (float)p->elim;
    } else {
        p->taxa = (float)p->elim / p->mortes;
    }

    printf("Quantas partidas jogadas? ");
    scanf("%d", &p->partidas);
    setbuf(stdin, NULL);
}

void exibir(soldado *p) {
    printf("\n--- Soldado Atual ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Eliminações: %d\n", p->elim);
    printf("Mortes: %d\n", p->mortes);
    printf("Taxa de Eliminações: %.2f\n", p->taxa);
    printf("Partidas Jogadas: %d\n", p->partidas);
    printf("----------------------\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    soldado s;
    FILE *arquivo;
    char opcion;

    arquivo = fopen("binary.bin", "rb");
    if (arquivo) {
        fread(&s, sizeof(soldado), 1, arquivo);
        fclose(arquivo);
    } else {
        printf("Nenhum soldado encontrado. Criando um novo.\n");
        cad_soldado(&s);
        arquivo = fopen("binary.bin", "wb");
        fwrite(&s, sizeof(soldado), 1, arquivo);
        fclose(arquivo);
    }

    while (1) {
        printf("\n[N] Novo Soldado\n[A] Atualizar Soldado\n[E] Exibir Soldado\n[S] Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcion);
        setbuf(stdin, NULL);

        switch (opcion) {
            case 'N':
                cad_soldado(&s);
                arquivo = fopen("binary.bin", "wb");
                fwrite(&s, sizeof(soldado), 1, arquivo);
                fclose(arquivo);
                break;
            case 'A':
                cad_soldado(&s);
                arquivo = fopen("binary.bin", "wb");
                fwrite(&s, sizeof(soldado), 1, arquivo);
                fclose(arquivo);
                break;
            case 'E':
                exibir(&s);
                break;
            case 'S':
                printf("\n>> Obrigado, volte sempre.\n");
                return 0;
            default:
                printf("\n>> Opção inválida, tente novamente.\n");
                break;
        }
    }
}
