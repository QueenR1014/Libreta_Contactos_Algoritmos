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

    void AgregarContacto(const Contacto& nuevoContacto) {
        contactos.push_back(nuevoContacto);

        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) { //Al añadir un contacto, automáticamente se ordena alfabéticamente
            return a < b;
        });
    }


////////////////////

    void EliminarContacto(const string& nombre) {
        auto it = remove_if(contactos.begin(), contactos.end(), [nombre](Contacto& contacto) { return contacto.get_nombre() == nombre; });

        //Función remove, una vez encuentre el nombre, desde el rango begin hasta el end, lo elimina.

        contactos.erase(it, contactos.end());
    }


//////////////////

    void BuscarContacto(const string& nombre) {
        auto it = find_if(contactos.begin(), contactos.end(),
                          [nombre](Contacto& contacto) { return contacto.get_nombre() == nombre; });

        /* Función find if, de la misma manera que el remove, desde el rango begin hasta en, va sacando los nombre de cada contacto y los iguala al 
        nombre dado */

        if (it != contactos.end()) {
            cout << *it << endl; 
            cout << "Redes:\n" << it->print_map() << endl;  // si lo encuentra, se imprimen sus redes
        } else {
            cout << "Contacto no encontrado." << endl; // caso en el que no
        }
    }



////////////////////////

    void MostrarContactos() const {
        for (Contacto c : contactos) { //For en el que imprime contacto por contacto
            cout<<c<< endl;
            cout<< "Redes:\n" << c.print_map() << endl;
        }
    }



//////////////////////////

    void MostrarCantidadContactos() const {
        cout << "Total de contactos: " << contactos.size() << endl;
    }



/////////////////////////

    void MostrarContactosPorLetra(char letra) {
        for (auto& contacto : contactos) {
            if (tolower(contacto.get_nombre()[0]) == tolower(letra)) {  // dentro de contactos, se tomas todos los contactos cuya primera letra (convertida a 
                cout << contacto << endl;                               // minúscula) sean igual a la letra dada y se imprimen.
                cout << "Redes:\n" << contacto.print_map() << endl;
            }
        }
    }



////////////////////////////////////////
     void RealizarCopiaSeguridad(const string& nombreArchivo){
        ofstream archivo(nombreArchivo);                             

        for (auto& contacto : contactos) {
            archivo << contacto << endl;
            archivo << "Redes:\n" << contacto.print_map() << endl;
        }

        archivo.close();
    }


    void OrdenarContactos(){
        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) {
            return a < b;
        });
    }
    void ImportarContactos(vector<Contacto> importado){
        contactos = importado;
        ordenarContactos();
    }

    Contacto BusquedaBinaria(string nombre){
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

