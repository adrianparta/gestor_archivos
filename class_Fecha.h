#ifndef CLASS_FECHA_H_INCLUDED
#define CLASS_FECHA_H_INCLUDED
bool fechavalida(int dia, int mes, int anio);

class Fecha
{
    private:
        int dia, mes, anio;
    public:
        bool Cargar();
        void Mostrar();
        //sets
        void setDia(int d){
            dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        //gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

bool Fecha::Cargar()
{
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    if(!fechavalida(dia, mes, anio)){
        cout<<"fecha invalida"<<endl;
        system("pause");
        return false;
    }
    return true;
}

void Fecha::Mostrar()
{
    cout<<"FECHA: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

bool fechavalida(int dia, int mes, int anio){
    if(dia<1 || dia>31) return false;
    else if (mes<1 || mes>12) return false;
    else switch(mes)
    {
        case 4: case 6: case 9: case 11:
            if(dia>30) return false;
            break;
        case 2:
            if (dia>28)return false;
            break;
    }

    time_t tiempo;
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

int fecha[3];
fecha[0]=tmPtr->tm_mday;
fecha[1]=tmPtr->tm_mon+1;
fecha[2]=1900+tmPtr->tm_year;

    if (anio>fecha[2])return false;
    if(anio<fecha[2])return true;
    if(anio==fecha[2]){
        if(mes>fecha[1])return false;
        if (mes<fecha[1])return true;
        if (mes==fecha[1]){
            if(dia>fecha[0]){
                return false;}
            return true;
        }
    }
    return false;
}

#endif // CLASS_FECHA_H_INCLUDED
