#include <iostream>
#include <fstream>
#include "libreta.cpp"
//#include "contacto.cpp"

using namespace std;

void calltext(string doc){
    
    ifstream artFile(doc);
    string line;

    if (artFile.is_open())
    {
        while (getline(artFile, line))
        {
            cout << line << endl;
        }
        artFile.close();
    }
    else
    {
        cerr<< "Failed to open .txt" << endl;
    }
};


void menu(int option, LibretaContactos& libreta){
    int option1;
    int option2;
    string nombre_b;
    string nombre_c;
    Contacto contactoNuevo;
    string nom;
    int num;
    string dire;
    string red_s;
    string nred;
    int Q;
    bool estado = false;
    int num_a = rand()%4000+4000;
    char icono = static_cast<char>(num_a);
    int op;
    bool esta;
    switch (option) {
        case 1:
            //Contactos
            calltext("contactos.txt");
            cout << "Que contactos desea ver? " << endl << "(1) Todos los contactos: " << endl <<"(2) Más frecuentes: " << endl <<"(3) Buscar nombre por letra: "<<endl<<"(4) Buscar por nombre: " <<endl << "Contactos totales: " << libreta.MostrarCantidadContactos() << endl ;
            cin >> option1;
            switch(option1){
                case 1:
                    libreta.MostrarContactos();
                    break;
                case 2:
                    libreta.RevisarFrecuencia();
                    break;
                case 3:
                    char letra;
                    cout<< "Ingresa la letra por buscar: "<< endl;
                    cin >> letra;
                    libreta.MostrarContactosPorLetra(letra);
                    break;
                case 4:
                    cout << "A quien buscas? "<<endl;
                    cin >> nombre_b;
                    libreta.BuscarContacto(nombre_b);
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    break;
            }
            break;
        case 2:
            //Editor
            calltext("editor.txt");
            cout << "Que desea hacer? " << endl << "(1) Agregar contacto: " << endl <<"(2) Eliminar contacto: " << endl <<"(3) Volver: "<< endl;
            cin >> option2;
            switch(option2){
                case 1:
                    cout<<"Nombre: "<< endl;
                    cin>>nom;
                    cout<<"Numero: "<<endl;
                    cin>>num;
                    cout<<"Deseas agregar una dirección? (1) si (2) no"<<endl;
                    cin >> op;
                    if(op==1){
                        esta = true;
                        
                    }
                    else{
                        esta = false;
                    }
                    while(esta == true){
                        cout<<"Direccion: "<<endl;
                        cin>>dire;                        
                    }
                    cout<<"Desea agregar una red social? (1) si (2) no"<<endl;
                    cin>>Q;
                    if(Q == 1){
                        estado = true;
                    }else{
                        estado = false;
                    }
                    while (estado){
                    cout<<"Red social: "<<endl;
                    cin>>red_s;
                    cout<<"Usuario"<<endl;
                    cin>>nred;
                    contactoNuevo.set_red(red_s, nred);
                    cout<<"Desea agregar otra red social? (1) si (2) no"<<endl;
                    cin>>Q;
                    if(Q == 1){
                        estado = true;
                    }else{
                        estado = false;
                    }
                }; 

                    contactoNuevo.set_nombre(nom);
                    contactoNuevo.set_telf(num);
                    contactoNuevo.set_direcc(dire);
                    contactoNuevo.set_ico(icono);
                    libreta.AgregarContacto(contactoNuevo);
                    cout << "Contacto agregado exitosamente." << endl;
                    break;
                case 2:
                    string eliminado;
                    cout << "A quién desea eliminar? (Por favor escriba el nombre tal cual como ha sido guardado): "<<endl;
                    cin >> eliminado;
                    libreta.EliminarContacto(eliminado);
                    break;

            }
            break;
        case 3:
            cout<<"Como desea llamar a la copia? "<<endl;
            cin>>nombre_c;
            libreta.RealizarCopiaSeguridad(nombre_c);    
    }
}
