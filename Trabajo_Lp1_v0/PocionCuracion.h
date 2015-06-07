/* 
 * File:   PocionCuracion.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:17 AM
 */

#ifndef POCIONCURACION_H
#define	POCIONCURACION_H

class PocionCuracion : public Artefacto{
private:
    int puntosVida;

public:
    PocionCuracion();
    PocionCuracion(const PocionCuracion& orig);
    //virtual ~PocionCuracion();


};

#endif	/* POCIONCURACION_H */

