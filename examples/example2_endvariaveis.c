#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int copos = 6;
    double cafe = 4.5;

    printf("Valor de copos = %d\n", copos);
    printf("Endereço de copos = %p\n", (void*)&copos);

    printf("Valor de café = %.2lf\n", cafe);
    printf("Endereço de café = %p\n", (void*)&cafe);

    int *ponteiroCopos = &copos;
    printf("Valor apontado por ponteiroCopos = %d\n", *ponteiroCopos);

    return 0;
}
