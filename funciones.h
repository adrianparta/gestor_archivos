#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
void cargarCadena(char *pal, int tam);
float sueldoBaseF();
float sueldoBase;
void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

int anioActual(){
std::time_t t = std::time(nullptr);
std::tm* now = std::localtime(&t);

return now->tm_year + 1900;
}

float sueldoBaseF(){
    cout<<"Ingrese sueldo base: ";
    int i;
    cin>>i;
    if(i>0){
        cout<<"Sueldo base agregado correctamente."<<endl;
        system("pause");
        return i;
    }
    return 0;
}



#endif // FUNCIONES_H_INCLUDED
