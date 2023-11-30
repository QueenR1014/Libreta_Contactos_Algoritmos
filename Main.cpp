#if __has_include("libreta.cpp")
#elif
#include "libreta.cpp"
#endif
#if __has_include("contacto.cpp")
#elif
#include "contacto.cpp"
#endif
#include "Menu.cpp"
#include <iostream>

using namespace std;



int main() {
    calltext("nombre.txt");
    LibretaContactos libreta;

    int option0;
    cout << "###################################### \n ¡Bienvenid@! ¿Qué deseas hacer hoy?" << endl;
    main_validation1:
    cout << " (1) Ver Contactos \n (2) Agregar o editar contactos \n (0) Salir " << endl;
    cin >> option0;
    if(!validate_input(option0,0,2)){
        cout<<"Ingreso Inválido. Intenta de Nuevo"<<endl;
        goto main_validation1;
    }

    menu(option0, libreta);

    while (option0 != 0) {
        
        cout << "###################################### \n ¿Qué deseas hacer ahora? (0 para salir): " << endl;
        cout << "(1) Ver Contactos " << endl << "(2) Agregar o editar contactos  " << endl << "(3) Copia de seguridad " << endl;
        cin >> option0;
        if(!validate_input(option0,0,3)){
            continue;
        }
        menu(option0, libreta); // Se pasa la instancia de libreta a la función menu
    }
    return 0;
}
