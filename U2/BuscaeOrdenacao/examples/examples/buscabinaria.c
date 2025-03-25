#include<stdio.h>
#include<locale.h>

int buscaBinaria(int lista[], int tamanho, int elemento){
    int esquerda = 0;
    int direita = tamanho - 1;

    while (esquerda<=direita){
        int meio = (esquerda+direita)/2;

        if(lista[meio] == elemento){
            return meio;
        }else if(lista[meio]<elemento){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }
    }
    return -1;
}

int main(){
    setlocale(LC_ALL, "portuguese");
    int lista[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(lista)/sizeof(lista[0]);
    int elemento = 30;

    int resultado = buscaBinaria(lista, tamanho, elemento);

    if(resultado != -1){
        printf("Elemento encontrado no índice %d\n", resultado);
    }else{
        printf("Elemento não encontrado\n");
    }
    return 0;
}
