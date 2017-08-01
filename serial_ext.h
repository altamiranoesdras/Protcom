//
// Created by root on 6/01/17.
//
#include <iostream>
#ifndef PROTCOM_SERIAL_EXT_H
#define PROTCOM_SERIAL_EXT_H
#define USBTTY0 "/dev/ttyUSB0"
#define USBTTY1 "/dev/ttyUSB1"
#define USBTTY2 "/dev/ttyUSB2"

using namespace std;

/**
 * Valida si el puerto esta abierto, de no ser así lo abre
 * @param port
 */
void abrirPuerto(char *strPort,HANDLE &port){

    if( port!=-1 )
        cout<<"El puerto "<< strPort <<"ya se encuentra abierto\n";
    else
        cout<<"Se abrira el puerto"<< strPort <<endl;
        port=Open_Port(strPort);
};
#endif //PROTCOM_SERIAL_EXT_H
