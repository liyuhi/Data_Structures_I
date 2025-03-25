#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct no {
    int data;
    struct no *prox;
} no;   

typedef struct Queue{
    no* front;
    no* rear;
}Queue;

void iniQueue(Queue* queue){
    queue->front = queue->rear = NULL;
}

int isEmpty(Queue* queue){
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data){
    no* novono = (no*)malloc(sizeof(no));
    if(novono == NULL){
        printf("Erro ao alocar memória.\n");
        return;
    }

    novono->data = data;
    novono->prox = NULL;

   
    if(queue->rear == NULL){
        queue->front = queue->rear = novono;
    }else{
        queue->rear->prox = novono;
        queue->rear = novono;
    }
}

int dequeue(Queue* queue){
    if(isEmpty(queue)){
        printf("Erro: Fila vazia.\n");
        return -1;
    }
    no* temp = queue->front;
}
