#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int copos = 6;
    double cafe = 4.5;

    printf("Valor de copos = %d\n", copos);
    printf("Endere�o de copos = %p\n", (void*)&copos);

    printf("Valor de caf� = %.2lf\n", cafe);
    printf("Endere�o de caf� = %p\n", (void*)&cafe);

    return 0;
}
