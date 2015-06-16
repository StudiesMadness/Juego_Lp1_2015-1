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
#include "Monstruo.h"
#include "Arma.h"
#include "Armadura.h"
#include "PocionCuracion.h"


#include <WINDOWS.h> 
#include <MMSystem.h>
using namespace std;


 
int main(int argc, char** argv) {
    
    PlaySound(("castlevania.wav"), NULL, SND_ASYNC); //funcion para iniciar un sonido
    
    char c1;
    int flag=1, numM, numAC, numAA, numAd, numP;
    Monstruo *Mons;
    Arma *ArmA, *ArmC;
    Armadura *Armd;
    PocionCuracion *Poc;
    historiaDelJuego();
    Juego nuevoJuevo;
    Dibujador dibujadorNuevo;
    dibujadorNuevo.SetA(10);
    dibujadorNuevo.SetB(10);
    nuevoJuevo.SetDibujador(dibujadorNuevo);
    nuevoJuevo.CargarLaberintos();
    nuevoJuevo.iniciarPosicionAvatar();
   // nuevoJuevo.GetLaberintoActual().impresion(); //<--- elmetodo de impresio(despues borrarlo))
    // nuevoJuevo.GetAvatar().impresionInformacionAvatar() ; 
    CargarMonstruos(Mons, numM);
    CargarArmas(ArmA, ArmC, numAA, numAC);
    CargarArmaduras(Armd, numAd);
    CargarPociones(Poc, numP);
    
    PlaySound(NULL,NULL,0);  //Funcion para detener un sonido
    PlaySound(("Doom_2-Level_1.wav"), NULL, SND_ASYNC);
    while (1) {       
        if(flag==1){
            nuevoJuevo.dibujarEsquema();
            nuevoJuevo.GetAvatar().mostrarDatosMapa();
//            nuevoJuevo.GetDibujador().
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

