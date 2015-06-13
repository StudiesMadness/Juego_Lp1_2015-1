/* 
 * File:   PocionCuracion.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:17 AM
 */
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "Artefacto.h" 
#include "PocionCuracion.h"

PocionCuracion::PocionCuracion(int ptos) {
    puntosVida=0;
    nombre = NULL;
}

PocionCuracion::PocionCuracion(const PocionCuracion& orig) {
}

PocionCuracion::~PocionCuracion() {

}

void PocionCuracion::AsignarPocion(int ptos, char *name){
    puntosVida=ptos;
    nombre = new char[strlen(name)+1];
    strcpy(nombre,name);
}