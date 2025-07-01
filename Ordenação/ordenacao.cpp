#include "ordenacao.hpp"
#include <stdio.h>

void fazer_vetor(int v[], int n) {
    /*Fazer o vetor decrescente de n até 1*/
    for (int valor = n, *p = v + n - 1; valor > 0; valor--, p--)
        *p = valor;
}

void printar_vetor(int v[], int n) {
    printf("O vetor está assim: [");
    for (int *p = v; p < v + n; p++)
        printf("%d ", *p);
    printf("%c]", 8);
}

void p_Bubble(int v[], int n) {
    int aux;
    for (int *p = v; p < v + n - 1; p++) {
        for (int *q = v; q < v + n - 1; q++) {
            if (*q > *(q + 1)) {
                aux = *q;
                *q = *(q + 1);
                *(q + 1) = aux;
            }
        }
    }
}