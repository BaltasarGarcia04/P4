#include "Controladores/ControladorUsuario.h"
#include "Controladores/ControladorPublicacion.h"
#include "Manejadores/ManejadorUsuario.h"
#include "Manejadores/ManejadorInmueble.h"
#include "Manejadores/ManejadorPublicacion.h"
#include <cstddef>

ControladorUsuario *ControladorUsuario::instance = NULL;

ControladorUsuario::ControladorUsuario()
{
}

ControladorUsuario *ControladorUsuario::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorUsuario();
    }
    return instance;
}

bool ControladorUsuario::altaCliente(String nickname, String contrasena, String nombre, String email, String apellido, String documento)
{
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    bool ok = manejadorUsuario->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    return ok;
}

bool ControladorUsuario::altaPropietario(String nickname, String contrasena, String nombre, String email, String cuentaBancaria, String telefono)
{
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    bool ok = manejadorUsuario->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    if (!ok)
    {
        return false;
    }

    this->p = manejadorUsuario->getPropietario(nickname);

    return true;
}

bool ControladorUsuario::altaInmobiliaria(String nickname, String contrasena, String nombre, String email, String direccion, String url, String telefono)
{
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    bool ok = manejadorUsuario->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    if (!ok)
    {
        return false;
    }

    this->i = manejadorUsuario->getInmobiliaria(nickname);

    return true;
}

void ControladorUsuario::altaCasa(String direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho tech)
{
    ManejadorInmueble *manejadorInmueble = ManejadorInmueble::getInstance();

    manejadorInmueble->altaCasa(direccion, numeroPuerta, superficie, anoConstruccion, esPH, tech);

    Inmueble *casa = manejadorInmueble->getUltimoInmueble();

    this->p->agregarInmueble(casa);
}

void ControladorUsuario::altaApartamento(String direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
{
    ManejadorInmueble *manejadorInmueble = ManejadorInmueble::getInstance();

    manejadorInmueble->altaApartamento(direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);

    Inmueble *apartamento = manejadorInmueble->getUltimoInmueble();

    this->p->agregarInmueble(apartamento);
}

SetDTUsuario ControladorUsuario::listarPropietarios()
{
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    return manejadorUsuario->listarPropietarios();
}

void ControladorUsuario::representarPropietarios(String nicknamePropietario)
{
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstance();

    Propietario *p = manejadorUsuario->getPropietario(nicknamePropietario);

    this->i->representarPropietario(p);
}

void ControladorUsuario::finalizarAltaUsuario()
{
    this->i = nullptr;
    this->p = nullptr;
}

ControladorUsuario::~ControladorUsuario() {}
