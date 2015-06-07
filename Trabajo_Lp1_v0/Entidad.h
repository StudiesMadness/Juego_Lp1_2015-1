/* 
 * File:   Entidad.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:11 AM
 */
#include "Saco.h"

#ifndef ENTIDAD_H
#define	ENTIDAD_H

class Entidad {
private:
    int posY;
    int posX;
    int maxVida;
    int VidaActual;
    char* nombre;
    Saco saco;
public:
    Entidad();
    Entidad(const Entidad& orig);
    virtual ~Entidad();


};

#endif	/* ENTIDAD_H */

