/* 
 * File:   Arma.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:15 AM
 */

#ifndef ARMA_H
#define	ARMA_H


class Arma : public Artefacto {
    
private:
    int danhoMin;
    int danhoMax;
    char* nombre;

public:
    Arma();
    Arma(const Arma& orig);
   // virtual ~Arma();


};

#endif	/* ARMA_H */

