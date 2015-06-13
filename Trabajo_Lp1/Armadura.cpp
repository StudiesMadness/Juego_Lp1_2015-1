/* 
 * File:   Armadura.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:15 AM
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Artefacto.h"
#include "Armadura.h"

Armadura::Armadura(int def) {
    defensa = def;
    nombre = NULL;
}

Armadura::Armadura(const Armadura& orig) {
}

Armadura::~Armadura() {
}

void Armadura::AsignarArmadura(int def, char *name){
    defensa = def;
    nombre = new char[strlen(name)+1];
    strcpy(nombre, name);
}
