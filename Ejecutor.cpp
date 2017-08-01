#define __LINUX_COM__
#include "com/serial.h"
#include "serial_ext.h"
#include <sys/msg.h>
#include <stdlib.h>
#include "msgq.h"

int main(){

    system("clear");
    cout<<"############### PROCESO EJECUTOR ###############\n\n";

    int idCola;
    int contador=0;
    idCola=creaCola(COLA_EJECUTOR);

    Msg msg;


    do{
        if(contador==0)
            cout<<"Esperando paquetes para procesar...\n\n";


        msgrcv (idCola, (struct msgbuf *)&msg,sizeof(msg), 1,0);

        cout <<"Paquete recibido: "<<msg.pkg<<" de tamano: "<< sizeof(msg.pkg)<<endl;

        contador++;
    }while(1);

}