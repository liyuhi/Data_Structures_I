//Defina um registro ASCII que armazena um caractere e um valor inteiro associado. Crie uma função que recebe um valor inteiro e um caractere, e retorna o endereço de um elemento do tipo ASCII, alocado dinamicamente na memória. O programa principal deve chamar a função passando valores lidos do usuário, receber o retorno em um ponteiro, exibir os valores de retorno e deletar a memória que foi alocada dentro da função.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct{
    char caractere;
    int valor;
} ASCII;

ASCII* ptrASCII(char c, int v){
    ASCII *newASCII = (ASCII *)malloc(sizeof(ASCII));

    if(newASCII == NULL){
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    newASCII->caractere = c;
    newASCII->valor = v;
    return newASCII;
} 

int main(){
    setlocale(LC_ALL, "portuguese");

    char c;
    int v;

    printf("Digite um caractere: ");
    scanf("%c", &c);
    printf("Digite um valor inteiro: ");
    scanf("%d", &v);

    ASCII *ascii = ptrASCII(c, v);
    if(ascii == NULL){
        return;
    }

    printf("Caractere: %c\n", ascii->caractere);
    printf("Valor: %d\n", ascii->valor);

    free(ascii);

    return 0;
}
