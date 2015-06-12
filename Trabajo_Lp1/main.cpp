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
#define FIN 'e'

#define DIR_ARRIBA  'i'
#define DIR_ABAJO    'k'
#define DIR_DERECHA   'l'
#define DIR_IZQUIERDA  'j'
#include <cstdlib>
#include <cstdio>
#include "Juego.h"
#include "FuncionesExtras.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char c1;
    int flag=1;
    historiaDelJuego();
    Juego nuevoJuevo;
    Dibujador dibujadorNuevo;
    dibujadorNuevo.SetA(10);
    dibujadorNuevo.SetB(10);
    nuevoJuevo.SetDibujador(dibujadorNuevo);
    nuevoJuevo.CargarLaberintos();
    nuevoJuevo.iniciarPosicionAvatar();
    nuevoJuevo.GetLaberintoActual().impresion(); //<--- elmetodo de impresio(despues borrarlo))
    // nuevoJuevo.GetAvatar().impresionInformacionAvatar() ; 
    while (1) {       
        if(flag==1){
            nuevoJuevo.dibujarEsquema();
            mostrarOpcionesGenerales();
        }
        LecturaMoviento(c1);
        if (c1 == DIR_ARRIBA || c1 ==DIR_ABAJO || c1 == DIR_DERECHA || c1 ==DIR_IZQUIERDA && c1!=FIN) {
            nuevoJuevo.intentarmosMoverAvatar(c1, flag);   
            if(c1 == FIN) {
                printf("YOU WIN :D\n");
                break;
            }
        } else if (c1 == 'a') {  // iteractuira con el moustro
            nuevoJuevo.intentamosInteractuarAvatar();
        } else if (c1 == 's') {   // usar algo 
            printf("Saca Objeto\n") ; 
        } else if (c1 == FIN) {   // Falta reconocoer Escape
            printf("CLOSE SUCCESFULLY\n");
            break;
        }
        else flag=0;
    }
    return 0;
}

