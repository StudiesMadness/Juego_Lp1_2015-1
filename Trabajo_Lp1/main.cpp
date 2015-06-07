/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 10:57 AM
 */
#define PARED  '#' 
#define ADENTRO ' '
#define ANTERIOR '-' 
#define SIGUIENTE '+'
#define MONSTRUO 'M'
#define ARTEFACTO 'A'
#include <cstdlib>
#include <cstdio>
#include "Juego.h"
#include "FuncionesExtras.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //   // Prueba 1 
    //    Juego j; //  Se crea el juego 
    //    j.CargarLaberintos(); //  cargo todos los archivos el tipo Lab_"NombreDeLaberinto"
    //    // El elmetodo de crear de GestorLaberintos solo devuelve un laberinto
    // 
    //    j.GetLaberintoActual().impresion();
    //    Avatar brayan;
    //    brayan.SetPosX(29);
    //    brayan.SetPosY(29);
    //    j.SetAvatar(brayan);
    //    Dibujador de;
    //    de.SetA(2);
    //    de.SetB(2);
    //    j.SetDibujador(de);
    //    printf("==========\n");
    //    j.dibujarEsquema();
    char c1, c2;
    historiaDelJuego();
    Juego nuevoJuevo;
    nuevoJuevo.CargarLaberintos();
    nuevoJuevo.iniciarPosicionAvatar();
    nuevoJuevo.GetLaberintoActual().impresion();    
    // nuevoJuevo.GetAvatar().impresionInformacionAvatar() ; 
    while (1) {
        printf("%45s==Esquema_Avatar==\n"," ");
        nuevoJuevo.dibujarEsquema();
        printf("%45s==================\n"," ");
        mostrarOpcionesGenerales(c1, c2);
        if (c1 == 'm') {
            //nuevoJuevo.intentarmosMoverAvatar();
        } else if (c1 == 'i') {
            
        } else if (c1 == 'u') {

        } else if (c1 == 's') {
            printf("Termino el juego\n");
            break;
        }
    }
    return 0;
}

