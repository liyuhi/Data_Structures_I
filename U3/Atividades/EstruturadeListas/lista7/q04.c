/*Um serviço de streaming quer armazenar seu catálogo de filmes e séries, incluindo nome, ano de lançamento e categoria. Crie uma lista de dicionários para armazenar os títulos e implemente funções para:
● Adicionar um novo título
● Buscar títulos por categoria
● Listar os títulos ordenados pelo ano de lançamento*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULOS 100
#define MAX_CATEGORIA 50
#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    int ano;
    char categoria[MAX_CATEGORIA];
} Titulo;

Titulo catalogo[MAX_TITULOS];
int numTitulos = 0;

// Função para adicionar um novo título
void adicionarTitulo() {
    if (numTitulos >= MAX_TITULOS) {
        printf("Catalogo cheio! Não é possível adicionar mais títulos.\n");
        return;
    }
   
    printf("Digite o nome do título: ");
    scanf(" %[^\n]", catalogo[numTitulos].nome);
   
    printf("Digite o ano de lançamento: ");
    scanf("%d", &catalogo[numTitulos].ano);
   
    printf("Digite a categoria: ");
    scanf(" %[^\n]", catalogo[numTitulos].categoria);
   
    numTitulos++;
    printf("Título adicionado com sucesso!\n");
}


// Função para buscar títulos por categoria
void buscarPorCategoria() {
    char categoriaBusca[MAX_CATEGORIA];
    int encontrados = 0;
   
    printf("Digite a categoria para buscar: ");
    scanf(" %[^\n]", categoriaBusca);
   
    printf("\nTítulos na categoria '%s':\n", categoriaBusca);
    for (int i = 0; i < numTitulos; i++) {
        if (strcmp(catalogo[i].categoria, categoriaBusca) == 0) {
            printf("- %s (%d)\n", catalogo[i].nome, catalogo[i].ano);
            encontrados++;
        }
    }
   
    if (encontrados == 0) {
        printf("Nenhum título encontrado nesta categoria.\n");
    }
}


// Função de comparação para qsort (ordenar por ano)
int compararPorAno(const void *a, const void *b) {
    Titulo *tituloA = (Titulo *)a;
    Titulo *tituloB = (Titulo *)b;
    return tituloA->ano - tituloB->ano;
}


// Função para listar títulos ordenados por ano
void listarPorAno() {
    if (numTitulos == 0) {
        printf("O catálogo está vazio.\n");
        return;
    }
   
    Titulo copia[MAX_TITULOS];
    memcpy(copia, catalogo, sizeof(Titulo) * numTitulos);
    qsort(copia, numTitulos, sizeof(Titulo), compararPorAno);
    printf("\nTítulos ordenados por ano:\n");
    for (int i = 0; i < numTitulos; i++) {
        printf("- %s (%d) - %s\n", copia[i].nome, copia[i].ano, copia[i].categoria);
    }
}


// Menu principal
void mostrarMenu() {
    printf("\n--- Catálogo de Streaming ---\n");
    printf("1. Adicionar novo título\n");
    printf("2. Buscar títulos por categoria\n");
    printf("3. Listar títulos por ano\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
}


int main() {
    int opcao;
   
    do {
        mostrarMenu();
        scanf("%d", &opcao);
       
        switch(opcao) {
            case 1:
                adicionarTitulo();
                break;
            case 2:
                buscarPorCategoria();
                break;
            case 3:
                listarPorAno();
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);
   
return (0);
}

