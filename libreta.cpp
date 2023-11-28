class LibretaContactos {
private:
    vector<Contacto> contactos;

public:
    void AgregarContacto(const Contacto& nuevoContacto) {
        contactos.push_back(nuevoContacto);
        cout << "Tamaño del vector después de agregar: " << contactos.size() << endl;

        //sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) { //Al añadir un contacto, automáticamente se ordena alfabéticamente
            //return a < b;
        //});
    }



    void EliminarContacto(const string& nombre) {
        auto it = remove_if(contactos.begin(), contactos.end(), [nombre](Contacto& contacto) { return contacto.get_nombre() == nombre; });

        //Función remove, una vez encuentre el nombre, desde el rango begin hasta el end, lo elimina.

        contactos.erase(it, contactos.end());
    }



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

    void MostrarContactos() const {
        for (const Contacto& c : contactos) { // Utilizar una referencia constante para evitar problemas de tipos
            cout << c << endl;
            cout << "Redes:\n" << c.print_map() << endl;
        }
    }




    int MostrarCantidadContactos() const {

        return contactos.size();
    }


    void MostrarContactosPorLetra(char letra) {
        for (auto& contacto : contactos) {
            if (tolower(contacto.get_nombre()[0]) == tolower(letra)) {  // dentro de contactos, se tomas todos los contactos cuya primera letra (convertida a
                cout << contacto << endl;                               // minúscula) sean igual a la letra dada y se imprimen.
                cout << "Redes:\n" << contacto.print_map() << endl;
            }
        }
    }


    void RealizarCopiaSeguridad(const string& nombreArchivo, queue<string>& c_s) {
    ofstream archivo(nombreArchivo); // Crear archivo de copia de seguridad

    // Escribir los contactos en el archivo
    for (auto& contacto : contactos) {
        archivo << contacto << endl;
        archivo << "Redes:\n" << contacto.print_map() << endl;
    }
    archivo.close(); // Cerrar el archivo

    c_s.push(nombreArchivo); // Agregar el nombre del archivo a la cola

    int x = 0;
    cout << "Desea ver las copias de seguridad? (1) para sí, (2) para no: ";
    cin >> x;
    if (x == 1) {
        queue<string> temp = c_s; // Crear una copia temporal de la cola para no alterar la original
        while (!temp.empty()) {
            cout << "Archivo: " << temp.front() << endl;
            temp.pop();
        }
    }
}



    void OrdenarContactos(){
        sort(contactos.begin(), contactos.end(), []( Contacto& a,  Contacto& b) {
            return a < b;
        });
    }


    void ImportarContactos(vector<Contacto> importado){
        contactos = importado;
        OrdenarContactos();
    }



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
