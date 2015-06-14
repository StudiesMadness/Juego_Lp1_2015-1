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
    Arma(int min=0,int max=0);
    virtual ~Arma();
    void AsignarArma(int, int, char*);
    
    void SetDanhoMax(int danhoMax);
    int GetDanhoMax() const;
    void SetDanhoMin(int danhoMin);
    int GetDanhoMin() const;

};

#endif	/* ARMA_H */

