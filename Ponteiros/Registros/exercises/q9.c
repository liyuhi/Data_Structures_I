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
