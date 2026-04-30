#ifndef IALTADEUSUARIO_H
#define IALTADEUSUARIO_H

#include "Dts/DTUsuario.h"
#include "Enums/TipoTecho.h"
#include <set>
#include <string>
#include "Tipos.h"

class IAltaDeUsuario {
    public:
        virtual bool altaCliente(String nickname, String contrasena, String nombre, String email, String apellido, String documento) = 0;
        virtual bool altaPropietario(String nickname, String contrasena, String nombre, String email, String cuentaBancaria, String telefono) = 0;
        virtual bool altaInmobiliaria(String nickname, String contrasena, String nombre, String email, String direccion, String url, String telefono) = 0;
        virtual void altaCasa(String direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho tech) = 0;
        virtual void altaApartamento(String direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;
        virtual SetDTUsuario listarPropietarios() = 0;
        virtual void representarPropietarios(String nicknamePropietario) = 0;
        virtual void finalizarAltaUsuario() = 0;
        virtual ~IAltaDeUsuario() {};
};

#endif
