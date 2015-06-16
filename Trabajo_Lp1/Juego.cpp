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
#include "rlutil.h"
#include "Juego.h"
#include <fstream>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<time.h>
#include <iostream>


#include <WINDOWS.h> 
#include <MMSystem.h>

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
        flag = 0;
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == ADENTRO) {
        flag = 1;
        avatar.SetPosX(nx);
        avatar.SetPosY(ny);
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == ARTEFACTO) {
        flag = 0;
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == MONSTRUO) {
        flag = 0;
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == ANTERIOR) {
        if (posLaberintoActual == 0) {
            flag = 0; //no hace nada
        } else {
            flag = 1;
            posLaberintoActual -= 1;
            LaberintoActual = arreLaberintos[posLaberintoActual];
            avatar.SetPosX(LaberintoActual.getX_Sig());
            avatar.SetPosY(LaberintoActual.getY_sig());
        }
    } else if (LaberintoActual.getCelda()[ny][nx].GetTipo() == SIGUIENTE) {
        if (posLaberintoActual == cantidadDeLaberintos - 1) {
            movimiento = FIN;
            flag = 0;
        } else {
            flag = 1;
            posLaberintoActual += 1;
            LaberintoActual = arreLaberintos[posLaberintoActual];
            avatar.SetPosX(LaberintoActual.getX_Ant());
            avatar.SetPosY(LaberintoActual.getY_Ant());
        }
    }
}

void Juego::intentamosInteractuarAvatar(void) {
    char tipo;

    int y = avatar.GetPosY();
    int x = avatar.GetPosX();

    for (int f = -1; f < 2; f++) {
        for (int k = -1; k < 2; k++) { //recorrido alrededor del Avatar

            if (!(f == 0 && k == 0)) { // para evitar que revise la posiciÃ³n actual del Avatar

                tipo = (char) LaberintoActual.getCelda()[y + f][x + k].GetTipo();

                if (tipo == MONSTRUO || tipo == ARTEFACTO) {

                    switch (tipo) {
                        case MONSTRUO:
                            PreguntarPelearConMonstruo();
                            PlaySound(NULL, NULL, 0);
                            PlaySound(("Doom_2-Level_1.wav"), NULL, SND_ASYNC);
                            k = 3;
                            f = 3; //para salir del bucle
                            break;
                        case ARTEFACTO:
                            //cogerArtefacto
                            break;
                    }

                }
            }
        }
    }
}

void Juego::PreguntarPelearConMonstruo(void) {

    PlaySound(NULL, NULL, 0);
    PlaySound(("Doom_Level_1.wav"), NULL, SND_ASYNC);
    char linea[30];
    Monstruo monster;
    system("cls");

    printf( ".          O7OI77Z$77I7$$7$.           \n"
            "         .77O$8II77$I7887I7$$7          \n"
            "       .7+77I$8ZI$O$7O:77$7?+77..       \n"
            "     .87++I$77:+++I7?==ZZIZ?IZ8$7$.     \n"
            "   .877OI7=Z7IN~IZ8.8.8IO,7777$7O7I.   \n"
            "  .7$777$7Z8..8O8DZI8O8.O$777O$$$$$$..  \n"
            " .$$7$$$$I$ON,.O.~Z~~+~8I7$7$Z7$OD=??7. \n"
            " .O+$+Z$78ID8Z$=7777$=+I777$$778?O?$?+,.\n"
            ".?Z?OI?O$7OZ7I$$7I7$7$7777O$77$Z.,+I78..\n"
            ".++8II+Z$77ZO$7777$7I7$$$$7777$:.       \n"
            "    .~7$77777$$Z8O$$$7777777$Z77O..     \n"
            "  .O$Z7$Z77$777777777777777Z$O$O$$I..   \n"
            " .:777777Z$$$77777$I77777$$$$777IIZ7.   \n"
            " .II77777$.78Z$$$$$$Z$$$$8O.77777777O.. \n"
            " .I77777$7. ..Z$$ZZ$$ZZZ....$OI77III$$. \n"
            ".+O$I777II.     ..... ..     .=8$78+I    \n"
            "                                         \n");

    cout << endl << "El monstruo tiene:\n" << endl;
    cout << "vida: " << monster.GetMaxVida() << endl;
    cout << "Danho base: " << monster.GetDanhoBase() << endl;
    if (monster.GetArmadura().GetDefensa() != 0)
        cout << "armadura:" << monster.GetArmadura().GetDefensa() << endl;
    else
        cout << "armadura: No tiene" << endl;
    if (monster.GetArma().GetDanhoMax() != 0) {
        cout << "arma (danho max): " << monster.GetArma().GetDanhoMax() << endl;
        cout << "arma (danho min): " << monster.GetArma().GetDanhoMin() << endl;
    } else
        cout << "arma: No tiene" << endl;

    cout << endl << "tienes " << this->GetAvatar().GetVidaActual() << " de vida actual\n" << endl;

    printf("\n\n Deseas pelear con el monstruo?  ");
    gets(linea);
    int yes, no;

    while (1) {
        yes = (strcmp(linea, "yes") == 0) ? 1 : 0; //si es igual a "yes"
        no = (strcmp(linea, "no") == 0) ? 1 : 0; // si es igual a "no"

        if (yes || no) break; //Si responde correctamente sale del bucle

        printf("Tienes que escribir \"yes\" o \"no\" :  ");
        gets(linea);
    }
    if (yes) { // en caso acepte la batalla
        PelearConMonstruo(monster);
    }

}

