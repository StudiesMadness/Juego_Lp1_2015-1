/* 
 * File:   Armadura.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:15 AM
 */

#ifndef ARMADURA_H
#define	ARMADURA_H

class Armadura : public Artefacto{
private:
    int defensa;
    char * nombre;
    
public:
    Armadura();
    Armadura(const Armadura& orig);
    //virtual ~Armadura();

};

#endif	/* ARMADURA_H */

