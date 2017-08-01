#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "msgq.h"

using namespace std;

/**
 * Muestra el menu y cambia el valor de la variable op segun la opcion seleccionada
 * @param op
 */
void menu(int &op);
/**
 * Pregunta si desa continuar
 * @return bool
 */
bool continuar();

int main() {

    int op;
    bool continua;
    char textoEnvia[256];

    int idCola;

    idCola=creaCola(COLA_EMISOR);

    do{
        menu(op);

        switch (op){
            case 1:
                do{
                    system("clear");

                    cout<<"Ingrese el texto a enviar: ";
                    cin.getline(textoEnvia,256);

                    sendMsg(idCola,textoEnvia);

                }while(continuar());

                break;
            case 2:
                cout<<"A elegido la opcion para enviar archivos";
                break;
            case 3:
                exit(EXIT_SUCCESS);

            default:

                cout<<"Opción no valida";
                break;

        }


    }while (op!=3);

}

void menu(int &op){

    int aux;
    system("clear");
    cout<< ":::::::::::::MENU::::::::::::\n\n";
    cout<< "1) Enviar Texto \n";
    cout<< "2) Enviar Archivo \n";
    cout<< "3) Salir \n\n";
    cout<< "Elija una opción: ";
    cin>>aux;
    cin.ignore();
    op=aux;
}

bool continuar(){
    char sn[2];

    cout<<"\nDesa continuar [s/N]:";
    cin>>sn;
    cin.ignore();

    if(strcmp("s",sn)==0 || strcmp("S",sn)==0){
        return true;
    }
    else{
        return false;
    }

}
