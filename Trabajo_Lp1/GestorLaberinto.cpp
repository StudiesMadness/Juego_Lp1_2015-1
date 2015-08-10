/* 
 * File:   GestorLaberinto.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:23 AM
 */
#define PARED  '#' 
#define ADENTRO ' '
#define ANTERIOR '-' 
#define SIGUIENTE '+'
#define MONSTRUO 'M'
#define ARTEFACTO 'A'
#include "GestorLaberinto.h"
#include "Laberinto.h"
#include <fstream>
#include <iostream>
#include <io.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

GestorLaberinto::GestorLaberinto() {
}

GestorLaberinto::~GestorLaberinto() {
}

Laberinto GestorLaberinto::crear(char *nombreArchivo) {
    Laberinto lab;
    int m, n;
    char c;
    ifstream archEntrad(nombreArchivo);
    if (!archEntrad) {
        cerr << "No se pudo abrir Archivo" << endl;
        return lab;
    }
    int contM = 2, contA = 2;
    archEntrad >> m >> n;
    lab.setM(m);
    lab.setN(n);
    c = archEntrad.get(); // Se lee cambio de linea 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c = archEntrad.get();
            if (c == '\n') c = archEntrad.get();
            if (c == ANTERIOR) {
                lab.setX_Ant(j) ; 
                lab.setY_Ant(i) ; 
            }
            if(c == SIGUIENTE){
                lab.setX_Sig(j) ; 
                lab.setY_sig(i) ;
            }            
	    if (c == MONSTRUO) {
                srand(time(NULL));
                int numb = rand() % 10 + 1;
                if (numb < 5 && contM > 0) {
                    c = ' ';
                    contM--;
                }
            }
            if (c == ARTEFACTO) {
                srand(time(NULL));
                int numb = rand() % 10 + 1;
                if (numb < 5 && contA > 0) {
                    c = ' ';
                    contA--;
                }
            }
            lab.getCelda()[i][j].SetTipo(c);
        }
    }
    return lab;
}