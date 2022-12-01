#ifndef CLASS_PROVEEDORES_H_INCLUDED
#define CLASS_PROVEEDORES_H_INCLUDED

class Proveedor{
private:
    int IDProveedor;
    char nombre[50];
    int diaQueViene;
    int telefono;
    char mail[64];
    int cuil;
    bool estado;

public:
    ///gets
    int GetIDProveedor(){return IDProveedor;}
    char *GetNombre(){return nombre;}
    int GetDiaQueViene(){return diaQueViene;}
    int GetTelefono(){return telefono;}
    char *GetMail(){return mail;}
    int GetCuil(){return cuil;}
    bool GetEstado(){return estado;}

    ///sets
    void SetNombre(){cargarCadena(nombre,49);}
    bool SetDiaQueViene(int d){
        if(d>0 && d<8){
            diaQueViene=d;
            return true;
        }
    cout<<"Dia invalido."<<endl;
    system("pause");
    return false;
    }
    bool SetTelefono(int t){
        if(t>0){
            telefono=t;
            return true;
        }
    cout<<"Numero invalido."<<endl;
    system("pause");
    return false;
    }
    void SetMail(){cargarCadena(mail,63);}
    bool SetCuil(int c){
        if(c>0){
            cuil=c;
            return true;
        }
    cout<<"Numero invalido."<<endl;
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

bool Proveedor::Cargar(){
IDProveedor=contadorID();
cout<<"El id del proveedor es: "<<IDProveedor<<endl;

cout<<"Indique nombre del proveedor: "<<endl;
cargarCadena(nombre,49);

cout<<"Indique dia que viene (1 para lunes, 7 para domingo):"<<endl;
int di;
cin>>di;
if(!SetDiaQueViene(di))return false;

cout<<"Indique telefono: "<<endl;
cin>>di;
if(!SetTelefono(di)){
    cout<<"Numero invalido.";
    return false;
}

cout<<"Indique mail: "<<endl;
SetMail();

cout<<"Indique cuil: "<<endl;
cin>>di;
if(!SetCuil(di)){
    cout<<"Numero invalido"<<endl;
    return false;
}

SetEstado(true);

cout<<"Proveedor agregado correctamente."<<endl;
system("pause");
return true;
}

void Proveedor::Mostrar(){
    cout<<"El ID es: "<<IDProveedor<<endl;
    cout<<"El nombre es: "<<nombre<<endl;
    cout<<"El dia que viene es: "<<diaQueViene<<endl;
    cout<<"El telefono es: "<<telefono<<endl;
    cout<<"El mail es: "<<mail<<endl;
    cout<<"El cuil es: "<<cuil<<endl;
    return;
}

bool Proveedor::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Proveedores.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Proveedor), 0);
    bool leyo = fread(this, sizeof (Proveedor), 1, p);
    fclose(p);
    return leyo;
}

bool Proveedor::grabarEnDisco(){
    FILE *p;
    p=fopen("Proveedores.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Proveedor), 1, p);
    fclose(p);
    return escribio;
}


bool Proveedor::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Proveedores.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Proveedor), 0);
    bool escribio=fwrite(this, sizeof (Proveedor), 1, p);
    fclose(p);
    return escribio;
}

int Proveedor::contadorID(){
    Proveedor obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){}
    return pos;
}
#endif // CLASS_PROVEEDORES_H_INCLUDED
