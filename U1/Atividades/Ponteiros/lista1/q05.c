/*Como seria o output se eu desse "print" nas variáveis a seguir:
int x = 68, y;
int *p;
p = &x;
y = *p + 200;*/

#include<stdio.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    
    int x = 68, y;
    int *p;
    p = &x;
    y = *p + 200;

    printf("Valor de x = %d\n", x);
    printf("Valor de y = %d\n", y);
    printf("Valor de p = %p\n", p);
    

    return(0);
}
