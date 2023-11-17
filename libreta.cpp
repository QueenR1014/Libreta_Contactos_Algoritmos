#include "contacto.cpp"
#include <iostream>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

class LibretaContactos {
private:
    vector<Contacto> contactos;

public:


    vector<Contacto> insercionOrdenada(Contacto nuevo){

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
    }
///////////////
    void agregarContacto(const Contacto& nuevoContacto) {
        contactos.push_back(nuevoContacto);

        /*sort(contactos.begin(), contactos.end(), [](const Contacto& a, const Contacto& b) {
            return a.get_nombre() < b.get_nombre();
        });*/
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
};

