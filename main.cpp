#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
using namespace std;
#include "class_Fecha.h"
#include "class_ventas.h"
#include "class_Detalles.h"
#include "class_Empleados.h"

int main()
{
    Empleado hola;
    if(!hola.Cargar())return 0;
    hola.Mostrar();
    return 0;
}
