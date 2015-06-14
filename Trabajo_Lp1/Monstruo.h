/* 
 * File:   Monstruo.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:18 AM
 */
#include "Entidad.h"

#ifndef MONSTRUO_H
#define	MONSTRUO_H

class Monstruo : public Entidad{
private:
    int nivel;
public:
    Monstruo(int level=0);
    virtual ~Monstruo();
    void AsignarMons(int, int, int, char*);
    
    Entidad GetDatos() const;

};

#endif	/* MONSTRUO_H */

