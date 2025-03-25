/* No exercício anterior, se o usuário digitar apenas espaços para a mensagem, o resultado será uma faixa colorida com a cor de fundo. Podemos usar isso para criar uma imagem formada apenas por caracteres de espaço coloridos.
Construa um programa que peça a largura e altura da imagem e leia do usuário uma matriz de números. Cada número de 3 dígitos representa a cor de um “bloco” da imagem. Guarde em um arquivo binário os valores de altura, largura e de cada bloco da imagem. Assim como o programa anterior, construa um menu para controlar as opções de armazenamento e exibição da imagem.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    int largura;
    int altura;
    int cores[100][100];
} Imagem;

void armazenar() {
    FILE *arquivo = fopen("imagem.bin", "wb");
    if (arquivo == NULL) {
        printf(">> Erro ao abrir o arquivo.\n");
        exit(1);
    }
    Imagem img;
    printf("Digite a largura da imagem: ");
    scanf("%d", &img.largura);
    setbuf(stdin, NULL);
    printf("Digite a altura da imagem: ");
    scanf("%d", &img.altura);
    setbuf(stdin, NULL);

    printf("Digite os valores da matriz (%d x %d) [000 a 255]:\n", img.altura, img.largura);
    for (int i = 0; i < img.altura; i++) {
        for (int j = 0; j < img.largura; j++) {
            scanf("%d", &img.cores[i][j]);
            setbuf(stdin, NULL);
        }
    }
    fwrite(&img, sizeof(Imagem), 1, arquivo);
    fclose(arquivo);
    printf("\n>> Imagem armazenada com sucesso.\n");
}

void exibir() {
    FILE *arquivo = fopen("imagem.bin", "rb");
    if (arquivo == NULL) {
        printf(">> Nenhuma imagem encontrada.\n");
        exit(1);
    }
    Imagem img;
    fread(&img, sizeof(Imagem), 1, arquivo);
    fclose(arquivo);

    printf("\nImagem carregada (%dx%d):\n", img.largura, img.altura);
    for (int i = 0; i < img.altura; i++) {
        for (int j = 0; j < img.largura; j++) {
            printf("\033[48;5;%03dm  \033[0m", img.cores[i][j]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    while(1) {
        printf("Imagens Coloridas\n");
        printf("-----------------\n");
        printf("[A]rmazenar imagem\n");
        printf("[E]xibir imagem\n");
        printf("[S]air\n");
        printf("-----------------\n");
        printf("Opção: ");
        scanf("%c", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {
            case 'A':
                armazenar();
                break;
            case 'E':
                exibir();
                break;
            case 'S':
                printf(">> Obrigado, volte sempre!\n");
                return 0;
            default:
                printf(">> Opçãoo inválida, tente novamente.\n");
        }
    }
}


