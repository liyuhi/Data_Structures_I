#include<stdio.h>
#include<locale.h>

typedef enum {
    JPG,
    PNG,
    BMP
} TipoImagem;

typedef struct {
    char nome[50];     
    int altura;          
    int largura;         
    TipoImagem tipo;     
} Imagem;

void Detalhes(const Imagem *img) {
    printf("A imagem \"%s\" com tamanho %dx%d tem formato ", img->nome, img->largura, img->altura);
    switch (img->tipo) {
        case JPG:
            printf("JPG.\n");
            break;
        case PNG:
            printf("PNG.\n");
            break;
        case BMP:
            printf("BMP.\n");
            break;
        default:
            printf("Inválido.\n");
            break;
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");
    Imagem imagem1 = {
        "backg.png",       
        1080,              
        1920,         
        PNG               
    };

    Detalhes(&imagem1);

    return (0);
}
