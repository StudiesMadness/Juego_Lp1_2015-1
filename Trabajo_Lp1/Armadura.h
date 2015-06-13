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
    Armadura(int def=0);
    Armadura(const Armadura& orig);
    virtual ~Armadura();
    void AsignarArmadura(int, char*);
};

#endif	/* ARMADURA_H */

