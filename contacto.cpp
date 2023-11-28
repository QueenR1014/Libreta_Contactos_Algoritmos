class Contacto{
    private:
//declaracion de variables
        string nombre;
        int telefono;
        map<string, string> redes = crear_redes();
        string direccion;
        char ico;
        int recurrence;
    public:

//constructores de la clase
        Contacto(){
            //test
            recurrence = 0;
        }


        Contacto(string n, int t, string di, int i){
            recurrence = 0;
            nombre = nombre;
            telefono = t;
            direccion = di;
            ico = i;
        }

        Contacto(string n){
            Contacto(n,0,"",0);
            //test
        }

        Contacto(string n , int t){
            Contacto(n,t,"",0);
        }

        //Methods
        // set's and get's
        void set_nombre(string n){
            nombre = n;
        }

        string get_nombre(){
            return nombre;
        }

        void set_telf(int t){
            telefono  = t;
        }

        int get_telf(){
            return telefono;
        }

        void set_red(string red , string info){
            redes[red] = info;
        }

        string get_red(string red){
            return redes[red];
        }

        void set_direcc(string d){
            direccion = d;
        }

        string get_direcc(){
            return direccion;
        }

        void set_ico(int i){
            ico = i;
        }

        int get_ico(){
            return ico;
        }

        int get_frecuencia(){
            return recurrence;
        }

        void set_frecuencia(int r){
            recurrence = r;
        }
        // Prints para mostrar la informacion almacenada en la clase segun la estructura
        string print_map() const {
            string redes_string;
            for (const auto& par : redes) {
                redes_string += par.first + ": " + par.second + " \n";
            }
            return redes_string;
        }


        string print() const {
            return "Nombre: " + nombre + " Teléfono: " + to_string(telefono) +  " Dirección: " + direccion;
        }

        friend std::ostream& operator<<(std::ostream& os, Contacto& b){
            return os << b.print();
        }
        //sobrecarga de los operadores principales para las operaciones basicas sea un cout o una comparacion para los sort's
        friend std::ostream& operator<<(std::ostream& os, Contacto* b){
            return os << b->print();
        }
        friend std::ostream& operator<<(std::ostream& os, const Contacto& b){
            return os << b.print();
        }

        friend std::ostream& operator<<(std::ostream& os, const Contacto* b){
            return os << b->print();
        }


    bool operator<(Contacto a){
            return nombre[0] < a.get_nombre()[0];
        }

        bool operator>(Contacto a){
            return nombre[0] > a.get_nombre()[0];
        }

};
