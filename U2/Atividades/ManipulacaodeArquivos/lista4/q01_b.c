//Modifique o programa para ler uma palavra do arquivo de texto

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char word[100];
   
    fscanf(fin, "%s", word);
    fclose(fin);

    printf("%s\n", word); 
    return 0;
}

