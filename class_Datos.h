#ifndef CLASS_DATOS_H_INCLUDED
#define CLASS_DATOS_H_INCLUDED

class Datos{
private:
    float alquiler,sueldoBase;
public:
    bool SetAlquiler(float a){
    if(a<=0){
        cout<<"Numero invalido."<<endl;
        system("pause");
        return false;
    }
    alquiler=a;
    return true;
}

bool SetSueldoBase(float a){
    if(a<=0){
        cout<<"Numero invalido."<<endl;
        system("pause");
        return false;
    }
    sueldoBase=a;
    return true;
}

float GetAlquiler(){return alquiler;}
float GetSueldoBase(){return sueldoBase;}

void cargar(){
cout<<"Indique suma de alquiler y servicios: ";
float a;
cin>>a;
if(!SetAlquiler(a))return;
cout<<"Indique sueldo base: ";
cin>>a;
if(!SetSueldoBase(a))return;
}

bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("Datos.dat","rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Datos), 0);
    bool leyo = fread(this, sizeof (Datos), 1, p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco(){
    FILE *p;
    p=fopen("Datos.dat","ab");
    if(p==NULL) return false;
    bool escribio = fwrite(this, sizeof (Datos), 1, p);
    fclose(p);
    return escribio;
}


bool modificarEnDisco(){
    FILE *p;
    p=fopen("Datos.dat","rb+");
    if(p==NULL) return false;
    fseek(0, sizeof(Datos), 0);
    bool escribio=fwrite(this, sizeof (Datos), 1, p);
    fclose(p);
    return escribio;
}


};

#endif // CLASS_DATOS_H_INCLUDED
