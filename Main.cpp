#include "libreta.cpp"
/*#if __has_include("contacto.cpp")
#elif
#include "contacto.cpp"
#endif*/
#include "Menu.cpp"
#include <iostream>

using namespace std;


int main() {
    calltext("nombre.txt");
    LibretaContactos libreta;

    cout << "###################################### \n ¡Bienvenid@! ¿Qué deseas hacer hoy?" << endl;
    cout << " (1) Ver Contactos \n (2) Editar contactos \n (0) Salir " << endl;

    int option0;
    cin >> option0;
    menu(option0, libreta);

    while (option0 != 0) {
        cout << "###################################### \n ¿Qué deseas hacer ahora? (0 para salir): " << endl;
        cout << "(1) Ver Contactos " << endl << "(2) Editar contactos " << endl << "(3) Copia de seguridad " << endl;

        cin >> option0;
        menu(option0, libreta); // Se pasa la instancia de libreta a la función menu
    }
    return 0;
}
