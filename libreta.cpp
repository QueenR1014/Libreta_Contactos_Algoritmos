#include "contacto.cpp"
#include <iostream>
#include <vector>
#include <iostream>
#include <map>
//métodos de búsqueda y ordenamiento
#include <algorithm>
#include <fstream>
//Manejo de strings
#include <cctype>
using namespace std;

class LibretaContactos {
private:
    vector<Contacto> contactos;

public:


    /*vector<Contacto> insercionOrdenada(Contacto nuevo){

        //Vector displacement acording to name
        bool inserted = false;
        vector<Contacto> temp;
        for(int i = 0; i < contactos.size(); i++ ){
            if(contactos[i] < nuevo && !inserted){
                temp[i] = contactos[i];
                temp[i + 1] = nuevo; 
            }else if(!inserted){
                temp[i] = nuevo;
            }else{
                temp[i] = contactos[i];
            }
        }
        
        contactos = temp;
        return temp;
    }*/
///////////////
    void agregarContacto(const Contacto& nuevoContacto) {
        contactos.push_back(nuevoContacto);

        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) {
            return a < b;
        });
    }


////////////////////
    void eliminarContacto(const string& nombre) {
        auto it = remove_if(contactos.begin(), contactos.end(), [nombre](Contacto& contacto) { return contacto.get_nombre() == nombre; });

        contactos.erase(it, contactos.end());
    }


//////////////////
    void buscarContacto(const string& nombre) {
        auto it = find_if(contactos.begin(), contactos.end(),
                          [nombre](Contacto& contacto) { return contacto.get_nombre() == nombre; });

        if (it != contactos.end()) {
            cout << *it << endl; 
            cout << "Redes:\n" << it->print_map() << endl;
        } else {
            cout << "Contacto no encontrado." << endl;
        }
    }



////////////////////////
    void mostrarContactos() const {
        for (Contacto c : contactos) {
            cout<<c<< endl;
            cout<< "Redes:\n" << c.print_map() << endl;
        }
    }



//////////////////////////
    void mostrarCantidadContactos() const {
        cout << "Total de contactos: " << contactos.size() << endl;
    }

    void mostrarContactosPorLetra(char letra) {
        for (auto& contacto : contactos) {
            if (tolower(contacto.get_nombre()[0]) == tolower(letra)) {
                cout << contacto << endl;
                cout << "Redes:\n" << contacto.print_map() << endl;
            }
        }
    }



////////////////////////////////////////
     void realizarCopiaSeguridad(const string& nombreArchivo){
        ofstream archivo(nombreArchivo);

        for (auto& contacto : contactos) {
            archivo << contacto << endl;
            archivo << "Redes:\n" << contacto.print_map() << endl;
        }

        archivo.close();
    }


    void ordenarContactos(){
        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) {
            return a < b;
        });
    }
    void importarContactos(vector<Contacto> importado){
        contactos = importado;
        ordenarContactos();
    }

    Contacto busquedaBinaria(string nombre){
        bool found = false;
        int max = contactos.size() - 1;
        int min = 0;
        while(!found){

            Contacto mitad = contactos[(max + min) / 2];

            if(nombre > mitad.get_nombre()){
                min = (max + min)/ 2 ;
            }else if(nombre < mitad.get_nombre()){
                max = (max + min)/ 2;
            }else if(nombre == mitad.get_nombre()){
                return mitad;
            }
        }
    }

};

