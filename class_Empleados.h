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
    bool SetNombre(){cargarCadena(nombre,29); return true;}
    bool SetApellido(){cargarCadena(apellido,29); return true;}
    bool SetDocumento(int d){
        if(d>0){
            documento=d;
            return true;
        }
        cout<<"Numero invalido."<<endl;
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
    bool SetEmail(){cargarCadena(email,63); return true;}
    bool SetFechaDeContratacion(){
        if(fechaDeContratacion.Cargar())return true;
        return false;
    }
    bool SetSueldo(){
            if((anioActual()-fechaDeContratacion.getAnio())==0){
                sueldo=sueldoBase;
                return true;
            }
            else{
                sueldo=sueldoBase+sueldoBase*0.1*(anioActual()-fechaDeContratacion.getAnio());
                return true;
            }
        cout<<"Numero invalido."<<endl;
        return false;
    }
    bool SetEstado(bool es){estado=es; return true;}

///GETS
    int GetIDEmpleado(){return IDEmpleado;}
    char *GetNombre(){return nombre;}
    char *GetApellido(){return apellido;}
    int GetDocumento(){return documento;}
    int GetTelefono(){return telefono;}
    char *GetEmail(){return email;}
    Fecha GetFechaDeContratacion(){return fechaDeContratacion;}
    float GetSueldo(){return sueldo;}
    bool GetEstado(){return estado;}

    bool Cargar();
    void Mostrar();
    bool leerDeDisco(int pos);
    bool grabarEnDisco();
    bool modificarEnDisco(int pos);
    int contadorID();
};

bool Empleado::Cargar(){
IDEmpleado=contadorID();
cout<<"Indique nombre: "<<endl;
if(!SetNombre())return false;
cout<<"Indique apellido: "<<endl;
if(!SetApellido())return false;
cout<<"Indique documento: "<<endl;
int IDe;
cin>>IDe;
if(!SetDocumento(IDe))return false;
cout<<"Indique telefono: "<<endl;
cin>>IDe;
if(!SetTelefono(IDe))return false;

cout<<"Indique e-mail: "<<endl;
if(!SetEmail())return false;
cout<<"Indique fecha de contratacion: "<<endl;
if(!fechaDeContratacion.Cargar())return false;
SetSueldo();
SetEstado(true);
cout<<"Empleado agregado correctamente"<<endl;
system("pause");
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
cout<<"El sueldo es: "<<GetSueldo()<<endl;
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

int Empleado::contadorID(){
    Empleado obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){}
    return pos;
}

#endif // CLASS_EMPLEADOS_H_INCLUDED
