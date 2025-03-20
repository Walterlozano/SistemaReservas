
#include "Cliente.h"
#include "Reserva.h"
#include <iostream>
using namespace std;

int main()
{
    int Opcion;
    vector<Cliente> clientes;
    vector<Reserva> reservas;

    cout << R"(
     _____     _     _            _               ____                      _   
    |_   _| __(_) __| | ___ _ __ | |_ _   _ ___  |  _ \ ___  ___  ___  _ __| |_ 
      | || '__| |/ _` |/ _ \ '_ \| __| | | / __| | |_) / _ \/ __|/ _ \| '__| __|                     
      | || |  | | (_| |  __/ | | | |_| |_| \__ \ |  _ <  __/\__ \ (_) | |  | |_ 
      |_||_|  |_|\__,_|\___|_| |_|\__|\__,_|___/ |_| \_\___||___/\___/|_|   \__|

                              __- -
                               (   
                              _))_ 
                              |  |________
                     .-------"""""   |    """""------.
                    /.".\            |            /.".\
                   /.   .\           |           /.   .\
                  /.     .\          |          /.     .\
                 /.  ___ '.|__....--"T"--....__|.' ___  .\
                |   |_|_|  |   _..   |   --.   |  |_|_|  |
                |   |_|_|  |  |  |   |   |_|   |  |_|_|  |
                |__________|__|..+--"""--....__|_________| 

      )";

    do {
        cout << R"(
----------------------------------
|       MENU PRINCIPAL           |
----------------------------------
|                                |
| [1] Crear reservas             |
| [2] Crear/Actualizar clientes  |
| [3] Consultar clientes         |
| [4] Consultar reservas         |
| [5] Salir                      |
|                                |
----------------------------------
   Seleccione una opcion: 
)";
        cin >> Opcion;

        switch (Opcion) {
        case 1: {
            Reserva nuevaReserva(0, "", "", "");
            nuevaReserva.CrearReserva(reservas, clientes);
            break;
        }
        case 2: {
            Cliente nuevoCliente;
            nuevoCliente.AgregarCliente(clientes);
            break;
        }
        case 3: {
            cout << "Clientes registrados:\n";
            Cliente().mostrarClientes(clientes);
            break;
        }
        case 4: {
            cout << "Reservas registradas:\n";
            Reserva().mostrarReservas(reservas);
            break;
        }
        case 5:
            cout << "Saliendo...\n";
            break;

        default:
            cout << "Error :: Opcion Invalida\n";
        }
    } while (Opcion != 5);

    exit(0);
    return 0;
}
