#ifndef CLASS_PRODUCTOS_H_INCLUDED
#define CLASS_PRODUCTOS_H_INCLUDED

bool existeProveedor(int id);

class Producto{
private:
    int IDProducto;
    int IDProveedor;
    int stock;
    char nombre[50];
    float precioVenta;
    float precioCompra;
    bool estado;

public:
    ///gets
    int GetIDProducto(){return IDProducto;}
    int GetIDProveedor(){return IDProveedor;}
    int GetStock(){return stock;}
    char *GetNombre(){return nombre;}
    float GetPrecioVenta(){return precioVenta;}
    float GetPrecioCompra(){return precioCompra;}
    bool GetEstado(){return estado;}

    ///sets
    bool SetIDProveedor(int idpv){
        if(existeProveedor(idpv)){
            IDProveedor=idpv;
            return true;
        }
    return false;
    }
    bool SetStock(int s){
        if(s>=0){
            stock=s;
            return true;
        }
    return false;
    }
    void SetNombre(){cargarCadena(nombre,49);}
    bool SetPrecioCompra(float pc){
        if(pc>0){
            precioCompra=pc;
            return true;
        }
        cout<<"El precio de compra no puede ser menor o igual a 0"<<endl;
        system("pause");
        return false;
    }
    bool SetPrecioVenta(float pv){
        if(pv>precioCompra){
            precioVenta=pv;
            return true;
        }
        cout<<"El precio de venta no puede ser menor o igual al precio de compra"<<endl;
        system("pause");
        return false;
    }
    void SetEstado(bool e){estado=e;}

    bool Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
    int contadorID();
};

bool Producto::Cargar(){
IDProducto=contadorID();
cout<<"El ID del Producto es: "<<IDProducto<<endl;

int IDp;

cout<<"Indique nombre del producto: "<<endl;
SetNombre();

cout<<"Indique ID del proveedor: "<<endl;
cin>>IDp;
if(!SetIDProveedor(IDp)){
    cout<<"El proveedor no existe."<<endl;
    system("pause");
    return false;
}

cout<<"Indique cantidad de stock: "<<endl;
int s;
cin>>s;
if(!SetStock(s)){
    cout<<"No se puede tener stock negativo."<<endl;
    return false;
}

cout<<"Indique precio de compra"<<endl;
float p;
cin>>p;
if(!SetPrecioCompra(p))return false;

cout<<"Indique precio de venta"<<endl;
cin>>p;
if(!SetPrecioVenta(p))return false;

SetEstado(true);
cout<<"Producto cargado correctamente."<<endl;
system("pause");
return true;
}

void Producto::Mostrar(){
    cout<<"ID: "<<IDProducto<<endl;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"ID proveedor: "<<IDProveedor<<endl;
    cout<<"Stock: "<<stock<<endl;
    cout<<"Precio compra: "<<precioCompra<<endl;
    cout<<"Precio venta: "<<precioVenta<<endl;
    return;
}

bool Producto::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Productos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Producto), 0);
    bool leyo = fread(this, sizeof (Producto), 1, p);
    fclose(p);
    return leyo;
}

bool Producto::grabarEnDisco(){
    FILE *p;
    p=fopen("Productos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Producto), 1, p);
    fclose(p);
    return escribio;
}

bool Producto::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Productos.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Producto), 0);
    bool escribio=fwrite(this, sizeof (Producto), 1, p);
    fclose(p);
    return escribio;
}

int Producto::contadorID(){
    Producto obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){}
    return pos;
}

bool existeProveedor(int id){
Proveedor obj;
FILE *p;
p=fopen("Proveedores.dat","rb");
if(p==NULL){
    cout<<"el archivo no pudo abrirse"<<endl;
    system("pause");
    fclose(p);
    return false;
}
while(fread(&obj,sizeof obj,1,p)){
    if(id==obj.GetIDProveedor() && obj.GetEstado()){
        fclose(p);
        return true;
    }
}
fclose(p);
return false;
}
#endif // CLASS_PRODUCTOS_H_INCLUDED
