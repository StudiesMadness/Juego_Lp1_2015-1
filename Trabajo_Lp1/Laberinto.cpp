/* 
 * File:   Laberinto.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:19 AM
 */

#include "Laberinto.h"
#include "GestorLaberinto.h"
#include <iostream>
using namespace std ; 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

Laberinto::Laberinto() {
    M = 30;
    N = 30;
    pctArtefacto = 0;
    pctArtefacto = 0;
    nivelesArtefacto = new int[10];
    nivelesMonstruo = new int[10];
    celda = new Celda*[N];
    for (int i = 0; i < M; i++) {
        celda[i] = new Celda[M];
    }
}

Laberinto::~Laberinto() {

}

//Laberinto Laberinto::creaion(char *nombreArchivo) {
  //  GestorLaberinto GL;
//    return GL.crear(nombreArchivo);
//}

void Laberinto::impresion() {
     for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << (char)celda[i][j].GetTipo();
        }
        cout << endl ; 
    }
}

void Laberinto::setY_sig(int y_sig) {
    this->y_sig = y_sig;
}

int Laberinto::getY_sig() const {
    return y_sig;
}

void Laberinto::setX_Sig(int x_Sig) {
    this->x_Sig = x_Sig;
}

int Laberinto::getX_Sig() const {
    return x_Sig;
}

void Laberinto::setY_Ant(int y_Ant) {
    this->y_Ant = y_Ant;
}

int Laberinto::getY_Ant() const {
    return y_Ant;
}

void Laberinto::setX_Ant(int x_Ant) {
    this->x_Ant = x_Ant;
}

int Laberinto::getX_Ant() const {
    return x_Ant;
}

void Laberinto::setCelda(Celda** celda) {
    this->celda = celda;
}

Celda** Laberinto::getCelda() const {
    return celda;
}

void Laberinto::setNivelesArtefacto(int* nivelesArtefacto) {
    this->nivelesArtefacto = nivelesArtefacto;
}

int* Laberinto::getNivelesArtefacto() const {
    return nivelesArtefacto;
}

void Laberinto::setPctArtefacto(double pctArtefacto) {
    this->pctArtefacto = pctArtefacto;
}

double Laberinto::getPctArtefacto() const {
    return pctArtefacto;
}

void Laberinto::setNivelesMonstruo(int* nivelesMonstruo) {
    this->nivelesMonstruo = nivelesMonstruo;
}

int* Laberinto::getNivelesMonstruo() const {
    return nivelesMonstruo;
}

void Laberinto::setPctMonstruo(double pctMonstruo) {
    this->pctMonstruo = pctMonstruo;
}

double Laberinto::getPctMonstruo() const {
    return pctMonstruo;
}

void Laberinto::setN(int N) {
    this->N = N;
}

int Laberinto::getN() const {
    return N;
}

void Laberinto::setM(int M) {
    this->M = M;
}

int Laberinto::getM() const {
    return M;
}
