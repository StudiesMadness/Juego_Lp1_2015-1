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
    int cantidadDeLaberintos;
    Laberinto *arreLaberintos;
public:
    Juego();
    Juego(const Juego& orig);
    virtual ~Juego();

    void CargarLaberintos();
    void iniciarPosicionAvatar();
    
    void intentarmosMoverAvatar(char& , int&);
    void intentamosInteractuarAvatar(void);
    void PreguntarPelearConMonstruo(void);
    void PelearConMonstruo(Monstruo monster);   
    void meterAlSaco();
    
    void SetDibujador(Dibujador dibujador);
    Dibujador GetDibujador() const;
    void dibujarEsquema();
    Laberinto GetLaberintoActual() const;
    void SetAvatar(Avatar avatar);
    Avatar GetAvatar() const;
    void SetPosLaberintoActual(int posLaberintoActual);
    int GetPosLaberintoActual() const;

};

#endif	/* JUEGO_H */

