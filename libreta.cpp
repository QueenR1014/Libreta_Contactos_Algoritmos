#include "contacto.cpp"
#include <iostream>
#include <vector>

using namespace std;

class LibretaContactos {
private:
    vector<Contacto> contactos;

public:

///////////////
    void agregarContacto(const Contacto& nuevoContacto) {
        contactos.push_back(nuevoContacto);
        
        
        //////
        
        sort(contactos.begin(), contactos.end(), [](const Contacto& a, const Contacto& b) {
            return a.get_nombre() < b.get_nombre();
        });
    }


////////////////////
    void eliminarContacto(const string& nombre) {
        auto it = remove_if(contactos.begin(), contactos.end(),
                            [nombre](const Contacto& contacto) { return contacto.get_nombre() == nombre; });

        contactos.erase(it, contactos.end());
    }


//////////////////
    void buscarContacto(const string& nombre) const {
        auto it = find_if(contactos.begin(), contactos.end(),
                          [nombre](const Contacto& contacto) { return contacto.get_nombre() == nombre; });

        if (it != contactos.end()) {
            cout << *it << endl;
            cout << "Redes:\n" << it->print_map() << endl;
        } else {
            cout << "Contacto no encontrado." << endl;
        }
    }



////////////////////////
    void mostrarContactos() const {
        for (const auto& contacto : contactos) {
            cout<< contacto << endl;
            cout<< "Redes:\n" << contacto.print_map() << endl;
        }
    }



//////////////////////////
    void mostrarCantidadContactos() const {
        cout << "Total de contactos: " << contactos.size() << endl;
    }

    void mostrarContactosPorLetra(char letra) const {
        for (const auto& contacto : contactos) {
            if (tolower(contacto.get_nombre()[0]) == tolower(letra)) {
                cout << contacto << endl;
                cout << "Redes:\n" << contacto.print_map() << endl;
            }
        }
    }



////////////////////////////////////////
    void realizarCopiaSeguridad(const string& nombreArchivo) const {
        ofstream archivo(nombreArchivo);

        for (const auto& contacto : contactos) {
            archivo << contacto << endl;
            archivo << "Redes:\n" << contacto.print_map() << endl;
        }

        archivo.close();
    }
};




int main() {

    return 0;
}
