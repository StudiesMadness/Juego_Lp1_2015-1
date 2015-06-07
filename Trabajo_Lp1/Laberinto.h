/* 
 * File:   Laberinto.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:19 AM
 */

#ifndef LABERINTO_H
#define	LABERINTO_H

#include "Celda.h"

class Laberinto {
private:
    int M;
    int N;
    double pctMonstruo;
    int nivelesMonstruo[];
    //double pctArtefacto;
    int nivelesArtefacto[];
    Celda celda[];
    
public:
    Laberinto();
    Laberinto(const Laberinto& orig);
    virtual ~Laberinto();


};

#endif	/* LABERINTO_H */

