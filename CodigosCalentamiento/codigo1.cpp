#include <iostream>
#include <conio.h>
using namespace std;

int productoIva( float vP ){
    float IVA = 1.19, resultado = 0;
    resultado = IVA * vP;
    return resultado;
}

int main(){
    string nombreProducto;
    float valorProducto = 0, total;
    cout<<"Valor del producto: ";cin>>valorProducto;
    total = productoIva( valorProducto );
    cout<<"El valor del producto es de "<<total;
    getch();
    return 0;
}