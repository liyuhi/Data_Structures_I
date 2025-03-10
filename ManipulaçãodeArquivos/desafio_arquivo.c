#include<stdio.h>

void criararquivo(){
    FILE *arquivo = fopen("dados.txt", "w");

    fprintf(arquivo, "Nome: Joãozinho\n");
    fprintf(arquivo, "Idade: 24\n");
    fprintf(arquivo, "Cidade: Pau dos Ferros\n");

    fclose(arquivo);
    printf("Arquivo criado e preenchido com sucesso!\n");
}

void lerarquivo(){
    FILE *arquivo = fopen("dados.txt", "r");

    char linha[100];
    printf("\nConteúdo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }
    fclose(arquivo);
} 

void alterararquivo(){
    FILE *arquivo = fopen("dados.txt", "r");

    char buffer[500] = "";
    char linha{100};

    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "Idade: 24") != NULL){
            strcat(buffer, "Idade: 42\n");
        }else{
            strcat(buffer, linha);
        }
    }
    fclose(arquivo);

    arquivo = fopen("dados.txt", "w");
    fprintf(arquivo, "%s", buffer);
    fclose(arquivo);
    printf("\nArquivo atualizado com sucesso!\n");
}

int main(){
    criararquivo();
    lerarquivo();
    alterararquivo();
    lerarquivo();

    return 0;
}