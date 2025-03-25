//Escreva um programa que leia um valor inteiro do usuário e armazene-o em um arquivo binário chamado “interger.bin”. Ao entrar, o programa deve verificar se o arquivo “integer.bin” existe, e em caso positivo, deve ler e exibir o número na tela.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo = fopen("interger.bin", "wb");
    int num;
    printf("Digite um valor inteiro: ");
    scanf("%d", &num);
    setbuf(stdin, NULL);

    fwrite(&num, sizeof(int), 1, arquivo);

    fclose(arquivo);
    
    arquivo = fopen("interger.bin", "rb");

    if(arquivo == NULL){
        printf(">> Arquivo inexistente.\n");
        exit(1);
    }

    int n;
    fread(&n, sizeof(int), 1, arquivo);
    printf("Conteudo do arquivo: %d", n);
    fclose(arquivo);
    return 0;
}


