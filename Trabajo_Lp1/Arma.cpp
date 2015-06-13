/* 
 * File:   Arma.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:15 AM
 */
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "Artefacto.h"
#include "Arma.h"

Arma::Arma(int min,int max) {
    danhoMin=min;
    danhoMax=max;
    nombre=NULL;
}

Arma::Arma(const Arma& orig) {
}

Arma::~Arma() {

}

void Arma::AsignarArma(int min, int max, char *name){
    danhoMin=min;
    danhoMax=max;
    nombre = new char[strlen(name)+1];
    strcpy(nombre, name);
}