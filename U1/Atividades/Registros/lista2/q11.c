// Crie um registro Imagem que contenha campos para nome, altura, largura e tipo, sendo o tipo um dos seguintes valores: JPG, PNG ou BMP. Use uma enumeração para guardar o tipo da imagem. No programa principal inicialize uma variável do tipo Imagem e passe seu endereço para uma função Detalhes. A função deve receber o endereço de uma Imagem e exibir os seus dados no formato do exemplo abaixo.

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
