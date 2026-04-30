#include "Clases/Cliente.h"
#include "Clases/Usuario.h"

Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,
        std::string apellido, std::string documento): Usuario(nickname,contrasena,nombre,email), apellido(apellido),documento(documento){

        };


std::string Cliente::getApellido(){
    return apellido;
};


std::string Cliente::getDocumento(){
    return documento;
};


Cliente::~Cliente(){

};


