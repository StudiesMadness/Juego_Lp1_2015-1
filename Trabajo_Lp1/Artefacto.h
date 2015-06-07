/* 
 * File:   Artefacto.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:14 AM
 */

#ifndef ARTEFACTO_H
#define	ARTEFACTO_H

class Artefacto { //Hereda a Arma , Armadura y PocionCuracion 
private:

public:
    Artefacto();
    Artefacto(const Artefacto& orig);
    virtual ~Artefacto();        
};

#endif	/* ARTEFACTO_H */

