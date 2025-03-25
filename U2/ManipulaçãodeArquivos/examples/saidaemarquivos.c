#include <stdio.h>

int main() {
    FILE *arquivo; 
   
    arquivo = fopen("arquivo_texto.txt", "w");

    fprintf(arquivo, "Linha de arquivo = 30\n");
    fprintf(arquivo, "Linha de exemplo = 39\n"); 

    fclose(arquivo);

    printf("Arquivo gravado com sucesso!\n");

    return 0;
}
