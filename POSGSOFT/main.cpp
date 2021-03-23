#include <iostream>
#include "criterio.h"
#include "acta.h"
#include "director.h"
#include "jurado.h"
#include "menu.h"
#include "universidad.h"
#include "estudiante.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;




int main(){
    Universidad PUJ;
    int opc;

    cout << " _______  ___   _______  _______  _______  __   __  _______    ______   _______    _______  _______  ___      ___   _______  ___   _______  _______  _______  ___   _______  __    _ " << endl;
    cout << "|       ||   | |       ||       ||       ||  |_|  ||   _   |  |      | |       |  |       ||   _   ||   |    |   | |       ||   | |       ||   _   ||       ||   | |       ||  |  | |" << endl;
    cout << "|  _____||   | |  _____||_     _||    ___||       ||  |_|  |  |  _    ||    ___|  |       ||  |_|  ||   |    |   | |    ___||   | |       ||  |_|  ||       ||   | |   _   ||   |_| |"<< endl;
    cout << "| |_____ |   | | |_____   |   |  |   |___ |       ||       |  | | |   ||   |___   |       ||       ||   |    |   | |   |___ |   | |       ||       ||       ||   | |  | |  ||       |" << endl;
    cout << "|_____  ||   | |_____  |  |   |  |    ___||       ||       |  | |_|   ||    ___|  |      _||       ||   |___ |   | |    ___||   | |      _||       ||      _||   | |  |_|  ||  _    |" << endl;
    cout << " _____| ||   |  _____| |  |   |  |   |___ | ||_|| ||   _   |  |       ||   |___   |     |_ |   _   ||       ||   | |   |    |   | |     |_ |   _   ||     |_ |   | |       || | |   |" << endl;
    cout << "|_______||___| |_______|  |___|  |_______||_|   |_||__| |__|  |______| |_______|  |_______||__| |__||_______||___| |___|    |___| |_______||__| |__||_______||___| |_______||_|  |__|" << endl << endl;
    do{
        menu();
        cin >> opc;
        switch (opc)
        {
        case 1:
            PUJ.crearNuevaActa();
            break;
        case 2:
            PUJ.modificarActaUniversidad();
            break;
        case 3:
            PUJ.mostrarActa();
            break;
        case 4:
            PUJ.crearDirector();
            break;
        case 5:
            PUJ.mostrarTodosDirectores();
            break;
        case 6:
            PUJ.crearJurado();
            break;
        case 7:
            PUJ.mostrarJurados();
            break;
        case 8: 
            PUJ.listarActasPorEstado();
            break;
        case 9:
            PUJ.borrarActa();
            break;
        case 10:
            PUJ.listarActasPorTipoTrabajo();
            break;
        case 11:
            PUJ.listarJuradoPorLugarTrabajo();
            break;
        case 12:
            PUJ.listarActasPorJurado();
            break;
        case 13:
            PUJ.listarActasPorDirector();
            break;
        case 14:
            PUJ.listarActasPorNota();
            break;
        case 15:
            PUJ.funcionalidadSorpresa();
            break;
        case 0:
            cout << "Hasta Luego :D" << endl;
            break;
        default:
            cout << "Ponga un numero que sirva OOMMEEE  " << endl;
            break;
        }
    }while(opc != 0);
    return 0;
}