#ifndef CLASS_EMPLEADOS_H_INCLUDED
#define CLASS_EMPLEADOS_H_INCLUDED

class Empleado{
private:
    int IDEmpleado;
    char nombre[30];
    char apellido[30];
    int documento;
    int telefono;
    char email[64];
    Fecha fechaDeContratacion;
    float sueldo;
    bool estado;

public:
///SETS
    bool SetIDEmpleado(int e){IDEmpleado=e; return true;}
    bool SetNombre(const char *nom){strcpy(nombre,nom); return true;}
    bool SetApellido(const char *ap){strcpy(apellido,ap); return true;}
    bool SetDocumento(int d){documento=d; return true;}
    bool SetTelefono(int t){telefono=t; return true;}
    bool SetEmail(const char *em){strcpy(email,em); return true;}
    bool SetSueldo(float su){sueldo=su; return true;}
    bool SetEstado(bool es){estado=es; return true;}

///GETS
    int GetIDEmpleado(){return IDEmpleado;}
    char GetNombre(){return nombre[30];}
    char GetApellido(){return apellido[30];}
    int GetDocumento(){return documento;}
    int GetTelefono(){return telefono;}
    char GetEmail(){return email[64];}
    float GetSueldo(){return sueldo;}
    bool GetEstado(){return estado;}

    bool Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);

};

bool Empleado::Cargar(){
cout<<"Indique ID Empleado: "<<endl;
int IDe;
cin>>IDe;
if(!SetIDEmpleado(IDe))return false;
cout<<"Indique nombre: "<<endl;
char nom[30];
cin>>nom;
if(!SetNombre(nom))return false;
cout<<"Indique apellido: "<<endl;
cin>>nom;
if(!SetApellido(nom))return false;
cout<<"Indique documento: "<<endl;
cin>>IDe;
if(!SetDocumento(IDe))return false;
cout<<"Indique telefono: "<<endl;
cin>>IDe;
if(!SetTelefono(IDe))return false;
cout<<"Indique e-mail: "<<endl;
char ema[64];
cin>>ema;
if(!SetEmail(ema))return false;
cout<<"Indique fecha de contratacion: "<<endl;
if(!fechaDeContratacion.Cargar())return false;
cout<<"Indique sueldo: "<<endl;
cin>>IDe;
if(!SetSueldo(IDe))return false;
cout<<"Indique estado: "<<endl;
cin>>IDe;
if(!SetEstado(IDe))return false;
return true;
}

void Empleado::Mostrar(){
cout<<"El ID de Empleado es: "<<GetIDEmpleado()<<endl;
cout<<"El nombre es: "<<GetNombre()<<endl;
cout<<"El apellido es: "<<GetApellido()<<endl;
cout<<"El documento es: "<<GetDocumento()<<endl;
cout<<"El telefono es: "<<GetTelefono()<<endl;
cout<<"El e-mail es: "<<GetEmail()<<endl;
cout<<"La fecha de contratacion es: ";
fechaDeContratacion.Mostrar();
cout<<endl;
cout<<"El sueldo es: "<<GetSueldo()<<endl;
cout<<"El estado es: "<<GetEstado()<<endl;
return;
}

bool Empleado::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Empleados.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Empleado), 0);
    bool leyo = fread(this, sizeof (Empleado), 1, p);
    fclose(p);
    return leyo;
}

bool Empleado::grabarEnDisco(){
    FILE *p;
    p=fopen("Empleados.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Empleado), 1, p);
    fclose(p);
    return escribio;
}

bool Empleado::modificarEnDisco(int pos){
    FILE *p;
    p=fopen("Empleados.dat","rb+");
    if(p==NULL) return false;
    fseek(p, pos * sizeof(Empleado), 0);
    bool escribio=fwrite(this, sizeof (Empleado), 1, p);
    fclose(p);
    return escribio;
}

#endif // CLASS_EMPLEADOS_H_INCLUDED
