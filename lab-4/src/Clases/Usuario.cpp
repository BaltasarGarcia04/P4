#include"Clases/Usuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email){
    this->nickname = nickname;
    this->contrasena =  contrasena;
    this->nombre = nombre;
    this->email = email;
}

std::string Usuario::getNickname(){
    return nickname;
}

std::string Usuario::getNombre(){
    return nombre;
}

std::string Usuario::getEmail(){
    return email;
}

std::string Usuario::getContrasena(){
    return contrasena;
}

DTUsuario* Usuario::getDT() {
    return new DTUsuario(this->nickname, this->nombre);
}

Usuario::~Usuario(){}