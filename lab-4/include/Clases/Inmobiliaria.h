#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Clases/Usuario.h"
#include "Clases/Suscriptor.h"
#include "Clases/Propietario.h"
#include "Dts/DTInmobiliaria.h"
#include "Tipos.h"
#include <string>
#include <set>
#include <map>

class Inmobiliaria : public Usuario
{
private:
    std::string direccion;
    std::string url;
    std::string telefono;
    std::set<AdministraPropiedad *> AdministraPropiedades;
    SetSuscriptores suscriptores;
    SetPropietario propietariosRepresentados;
public:
    Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                 std::string direccion, std::string url, std::string telefono);
    void agregarAdministraPropiedad(AdministraPropiedad *ap);
    void eliminarAdministracion(AdministraPropiedad *ap);

    // Inicio - GETTERS
    DTInmobiliaria* getDT();
    std::string getDireccion();
    std::string getUrl();
    std::string getTelefono();
    // Fin - GETTERS

    // Inicio - Metodos de suscriptor (Observer)
    void agregarSuscriptor(Suscriptor *sub);
    bool esSuscriptor(Suscriptor *sus);
    void notificar(DTNotificacion *dtNotificacion);
    void eliminarSuscriptor(Suscriptor *sub);
    // Fin - Metodos de suscriptor (Observer)

    void representarPropietario(Propietario* p);

    // que hacemos con esto
    SetPropietario getsetpropietariosrepresentados();
    std::set<AdministraPropiedad *> getPropiedadesAdministradas();
    AdministraPropiedad *getAp(int codigoInmueble);
    ~Inmobiliaria();
};

#endif
