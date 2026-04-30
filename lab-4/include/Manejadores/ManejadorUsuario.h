#pragma once

#include <map>
#include <string>
#include <set>
#include "Clases/Usuario.h"
#include "Clases/Suscriptor.h"
#include "Clases/Inmobiliaria.h"
#include "Clases/Propietario.h"
#include "Clases/Cliente.h"
#include "Dts/DTUsuario.h"
#include "Dts/DTInmuebleAdministrado.h"
#include "Controladores/ControladorUsuario.h"
#include "Tipos.h"

class ManejadorUsuario
{
private:
    static ManejadorUsuario* instancia;
    ManejadorUsuario();
    MapUsuario usuarios;
    std::set<Inmobiliaria*> Inmobiliarias;
public:
    static ManejadorUsuario* getInstance();

    bool altaCliente(String nickname, String contrasena, String nombre, String email, String apellido, String documento);
    bool altaInmobiliaria(String nickname, String contrasena, String nombre, String email, String direccion, String url, String telefono);
    bool altaPropietario(String nickname, String contrasena, String nombre, String email, String cuentaBancaria, String telefono);
    SetDTUsuario listarPropietarios();
    Propietario* getPropietario(String nicknamePropietario);
    
    SetDTInmuebleListado listarInmueblesNoAdministradosInmobiliaria(String nicknameInmobiliaria);
    SetDTUsuario listarInmobiliarias();
    Inmobiliaria* getInmobiliaria(String nicknameInmobiliaria);

    SetDTUsuario listarClientes();
    Cliente* getCliente(String nicknameCliente);

    Suscriptor* getSuscriptor(String nicknameSuscriptor);

    SetDTInmuebleAdministrado listarInmueblesAdministrados(String nicknameInmobiliaria);
    std::set<Inmobiliaria*> getInmobiliarias();

    ~ManejadorUsuario();
};






