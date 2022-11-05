#ifndef CLASS_DETALLES_H_INCLUDED
#define CLASS_DETALLES_H_INCLUDED

class Detalle{
private:
    int IDDetalle;
    int IDVenta;
    int IDProducto;
    int Cant;

public:
///SETS
    bool SetIDDetalle(int d){IDDetalle=d; return true;}
    bool SetIDVenta(int v){IDVenta=v; return true;}
    bool SetIDProducto(int p){IDProducto=p; return true;}
    bool SetCant(int c){Cant=c; return true;}
///GETS
    int GetIDDetalle(){return IDDetalle;}
    int GetIDVenta(){return IDVenta;}
    int GetIDProducto(){return IDProducto;}
    int GetCant(){return Cant;}



    bool Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

};

bool Detalle::Cargar(){
cout<<"Indique ID Detalle: "<<endl;
int IDe;
cin>>IDe;
if(!SetIDDetalle(IDe))return false;
cout<<"Indique ID Venta: "<<endl;
cin>>IDe;
if(!SetIDVenta(IDe))return false;
cout<<"Indique ID Producto: "<<endl;
cin>>IDe;
if(!SetIDProducto(IDe))return false;
cout<<"Indique Cantidad: "<<endl;
cin>>IDe;
if(!SetCant(IDe))return false;
return true;
}

void Detalle::Mostrar(){
cout<<"El ID de Detalle es: "<<GetIDDetalle()<<endl;
cout<<"El ID de la Venta es: "<<GetIDVenta()<<endl;
cout<<"El ID del producto es: "<<GetIDProducto()<<endl;
cout<<"La cantidad es: "<<GetCant()<<endl;
return;
}

bool Detalle::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Detalles.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Detalle), 0);
    bool leyo = fread(this, sizeof (Detalle), 1, p);
    fclose(p);
    return leyo;
}

bool Detalle::grabarEnDisco(){
    FILE *p;
    p=fopen("Detalles.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Detalle), 1, p);
    fclose(p);
    return escribio;
}

bool Detalle::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Detalles.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Detalle), 0);
    bool escribio=fwrite(this, sizeof (Detalle), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLASS_DETALLES_H_INCLUDED