void Juego::PelearConMonstruo(Monstruo monster) {

    int max = monster.GetArma().GetDanhoMax();
    int min = monster.GetArma().GetDanhoMin();

    int aleatorioMonster = rand() % (max - min + 1);
    int danhoM = monster.GetDanhoBase() + aleatorioMonster;

    max = avatar.GetArma().GetDanhoMax();
    min = avatar.GetArma().GetDanhoMin();

    int aleatorioAvatar = rand() % (max - min + 1);
    int danhoA = avatar.GetDanhoBase() + aleatorioAvatar;

    while ((avatar.GetVidaActual() > 0) && (monster.GetVidaActual() > 0)) {

        if (avatar.GetArmadura().GetDefensa() != 0) {
            danhoM = (int) (danhoM * (avatar.GetArmadura().GetDefensa() / 100));
        }

        int vidaActualAvatar = avatar.GetVidaActual();
        avatar.SetVidaActual(vidaActualAvatar - danhoM);

        if (monster.GetArmadura().GetDefensa() != 0) {

            danhoA = (int) (danhoA * (monster.GetArmadura().GetDefensa() / 100));
        }
        monster.SetVidaActual(monster.GetVidaActual() - danhoA);
    }
    if ((avatar.GetVidaActual() <= 0)) {
        cout << "HAS PERDIDO\n" << endl;
    } else {
        cout << "Ganaste la Batalla! Felicitaciones!\n" << endl;
    }

    cout << "tienes " << avatar.GetVidaActual() << " de vida\n" << endl;

    cout << "Aprente una tecla para continuar: ";
    while (cin.get() != '\n');

}

void Juego::meterAlSaco(){
    
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
    system("cls");
    for (int i = i_arriba; i <= i_abajo; i++) {
        //     for (int k = 0; k < 40 - (j_der - j_izq) / 2; k++)printf(" "); // Para poder centrar el esquema
        
        for (int j = j_izq; j <= j_der; j++) {
            char celda = (char) this->LaberintoActual.getCelda()[i][j].GetTipo();
            if (avatar.GetPosX() == j && avatar.GetPosY() == i) {
                rlutil::setColor(114);
                printf("%c", IMAG_AVATAR);
            } else if (celda == '-' ||   celda == '+') {
                rlutil::setColor(121); // Entra  y Sale
                printf("%c", celda);
            } else if (celda == 'M' ||
                    celda == 'A') {
                rlutil::setColor(124);
                printf("%c", celda);
            } else {
                rlutil::setColor(112); // 96 176 112
                printf("%c",celda);
            }
        }
        printf("\n");
    }
    rlutil::setColor(7); // Restablece Co
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



