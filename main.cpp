#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
using namespace std;
#include "class_Datos.h"
#include "funciones.h"
#include "class_Fecha.h"
#include "class_Empleados.h"
#include "class_Proveedores.h"
#include "class_Productos.h"
#include "class_Detalles.h"
#include "class_ventas.h"
#include "class_Caja.h"
#include "menuProductos.h"

int main(){

    Datos obj;
    int a=0;
    while(obj.leerDeDisco(a)){
        a=1;
    }
    if(!a){
        obj.cargar();
        obj.grabarEnDisco();
    }

    int opcion;
    while(true)
    {
        system("cls");
        cout<<"----MENU PRINCIPAL----"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- MENU Productos"<<endl;
        cout<<"2- MENU Proveedores"<<endl;
        cout<<"3- MENU Empleados"<<endl;
        cout<<"4- MENU Ventas"<<endl;
        cout<<"5- MENU Cajas"<<endl;
        cout<<"6- REPORTES"<<endl;
        cout<<"0 -SALIR"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: menuProductos();
                break;
            case 2: menuProveedores();
                break;
            case 3: menuEmpleados();
                break;
            case 4: menuVentas();
                break;
            case 5: menuCajas();
                break;
            case 6: menuReportes();
                break;
            case 0:
                return 0;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
    return 0;
}
