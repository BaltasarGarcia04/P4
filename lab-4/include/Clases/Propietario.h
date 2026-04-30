#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Clases/Usuario.h"
#include "Clases/Suscriptor.h"
#include "Clases/Inmueble.h"
#include "Clases/Inmobiliaria.h"
#include "Tipos.h"
#include <string>
#include <map>


class Propietario : public Usuario, public Suscriptor{
    private:
        std::string cuentaBancaria;
        std::string telefono;
        SetInmueble inmuebles;
        SetInmobiliaria inmobiliarias;
    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, 
        std::string email, std::string cuentaBancaria, std::string telefono);
        std::string getCuentaBancaria();
        std::string getTelefono();
        void agregarInmueble(Inmueble* inmueble);
        void agregarInmobiliaria(Inmobiliaria *i);
        SetInmueble getInmuebles();
        ~Propietario();
};

#endif
