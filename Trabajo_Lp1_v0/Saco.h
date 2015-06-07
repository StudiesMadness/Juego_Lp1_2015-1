/* 
 * File:   Saco.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:14 AM
 */
#include "Artefacto.h"

#ifndef SACO_H
#define	SACO_H

class Saco {
    private:
        Artefacto artefacto[];
public:
    Saco();
    Saco(const Saco& orig);
    virtual ~Saco();


};

#endif	/* SACO_H */

