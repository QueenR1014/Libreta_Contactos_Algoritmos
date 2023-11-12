#include <vector>
#include "contacto.cpp"
class libreta{
private:
    vector<contacto> contactos;
public:
    libreta(){

    }
    void insert_c(contacto c){
        contactos.push_back(c);
    }
    contacto buscar_cont(string nom){
        for(int i = 0; i < contactos.size(); i++){
            if(nom == contactos[i].get_nombre()) {
                return contactos[i];
            }
        }
        cout<<"contaco no encontrado :("<<endl;
        return contacto();
    }

};


int main(){

}