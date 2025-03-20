#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Cliente.h"
using namespace std;

class Reserva
{
private:
	//precios de las habitaciones.
    int Habitacion_doble = 200000;
    int Habitacion_Familiar = 350000;
    int Habitacion_individual = 130000;
    int dia;
    string Fecha_Reserva;
    string Fecha_SalidaReserva;
    string Cedula_Cliente;
    Cliente cliente;
    int precioFinal;

public:
    Reserva() = default;
    Reserva(int dia_, string Fecha_Reserva_, string Fecha_SalidaReserva_, string Cedula_Cliente_);
    
	//Funciones
    void CrearReserva(vector<Reserva>& reservas, vector<Cliente>& clientes);
    void mostrarPrecio();
    void mostrarReservas(vector<Reserva>& reservas); 
};
