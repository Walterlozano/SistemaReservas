#include "Reserva.h"
#include <iostream>
using namespace std;

Reserva::Reserva(int dia_, string Fecha_Reserva_, string Fecha_SalidaReserva_, string Cedula_Cliente_)
    : dia(dia_), Fecha_Reserva(Fecha_Reserva_), Fecha_SalidaReserva(Fecha_SalidaReserva_), Cedula_Cliente(Cedula_Cliente_), precioFinal(0) {
}

void Reserva::CrearReserva(vector<Reserva>& reservas, vector<Cliente>& clientes) {
    //nuestras variables locales.
    int dia_;
    string Fecha_Reserva_;
    string Fecha_SalidaReserva_;
    string cedula;
    int opciones;

    cout << "Ingrese su cedula: ";
    cin >> cedula;

    bool clienteEncontrado = false;
    bool vip = false;
    for (auto& cliente : clientes) {
        if (cliente.getCedula() == cedula) {
            clienteEncontrado = true;
            vip = cliente.getVip();
            break;
        }
    }

    if (!clienteEncontrado) {
        cout << "Error: Cliente no encontrado.\n";
        return;
    }

	//solicitamos la informacion de la reserva.

    cout << "¿Cuantos dias desea reservar?: ";
    cin >> dia_;

    cout << "¿Cual es la Fecha de la Reserva?: ";
    cin >> Fecha_Reserva_;

    cout << "¿Cual es la Fecha de la Salida?: ";
    cin >> Fecha_SalidaReserva_;

    cout << "Que reserva deseas hacer? (1: Doble, 2: Familiar, 3: Individual): ";
    cin >> opciones;

    switch (opciones) {
    case 1:
        precioFinal = Habitacion_doble * dia_;
        break;
    case 2:
        precioFinal = Habitacion_Familiar * dia_;
        break;
    case 3:
        precioFinal = Habitacion_individual * dia_;
        break;
    default:
        cout << "Ese tipo de reserva no existe.\n";
        return;
    }

	//si el cliente es VIP se le aplica un descuento del 10%.
    if (vip) {
        precioFinal *= 0.9; 
        cout << "Se aplico un descuento VIP del 10%.\n";
    }

    reservas.push_back(Reserva(dia_, Fecha_Reserva_, Fecha_SalidaReserva_, cedula));
    reservas.back().precioFinal = precioFinal; 

    cout << "Reserva creada exitosamente.\n";
    mostrarPrecio();
}

//mostramos el precio total de la reserva.
void Reserva::mostrarPrecio() {
    cout << "El precio total de la reserva es: " << precioFinal << "\n";
}

//imprimimos las reservas realizadas.
void Reserva::mostrarReservas(vector<Reserva>& reservas) {
    if (reservas.empty()) {
        cout << "No hay reservas registradas.\n";
        return;
    }

    for (auto& reserva : reservas) {
        cout << "-----------------------------\n";
        cout << "Cedula del cliente: " << reserva.Cedula_Cliente << endl;
        cout << "Fecha de la reserva: " << reserva.Fecha_Reserva << endl;
        cout << "Fecha de salida: " << reserva.Fecha_SalidaReserva << endl;
        cout << "Dias reservados: " << reserva.dia << endl;
        cout << "Precio final: " << reserva.precioFinal << endl;
        cout << "-----------------------------\n";
    }
}
