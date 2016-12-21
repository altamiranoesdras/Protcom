#define __LINUX_COM__
#include "com/serial.h"
#include <sys/msg.h>
#include <stdlib.h>
#include "msgq.h"
#define USBTTY "/dev/ttyUSB0"

/**
 * Valida si el puerto esta abierto, de no ser así lo abre
 * @param port
 */
void abrirPuerto(const char *strPort,HANDLE &port);

int main(){

    system("clear");
    cout<<"############### PROCESO EMISOR ###############\n\n";

    int idCola;
    int contador=0;
    idCola=creaCola(COLA_EMISOR);
    Msg msg;

    do{
        if(contador==0)
            cout<<"Esperando paquetes para enviar...\n\n";


        msgrcv (idCola, (struct msgbuf *)&msg,sizeof(msg), 1,0);

        cout <<"Paquete recibido: "<<msg.pkg<<endl;


        contador++;
    }while(1);

}

void abrirPuerto(const char *strPort,HANDLE &port){

    if( port!=-1 )
        cout<<"El puerto "<< strPort <<"ya se encuentra abierto\n";
    else
        cout<<"Se abrira el puerto"<< strPort <<endl;
};