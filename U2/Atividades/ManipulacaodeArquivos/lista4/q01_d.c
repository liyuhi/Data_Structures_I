//Modifique o programa para ler uma linha do arquivo de texto

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char linha[100];
   
    if(fgets(linha, sizeof(linha), fin) != NULL){
        printf("A linha lida é: %s\n", linha);
    }else{
        printf("Erro ao ler a linha ou o arquivo está vazio.\n");
    }

    fclose(fin);
    return 0;
}

