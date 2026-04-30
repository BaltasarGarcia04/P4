#ifndef USUARIO_H
#define USUARIO_H

#include "Dts/DTUsuario.h"
#include <string>

class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        std::string getNickname();
        std::string getContrasena();
        std::string getNombre();
        std::string getEmail();
        DTUsuario* getDT();
        virtual ~Usuario();
};

#endif
