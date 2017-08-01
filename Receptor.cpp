#define __LINUX_COM__
#include "com/serial.h"
#include "serial_ext.h"
#include <sys/msg.h>
#include <stdlib.h>
#include "msgq.h"



int main(){

    system("clear");
    cout<<"############### PROCESO RECEPTOR ###############\n\n";

    int idCola;
    int contador=0;
    char texto[SIZE_PKG];
    int n=0;

    idCola=creaCola(COLA_EJECUTOR);

    Msg msg;

    HANDLE port=-1;

    port=Open_Port((char *) USBTTY1);

    do{
        if(contador==0)
            cout<<"Esperando paquetes para procesar...\n\n";


        //Esperar hasta que se llene el bufer
        while(Kbhit_Port(port) < SIZE_PKG);

        n=Read_Port(port,texto,SIZE_PKG);

        if(n>0){
            cout<<"Paquete recibido: "<<texto<<" de tamano: "<<n<<endl;
        }

        contador++;
    }while(1);

}