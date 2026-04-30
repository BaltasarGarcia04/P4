#include "Clases/Propietario.h"

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, 
            std::string email, std::string cuentaBancaria, std::string telefono):Usuario(nickname,contrasena,nombre,email){
                this->cuentaBancaria = cuentaBancaria;
                this->telefono = telefono;
            }
std::string Propietario::getCuentaBancaria(){
    return cuentaBancaria;
}

std::string Propietario::getTelefono(){
    return telefono;
}
void Propietario::agregarInmueble(Inmueble* inmueble){
    int codigo = inmueble->getcodigo();
    inmuebles[codigo] = inmueble;
    inmueble->agregarDuenio(this);
}

void Propietario::agregarInmobiliaria(Inmobiliaria *i) {
    inmobiliarias[i->getNickname()] = i;
}


Propietario::~Propietario(){
    for (SetInmueble::iterator it=inmuebles.begin(); it!=inmuebles.end(); ++it){
        delete it->second;
    }
}
