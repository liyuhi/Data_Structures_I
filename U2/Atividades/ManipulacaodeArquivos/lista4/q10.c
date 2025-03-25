//Construa um programa que leia um número desconhecido de peixes de um arquivo texto (semelhante ao arquivo utilizado na primeira questão) e grave estas informações em um arquivo binário que possa ser lido pelo programa da segunda questão. Compare o tamanho dos arquivos texto e binário.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[20];
    unsigned peso;
    float comp;
} peixe;

int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo = fopen("arquivo.txt", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    int num;
    printf("Quantos peixes deseja cadastrar? ");
    scanf("%d", &num);
    setbuf(stdin, NULL);
    peixe *peixes = (peixe*)malloc(num * sizeof(peixe));
    for(int x = 0; x < num; x++){
        peixe *p = &peixes[x];

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
    }
    fclose(arquivo);
    free(peixes);

    printf("Peixe salvo com sucesso!\n");
    return 0;
}


