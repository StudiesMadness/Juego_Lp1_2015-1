/* 
 * File:   Dibujador.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:24 AM
 */

#include "Dibujador.h"
#include "Avatar.h"

Dibujador::Dibujador() {
    A = 3;
    B = 3;
}

Dibujador::~Dibujador() {
}

void Dibujador::SetB(int B) {
    this->B = B;
}

int Dibujador::GetB() const {
    return B;
}

void Dibujador::SetA(int A) {
    this->A = A;
}

int Dibujador::GetA() const {
    return A;
}


