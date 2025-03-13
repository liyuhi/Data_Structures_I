#include<stdio.h>

int buscaLinear(int lista[], int tamanho, int elemento){
    for (int i=0; i<tamanho - 1; i++){
        if(lista[i] == elemento){
            return i;
        }
    }
    return -1;
}

int main(){
    int lista[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(lista)/sizeof(lista[0]);
    int elemento = 30;

    int resultado = buscaLinear(lista, tamanho, elemento);

    printf("%d\n", resultado);

    return 0;
}