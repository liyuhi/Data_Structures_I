//Modifique o programa para ler a quinta palavra do arquivo de texto

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char word[100];
    int count = 0;
   
    while(fscanf(fin, "%s", word) == 1){
        count++;
        if(count == 5){
            break;
        }
    }
    fclose(fin);

    if(count == 5){
        printf("A quinta palavra é: %s\n", word);
    }else{
        printf("O arquivo não contém cinco palavras.\n");
    }

    return 0;
}

