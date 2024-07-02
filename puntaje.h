#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED
#include <string>
#include "constantes.h"
#include "cartas.h"

int puntajesAltos[5];
std::string nombresAltos[5];

int calcularPuntaje(int mano[], int embaucadora){
    int puntaje = 0;
    for (int i = 0; i < CARTAS_MANO; ++i) {
        switch(embaucadora){
            case 0:
                if(mano[i]>4){
                    puntaje += valorMazo[mano[i]];
                }
            break;

            case 1:
                if(mano[i]<5 || mano[i]>9){
                    puntaje += valorMazo[mano[i]];
                }
            break;

            case 2:
                if(mano[i]<10 || mano[i]>14){
                    puntaje += valorMazo[mano[i]];
                }
            break;

            case 3:
                if(mano[i]<15){
                    puntaje += valorMazo[mano[i]];
                }
            break;
            }
    }
    return puntaje;
};

void actualizarEstadisticas(const std::string& nombre, int puntaje);
void mostrarEstadisticas();
void ordenarEstadisticas();

void actualizarEstadisticas(const std::string& nombre, int puntaje) {
    for (int i = 0; i < 5; ++i) {
        if (puntaje > puntajesAltos[i]) {
            for (int j = 5 - 1; j > i; --j) {
                puntajesAltos[j] = puntajesAltos[j - 1];
                nombresAltos[j] = nombresAltos[j - 1];
            }
            puntajesAltos[i] = puntaje;
            nombresAltos[i] = nombre;
            break;
        }
    }
    ordenarEstadisticas();
}



void ordenarEstadisticas() {
    for (int i = 0; i < 5 - 1; ++i) {
        for (int j = 0; j < 5 - i - 1; ++j) {
            if (puntajesAltos[j] < puntajesAltos[j + 1]) {
                int tempPuntaje = puntajesAltos[j];
                puntajesAltos[j] = puntajesAltos[j + 1];
                puntajesAltos[j + 1] = tempPuntaje;

                std::string tempNombre = nombresAltos[j];
                nombresAltos[j] = nombresAltos[j + 1];
                nombresAltos[j + 1] = tempNombre;
            }
        }
    }
}


#endif // PUNTAJE_H_INCLUDED
