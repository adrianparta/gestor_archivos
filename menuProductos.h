#ifndef MENUPRODUCTOS_H_INCLUDED
#define MENUPRODUCTOS_H_INCLUDED

///PRODUCTOS

void agregarProductos();
void buscarXIDProductos();
void listarProductos();
void actualizarPrecioProductos();
void modificarProveedorProductos();
void eliminarProductos();

void menuProductos(){
int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU PRODUCTOS****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR PRODUCTO"<<endl;
        cout<<"2- BUSCAR PRODUCTO POR ID"<<endl;
        cout<<"3- LISTAR TODOS LOS PRODUCTOS"<<endl;
        cout<<"4- ACTUALIZAR PRECIO"<<endl;
        cout<<"5- MODIFICAR PROVEEDOR"<<endl;
        cout<<"6- ELIMINAR PRODUCTO"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: agregarProductos();
                break;
            case 2: buscarXIDProductos();
                break;
            case 3: listarProductos();
                break;
            case 4: actualizarPrecioProductos();
                break;
            case 5: modificarProveedorProductos();
                break;
            case 6: eliminarProductos();
                break;
            case 0:
                return;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
}


void agregarProductos(){
Producto obj;
if(obj.Cargar())obj.grabarEnDisco();
}

void buscarXIDProductos(){
    Producto obj;
    int pos;
    FILE *p;
    p=fopen("Productos.dat","rb");
    if(p==NULL) return;
    cout<<"INGRESE ID: ";
    cin>>pos;
    while(fread(&obj,sizeof obj, 1, p)){
        if(pos==obj.GetIDProducto() && obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
            system("pause");
            fclose(p);
            return;
        }
    }
cout<<"No existe ese ID."<<endl;
system("pause");
fclose(p);
return;
}

