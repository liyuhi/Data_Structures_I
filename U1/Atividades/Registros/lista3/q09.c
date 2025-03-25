//Crie um registro "Local" com os campos nome, país e continente. Pergunte ao usuário quantos locais ele quer visitar nas próximas férias e crie um vetor de locais alocando dinamicamente o espaço de acordo com quantos locais ele quer visitar. Use um laço for para armazenar as informações dos locais que o usuário deseja visitar, e depois do armazenamento mostre os locais que ele escolheu. Libere o espaço alocado dinamicamente ao final do programa.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#define maxnome 100
#define maxpais 100
#define maxcont 100

typedef struct{
    char nome[maxnome], pais[maxpais], continente[maxcont];
} Local;

int main(){
    setlocale(LC_ALL, "portuguese");
    int num;
    Local *locais;

    printf("Quantos locais deseja visitar nas próximas férias? ");
    scanf("%d", &num);

    locais = (Local *)malloc(num * sizeof(Local));

    if(locais == NULL){
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (int i = 0; i < num; i++){
        printf("Digite o nome do local: ");
        scanf(" %[^\n]", locais[i].nome);
        printf("Digite o país do local: ");
        scanf(" %[^\n]", locais[i].pais);
        printf("Digite o continente do local: ");
        scanf(" %[^\n]", locais[i].continente);
    }  

    printf("\nOs locais que você decidiu passar as próximas férias são:\n");

    for (int i = 0; i < num; i++){
        printf("Local %d: %s, %s, %s\n", i+1, locais[i].nome, locais[i].pais, locais[i].continente);
    }

    free(locais);

    return 0;
}