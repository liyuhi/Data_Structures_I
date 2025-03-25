/*Declare um registro Horário com os campos horas e minutos. Crie uma função MostrarHorario que deve receber um ponteiro para um Horário e mostrá-lo no formato HH:MM. Na função principal, declare uma variável do tipo Horário e um ponteiro que aponta para ela. Peça que o usuário digite o horário atual e guarde-o na variável.
Usando o ponteiro, incremente o horário recebido em uma hora e em seguida mostre o horário corrigido com MostrarHorario.*/

#include <stdio.h>

typedef struct {
    int horas, minutos;
} Horario;

//função para mostrar o horário no formato HH:MM
void MostrarHorario(Horario *horario) {
    printf("%02d:%02d\n", horario->horas, horario->minutos);
}

int main() {
    Horario horarioAtual;
    Horario *ponteiroHorario = &horarioAtual;

    printf("Que horas são? ");
    scanf("%d:%d", &ponteiroHorario->horas, &ponteiroHorario->minutos);

    ponteiroHorario->horas += 1;
    if (ponteiroHorario->horas >= 24) {
        ponteiroHorario->horas -= 24; //ajustando para o formato de 24 horas
    }

    printf("Seu relógio está atrasado, o horário correto é ");
    MostrarHorario(ponteiroHorario);

    return (0);
}
