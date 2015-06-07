/* 
 * File:   Avatar.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:17 AM
 */
#include "Entidad.h"
#include "Avatar.h"

Avatar::Avatar() {
    this->SetPosX(3);
    this->SetPosY(3);
    this->SetMaxVida(100);
}

Avatar::Avatar(const Avatar& orig) {
    this->SetPosX(orig.GetPosX()) ; 
    this->SetPosY(orig.GetPosY()) ; 
    this->SetMaxVida(orig.GetMaxVida()) ; 
}

Avatar::~Avatar() {
}


