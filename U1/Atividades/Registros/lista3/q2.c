//Defina o registro balao como mostrado abaixo. Construa um programa para alocar dinamicamente uma variável do tipo balao. Peça ao usuário para entrar com valores para cada um dos membros e em seguida exiba o conteúdo do registro.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct balao
{
    float diametro;
    char marca[20];
    int modelo;
};

int main() {
    setlocale(LC_ALL, "portuguese");

    struct balao *Balao = (struct balao *)malloc(sizeof(struct balao));
   
    if (Balao == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite o diâmetro do balão: ");
    scanf("%f", &Balao->diametro);

    printf("\nDigite a marca do balão: ");
    scanf("%s", Balao->marca);

    printf("\nDigite o modelo do balão: ");
    scanf("%d", &Balao->modelo);
    
    printf("\n------ Informações sobre o balão ------\n");
    printf("O diâmetro do balão é %.1f.\n", Balao->diametro);
    printf("A marca do balão é %s.\n", Balao->marca);
    printf("O modelo do balão é %d.\n", Balao->modelo);
   
    free(Balao);

    return 0;
}

