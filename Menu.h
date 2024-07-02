#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <string>
#include <iostream>
#include "constantes.h"
#include "juego.h"
#include "puntaje.h"
#include "cartas.h"

int ID = 0;
std::string nombres[2]={};
int jugadorID[2]={};

void ingresarNombre(){
    system("cls");
    std::cout<<"EMBAUCADO"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Para continuar, ingresa los nombres de los jugadores: "<<std::endl;
    std::cout<<"Jugador 1: ";
    std::cin>>nombres[0];
    jugadorID[0]=ID++;
    std::cout<<"Jugador 2: ";
    std::cin>>nombres[1];
    jugadorID[1]=ID++;
    std::cout<<std::endl;
};
std::string confirmarNombres(){
    while(true){

        char confirmacion;

        std::cout<<"Confirmas esta seleccion de nombres? (S/N)"<<std::endl;
        std::cin>> confirmacion;

        switch(confirmacion){
            case 'S':
            case 's':
                return "continuar";
            break;

            case 'N':
            case 'n':
                return "volver.";
            break;

            default:
                std::cout<<"Opcion incorrecta. Por favor ingrese 'S' o 'N' para continuar.";
            break;

        }
    }
};

void mostrarEstadisticas() {
    std::cout<<"EMBAUCADO"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout << "ESTADISTICAS DE PUNTAJES MAS ALTOS:" << std::endl<< std::endl;
    for (int i = 0; i < 5; ++i) {
        if (puntajesAltos[i] > 0) {
            std::cout << i + 1 << ". " << nombresAltos[i] << ": " << puntajesAltos[i] << " puntos" << std::endl;
        }
    }
}

void mostrarInstrucciones(){
    std::cout<<"EMBAUCADO"<<std::endl;
    std::cout<<"------------------------------------------------------------------------"<<std::endl;
    std::cout << "Bienvenidos a Embaucado. Las reglas del juego son las siguientes..." << std::endl<< std::endl;
    std::cout << "El juego se juega con los 10, J, Q, K y A de los cuatro palos (Corazon, Diamante, Pica, Trebol)." << std::endl;
    std::cout << "En cada ronda, los jugadores reciben 5 cartas y se revela una carta embaucadora." << std::endl;
    std::cout << "Las cartas embaucadas no suman puntos." << std::endl<< std::endl;
    std::cout << "Los puntos se calculan de la siguiente manera: " << std::endl<< std::endl;
    std::cout <<"----------------------"<< std::endl;
    std::cout <<"   10 = 10 puntos"<< std::endl;
    std::cout <<"    J = 11 puntos"<< std::endl;
    std::cout <<"    Q = 12 puntos"<< std::endl;
    std::cout <<"    K = 15 puntos"<< std::endl;
    std::cout <<"    A = 20 puntos"<< std::endl;
    std::cout <<"---------------------"<< std::endl<< std::endl;
    std::cout << "A partir de la ronda 2 un jugador puede cambiar la carta embaucadora por el coste de 20 puntos." << std::endl;
    std::cout << "Solo un jugador por turno puede cambiar la carta embaucadora." << std::endl;
    std::cout << "Si uno decide no hacerlo, el otro jugador puede pagar el costo."<<std::endl;
    std::cout << "En la ronda 2, el jugador 1 puede cambiar la carta embaucadora. En la ronda 3, el jugador 2 puede." << std::endl;
    std::cout << "Despues de 3 rondas, el jugador con mas puntos gana." << std::endl;
};

int menu(){
        while(true){
            int opc;
            system("cls");
            std::cout << "EMBAUCADO" << std::endl;
            std::cout << "---------------------" << std::endl;
            std::cout << "1 - JUGAR" << std::endl;
            std::cout << "2 - ESTADISTICAS" << std::endl;
            std::cout << "3 - CREDITOS" << std::endl;
            std::cout << "4 - INSTRUCCIONES" << std::endl;
            std::cout << "---------------------" << std::endl;
            std::cout << "0 - SALIR" << std::endl;
            std::cout << "Elija una opcion: ";
            std::cin >> opc;

            switch(opc){
                case 1:
                    {
                         system("cls");
                        std::cout<<"A jugar."<<std::endl;
                        std::string res;
                        do{
                            ingresarNombre();
                        }
                        while(confirmarNombres()!="continuar");

                        iniciarJuego();
                        system("pause");
                    }
                    break;

                case 2:
                    system("cls");
                    mostrarEstadisticas();
                    std::cout<<"------------------------------------------------------------------------"<<std::endl;
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    std::cout<<"EMBAUCADO"<<std::endl;
                    std::cout<<"------------------------------------------------------------------------"<<std::endl;
                    std::cout<<"LEGAJO    NOMBRE COMPLETO"<<std::endl;
                    std::cout<<"------------------------------------------------------------------------"<<std::endl;
                    std::cout<<std::endl;
                    std::cout<<"30863     Tomas Acuña"<<std::endl;
                    std::cout<<"30258     Nahuel Agustin Caero"<<std::endl;
                    std::cout<<"30979     Francisco Valentin Garcia Aller"<<std::endl;
                    std::cout<<"------------------------------------------------------------------------"<<std::endl;
                    std::cout<<std::endl;

                    system("pause");
                    break;

                case 4:
                    {
                    system("cls");
                    mostrarInstrucciones();
                    system("pause");
                    }
                    break;

                case 0:
                    return 0;
                    break;
                default:
                    std::cout << "Opcion Incorrecta."<<std::endl;
                    system("pause");
            }
    }
    }

#endif // MENU_H_INCLUDED
