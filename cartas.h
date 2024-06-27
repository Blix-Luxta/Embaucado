#ifndef CARTAS_H_INCLUDED
#define CARTAS_H_INCLUDED
#include "puntaje.h"
#include <cstdlib>


void barajar(int cartas[], int tamanio){
    for (int i = 0; i < tamanio; ++i) {
            int j = rand() % tamanio;
            int temp = cartas[i];
            cartas[i] = cartas[j];
            cartas[j] = temp;
        }
}

void repartirCartas(int mazo[], int mano1[], int mano2[]){
        for (int i = 0; i < CARTAS_MANO; ++i) {
        mano1[i] = mazo[i];
        mano2[i] = mazo[i + CARTAS_MANO];
    }
}


#endif // CARTAS_H_INCLUDED
