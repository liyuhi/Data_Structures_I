//Repita o exercício anterior criando um vetor dinâmico de carros. Ao invés de inicializar o vetor com valores predefinidos, peça ao usuário para digitar os dados de dois carros. Use uma função para receber o vetor de carros e exibir o valor total dos carros.

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

struct carro{
    char modelo[20];
    int anofabricacao;
    float preco;
};

void dadoscarros(struct carro *carros, int quantidade){
    float total = 0;

    for(int i = 0; i < quantidade; i++){
        printf("Digite o modelo do %dº carro: ", i+1);
        scanf("%s", carros[i].modelo);
        printf("Digite o ano de fabricação do %dº carro: ", i+1);
        scanf("%d", &carros[i].anofabricacao);
        printf("Digite o preço do %dº carro: ", i+1);
        scanf("%f", &carros[i].preco);

        total += carros[i].preco;
    }

    printf("O valor total dos carros é R$%.2f\n", total);
}

int main(){
    setlocale(LC_ALL, "portuguese");
    
    int quantidade = 2;

    struct carro *carros = (struct carro *)malloc(quantidade *sizeof(struct carro));

    if (carros == NULL){
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    dadoscarros(carros, quantidade);

    free(carros);

    return 0;
}


