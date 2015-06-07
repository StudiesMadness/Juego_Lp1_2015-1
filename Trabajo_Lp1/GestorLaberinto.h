/* 
 * File:   GestorLaberinto.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:23 AM
 */

#ifndef GESTORLABERINTO_H
#define	GESTORLABERINTO_H

#include "Laberinto.h"

class GestorLaberinto {
private:

public:
    Laberinto crear(char *);
    GestorLaberinto();
    GestorLaberinto(const GestorLaberinto& orig);
    virtual ~GestorLaberinto();
};

#endif	/* GESTORLABERINTO_H */

