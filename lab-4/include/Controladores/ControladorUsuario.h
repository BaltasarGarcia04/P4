#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Interfaces/IAltaDeUsuario.h"
#include "Clases/AdministraPropiedad.h"
#include "Dts/DTUsuario.h"
#include "Dts/DTInmuebleAdministrado.h"
#include <string>
#include <set>

class ControladorUsuario : public IAltaDeUsuario{
    private:
        static ControladorUsuario* instance;
        ControladorUsuario();

        Propietario* p;
        Inmobiliaria* i;
    public:
        static ControladorUsuario* getInstance();
        
        bool altaCliente(String nickname, String contrasena, String nombre, String email, String apellido, String documento) override;
        bool altaPropietario(String nickname, String contrasena, String nombre, String email, String cuentaBancaria, String telefono) override;
        bool altaInmobiliaria(String nickname, String contrasena, String nombre, String email, String direccion, String url, String telefono) override;
        void altaCasa(String direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho tech) override;
        void altaApartamento(String direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes) override;
        SetDTUsuario listarPropietarios() override;
        void representarPropietarios(String nicknamePropietario) override;
        void finalizarAltaUsuario() override;        
       
        ~ControladorUsuario();
    };

#endif
