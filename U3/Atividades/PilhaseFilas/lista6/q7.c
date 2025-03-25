//Crie um programa que simule uma fila de impressão, onde os documentos são enfileirados para impressão e processados na ordem de chegada.

#include <stdio.h>
#include <string.h>
#include <locale.h>


#define max 50


void add(char *fila[max], int *tras, char documento[]) {
   if (*tras < max) {
      fila[*tras] = documento;
      (*tras)++;
   } else{
      printf(">> Fila cheia!\n");
   }
}
void imprim(char *fila[max], int *frente, int *tras) {
   if (*frente < *tras) {
      printf("Imprimindo %s\n", fila[*frente]);
      (*frente)++;
   } else{
      printf(">> Fila vazia!\n");
   }
}
void exibirFila(char *fila[max], int frente, int tras) {
   printf("Fila atual: [");
   for (int i = frente; i < tras; i++) {
      printf("'%s'", fila[i]);
      if (i < tras - 1) {
         printf(", ");
      }
   }
   printf("]\n");
}
int main() {
   setlocale(LC_ALL, "Portuguese");
   char *fila[max];  
   int frente = 0, tras = 0;
   
   add(fila, &tras, "Documento1.pdf");
   add(fila, &tras, "Relatório.docx");
   imprim(fila, &frente, &tras);
   add(fila, &tras, "Foto.png");


   exibirFila(fila, frente, tras);
   return 0;
}
