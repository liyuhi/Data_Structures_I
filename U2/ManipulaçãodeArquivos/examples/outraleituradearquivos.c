#include<stdio.h>

int main(){
    arquivo = fopen("arquivo_texto.txt", "r");

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
        printf("%s", linha);
}  
    fclose(arquivo); 

    return 0;
}