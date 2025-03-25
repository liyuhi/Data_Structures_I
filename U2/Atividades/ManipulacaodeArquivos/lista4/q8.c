//Crie um registro para representar um aluno, leia as informações do arquivo e guarde em um vetor de alunos. Em seguida use laços e testes condicionais para separar e exibir os alunos agrupados por turno e série
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

typedef struct{
    char nome[50];
    char turno;
    int serie; 
} aluno;

int main(){
    setlocale(LC_ALL, "Portuguese");
    int num;
    FILE *arquivo = fopen("arquivo.txt", "w");

    printf("Quantos alunos você deseja cadastrar? ");
    scanf("%d", &num);
    setbuf(stdin, NULL);
    aluno *alunos = (aluno*)malloc(num*sizeof(aluno));
    aluno *p;
    for(int x = 0; x < num; x++){
        p = &alunos[x];
        printf("Nome do %d� aluno: ", x+1);
        fgets(p->nome, 50, stdin);
        p->nome[strcspn(p->nome, "\n")] = 0;
        setbuf(stdin, NULL);
        
        printf("Turno: ");
        scanf("%c", &p->turno);
        setbuf(stdin, NULL);

        printf("Série: ");
        scanf("%d", &p->serie);
        setbuf(stdin, NULL);
    }

    fprintf(arquivo, "\nMatutino 6a serie\n");
    fprintf(arquivo, "-----------------\n");
    for(int i = 0; i < num; i++){
        p = &alunos[i];
        if(p->serie == 6 && p->turno == 'M'){
            fprintf(arquivo, "%-15s%c%d\n", p->nome, p->turno, p->serie);
        }
    }
    fprintf(arquivo, "\nMatutino 7a serie\n");
    fprintf(arquivo, "-----------------\n");
    for(int i = 0; i < num; i++){
        p = &alunos[i];
        if(p->serie == 7 && p->turno == 'M'){
            fprintf(arquivo, "%-10s%-10c%-10d\n", p->nome, p->turno, p->serie);
        }
    }
    fprintf(arquivo, "\nMatutino 8a serie\n");
    fprintf(arquivo, "-----------------\n");
    for(int i = 0; i < num; i++){
        p = &alunos[i];
        if(p->serie == 8 && p->turno == 'M'){
            fprintf(arquivo, "%-10s%-10c%-10d\n", p->nome, p->turno, p->serie);
        }
    }
    fprintf(arquivo, "\nVespertino 6a serie\n");
    fprintf(arquivo, "-----------------\n");
    for(int i = 0; i < num; i++){
        p = &alunos[i];
        if(p->serie == 6 && p->turno == 'T'){
            fprintf(arquivo, "%-10s%-10c%-10d\n", p->nome, p->turno, p->serie);
        }
    }
    fprintf(arquivo, "\nVespertino 7a serie\n");
    fprintf(arquivo, "-----------------\n");
    for(int i = 0; i < num; i++){
        p = &alunos[i];
        if(p->serie == 7 && p->turno == 'T'){
            fprintf(arquivo, "%-10s%-10c%-10d\n", p->nome, p->turno, p->serie);
        }
    }
    fprintf(arquivo, "\nVespertino 8a serie\n");
    fprintf(arquivo, "-----------------\n");
    for(int i = 0; i < num; i++){
        p = &alunos[i];
        if(p->serie == 8 && p->turno == 'T'){
            fprintf(arquivo, "%-10s%-10c%-10d\n", p->nome, p->turno, p->serie);
        }
    }

    fclose(arquivo);
    arquivo = fopen("arquivo.txt", "r");
    char ch;
    while((ch = fgetc(arquivo)) != EOF){
        printf("%c", ch);
    }
    fclose(arquivo);
    free(alunos);
    return 0;
}

