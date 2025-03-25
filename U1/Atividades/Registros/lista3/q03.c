//Construa um registro para guardar informações sobre um carro. Um carro deve ter um modelo, ano de fabricação e preço. Em seguida construa um vetor estático de 10 carros inicializando os dois primeiros carros respectivamente para "Vectra", 2009, R$58.000,00 e "Polo", 2008, R$45.000,00. Use um ponteiro para apontar para o segundo carro e exibir seus dados.

#include<stdio.h>
#include<locale.h>

struct carro{
    char modelo[20];
    int anofabricacao;
    float preco;
};

int main(){
    setlocale(LC_ALL, "portuguese");
    
    struct carro carros[10] = {
        {"Vectra", 2009, 58000},
        {"Polo", 2008, 45000}
    };

    struct carro *Carro = &carros[1];

    printf("Modelo: %s\n", Carro->modelo);
    printf("Ano de fabricação: %d\n", Carro->anofabricacao);
    printf("Preço: R$%.2f\n", Carro->preco);

    return 0;
}


