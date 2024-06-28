#ifndef PUNTAJE_H_INCLUDED
#define PUNTAJE_H_INCLUDED
#include "constantes.h"
#include "cartas.h"



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



#endif // PUNTAJE_H_INCLUDED
