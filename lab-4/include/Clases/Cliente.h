#ifndef CLIENTE_H
#define CLIENTE_H
#include "Clases/Usuario.h"
#include "Clases/Suscriptor.h"
#include <string>

class Cliente : public Usuario, public Suscriptor {
    private:
        std::string apellido;
        std::string documento;

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email,
        std::string apellido, std::string documento);
        std::string getApellido();
        std::string getDocumento();
        ~Cliente();
};

#endif