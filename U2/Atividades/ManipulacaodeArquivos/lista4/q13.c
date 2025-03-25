// O Exercício de Revisão 1 do Laboratório 6 (Tipos Inteiros) mostra como usar códigos de Escape para mudar a cor do texto exibido em um terminal. A sequência de caracteres "\033[38;5;000;48;5;154m" define a cor 000 para o texto e 154 para o fundo. Considerando que as cores são valores de 3 dígitos de 000 a 255, construa um programa para ler do usuário um texto com no máximo 80 caracteres, um código para a cor do texto e um código para a cor do fundo. Guarde essas informações em um arquivo binário. O usuário deve ter a opção de guardar uma nova frase ou exibir a frase já armazenada através de um menu, como mostrado no exemplo abaixo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define max 80

typedef struct {
    char mensagem[max];
    int cor_texto;
    int cor_fundo;
} Mensagem;

void armazenar() {
    FILE *arquivo = fopen("mensagem.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    Mensagem msg;
    printf("Sua mensagem: ");
    fgets(msg.mensagem, max, stdin);
    setbuf(stdin, NULL);
    msg.mensagem[strcspn(msg.mensagem, "\n")] = '\0';

    printf("Cor do texto (000-255): ");
    scanf("%d", &msg.cor_texto);
    setbuf(stdin, NULL);
    printf("Cor do fundo (000-255): ");
    scanf("%d", &msg.cor_fundo);
    setbuf(stdin, NULL);
    fwrite(&msg, sizeof(Mensagem), 1, arquivo);
    fclose(arquivo);
    printf("\nTexto colorido foi armazenado.\n");
}
void exibir() {
    FILE *arquivo = fopen("mensagem.bin", "rb");
    if (arquivo == NULL) {
        printf(">> Erro ao abrir arquivo.\n");
        exit(1);
    }
    Mensagem msg;
    fread(&msg, sizeof(Mensagem), 1, arquivo);
    fclose(arquivo);
    printf("\n\033[38;5;%03d;48;5;%03dm%s\033[0m\n", msg.cor_texto, msg.cor_fundo, msg.mensagem);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    char opcao;
    while(1){
        printf("Mensagens Coloridas\n");
        printf("-------------------\n");
        printf("[A]rmazenar\n");
        printf("[E]xibir\n");
        printf("[S]air\n");
        printf("-------------------\n");
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
                printf(">> Obrigado, volte sempre\n");
                return 0;
            default:
                printf(">> Opção inválida, por favor tente novamente.\n");
        }
    }
}

