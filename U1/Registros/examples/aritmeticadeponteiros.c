#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pi = (int*)malloc(2 * sizeof(int));
    if (pi == NULL) {
        printf("Erro ao alocar memória para pi\n");
        return 1;
    }

    pi[0] = 15;
    pi[1] = 34;

    printf("%d\n", *pi);   
    pi = pi + 1;           
    printf("%d\n", *pi); 

    short* ps = (short*)malloc(2 * sizeof(short));
    if (ps == NULL) {
        printf("Erro ao alocar memória para ps\n");
        return 1;
    }

    ps[0] = 0;  
    ps[1] = 10; 

    printf("%d\n", *ps);  
    ps = ps + 1;           
    printf("%d\n", *ps);   

    char* pc = (char*)malloc(2 * sizeof(char));
    if (pc == NULL) {
        printf("Erro ao alocar memória para pc\n");
        return 1;
    }

    pc[0] = 'A';  
    pc[1] = 'B';  

    printf("%c\n", *pc);  

    free(pi);
    free(ps);
    free(pc);

    return 0;
}
