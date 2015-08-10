/* 
 * File:   Monstruo.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:18 AM
 */
#include "Entidad.h"
#include "Monstruo.h"

Monstruo::Monstruo(int level) {
    nivel = level;
    this->SetMaxVida(100*(level+1));
    this->SetVidaActual(100*(level+1));
    this->SetDanhoBase(30*(level+1));
}

Monstruo::~Monstruo() {

}

void Monstruo::AsignarMons(int level, int max, int vida, char *name){
    nivel = level;
    this->SetNombre(name);
    this->SetMaxVida(max);
    this->SetVidaActual(vida);
}

