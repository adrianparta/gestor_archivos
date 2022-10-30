#ifndef CLASS_VENTAS_H_INCLUDED
#define CLASS_VENTAS_H_INCLUDED

class Venta{
private:
    int IDVenta;
    int IDEmpleado;
    float PrecioTotal;
    Fecha FechaDeVenta;
    bool EstadoVenta;

public:
///SETS
    bool SetIDEmpleado(int e){IDEmpleado=e; return true;}
    bool SetPrecioTotal(float p){PrecioTotal=p; return true;}
    bool SetEstadoVenta(bool ev){EstadoVenta=ev; return true;}

///GETS
    int GetIDVenta(){return IDVenta;}
    int GetIDEmpleado(){return IDEmpleado;}
    float GetPrecioTotal(){return PrecioTotal;}
    Fecha GetFechaDeVenta(){return FechaDeVenta;}
    bool GetEstadoVenta(){return EstadoVenta;}


    bool Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

};

bool Venta::Cargar(){
cout<<"Indique ID empleado: "<<endl;
int IDe;
cin>>IDe;
if(!SetIDEmpleado(IDe))return false;
cout<<"Indique precio total: "<<endl;
int pt;
cin>>pt;
cout<<"Indique fecha de la venta: "<<endl;
if(!FechaDeVenta.Cargar())return false;
if(!SetPrecioTotal(pt))return false;
cout<<"Indique estado de venta: "<<endl;
int edv;
cin>>edv;
if(!SetEstadoVenta(edv))return false;
return true;
}

void Venta::Mostrar(){
cout<<"El ID de venta es: "<<GetIDVenta()<<endl;
cout<<"El ID del empleado es: "<<GetIDEmpleado()<<endl;
cout<<"El precio total es: "<<GetPrecioTotal()<<endl;
cout<<"la fecha de venta es: ";
FechaDeVenta.Mostrar();
cout<<"El estado de la venta es: "<<GetEstadoVenta()<<endl;
return;
}

bool Venta::leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Venta), 0);
    bool leyo = fread(this, sizeof (Venta), 1, p);
    fclose(p);
    return leyo;
}

bool Venta::grabarEnDisco(){
    FILE *p;
    p=fopen("ventas.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Venta), 1, p);
    fclose(p);
    return escribio;
}

bool Venta::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Venta), 0);
    bool escribio=fwrite(this, sizeof (Venta), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLASS_VENTAS_H_INCLUDED
