#include <stdio.h>

void dobrar(int *num) {
    *num = *num * 2;
}

int main() {
    int x = 5;
    dobrar(&x);
    printf("Novo valor de x: %d\n", x);  //saída = 10
    return 0;
}

