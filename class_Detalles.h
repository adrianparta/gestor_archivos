#ifndef CLASS_DETALLES_H_INCLUDED
#define CLASS_DETALLES_H_INCLUDED

bool existeProducto(int id);

class Detalle{
private:
    int IDDetalle;
    int IDVenta;
    int IDProducto;
    int cant;
    bool estado;


public:
///SETS
    bool SetIDVenta(int v){
        IDVenta=v;
        return true;
    }
    bool SetIDProducto(int p){
        if(existeProducto(p)){
            IDProducto=p;
            return true;
        }
        cout<<"No existe el producto."<<endl;
        system("pause");
        return false;
    }
    bool SetCant(int c){
        if(c<=0){
            cout<<"Numero invalido."<<endl;
            system("pause");
            return false;
        }
        Producto obj;
        int pos=0;
        while(obj.leerDeDisco(pos++)){
            if(IDProducto==obj.GetIDProducto() && obj.GetStock()>=c){
                cant=c;
                actualizarStock();
                return true;
            }
        }
        cout<<"No hay stock suficiente."<<endl;
        system("pause");
        return false;
    }

    bool SetEstado(bool e){
        estado=e;
        if(e==false){
            Producto obj;
            int pos=0;
            while(obj.leerDeDisco(pos)){
                obj.SetStock(obj.GetStock()+cant);
                obj.modificarEnDisco(pos);
                pos++;
            }
        }
        return true;
        }

///GETS
    int GetIDDetalle(){return IDDetalle;}
    int GetIDVenta(){return IDVenta;}
    int GetIDProducto(){return IDProducto;}
    int GetCant(){return cant;}
    bool GetEstado(){return estado;}



    bool Cargar(int id);
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
    int contadorID();
    void actualizarStock();
};

bool Detalle::Cargar(int id){
IDDetalle=contadorID();
cout<<"El ID del detalle es: "<<IDDetalle<<endl;
SetIDVenta(id);
cout<<"Indique ID Producto: "<<endl;
int IDe;
cin>>IDe;
if(!SetIDProducto(IDe))return false;
cout<<"Indique Cantidad: "<<endl;
cin>>IDe;
if(!SetCant(IDe))return false;

estado=true;

return true;
}

void Detalle::Mostrar(){
cout<<"El ID de Detalle es: "<<IDDetalle<<endl;
cout<<"El ID del producto es: "<<IDProducto<<endl;
cout<<"La cantidad es: "<<cant<<endl;
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

int Detalle::contadorID()
{
    Detalle obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){}
    return pos;
}

bool existeProducto(int id){
Producto obj;
FILE *p;
p=fopen("Productos.dat","rb");
    if(p==NULL){
        cout<<"el archivo no pudo abrirse"<<endl;
        system("pause");
        fclose(p);
        return false;
    }
while(fread(&obj,sizeof obj,1,p)){
    if(id==obj.GetIDProducto() && obj.GetEstado()){
        fclose(p);
        return true;
    }
}
fclose(p);
return false;
}

void Detalle::actualizarStock(){
Producto obj;
int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.GetIDProducto()==IDProducto){
            obj.SetStock(obj.GetStock()-cant);
            obj.modificarEnDisco(pos);
        }
        pos++;
    }
}

#endif // CLASS_DETALLES_H_INCLUDED
