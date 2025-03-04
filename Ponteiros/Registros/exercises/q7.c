#include <stdio.h>

union Cor {
    struct {
        unsigned char r, g, b, a;  
    } rgba;
    unsigned int valor; 
};

//função para ler uma cor no formato RGBA
void CorRGBA(union Cor *cor) {
    printf("Digite uma cor no formato RGBA: ");
    scanf("%hhu %hhu %hhu %hhu", &cor->rgba.r, &cor->rgba.g, &cor->rgba.b, &cor->rgba.a);
}

//função para ler uma cor no formato de 32 bits
void Cor32Bits(union Cor *cor) {
    printf("Digite uma cor no formato Int32: ");
    scanf("%u", &cor->valor);
}

//função para imprimir uma cor no formato RGBA
void imprimirCorRGBA(union Cor *cor) {
    printf("RGBA: %hhu %hhu %hhu %hhu\n", cor->rgba.r, cor->rgba.g, cor->rgba.b, cor->rgba.a);
}

//função para imprimir uma cor no formato de 32 bits
void imprimirCor32Bits(union Cor *cor) {
    printf("Int32: %u\n", cor->valor);
}

int main() {
    union Cor Color;

    //ler e exibir uma cor no formato RGBA
    CorRGBA(&Color);
    imprimirCorRGBA(&Color);
    imprimirCor32Bits(&Color); // Exibe a cor como valor inteiro de 32 bits

    printf("\n");

    //ler e exibir uma cor no formato de 32 bits
    Cor32Bits(&Color);
    imprimirCorRGBA(&Color);  // Exibe os componentes RGBA
    imprimirCor32Bits(&Color); // Exibe a cor como valor inteiro de 32 bits

    return (0);
}
