#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cliente {
private:
    string cedula;
    string nombre;
    string fechaRegistro;
    bool vip;

public:
    Cliente(string nombre_, string cedula_, string fechaRegistro_, bool vip_);
    string getCedula();
	//Funciones
    bool getVip();
    void AgregarCliente(vector<Cliente>& clientes);
    void mostrarClientes(vector<Cliente>& clientes);
    Cliente() = default;
};