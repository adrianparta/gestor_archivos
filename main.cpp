#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
using namespace std;
#include "class_Fecha.h"
#include "class_ventas.h"

int main()
{
    Venta hola;
    if(!hola.Cargar())return 0;
    hola.Mostrar();
    return 0;
}
