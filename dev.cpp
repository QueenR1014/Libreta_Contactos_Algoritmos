#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

#include "libreta.cpp"

#if __has_include("contacto.cpp")
#elif
#include "contacto.cpp"
#endif

using namespace std;
/*
map<string, string> crear_redes(){
    map<string, string> redes;
    redes["Instagram"] = "";
    redes["Correo"] = "";
    redes["X"] = "";
    redes["LinkedIn"] = "";

    return redes;
}
*/
/*class Contacto {
private:
    string nombre;
    int telefono;
    map<string, string> redes = crear_redes();
    string direccion;
    int ico;

public:
    Contacto() {
    }

    void set_nombre(string n) {
        nombre = n;
    }

    string get_nombre() const {
        return nombre;
    }

    void set_telf(int t) {
        telefono = t;
    }

    int get_telf() const {
        return telefono;
    }

    void set_red(string red, string info) {
        redes[red] = info;
    }

    string get_red(string red) const {
        return redes.at(red);
    }

    void set_direcc(string d) {
        direccion = d;
    }

    string get_direcc() const {
        return direccion;
    }

    void set_ico(int i) {
        ico = i;
    }

    int get_ico() const {
        return ico;
    }

    string print_map() const {
        string redes_string;
        for (const auto& par : redes) {
            redes_string += par.first + ": " + par.second + " \n";
        }

        return redes_string;
    }

    string print() const {
        return "Nombre: " + nombre + " Teléfono: " + to_string(telefono) + " Dirección: " + direccion;
    }

    friend std::ostream& operator<<(std::ostream& os, const Contacto& b) {
        return os << b.print();
    }
};*/





//////////////////////////////////////////////////////////////////////////////




/*class LibretaContactos {
private:
    vector<Contacto> contactos;

public:

///////////////
    void agregarContacto(const Contacto& nuevoContacto) {
        contactos.push_back(nuevoContacto);
        
        
        //////
        
        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) {
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
            cout << contacto << endl;
            cout << "Redes:\n" << contacto.print_map() << endl;
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


*/

int main() {
    LibretaContactos libreta;


    Contacto contacto1;
    contacto1.set_nombre("Juan");
    contacto1.set_telf(123456789);
    contacto1.set_direcc("Calle 123");
    contacto1.set_red("Instagram", "@juan_instagram");
    contacto1.set_red("Correo", "juan@example.com");
    contacto1.set_ico(1);

    Contacto contacto2;
    contacto2.set_nombre("Ana");
    contacto2.set_telf(987654321);
    contacto2.set_direcc("Avenida 456");
    contacto2.set_red("LinkedIn", "linkedin.com/in/ana");
    contacto2.set_ico(2);

    libreta.agregarContacto(contacto1);
    libreta.agregarContacto(contacto2);

    cout << "Lista de contactos:" << endl;
    libreta.mostrarContactos();

    libreta.mostrarCantidadContactos();

    cout << "Buscar contacto por nombre:" << endl;
    libreta.buscarContacto("Juan");

    libreta.eliminarContacto("Ana");

    cout << "Lista de contactos después de eliminar a Ana:" << endl;
    libreta.mostrarContactos();


    libreta.mostrarCantidadContactos();


    cout << "Contactos cuyos nombres comienzan con 'J':" << endl;
    libreta.mostrarContactosPorLetra('J');

    libreta.realizarCopiaSeguridad("copia_seguridad.txt");

    return 0;
}
