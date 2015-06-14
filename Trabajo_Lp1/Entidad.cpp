/* 
 * File:   Entidad.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:11 AM
 */

#include "Entidad.h"
#include <cstdio>
#include <cstring>

Entidad::Entidad(int max, int vida) {
    maxVida = max;
    VidaActual = vida;
    nombre = NULL;
}


Entidad::~Entidad() {
}

void Entidad::SetSaco(Saco saco) {
    this->saco = saco;
}

Saco Entidad::GetSaco() const {
    return saco;
}

void Entidad::SetNombre(char* name) {
    this->nombre = new char[strlen(name) + 1];
    strcpy(this->nombre, name);
}

char* Entidad::GetNombre() const {
    char *aux;
    aux = new char[strlen(nombre) + 1 ];
    strcpy(aux, nombre);
    return aux;
}

void Entidad::SetVidaActual(int VidaActual) {
    this->VidaActual = VidaActual;
}

int Entidad::GetVidaActual() const {
    return VidaActual;
}

void Entidad::SetMaxVida(int maxVida) {
    this->maxVida = maxVida;
}

int Entidad::GetMaxVida() const {
    return maxVida;
}

void Entidad::SetPosX(int posX) {
    this->posX = posX;
}

int Entidad::GetPosX() const {
    return posX;
}

void Entidad::SetPosY(int posY) {
    this->posY = posY;
}

int Entidad::GetPosY() const {
    return posY;
}

void Entidad::SetArma(Arma arma) {
    this->arma = arma;
}

Arma Entidad::GetArma() const {
    return arma;
}

void Entidad::SetArmadura(Armadura armadura) {
    this->armadura = armadura;
}

Armadura Entidad::GetArmadura() const {
    return armadura;
}

void Entidad::SetDanhoBase(int danhoBase) {
    this->danhoBase = danhoBase;
}

int Entidad::GetDanhoBase() const {
    return danhoBase;
}





