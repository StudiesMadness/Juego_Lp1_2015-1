/* 
 * File:   Juego.cpp
 * Author: alulab14
 * 
 * Created on 5 de junio de 2015, 11:18 AM
 */

#include "Juego.h"
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>

Juego::Juego() {
    monstruo = new Monstruo[10]; // 10 es un ejemplo puede ser cualquie valor 
    arreLaberintos = new Laberinto[10]; // Suponiendo como maximos 10
    posLaberintoActual = 0; // Por empieza en el principio         
}

Juego::Juego(const Juego& orig) {
}

Juego::~Juego() {

}

int es_archivo_laberinto(char *aux) {
    if (aux[0] == 'L' && aux[1] == 'a' && aux[2] == 'b' &&
            aux[3] == '_') return 1;
    return 0;
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

void Juego::CargarLaberintos() {
    // Tener cuidado al modificar   DEBE HABER DOS SlASH "\\"
    char cadena[100] = "C:\\Users\\Junior\\Downloads\\Trabajo_Lp1_v0 (1)\\Trabajo_Lp1_v0";
    
    char arreNombArchv[50][50] = {0}, aux[50];
    int cant_Archivos = 0, indices[100] = {0};
 
    DIR *dir; //puntero a directorio
    struct dirent *ent; //cargar la direccion
    if ((dir = opendir(cadena)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] != '.') {//Directorios extraños "." y ".." ant y desp
                strcpy(aux, ent->d_name);
                if (es_archivo_laberinto(aux)) {
                    strcpy(arreNombArchv[cant_Archivos], aux);
                    //  printf("%s\n", arreNombArchv[cant_Archivos]);
                    cant_Archivos++;
                }
            }
        }
        closedir(dir);
        desordenar(indices, cant_Archivos);
        // Comprobacion si lee o no archivo Lab_berintos
        //for(int i = 0 ; i<cant_Archivos ; i++)
        //    printf("%s\n", arreNombArchv[indices[i]]) ; 

        arreLaberintos = new Laberinto[cant_Archivos];
        for (int i = 0; i < cant_Archivos; i++) {
            arreLaberintos[i] = gestorLaberinto.crear(arreNombArchv[indices[i]]);
        }
        posLaberintoActual = 0;
        LaberintoActual = arreLaberintos[0];

    } else {
        /* no se pudo abrir directorio */
        perror("Error");
        return;
    }
    return;
}

void Juego::iniciarPosicionAvatar() {
    this->avatar.SetPosX(this->LaberintoActual.getX_Ant());
    int a = this->LaberintoActual.getX_Ant() ; 
  //  printf("%d ",a) ; 
    this->avatar.SetPosY(this->LaberintoActual.getY_Ant());
    int b = this->LaberintoActual.getY_Ant() ;
  //  printf("%d ",b) ; 
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
    //Laberinto Lab_ActuaL = this->LaberintoActual;
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
    for (int i = i_arriba; i <= i_abajo; i++) {
        for(int k = 0 ; k<50; k++)printf(" ") ; 
        for (int j = j_izq; j <= j_der; j++) {
            printf("%c", (char) this->LaberintoActual.getCelda()[i][j].GetTipo());
        }
        printf("\n");
    }    
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



