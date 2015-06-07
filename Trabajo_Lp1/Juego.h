/* 
 * File:   Juego.h
 * Author: alulab14
 *
 * Created on 5 de junio de 2015, 11:18 AM
 */

#include "Avatar.h"
#include "Monstruo.h"
#include "Dibujador.h"
#include "Laberinto.h"
#include "GestorLaberinto.h"

#ifndef JUEGO_H
#define	JUEGO_H

class Juego {
private:
    Avatar avatar;
    Monstruo *monstruo;
    Dibujador dibujador;
    GestorLaberinto gestorLaberinto;
    Laberinto LaberintoActual;
    int posLaberintoActual;
    Laberinto *arreLaberintos;
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();
    
    void CargarLaberintos();
    void iniciarPosicionAvatar() ; 
    
    void SetDibujador(Dibujador dibujador);
    Dibujador GetDibujador() const;
    void dibujarEsquema();
    Laberinto GetLaberintoActual() const;
    void SetAvatar(Avatar avatar);
    Avatar GetAvatar() const;
        
};

#endif	/* JUEGO_H */

