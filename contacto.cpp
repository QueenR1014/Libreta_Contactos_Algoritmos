#include <iostream>
#include <map>
#include <string>
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

        void set_nombre(string n){
            nombre = n;
        }

        string get_nombre(){
            return nombre;
        }

        void set_telf(int t){
            telefono  = t;
        }

        int get_telf(){
            return telefono;
        }

        void set_red(string red , string info){
            redes[red] = info;
        }

        string get_red(string red){
            return redes[red];
        }

        void set_direcc(string d){
            direccion = d;
        }

        string get_direcc(){
            return direccion;
        }
        string print_map(){

            string redes_string;
            for(const auto& par : redes){
                redes_string += par.first + ": " + par.second + " \n";
            }

            return redes_string;
        }

        string print(){
            return "Nombre: " + nombre + " Teléfono: " + to_string(telefono) +  " Dirección: " + direccion;
        }


        
};