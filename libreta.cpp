#include "contacto.cpp"
#include <iostream>
#include <vector>
#include <iostream>
#include <map>
//métodos de búsqueda y ordenamiento
#include <algorithm>
//método de creación de ficheros en un programa
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
     void RealizarCopiaSeguridad(const string& nombreArchivo, queue<string> c_s){
        ofstream archivo(nombreArchivo);                             //usando file stream, se crea la copia de seguridad como archivo .txt
        int x = 0;
        for (auto& contacto : contactos) {
            archivo << contacto << endl;
            archivo << "Redes:\n" << contacto.print_map() << endl;    // donde se imprimen todos los contactos existentes
        }

        archivo.close();           // se cierra el archivo

        c_s.push(nombreArchivo);
        while(x != 1 || x != 2){
            cout<<"Desea ver las copias de seguridad? (1) para si (2) para no" << endl;
        }
         
    }


///////////////////////////////

    void OrdenarContactos(){
        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) {
            return a < b;
        });
    }


//////////////////////////////////////////////////
    void ImportarContactos(vector<Contacto> importado){
        contactos = importado;
        OrdenarContactos();
    }

/////////////////////////////////////////////////////

    vector<Contacto> RevisarFrecuencia(){
        vector<Contacto> MasFrecuentes;
        int frecuence;
        if(MasFrecuentes.size() < 10){
            frecuence = 5;
        }else if(MasFrecuentes.size() >= 10){
            frecuence = 0;
            for(int i = 0; i < MasFrecuentes.size(); i++){
                frecuence += MasFrecuentes[i].get_frecuencia();
            }

            frecuence = frecuence / MasFrecuentes.size();
        }
        for(int i = 0; i < contactos.size(); i++){

            if(contactos[i].get_frecuencia() > frecuence){
                MasFrecuentes.push_back(contactos[i]);
            }
        }
        sort(MasFrecuentes.begin(), MasFrecuentes.end(), []( Contacto& a,  Contacto& b) {
            return a < b;
        });
        return MasFrecuentes;
    }




////////////////////////////////////////////////////
    Contacto BusquedaBinaria(string nombre){
        bool found = false;
        int max = contactos.size() - 1;
        int min = 0;
        int mitad = (max + min)/2;
        while(!found){


            if(nombre > contactos[mitad].get_nombre()){         //Se ajusta el límite inferior (min) para buscar en la mitad derecha de la lista
                min = (max + min)/ 2 ;
            }else if(nombre < contactos[mitad].get_nombre()){         //Se ajusta el límite superior (max) para buscar en la mitad izquierda de la lista.
                max = (max + min)/ 2;
            }else if(nombre == contactos[mitad].get_nombre()){        //Se ha encontrado el contacto y se devuelve ese contacto.
                return contactos[mitad];
            }
        }
    }

};

