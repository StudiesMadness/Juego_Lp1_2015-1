/* 
 * File:   Juego.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:18 AM
 */

#include "Avatar.h"
#include "Monstruo.h"
#include "Dibujador.h"
#include "Laberinto.h"
#include "GestorLaberinto.h"

#ifndef JUEGO_H
#define	JUEGO_H

class Juego {
private:
    Avatar avatar[];
    Monstruo monstruo[];
    Dibujador dibujador;
    Laberinto laberinto[];
    GestorLaberinto gestorLaberinto;
    
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();


};

#endif	/* JUEGO_H */

