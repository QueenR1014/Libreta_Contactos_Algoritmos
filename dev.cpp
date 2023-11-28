#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

#include "libreta.cpp"
/*
#if __has_include("contacto.cpp")
#elif*/
#include "contacto.cpp"
//#endif

using namespace std;


int main() {
    cout<<"################# \n INICIO DE PRUEBA \n #################"<<endl;
    LibretaContactos libreta;


    Contacto contacto1;
    contacto1.set_nombre("Juan Reina");
    contacto1.set_telf(3228703929);
    contacto1.set_direcc("Calle 123");
    contacto1.set_red("Instagram", "@juanhdgamer");
    contacto1.set_red("Correo", "juan@urosario.co");
    contacto1.set_ico(1);

    Contacto contacto2;
    contacto2.set_nombre("Laura");
    contacto2.set_telf(3184100100);
    contacto2.set_direcc("Avenida 456");
    contacto2.set_red("LinkedIn", "linkedin.com/in/Laura");
    contacto2.set_ico(2);

    libreta.AgregarContacto(contacto1);
    libreta.AgregarContacto(contacto2);

    cout << "Lista de contactos:" << endl;
    libreta.MostrarContactos();

    libreta.MostrarCantidadContactos();

    cout << "Buscar contacto por nombre:" << endl;
    libreta.BuscarContacto("Juan Reina");

    libreta.EliminarContacto("Laura");

    cout << "Lista de contactos después de eliminar a Laura:" << endl;
    libreta.MostrarContactos();


    libreta.MostrarCantidadContactos();


    cout << "Contactos cuyos nombres comienzan con 'J':" << endl;
    libreta.MostrarContactosPorLetra('J');

    libreta.RealizarCopiaSeguridad("copia_seguridad.txt");

    return 0;
}
