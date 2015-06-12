#include <cstdio>
#include <cstring>
#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void historiaDelJuego() {

}

int opciones_contiene_palabra_mover(char opcion[], const char*pal) {
    for (int i = 0; opcion[i]; i++) {
        if (opcion[i] == ' ') opcion[i] = 0;
    }
    return strcmp(opcion, pal);
}

void mostrarOpcionesGenerales() {
    // c1 indicara si es m,i,u,s (mover, interactuar , usar , salir))
    // c2 indicar el parametro demas 
    //      en mover c2 seria(u,d,l,r) 
    //      en interactur falta definir 
    //      en usar C2 seria i el numero de iten a usar pero en caracter
    //      en salir C2 seria 0 ; 

    printf("\n--OPCIONES:\n");
    //printf("- mover Direccionales\n");
    //    printf("                 Arriba:     \"mover u\"\n");
    //    printf("                 Abajo:      \"mover d\"\n");
    //    printf("                 Izquierda:  \"mover l\"\n");
    //    printf("                 Derecha:    \"mover r\"\n");
    printf("- interactuar(a)\n");
    printf("- usar i(s)\n");
    printf("- salir(e)\n");
    printf("- Escriba una accion         :");
}

void LecturaMoviento(char &c1){
    int c;
    while (1) {
        c = 0;
        c = getch();
        if( 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z') {
            c1 = (char) c ; 
            return ; 
        }
        switch ((c = getch())) {
            case KEY_UP:
                //cout << endl << "Up" << endl;//key up
                c1 = 'i' ; 
                return;
            case KEY_DOWN:
                c1 = 'k';
                return;
            case KEY_LEFT:
                c1 = 'j';
                return;
            case KEY_RIGHT:
                c1 = 'l';
                return;
            default:
                cout << endl << "null" << endl; // key left
                return ;
        }
    }
}