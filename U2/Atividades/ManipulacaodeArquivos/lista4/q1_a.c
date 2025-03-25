//Modifique o programa para ler o oitavo caractere do arquivo de texto

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");

    FILE *fin;
    fin = fopen("intro.txt", "r");

    char ch;
    int count = 0;

    while(fscanf(fin, "%c", &ch) == 1){
        count++;
        if(count == 8){
            printf("O oitavo caractere é: %c\n", ch);
            break;
        }
    }
    fclose(fin);
    
    return 0;
}

