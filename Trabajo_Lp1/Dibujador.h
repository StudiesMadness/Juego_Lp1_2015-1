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
    virtual ~Dibujador();
    void SetB(int B);
    int GetB() const;
    void SetA(int A);
    int GetA() const;
};

#endif	/* DIBUJADOR_H */

