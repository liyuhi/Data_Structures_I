/*Imagine que você está desenvolvendo um aplicativo de música e precisa implementar uma playlist dinâmica. Utilize a estrutura duplamente encadeada juntamente com a estrutura circular.
● Cada música é representada por um objeto com título, artista e duração.
● A playlist deve permitir adicionar músicas, remover músicas e exibir a lista atual.
● Criar função que permita o usuário reorganizar sua playlist*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Musica {
    char titulo[100];
    char artista[100];
    int minutos; // duração em minutos
    int segundos; // duração em segundos
    struct Musica* anterior;
    struct Musica* proximo;
} Musica;

typedef struct Playlist {
    Musica* cabeca;
} Playlist;

// Função para criar uma nova música
Musica* criarMusica(const char* titulo, const char* artista, int minutos, int segundos) {
    Musica* novaMusica = (Musica*)malloc(sizeof(Musica));
    strcpy(novaMusica->titulo, titulo);
    strcpy(novaMusica->artista, artista);
    novaMusica->minutos = minutos;
    novaMusica->segundos = segundos;
    novaMusica->anterior = NULL;
    novaMusica->proximo = NULL;
    return novaMusica;
}

// Função para inicializar a playlist
void inicializarPlaylist(Playlist* playlist) {
    playlist->cabeca = NULL;
}

// Função para adicionar música à playlist
void adicionarMusica(Playlist* playlist, const char* titulo, const char* artista, int minutos, int segundos) {
    Musica* novaMusica = criarMusica(titulo, artista, minutos, segundos);
    if (playlist->cabeca == NULL) {
        playlist->cabeca = novaMusica;
        novaMusica->proximo = novaMusica; // circular
        novaMusica->anterior = novaMusica; // circular
    } else {
        Musica* ultimo = playlist->cabeca->anterior;
        ultimo->proximo = novaMusica;
        novaMusica->anterior = ultimo;
        novaMusica->proximo = playlist->cabeca;
        playlist->cabeca->anterior = novaMusica;
    }
}

// Função para remover música da playlist
void removerMusica(Playlist* playlist, const char* titulo) {
    if (playlist->cabeca == NULL) {
        printf("A playlist está vazia.\n");
        return;
    }

    Musica* atual = playlist->cabeca;
    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (atual->anterior == atual) { // único elemento
                free(atual);
                playlist->cabeca = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == playlist->cabeca) {
                    playlist->cabeca = atual->proximo; // atualiza a cabeça se necessário
                }
                free(atual);
            }
            printf("Música '%s' removida da playlist.\n", titulo);
            return;
        }
        atual = atual->proximo;
    } while (atual != playlist->cabeca);

    printf("Música '%s' não encontrada na playlist.\n", titulo);
}

// Função para exibir a playlist
void exibirPlaylist(Playlist* playlist) {
    if (playlist->cabeca == NULL) {
        printf("\nA playlist está vazia.\n");
        return;
    }

    Musica* atual = playlist->cabeca;
    printf("\nPlaylist atual:\n");
    do {
        printf("Título: %s | Artista: %s | Duração: %d minutos e %d segundos\n", atual->titulo, atual->artista, atual->minutos, atual->segundos);
        atual = atual->proximo;
    } while (atual != playlist->cabeca);
    printf("\n");
}

// Função para reorganizar a playlist
void reorganizarPlaylist(Playlist* playlist) {
    if (playlist->cabeca == NULL) {
        printf("A playlist está vazia.\n");
        return;
    }

    Musica* atual = playlist->cabeca;
    Musica* temp = NULL;

    // Inverte a lista
    do {
        temp = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = temp;
        atual = atual->anterior; // Move para o próximo nó
    } while (atual != playlist->cabeca);

    // Ajustar a cabeça da playlist
    playlist->cabeca = temp->anterior;
}

// Função principal para testar a playlist
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001");

    Playlist playlist;
    inicializarPlaylist(&playlist);
    int opcao;
    char titulo[100], artista[100];
    int minutos, segundos;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar música\n");
        printf("2. Remover música\n");
        printf("3. Exibir playlist\n");
        printf("4. Reorganizar playlist\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Digite o título da música: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove a nova linha
                printf("Digite o artista: ");
                fgets(artista, sizeof(artista), stdin);
                artista[strcspn(artista, "\n")] = 0; // Remove a nova linha
                printf("Digite a duração (minutos e segundos): ");
                scanf("%d %d", &minutos, &segundos);
                adicionarMusica(&playlist, titulo, artista, minutos, segundos);
                break;
            case 2:
                printf("Digite o título da música a ser removida: ");
                fgets(titulo, sizeof(titulo), stdin);
                titulo[strcspn(titulo, "\n")] = 0; // Remove a nova linha
                removerMusica(&playlist, titulo);
                break;
            case 3:
                exibirPlaylist(&playlist);
                break;
            case 4:
                reorganizarPlaylist(&playlist);
                printf("Playlist reorganizada.\n");
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
            }
        } while (opcao != 5);
    
        // Liberar memória
        printf("Liberando memória...\n");
        while (playlist.cabeca != NULL) {
            Musica* atual = playlist.cabeca;
            removerMusica(&playlist, atual->titulo);
        }
    
        printf("Programa encerrado.\n");
        return 0;
    }
