#include <cstdio>
#include <cstring>

void historiaDelJuego() {

}

int opciones_contiene_palabra_mover(char opcion[], const char*pal) {
    for (int i = 0; opcion[i]; i++) {
        if (opcion[i] == ' ') opcion[i] = 0;
    }
    return strcmp(opcion, pal);
}

void mostrarOpcionesGenerales(char &c1, char &c2) {
    // c1 indicara si es m,i,u,s (mover, interactuar , usar , salir))
    // c2 indicar el parametro demas 
    //      en mover c2 seria(u,d,l,r) 
    //      en interactur falta definir 
    //      en usar C2 seria i el numero de iten a usar pero en caracter
    //      en salir C2 seria 0 ; 
    char opcion[10];
    printf("--Opciones\n");
    printf("- mover x\n");
    printf("                 Arriba:     \"mover u\"\n");
    printf("                 Abajo:      \"mover d\"\n");
    printf("                 Izquierda:  \"mover l\"\n");
    printf("                 Derecha:    \"mover r\"\n");
    printf("- interactuar\n");
    printf("- usar i\n");
    printf("- salir\n\n");
    printf("- Escriba una accion         :");
    gets(opcion);
    c2 = opcion[strlen(opcion) - 1];
    if (opciones_contiene_palabra_mover(opcion, "mover") == 0) {
        c1 = 'm';
    } else if (strcmp(opcion, "interactuar") == 0) {
        c1 = 'i';
    } else if (strcmp(opcion, "usar") == 0) {
        c1 = 'u';
    } else if (strcmp(opcion, "salir") == 0) {
        c1 = 's';
    } else
        printf("- Escriba una opcion correcta !!!\n\n");
}