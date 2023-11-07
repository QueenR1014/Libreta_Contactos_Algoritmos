#include <iostream>
#include <map>
using namespace std;

map<string,string> crear_redes(){
    map<string, string> redes;
    redes["Instagram"] = "";
    redes["Correo"] = "";
    redes["X"] = "";
    redes["LinkedIn"] = "";

    return redes;
}

class contacto{
    private:
        string nombre;
        int telefono;
        map<string, string> redes = crear_redes();
        string direccion;
        
    public:

        contacto(){
            //test
        }

        void set_nombre(string n ){

        }
};