#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Cliente.h"

Cliente::Cliente(string nombre_, string cedula_, string fechaRegistro_, bool vip_)
    : nombre(nombre_), cedula(cedula_), fechaRegistro(fechaRegistro_), vip(vip_) {
}

string Cliente::getCedula() {
    return cedula;
}

bool Cliente::getVip() {
    return vip;
}

//Solicitamos la informacion de nuestro cliente , la cual se almacena en un vector de clientes .
void Cliente::AgregarCliente(vector<Cliente>& clientes) {
    string nombre_, cedula_, fechaRegistro_;
    bool vip_;
    int MostrarVip;

    cout << "Ingrese su numero de cedula : \n";
    cin >> cedula_;

    for (auto& cliente : clientes) {
        if (cliente.cedula == cedula_) {
            cout << "Error::cedula ya registrada.\n";
            return;
        }
    }

    cin.ignore();
    cout << "Ingrese su nombre: \n";
    getline(cin, nombre_);

    cout << "Ingrese su fecha Registro: (DD/MM/AA)\n";
    cin >> fechaRegistro_;

    cout << "Eres cliente VIP (1 para si/2 para No): ";
    cin >> MostrarVip;

    if (MostrarVip == 1) {
        vip_ = true;
        cout << "Eres Cliente VIP\n";
    }
    else if (MostrarVip == 2) {
        vip_ = false;
        cout << "No eres Cliente VIP\n";
    }
    else {
        cout << "Error :: Digito invalido\n";
        return;
    }

    clientes.push_back(Cliente(nombre_, cedula_, fechaRegistro_, vip_));

    cout << "Cliente Agregado de Forma Exitosa\n";

    cout << "Clientes en la lista actualmente: " << clientes.size() << endl;
}

//Mostramos la informacion de nuestros clientes.
void Cliente::mostrarClientes(vector<Cliente>& clientes) {
    for (const auto& cliente : clientes) {
        cout << "-----------------------------\n";
        cout << "Cedula : " << cliente.cedula << endl;
        cout << "Nombre : " << cliente.nombre << endl;
        cout << "Fecha (DD/MM/AA): " << cliente.fechaRegistro << endl;

        if (cliente.vip) {
            cout << R"(
            -----------------
            CLIENTE VIP
            -----------------
            )";
        }
        else {
            cout << R"(
            -----------------
            CLIENTE NO VIP
            -----------------
            )";
        }
    }
}
