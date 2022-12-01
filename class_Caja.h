#ifndef CLASS_CAJA_H_INCLUDED
#define CLASS_CAJA_H_INCLUDED

int cantEmpleados();

class Caja{
private:
    Fecha fecha;
    float egresos;
    bool estado;
    float ganancia;
    float alquiler;
public:
    ///gets
    float GetEgresos(){return egresos;}
    float GetGanancia(){return ganancia;}
    Fecha GetFecha(){return fecha;}
    bool GetEstado(){return estado;}
    ///sets
    bool SetEgresos(float eg){
        if(eg<0){
            cout<<"Numero invalido"<<endl;
            system("pause");
        }
        Empleado obj;
        int pos=0;
        float sueldos=0;
        while(obj.leerDeDisco(pos) && obj.GetEstado()){
            sueldos+=obj.GetSueldo();
            pos++;
        }
        egresos=eg+sueldos+alquiler;
        return true;
    }

    void SetAlquiler(){
        Datos obj;
        obj.leerDeDisco(0);
        alquiler=obj.GetAlquiler();
    }
    void SetFecha(Fecha f){fecha=f;}
    void SetEstado(bool e){
        estado=e;
        if(!e){
            Venta obj;
            int pos=0;
            while(obj.leerDeDisco(pos)){
                if(fecha.getAnio()==obj.GetFechaDeVenta().getAnio() && fecha.getMes()==obj.GetFechaDeVenta().getMes() && fecha.getDia()==obj.GetFechaDeVenta().getDia() && obj.GetEstadoVenta())
                obj.SetEstadoVenta(false);
                obj.modificarEnDisco(pos);
                pos++;
            }
        }
    }
    void SetGanancia(){ganancia=calcularGanancia()-egresos;}

    bool Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
    float calcularGanancia();
    float totalVentas();
};

bool Caja::Cargar(){

cout<<"Indique egresos: "<<endl;
float d;
cin>>d;
if(!SetEgresos(d))return false;

SetGanancia();

SetEstado(true);
return true;
}

void Caja::Mostrar(){
    cout<<"La fecha es: ";
    fecha.Mostrar();
    cout<<endl;
    cout<<"El total de egresos son: "<<GetEgresos()<<endl;
    cout<<"La ganancia del dia es: "<<GetGanancia()<<endl;
    cout<<"El total de ventas es: "<<totalVentas()<<endl;
    return;
}

bool Caja::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Cajas.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Caja), 0);
    bool leyo = fread(this, sizeof (Caja), 1, p);
    fclose(p);
    return leyo;
}

bool Caja::grabarEnDisco(){
    FILE *p;
    p=fopen("Cajas.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Caja), 1, p);
    fclose(p);
    return escribio;
}

bool Caja::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Cajas.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Caja), 0);
    bool escribio=fwrite(this, sizeof (Caja), 1, p);
    fclose(p);
    return escribio;
}

int cantEmpleados(){
Empleado obj;
int pos=0;
while(obj.leerDeDisco(pos))pos++;
return pos;
}

float Caja::calcularGanancia(){
Detalle d;
Producto p;
Venta v;
int pos=0;
ganancia=0;

while(v.leerDeDisco(pos++)){
    if(v.GetFechaDeVenta().getDia()==fecha.getDia() && v.GetFechaDeVenta().getMes()==fecha.getMes() && v.GetFechaDeVenta().getAnio()==fecha.getAnio() && v.GetEstadoVenta()){
        int posAux=0;
        while(d.leerDeDisco(posAux++)){
            if(v.GetIDVenta()==d.GetIDVenta() && d.GetEstado()){
                int posAuxAux=0;
                while(p.leerDeDisco(posAuxAux++)){
                    if(p.GetIDProducto()==d.GetIDProducto()){
                        ganancia+=d.GetCant()*(p.GetPrecioVenta()-p.GetPrecioCompra());
                    }
                }
            }
        }
    }
}
return ganancia;
}

float Caja::totalVentas(){
    Venta obj;
    float suma=0;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(fecha.getAnio()==obj.GetFechaDeVenta().getAnio() && fecha.getMes()==obj.GetFechaDeVenta().getMes() && fecha.getDia()==obj.GetFechaDeVenta().getDia() && obj.GetEstadoVenta()){
            suma+=obj.GetPrecioTotal();
        }
    }
    return suma;
}

#endif // CLASS_CAJA_H_INCLUDED
