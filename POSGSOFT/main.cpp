#include <iostream>
#include "criterios.h"
#include "acta.h"
#include "director.h"
#include "folderActas.h"
#include "jurado.h"
#include "menu.h"
#include "universidad.h"

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

            break;
        
        default:
            break;
        }
    }while(opc != 0);
    return 0;
}