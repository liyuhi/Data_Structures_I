//Construa duas funções que realizem o incremento de um número em uma unidade. A função Mais deve receber um número inteiro através de um ponteiro. A função Incrementa deve receber um valor inteiro, sem usar ponteiros, e retornar o valor incrementado em uma unidade. 

#include<stdio.h>
#include<locale.h>

void Mais(int *num) {
    (*num)++; 
}

int Incrementa(int num) {
    return num + 1; 
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int valor;

    printf("Digite um valor: ");
    scanf("%d", &valor);

    Mais(&valor);
    printf("Resultado após Mais: %d\n", valor);

    valor = Incrementa(valor);
    printf("Resultado após Incrementa: %d\n", valor);

    return (0);
}
