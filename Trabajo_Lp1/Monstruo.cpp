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
}

Monstruo::Monstruo(const Monstruo& orig) {
}

Monstruo::~Monstruo() {

}

void Monstruo::AsignarMons(int level, int max, int vida, char *name){
    nivel = level;
    datos.SetNombre(name);
    datos.SetMaxVida(max);
    datos.SetVidaActual(vida);
}
