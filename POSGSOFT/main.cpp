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