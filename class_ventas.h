#ifndef CLASS_VENTAS_H_INCLUDED
#define CLASS_VENTAS_H_INCLUDED

bool existeEmpleado(int id);

class Venta{
private:
    int IDVenta;
    int IDEmpleado;
    float PrecioTotal;
    Fecha FechaDeVenta;
    bool EstadoVenta;

public:
///SETS
    bool SetIDEmpleado(int e){
        if(existeEmpleado(e)){
            IDEmpleado=e;
            return true;
        }
        return false;
    }
    bool SetPrecioTotal(){PrecioTotal=sumaDetalles(); return true;}
    bool SetEstadoVenta(bool ev){
        EstadoVenta=ev;
        if(!ev){
            Detalle reg;
            int pos=0;
            while(reg.leerDeDisco(pos)){
                if(reg.GetIDVenta()==IDVenta && reg.GetEstado()){
                    reg.SetEstado(false);
                    reg.modificarEnDisco(pos);
                }
                pos++;
            }
        }
        return true;
    }

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
    int contadorID();
    float sumaDetalles();
};

bool Venta::Cargar(){

    IDVenta=contadorID();
    cout<<"El ID de la venta es: "<<IDVenta<<endl;

    cout<<"Indique ID empleado: "<<endl;
    int IDe;
    cin>>IDe;
    if(!SetIDEmpleado(IDe))return false;

    cout<<"Indique fecha de la venta: "<<endl;
    if(!FechaDeVenta.Cargar())return false;

    Detalle obj;
    if(obj.Cargar(IDVenta)){
        obj.grabarEnDisco();
        bool algoMas;
        cout<<"Algo mas?: ";
        cin>>algoMas;
        while(algoMas){
            if(obj.Cargar(IDVenta)){
                obj.grabarEnDisco();
                cout<<"Algo mas?: ";
                cin>>algoMas;
            }
            else{algoMas=false;}
        }
        SetPrecioTotal();
        EstadoVenta=true;
        return true;
    }
    return false;
}

void Venta::Mostrar(){
cout<<"El ID de venta es: "<<IDVenta<<endl;
cout<<"El ID del empleado es: "<<IDEmpleado<<endl;
cout<<"El precio total es: "<<PrecioTotal<<endl;
cout<<"la fecha de venta es: ";
FechaDeVenta.Mostrar();
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

int Venta::contadorID(){
    Venta obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){}
    return pos;
}

bool existeEmpleado(int id){
Empleado obj;
FILE *p;
p=fopen("Empleados.dat","rb");
if(p==NULL){
    cout<<"el archivo no pudo abrirse"<<endl;
    system("pause");
    fclose(p);
    return false;
}
while(fread(&obj,sizeof obj,1,p)){
    if(id==obj.GetIDEmpleado() && obj.GetEstado()){
        fclose(p);
        return true;
    }
}
fclose(p);
return false;
}

float Venta::sumaDetalles(){
    Detalle obj;
    Producto reg;
    int pos=0;
    float suma=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.GetIDVenta()==IDVenta){
            int posAux=0;
            while(reg.leerDeDisco(posAux++)){
                if(reg.GetIDProducto()==obj.GetIDProducto() && reg.GetEstado()){
                    suma+=obj.GetCant()*reg.GetPrecioVenta();
                }
            }
        }
    }
    return suma;
}

#endif // CLASS_VENTAS_H_INCLUDED
