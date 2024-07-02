#include "juego.h"
#include "constantes.h"
#include "cartas.h"
#include "puntaje.h"
#include "Menu.h"
#include <iostream>
#include <time.h>


using namespace std;


void iniciarJuego() {
    int mazo[NUM_CARTAS] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    std::string nombreCartas[NUM_CARTAS]={
        "10 de CORAZON","J de CORAZON","Q de CORAZON","K de CORAZON","A de CORAZON",
        "10 de DIAMANTE","J de DIAMANTE","Q de DIAMANTE", "K de DIAMANTE","A de DIAMANTE",
        "10 de PICAS","J de PICAS","Q de PICAS","K de PICAS","A de PICAS",
        "10 de TREBOL","J de TREBOL","Q de TREBOL","K de TREBOL","A de TREBOL"};

    int figuras[4] = {0, 1, 2, 3}; // 0: Corazón, 1: Diamante, 2: Pica, 3: Trébol
    string palos[4]={"Corazon","Diamante","Pica","Trebol"};
    int puntajes[NUM_JUGADORES] = {0, 0};

    int mano1[CARTAS_MANO], mano2[CARTAS_MANO];
    int embaucadora;
    bool sacrificado = false;


    for (int ronda = 1; ronda <= NUM_RONDAS; ronda++) {

        barajar(mazo, NUM_CARTAS);
        barajar(figuras, 4);

        system("cls");

        repartirCartas(mazo, mano1, mano2);

        cout<<"EMBAUCADO"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<< "RONDA #"<<ronda <<endl;
        cout<<nombres[0]<<" VS "<<nombres[1]<<endl;
        cout<<"+-------------------------+"<<endl;
        cout<<nombres[0]<<" ("<<puntajes[0]<<" Puntos)"<<endl;
        cout<<" "<<nombreCartas[mano1[0]]<<endl;
        cout<<" "<<nombreCartas[mano1[1]]<<endl;
        cout<<" "<<nombreCartas[mano1[2]]<<endl;
        cout<<" "<<nombreCartas[mano1[3]]<<endl;
        cout<<" "<<nombreCartas[mano1[4]]<<endl;
        cout<<endl<<endl;
        cout<<nombres[1]<<" ("<<puntajes[1]<<" Puntos)"<<endl;
        cout<<" "<<nombreCartas[mano2[0]]<<endl;
        cout<<" "<<nombreCartas[mano2[1]]<<endl;
        cout<<" "<<nombreCartas[mano2[2]]<<endl;
        cout<<" "<<nombreCartas[mano2[3]]<<endl;
        cout<<" "<<nombreCartas[mano2[4]]<<endl;
        cout<<"+-------------------------+"<<endl;
        cout << "Ronda " << ronda  << " - Embaucadora: " << palos[embaucadora] << endl;

        embaucadora = figuras[0];

        sacrificado = false;
        if (ronda > 1) {
            int jugadorSacrificio = ronda % 2;

            char decision1;
            do {
                if (puntajes[jugadorSacrificio] >= PUNTAJE_SACRIFICIO) {
                    cout << "Jugador " << jugadorSacrificio + 1 << ", ¿quieres sacrificar 20 puntos para cambiar la embaucadora? (S/N): ";
                    cin >> decision1;

                    if (decision1 == 's' || decision1 == 'S') {
                        puntajes[jugadorSacrificio] -= PUNTAJE_SACRIFICIO;
                        barajar(figuras, 4);
                        embaucadora = figuras[0];
                        cout << "- Nueva Embaucadora: " << palos[embaucadora] << endl << endl;
                        sacrificado = true;
                    } else if (decision1 == 'n' || decision1 == 'N') {
                        break;
                    } else {
                        cout << "Opcion invalida." << endl;
                    }
                } else {
                    break;
                }
            } while (decision1 != 's' && decision1 != 'S' && decision1 != 'n' && decision1 != 'N');

            char decision2;
            do {
                if (!sacrificado && puntajes[1 - jugadorSacrificio] >= PUNTAJE_SACRIFICIO) {
                    cout << "Jugador " << 2 - jugadorSacrificio << ", ¿quieres sacrificar 20 puntos para cambiar la embaucadora? (S/N): ";
                    cin >> decision2;

                    if (decision2 == 's' || decision2 == 'S') {
                        puntajes[1 - jugadorSacrificio] -= PUNTAJE_SACRIFICIO;
                        barajar(figuras, 4);
                        embaucadora = figuras[0];
                        cout << "- Nueva Embaucadora: " << palos[embaucadora] << endl;
                    } else if (decision2 == 'n' || decision2 == 'N') {
                        break;
                    } else {
                        cout << "Opcion invalida." << endl;
                    }
                } else {
                    break;
                }
            } while (decision2 != 's' && decision2 != 'S' && decision2 != 'n' && decision2 != 'N');
        }

        int puntaje1 = calcularPuntaje(mano1, embaucadora);
        int puntaje2 = calcularPuntaje(mano2, embaucadora);
        puntajes[0] += puntaje1;
        puntajes[1] += puntaje2;

        cout<<"Puntajes obtenidos:"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout << "Jugador 1: " << puntaje1 << " puntos (Total: " << puntajes[0] << ")" << endl;
        cout << "Jugador 2: " << puntaje2 << " puntos (Total: " << puntajes[1] << ")" << endl;

        system("pause");
    }

        actualizarEstadisticas(nombres[0], puntajes[0]);
        actualizarEstadisticas(nombres[1], puntajes[1]);

    if (puntajes[0] > puntajes[1]) {
        system("cls");
        cout << "¡Jugador 1 es el ganador con " << puntajes[0] << " puntos!" << endl;

    } else if (puntajes[1] > puntajes[0]) {
        system("cls");
        cout << "¡Jugador 2 es el ganador con " << puntajes[1] << " puntos!" << endl;

    } else {
        system("cls");
        cout << "¡Es un empate con " << puntajes[0] << " puntos cada uno!" << endl;

    }
}

int main()
{
    srand(time(0));

    menu();
}
