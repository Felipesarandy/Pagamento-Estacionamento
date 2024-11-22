#include <stdio.h>
#define PRECO_POR_HORA 3.55


void calculaTempoEPreco(int horaEntrada, int minEntrada, int horaSaida, int minSaida, int *horas, int *minutos, float *preco);

void calculaTempoEPreco(int horaEntrada, int minEntrada, int horaSaida, int minSaida, int *horas, int *minutos, float *preco) {
    int totalMinEntrada = horaEntrada * 60 + minEntrada;
    int totalMinSaida = horaSaida * 60 + minSaida;
    int totalMinPermanencia;

    if (totalMinSaida < totalMinEntrada) {
        totalMinSaida += 24 * 60;
    }

    totalMinPermanencia = totalMinSaida - totalMinEntrada;

    *horas = totalMinPermanencia / 60;
    *minutos = totalMinPermanencia % 60;

    *preco = (*horas + (*minutos > 0 ? 1 : 0)) * PRECO_POR_HORA;
}

int main() {
    int horaEntrada, minEntrada;
    int horaSaida, minSaida;
    int horasPermanencia, minutosPermanencia;
    float totalPagar;

    printf("Hora de entrada (HH MM): ");
    scanf("%i %i", &horaEntrada, &minEntrada);

    printf("Hora de saída (HH MM): ");
    scanf("%i %i", &horaSaida, &minSaida);

    calculaTempoEPreco(horaEntrada, minEntrada, horaSaida, minSaida, &horasPermanencia, &minutosPermanencia, &totalPagar);


    printf("Tempo de permanência: %d horas e %d minutos\n", horasPermanencia, minutosPermanencia);
    printf("Total a pagar: R$ %.2f\n", totalPagar);

    return 0;
}
