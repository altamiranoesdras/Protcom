#define __LINUX_COM__
#include "com/serial.h"
#include "serial_ext.h"
#include <sys/msg.h>
#include <stdlib.h>
#include "msgq.h"


int main(){

    system("clear");
    cout<<"############### PROCESO EMISOR ###############\n\n";

    int idCola;
    int contador=0;
    idCola=creaCola(COLA_EMISOR);
    Msg msg;

    HANDLE port=-1;

    port=Open_Port((char *) USBTTY0);

    do{
        if(contador==0)
            cout<<"Esperando paquetes para enviar...\n\n";


        msgrcv (idCola, (struct msgbuf *)&msg,sizeof(msg), 1,0);

        cout <<"Paquete recibido: "<<msg.pkg<<" de tamano: "<< sizeof(msg.pkg)<<endl;

        if(strcmp(msg.pkg,""))
        Write_Port(port,msg.pkg,SIZE_PKG);

        contador++;
    }while(1);

}
