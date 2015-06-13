/* 
 * File:   FuncionesExtras.h
 * Author: Junior
 *
 * Created on 7 de junio de 2015, 01:07 AM
 */
#include "Arma.h"
#include "Monstruo.h"
#include "Armadura.h"
#include "PocionCuracion.h"
#ifndef FUNCIONESEXTRAS_H
#define	FUNCIONESEXTRAS_H

void historiaDelJuego() ; 
void mostrarOpciones(); 
void mostrarOpcionesGenerales() ; 
void LecturaMoviento(char &c1);
void CargarMonstruos(Monstruo *&, int &);
void CargarArmas(Arma *&, Arma *&, int &, int &);
void CargarArmaduras(Armadura *&, int &);
void CargarPociones(PocionCuracion *&, int &);

#endif	/* FUNCIONESEXTRAS_H */

