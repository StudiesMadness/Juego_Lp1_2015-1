/* 
 * File:   Juego.cpp
 * Author: Brayan
 * 
 * Created on 5 de junio de 2015, 11:18 AM
 */
#define PARED  '#' 
#define ADENTRO ' '
#define ANTERIOR '-' 
#define SIGUIENTE '+'
#define MONSTRUO 'M'
#define ARTEFACTO 'A'
#define FIN 'e'
#define IMAG_AVATAR '&'
#define DIR_ARRIBA  'i'
#define DIR_ABAJO    'k'
#define DIR_DERECHA   'l'
#define DIR_IZQUIERDA  'j'

#include "Juego.h"
#include <fstream>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>

using namespace std;

Juego::Juego() {
    monstruo = new Monstruo[10]; // 10 es un ejemplo puede ser cualquie valor 
    arreLaberintos = new Laberinto[10]; // Suponiendo como maximos 10
    posLaberintoActual = 0; // Por empieza en el principio         
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {

}



void desordenar(int arre[], int N_elementos) {
    srand(time(NULL));
    int ordenado[100], usado[100] = {0};
    for (int i = 0; i < N_elementos; i++) {
        ordenado[i] = i;
    }
    int index = 0;
    for (int i = 0; i < N_elementos; i++) {
        do {
            index = (rand() % N_elementos);
        } while (usado[index]);
        arre[i] = ordenado[index];
        usado[index] = true;
    }
}

void leerLaberintos(char arreNombArch2[][50], int &cant) {
    char aux[50];
    cant = 0;
    ifstream archivoLab("Registro_Laberintos.txt");
    while (1) {
        archivoLab.getline(arreNombArch2[cant], 50);
        //printf("%s\n", arreNombArch2[cant]);
        if (strlen(arreNombArch2[cant]) == 0) break;

        cant++;
    }
    archivoLab.close();
}

void Juego::CargarLaberintos() {
    int cant_Labs = 0, indices[100] = {0};
    char arreNombArch[50][50] = {0};
    leerLaberintos(arreNombArch, cant_Labs);
    desordenar(indices, cant_Labs);
    arreLaberintos = new Laberinto[cant_Labs];
    for (int i = 0; i < cant_Labs; i++) {
        arreLaberintos[i] = gestorLaberinto.crear(arreNombArch[indices[i]]);
    }
    posLaberintoActual = 0;
    LaberintoActual = arreLaberintos[0];
    cantidadDeLaberintos = cant_Labs;
    return;
}

void Juego::iniciarPosicionAvatar() {
    this->avatar.SetPosX(this->LaberintoActual.getX_Ant());
    int a = this->LaberintoActual.getX_Ant();
    //  printf("%d ",a) ; 
    this->avatar.SetPosY(this->LaberintoActual.getY_Ant());
    int b = this->LaberintoActual.getY_Ant();
    //  printf("%d ",b) ; 
}

void Juego::intentarmosMoverAvatar(char& movimiento, int &flag) {
    int nx, ny;
    nx = avatar.GetPosX();
    ny = avatar.GetPosY();
    switch (movimiento) {
        case DIR_ARRIBA: ny = ny - 1;
            break;
        case DIR_ABAJO: ny = ny + 1;
            break;
        case DIR_IZQUIERDA: nx = nx - 1;
            break;
        case DIR_DERECHA: nx = nx + 1;
            break;
    }
    //    char s = (char) LaberintoActual.getCelda()[nx][ny].GetTipo() ;
    if (LaberintoActual.getCelda()[ny][nx].GetTipo() == PARED) {
        flag=0;
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == ADENTRO) {
        flag=1;
        avatar.SetPosX(nx);
        avatar.SetPosY(ny);
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == ARTEFACTO) {
        flag=0;
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == MONSTRUO) {
        flag=0;
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == ANTERIOR) {
        if (posLaberintoActual == 0) {
            flag=0;//no hace nada
        } else {
            flag=1;
            posLaberintoActual -= 1;
            LaberintoActual = arreLaberintos[posLaberintoActual];
            avatar.SetPosX(LaberintoActual.getX_Sig());
            avatar.SetPosY(LaberintoActual.getY_sig());
        }
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == SIGUIENTE) {
        if (posLaberintoActual == cantidadDeLaberintos - 1) {
            movimiento = FIN;           
            flag=0;
        } else {
            flag=1;
            posLaberintoActual += 1;
            LaberintoActual = arreLaberintos[posLaberintoActual];
            avatar.SetPosX(LaberintoActual.getX_Ant());
            avatar.SetPosY(LaberintoActual.getY_Ant());
        }
    }
}

void Juego::SetDibujador(Dibujador dibujador) {
    this->dibujador = dibujador;
}

Dibujador Juego::GetDibujador() const {
    return dibujador;
}

void Juego::dibujarEsquema() {
    int posX_Avatar = this->avatar.GetPosX();
    int m = this->LaberintoActual.getM();
    int n = this->LaberintoActual.getN();
    int posY_Avatar = this->avatar.GetPosY();
    int mitad_ancho = this->dibujador.GetA();
    int mitad_alto = this->dibujador.GetB();
    int i_arriba, i_abajo, j_izq, j_der;
    i_arriba = posY_Avatar - mitad_alto;
    if (i_arriba < 0) i_arriba = 0;
    i_abajo = posY_Avatar + mitad_alto;
    if (i_abajo > m - 1) i_abajo = m - 1;
    j_izq = posX_Avatar - mitad_ancho;
    if (j_izq < 0) j_izq = 0;
    j_der = posX_Avatar + mitad_ancho;
    if (j_der > n - 1) j_der = n - 1;
    //for (int k = 0; k < 40 - (j_der - j_izq) / 2; k++)printf(" ");
    int ai = avatar.GetPosX();
    int aj = avatar.GetPosY();    
    printf("\n====Esquema_Avatar====\n");
    for (int i = i_arriba; i <= i_abajo; i++) {
        //     for (int k = 0; k < 40 - (j_der - j_izq) / 2; k++)printf(" "); // Para poder centrar el esquema
        for (int j = j_izq; j <= j_der; j++) {
            if (avatar.GetPosX() == j && avatar.GetPosY() == i) {
                printf("%c", IMAG_AVATAR);
            } else
                printf("%c", (char) this->LaberintoActual.getCelda()[i][j].GetTipo());
        }
        printf("\n");
    }
    //   for (int k = 0; k < 40 - (j_der - j_izq) / 2; k++)printf(" ");
    //printf("====Esquema_Avatar====\n");
}

Laberinto Juego::GetLaberintoActual() const {
    return LaberintoActual;
}

void Juego::SetAvatar(Avatar avatar) {
    this->avatar = avatar;
}

Avatar Juego::GetAvatar() const {
    return avatar;
}

void Juego::SetPosLaberintoActual(int posLaberintoActual) {
    this->posLaberintoActual = posLaberintoActual;
}

int Juego::GetPosLaberintoActual() const {
    return posLaberintoActual;
}