void listarProductos(){
    Producto obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void actualizarPrecioProductos(){
    Producto obj;
    int pos=0;
    cout<<"Ingrese ID: ";
    int id;
    cin>>id;
    float p;
    while(obj.leerDeDisco(pos)){
        if(obj.GetIDProducto()==id && obj.GetEstado()){
            cout<<obj.GetNombre()<<endl;
            cout<<"El precio de compra es: "<<obj.GetPrecioCompra()<<endl;
            cout<<"El precio de venta es: "<<obj.GetPrecioVenta()<<endl;
            cout<<"Ingrese nuevo precio de compra: ";
            cin>>p;
            if(!obj.SetPrecioCompra(p)){
                system("pause");
                return;
            }
            cout<<"Ingrese nuevo precio de venta: ";
            cin>>p;
            if(!obj.SetPrecioVenta(p)){
                system("pause");
                return;
            }
            if(obj.modificarEnDisco(pos))cout<<"Se actualizaron los precios correctamente"<<endl;
            system("pause");
            return;
        }
        pos++;
    }
    cout<<"No existe el producto"<<endl;
    system("pause");
}

void modificarProveedorProductos(){
    Producto reg;
    Proveedor obj;
    int pos=0, id;
    cout<<"Ingrese ID del producto: "<<endl;
    cin>>id;
    while(reg.leerDeDisco(pos++)){
        int posAux=0;
        if(reg.GetIDProducto()==id && reg.GetEstado()){
            while(obj.leerDeDisco(posAux++)){
                if(reg.GetIDProveedor()==obj.GetIDProveedor()){
                    cout<<reg.GetNombre()<<endl;
                    cout<<"El proveedor de este producto es: "<<obj.GetNombre()<<endl<<"Su ID es: "<<obj.GetIDProveedor()<<endl;
                    cout<<"Ingrese ID del nuevo proveedor: ";
                    cin>>id;
                    if(existeProveedor(id)){
                        reg.SetIDProveedor(id);
                        reg.modificarEnDisco(pos-1);
                        cout<<"Proovedor modificado correctamente."<<endl;
                        system("pause");
                        return;
                    }
                    cout<<"No existe el proveedor."<<endl;
                    system("pause");
                    return;
                }
            }
        }
    }
    cout<<"No existe ese producto"<<endl;
    system("pause");
}

void eliminarProductos(){
    Producto obj;
    int pos=0, id;
    cout<<"Indique el ID del producto que desea eliminar: ";
    cin>>id;
    while(obj.leerDeDisco(pos++)){
        if(id==obj.GetIDProducto() && obj.GetEstado()){
            obj.SetEstado(false);
            obj.modificarEnDisco(pos-1);
            cout<<"Producto eliminado correctamente."<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No existe ese producto."<<endl;
}

///Proveedores

void agregarProveedores();
void buscarXIDProveedores();
void listarProveedores();
void modificarDatosProveedores();
void eliminarProveedores();

void menuProveedores(){
int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU PROOVEDORES****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR PROVEEDOR"<<endl;
        cout<<"2- BUSCAR PROOVEDOR POR ID"<<endl;
        cout<<"3- LISTAR TODOS LOS PROOVEDORES"<<endl;
        cout<<"4- MODIFICAR DATOS"<<endl;
        cout<<"5- ELIMINAR PROOVEDOR"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: agregarProveedores();
                break;
            case 2: buscarXIDProveedores();
                break;
            case 3: listarProveedores();
                break;
            case 4: modificarDatosProveedores();
                break;
            case 5: eliminarProveedores();
                break;
            case 0:
                return;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
}

void agregarProveedores(){
Proveedor obj;
if(obj.Cargar())obj.grabarEnDisco();
}

void buscarXIDProveedores(){
    Proveedor obj;
    int pos;
    FILE *p;
    p=fopen("Proveedores.dat","rb");
    if(p==NULL) return;
    cout<<"INGRESE ID: ";
    cin>>pos;
    while(fread(&obj,sizeof obj, 1, p)){
        if(pos==obj.GetIDProveedor() && obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
            system("pause");
            fclose(p);
            return;
        }
    }
cout<<"No existe ese ID."<<endl;
system("pause");
fclose(p);
return;
}

void listarProveedores(){
    Proveedor obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void modificarDatosProveedores(){
    Proveedor obj;
    int pos=0, id;
    cout<<"Ingrese ID del proveedor: "<<endl;
    cin>>id;
    while(obj.leerDeDisco(pos)){
        if(obj.GetIDProveedor()==id && obj.GetEstado()){
            cout<<"Nombre: "<<obj.GetNombre()<<endl;
            cout<<"Dia: "<<obj.GetDiaQueViene()<<endl;
            cout<<"Telefono: "<<obj.GetTelefono()<<endl;
            cout<<"Mail: "<<obj.GetMail()<<endl;
            cout<<"CUIL: "<<obj.GetCuil()<<endl<<endl;
            cout<<"Ingrese nuevos datos:"<<endl;
            cout<<"nombre: ";
            obj.SetNombre();
            cout<<"Dia: ";
            int di;
            cin>>di;
            if(!obj.SetDiaQueViene(di))return;
            cout<<"Telefono: ";
            cin>>di;
            if(!obj.SetTelefono(di))return;
            cout<<"Mail: ";
            obj.SetMail();
            cout<<"CUIL: ";
            cin>>di;
            if(!obj.SetCuil(di))return;
            cout<<endl;
            if(obj.modificarEnDisco(pos))cout<<"Datos modificados correctamente."<<endl;
            system("pause");
            return;
        }
    pos++;
    }
    cout<<"No existe ese proveedor"<<endl;
    system("pause");
}

void eliminarProveedores(){
    Proveedor obj;
    int pos=0, id;
    cout<<"Indique el ID del proveedor que desea eliminar: ";
    cin>>id;
    while(obj.leerDeDisco(pos++)){
        if(id==obj.GetIDProveedor() && obj.GetEstado()){
            obj.SetEstado(false);
            obj.modificarEnDisco(pos-1);
            cout<<"Proveedor eliminado correctamente."<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No existe ese proveedor."<<endl;
    system("pause");
}

///EMPLEADOS
void agregarEmpleados();
void buscarXIDEmpleados();
void listarEmpleados();
void modificarDatosEmpleados();
void eliminarEmpleados();

void menuEmpleados(){

int opcion;
    while(true){
        system("cls");
        cout<<"****MENU EMPLEADOS****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR EMPLEADO"<<endl;
        cout<<"2- BUSCAR EMPLEADO POR ID"<<endl;
        cout<<"3- LISTAR TODOS LOS EMPLEADOS"<<endl;
        cout<<"4- MODIFICAR DATOS"<<endl;
        cout<<"5- ELIMINAR EMPLEADO"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: agregarEmpleados();
                break;
            case 2: buscarXIDEmpleados();
                break;
            case 3: listarEmpleados();
                break;
            case 4: modificarDatosEmpleados();
                break;
            case 5: eliminarEmpleados();
                break;
            case 0:
                return;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
        }
    }
}

void agregarEmpleados(){
Empleado obj;
if(obj.Cargar())obj.grabarEnDisco();
}

void buscarXIDEmpleados(){
    Empleado obj;
    int pos;
    FILE *p;
    p=fopen("Empleados.dat","rb");
    if(p==NULL) return;
    cout<<"INGRESE ID: ";
    cin>>pos;
    while(fread(&obj,sizeof obj, 1, p)){
        if(pos==obj.GetIDEmpleado() && obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
            system("pause");
            fclose(p);
            return;
        }
    }
cout<<"No existe ese ID."<<endl;
system("pause");
fclose(p);
return;
}

void listarEmpleados(){
    Empleado obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void modificarDatosEmpleados(){
    Empleado obj;
    int pos=0, id;
    cout<<"Ingrese ID: "<<endl;
    cin>>id;
    while(obj.leerDeDisco(pos)){
        if(obj.GetIDEmpleado()==id && obj.GetEstado()){
            cout<<"Nombre: "<<obj.GetNombre()<<endl;
            cout<<"Apellido: "<<obj.GetApellido()<<endl;
            cout<<"Documento: "<<obj.GetDocumento()<<endl;
            cout<<"Telefono: "<<obj.GetTelefono()<<endl;
            cout<<"Mail: "<<obj.GetEmail()<<endl;
            obj.GetFechaDeContratacion().Mostrar();
            obj.SetSueldo();
            cout<<endl;
            cout<<"Ingrese nuevos datos:"<<endl;
            cout<<"nombre: ";
            obj.SetNombre();
            cout<<"Apellido: ";
            obj.SetApellido();
            cout<<"Documento: ";
            int di;
            cin>>di;
            if(!obj.SetDocumento(di))return;
            cout<<"Telefono: ";
            cin>>di;
            if(!obj.SetTelefono(di))return;
            cout<<"Mail: ";
            obj.SetEmail();
            cout<<"Fecha de contratacion: ";
            if(!obj.SetFechaDeContratacion())return;
            obj.SetSueldo();
            cout<<endl;
            if(obj.modificarEnDisco(pos))cout<<"Datos modificados correctamente."<<endl;
            system("pause");
            return;

        }
        pos++;
    }
    cout<<"No existe ese empleado"<<endl;
    system("pause");
}

void eliminarEmpleados(){
    Empleado obj;
    int pos=0, id;
    cout<<"Indique el ID del empleado que desea eliminar: ";
    cin>>id;
    while(obj.leerDeDisco(pos++)){
        if(id==obj.GetIDEmpleado() && obj.GetEstado()){
            obj.SetEstado(false);
            obj.modificarEnDisco(pos);
            cout<<"Empleado eliminado correctamente."<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No existe ese empleado."<<endl;
}

///Ventas

void agregarVentas();
void buscarXIDVentas();
void listarVentas();
void listarDetalleXIDVentas();
void eliminarVentas();

void menuVentas(){
int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU VENTAS****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR VENTA"<<endl;
        cout<<"2- BUSCAR VENTA POR ID"<<endl;
        cout<<"3- LISTAR TODAS LAS VENTAS"<<endl;
        cout<<"4- LISTAR DETALLE POR ID"<<endl;
        cout<<"5- ELIMINAR VENTA"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
            {
            case 1: agregarVentas();
                break;
            case 2: buscarXIDVentas();
                break;
            case 3: listarVentas();
                break;
            case 4: listarDetalleXIDVentas();
                break;
            case 5: eliminarVentas();
                break;
            case 0:
                return;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
            }
    }
}

void agregarVentas(){
    Venta obj;
    if(obj.Cargar()){
        cout<<"Venta cargada correctamente."<<endl;
        system("pause");
        obj.grabarEnDisco();
    }
}

void buscarXIDVentas(){
    Venta obj;
    int pos;
    FILE *p;
    p=fopen("Ventas.dat","rb");
    if(p==NULL) return;
    cout<<"INGRESE ID: ";
    cin>>pos;
    while(fread(&obj,sizeof obj, 1, p)){
        if(pos==obj.GetIDVenta() && obj.GetEstadoVenta()){
            obj.Mostrar();
            cout<<endl;
            system("pause");
            fclose(p);
            return;
        }
    }
    cout<<"No existe ese ID."<<endl;
    system("pause");
    fclose(p);
    return;
}

void listarVentas(){
    Venta obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.GetEstadoVenta()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void listarDetalleXIDVentas(){
    Detalle reg;
    int pos=0,id;
    cout<<"Ingrese ID: ";
    cin>>id;
    bool bandera=1;
    while(reg.leerDeDisco(pos++)){
        if(id==reg.GetIDVenta() && reg.GetEstado()){
            reg.Mostrar();
            cout<<endl;
            bandera=0;
        }
    }
    if(bandera)cout<<"No existe ese ID."<<endl;
    system("pause");
}

void eliminarVentas(){
    Venta obj;
    int pos=0, id;
    cout<<"Indique el ID de la venta que desea eliminar: ";
    cin>>id;
    while(obj.leerDeDisco(pos++)){
        if(id==obj.GetIDVenta() && obj.GetEstadoVenta()){
            obj.SetEstadoVenta(false);
            obj.modificarEnDisco(pos-1);
            cout<<"Venta eliminada correctamente."<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No existe esa venta."<<endl;
}

///Caja

void agregarEgresosCajas();
void buscarXFechaCajas();
void listarCajas();
void modificarEgresosCajas();
void eliminarCajas();

void menuCajas(){
int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU CAJA****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- AGREGAR DIA"<<endl;
        cout<<"2- MOSTRAR CAJA POR DIA "<<endl;
        cout<<"3- MOSTRAR CAJA DE TODOS LOS DIAS"<<endl;
        cout<<"4- MODIFICAR EGRESOS DEL DIA"<<endl;
        cout<<"5- ELIMINAR VENTA"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: agregarEgresosCajas();
                break;
            case 2: buscarXFechaCajas();
                break;
            case 3: listarCajas();
                break;
            case 4: modificarEgresosCajas();
                break;
            case 5: eliminarCajas();
                break;
            case 0:
                return;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
        }
    }
}

void agregarEgresosCajas(){
    Caja obj;
    Caja reg;
    int pos=0;
    Fecha f;
    cout<<"Indique fecha: "<<endl;
    f.Cargar();
    while(reg.leerDeDisco(pos++)){
        if(f.getAnio()==reg.GetFecha().getAnio() && f.getMes()==reg.GetFecha().getMes() && f.getDia()==reg.GetFecha().getDia() && reg.GetEstado()){
           cout<<"La fecha ya esta cargada."<<endl;
           system("pause");
           return;
        }
    }
    obj.SetFecha(f);
    if(obj.Cargar() && obj.GetEstado()){
        cout<<"Caja agregada correctamente."<<endl;
        system("pause");
        obj.grabarEnDisco();
    }
}

void buscarXFechaCajas(){
    Caja obj;
    int pos;
    Fecha f;
    FILE *p;
    p=fopen("Cajas.dat","rb");
    if(p==NULL) return;
    cout<<"INGRESE FECHA: ";
    f.Cargar();
    while(obj.leerDeDisco(pos++)){
        if(f.getAnio()==obj.GetFecha().getAnio() && f.getMes()==obj.GetFecha().getMes() && f.getDia()==obj.GetFecha().getDia() && obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
            system("pause");
            fclose(p);
            return;
        }
    }
    cout<<"No existe esa fecha."<<endl;
    system("pause");
    fclose(p);
    return;
}

void listarCajas(){
    Caja obj;
    int pos=0;
    while(obj.leerDeDisco(pos++)){
        if(obj.GetEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
    system("pause");
}

void modificarEgresosCajas(){
    Caja obj;
    int pos=0;
    Fecha f;
    float e;
    cout<<"Ingrese fecha: ";
    f.Cargar();
    while(obj.leerDeDisco(pos)){
        if(f.getAnio()==obj.GetFecha().getAnio() && f.getMes()==obj.GetFecha().getMes() && f.getDia()==obj.GetFecha().getDia() && obj.GetEstado()){
            cout<<"Indique egresos del dia: ";
            cin>>e;
            obj.SetEgresos(e);
            obj.modificarEnDisco(pos);
        }
        pos++;
    }
    cout<<"Egresos del dia modificados correctamente."<<endl;
    system("pause");
}

void eliminarCajas(){
    Caja obj;
    Fecha f;
    int pos=0;
    cout<<"Indique la fecha que desea eliminar: ";
    f.Cargar();
    while(obj.leerDeDisco(pos++)){
        if(f.getAnio()==obj.GetFecha().getAnio() && f.getMes()==obj.GetFecha().getMes() && f.getDia()==obj.GetFecha().getDia() && obj.GetEstado()){
            obj.SetEstado(false);
            obj.modificarEnDisco(pos-1);
            cout<<"Dia eliminado correctamente."<<endl;
            system("pause");
            return;
        }
    }
    cout<<"No hay datos de ese dia."<<endl;
}

///reportes
void op1();
void op2();
void op3();
void op4();
void op5();



void menuReportes(){
    int opcion;
    while(true)
    {
        system("cls");
        cout<<"****MENU CAJA****"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"1- DIA DE MAS VENTAS "<<endl;
        cout<<"2- EMPLEADO QUE MAS COBRA "<<endl;
        cout<<"3- PRODUCTO QUE MAS PORCENTAJE DE GANANCIA DEJA"<<endl;
        cout<<"4- PROVEEDOR QUE MAS PRODUCTOS ME TRAE"<<endl;
        cout<<"5- MODIFICAR SUELDO BASE Y ALQUILER"<<endl;
        cout<<"--------------------"<<endl;
        cout<<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"--------------------";
        cout<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opcion;
        system("cls");
        switch(opcion){
            case 1: op1();
                break;
            case 2: op2();
                break;
            case 3: op3();
                break;
            case 4: op4();
                break;
            case 5: op5();
                break;
            case 0:
                return;
                break;
            default: cout<<"ERROR"<<endl;
                system("pause");
                break;
        }
    }
}

void op1(){
    Fecha *vec;
    int *contador;
    Venta obj;
    int pos=0,contarRegistros=0;
    while(obj.leerDeDisco(pos)){
        pos++;
        contarRegistros++;
    }
    vec=new Fecha[contarRegistros];
    contador=new int[contarRegistros];
    for(int i=0; i<contarRegistros; i++){
        contador[i]=0;
    }
    pos=0;
    while(obj.leerDeDisco(pos)){
        vec[pos]=obj.GetFechaDeVenta();
        pos++;
    }

    pos=0;
    while(obj.leerDeDisco(pos)){
        for(int i=0; i<contarRegistros; i++){
            if(obj.GetFechaDeVenta().getAnio()==vec[i].getAnio() && obj.GetFechaDeVenta().getMes()==vec[i].getMes() && obj.GetFechaDeVenta().getDia()==vec[i].getDia() && obj.GetEstadoVenta()){
                contador[i]++;
            }
        }
        pos++;
    }
    int maximo=0, posmax=0;
    for(int i=0; i<contarRegistros; i++){
        if(contador[i]>maximo){
            maximo=contador[i];
            posmax=i;
        }
    }
    cout<<"El dia con mayor cantidad de ventas es: "<<endl;
    vec[posmax].Mostrar();
    cout<<"Ese dia hubo "<<contador[posmax]<<" ventas."<<endl;
    system("pause");

    delete vec;
    delete contador;
}

void op2(){
    Empleado obj,maximo;
    float maxsueldo=0;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(obj.GetSueldo()>maxsueldo){
            maxsueldo=obj.GetSueldo();
            maximo=obj;
        }
        pos++;
    }
    cout<<"El empleado que mas cobra es: "<<maximo.GetNombre()<<" "<<maximo.GetApellido()<<endl;
    cout<<"Su sueldo es de: "<<maximo.GetSueldo()<<endl;
    system("pause");
}

void op3(){
    Producto obj,maximo;
    float maxdif=0;
    int pos=0;
    while(obj.leerDeDisco(pos)){
        if(((obj.GetPrecioVenta()/obj.GetPrecioCompra())-1)*100>maxdif && obj.GetEstado()){
            maxdif=((obj.GetPrecioVenta()/obj.GetPrecioCompra())-1)*100;
            maximo=obj;
        }
        pos++;
    }
    cout<<"El producto que mas porcentaje de ganancia es: "<<maximo.GetNombre()<<endl;
    cout<<"deja "<<maxdif<<"% de ganancia."<<endl;
    system("pause");
}

void op4(){
    Producto obj;
    Proveedor reg,*aux;
    int*contador,i=0;
    while(reg.leerDeDisco(i)){
        i++;
    }
    aux=new Proveedor[i];
    contador=new int[i];
    int pos=0;
    while(reg.leerDeDisco(pos)){
        aux[pos]=reg;
        contador[pos]=0;
        pos++;
    }

    pos=0;
    while(obj.leerDeDisco(pos)){
        for(int e=0; e<i; e++){
            if(obj.GetIDProveedor()==aux[e].GetIDProveedor() && obj.GetEstado()){
                contador[e]++;
            }
        }
        pos++;
    }

    int maximo=0, posmax=0;
    for(int g=0; g<i; g++){
        if(contador[g]>maximo){
            maximo=contador[g];
            posmax=g;
        }
    }

    cout<<"El proveedor que mas productos trae es: "<<aux[posmax].GetNombre()<<endl;
    cout<<"Trae "<<maximo<<" productos."<<endl;
    system("pause");
}

void op5(){
    Datos obj;
    obj.leerDeDisco(0);
    cout<<"El alquiler y el pago de servicios es: "<<obj.GetAlquiler()<<endl;
    cout<<"El sueldo base es: "<<obj.GetSueldoBase()<<endl;
    cout<<"Indique nuevos datos: "<<endl;
    cout<<"Alquiler: ";
    float f;
    cin>>f;
    if(!obj.SetAlquiler(f))return;
    cout<<"Sueldo base: ";
    cin>>f;
    if(!obj.SetSueldoBase(f))return;
    obj.modificarEnDisco();
    Empleado reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
        reg.SetSueldo();
        reg.modificarEnDisco(pos);
        pos++;
    }

    Caja aux;
    pos=0;
    while(aux.leerDeDisco(pos)){
        aux.SetAlquiler();
        reg.modificarEnDisco(pos);
        pos++;
    }
    cout<<"Se actualizaron los valores."<<endl;
    system("pause");
}



#endif // MENUPRODUCTOS_H_INCLUDED
