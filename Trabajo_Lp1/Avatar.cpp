/* 
 * File:   Avatar.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:17 AM
 */
#include "Entidad.h"
#include "Avatar.h"
#include <iostream>

using namespace std;

Avatar::Avatar() {
    this->SetPosX(3);
    this->SetPosY(3);
    this->SetMaxVida(1000);
    this->SetVidaActual(1000);
    this->SetDanhoBase(120);
}

//Avatar::Avatar(const Avatar& orig) {
//    this->SetPosX(orig.GetPosX()) ; 
//    this->SetPosY(orig.GetPosY()) ; 
//    this->SetMaxVida(orig.GetMaxVida()) ; 
//}

Avatar::~Avatar() {
}

void Avatar::mostrarDatosMapa() {
    cout << "Vida: " << this->GetVidaActual() << endl;
    cout << "X: " << this->GetPosX() << " " << "Y: " << this->GetPosY() << endl;
}
