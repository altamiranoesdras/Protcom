#include <sys/msg.h>
#include <iostream>

#ifndef PROTCOM_PAQUETE_H
#define PROTCOM_PAQUETE_H
#define SIZE_PKG 1024 //size of package
#define COLA_EJECUTOR 11
#define COLA_EMISOR 33

using namespace std;

typedef struct p{
    long id;
    char pkg[SIZE_PKG];
} Msg;

int creaCola(int proj_id){

    key_t Clave1;
    int Id_Cola_Mensajes;

    //obtiene clave  para la cola
    Clave1 = ftok ("/bin/ls",proj_id);
    if (Clave1 == (key_t)-1){
        cout<<"Error al obtener clave para cola mensajes";
        exit(EXIT_FAILURE);
    } else{
        // creamos la cola de mensajes
        Id_Cola_Mensajes = msgget (Clave1, 0600 | IPC_CREAT);
        if (Id_Cola_Mensajes == -1){
            cout<<"Error al obtener identificador para cola mensajes";
            exit (EXIT_FAILURE);
        }else{
            cout<<"Cola de mensajes creada correctamente!!\n\n";
        }
    }

    return Id_Cola_Mensajes;
}

void sendMsg(int idCola,char pkg[SIZE_PKG]){
    Msg msg;

    msg.id=1;
    strcpy(msg.pkg,pkg);

    msgsnd (idCola, (struct msgbuf *)&msg, sizeof(msg), IPC_NOWAIT);
}

/**
 * Salir de la ejecucion mediante un mensaje
 * @param msg
 */
void error(char* msg){
    cout<<msg<<endl;
    exit(EXIT_FAILURE);
}

#endif //PROTCOM_PAQUETE_H
