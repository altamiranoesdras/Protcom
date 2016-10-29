#define __LINUX_COM__
#include "com/serial.h"
#include <stdio.h>    // Libreria estanda entrada y salida
#include <unistd.h>   // para utilizar usleep()
#include <getopt.h>   // para leer la opciones que se pasan como argumentos
#include <string.h>   // para manejar cadenas de texto
#include <stdlib.h>
#include <iostream>

using namespace std;
main() {
    int a;
    printf("_:::::::::::::MENU::::::::::::_\n");
    printf("1) ENVIAR MENSAJE \n");
    printf("2) ENVIAR ARCHIVO \n");
    printf("\n \n elija su opcion \n");
    printf("___________________________________\n");
    printf("opcion  "); cin>>a;
    switch(a){
        case 1:
            system("clear");
            printf("entro en peticion 1");
            break;
    }

    getchar();
}