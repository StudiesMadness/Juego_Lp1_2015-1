/* 
 * File:   Dibujador.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:24 AM
 */

#ifndef DIBUJADOR_H
#define	DIBUJADOR_H

class Dibujador {
private:
    int A;
    int B;

public:
    Dibujador();
    Dibujador(const Dibujador& orig);
    virtual ~Dibujador();


};

#endif	/* DIBUJADOR_H */

