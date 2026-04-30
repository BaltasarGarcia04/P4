#include "Clases/Inmobiliaria.h"
#include "Clases/AdministraPropiedad.h"
#include <stdexcept>

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email,
                           std::string direccion, std::string url, std::string telefono) : Usuario(nickname, contrasena, nombre, email), direccion(direccion), url(url), telefono(telefono)
{
}

DTInmobiliaria *Inmobiliaria::getDT()
{
    return new DTInmobiliaria(this->getNombre(), this->getNickname(), direccion, url, telefono);
}

std::string Inmobiliaria::getDireccion()
{
    return direccion;
}

std::string Inmobiliaria::getUrl()
{
    return url;
}

std::string Inmobiliaria::getTelefono()
{
    return telefono;
}

std::set<AdministraPropiedad *> Inmobiliaria::getPropiedadesAdministradas()
{
    return AdministraPropiedades;
}

SetPropietario Inmobiliaria::getsetpropietariosrepresentados()
{
    return propietariosRepresentados;
}

void Inmobiliaria::agregarAdministraPropiedad(AdministraPropiedad *ap)
{
    AdministraPropiedades.insert(ap);
}

void Inmobiliaria::eliminarAdministracion(AdministraPropiedad *ap)
{
    std::set<AdministraPropiedad *>::iterator it = AdministraPropiedades.begin();
    for (; it != AdministraPropiedades.end(); ++it)
    {
        if (*it == ap)
        {
            AdministraPropiedades.erase(it);
        }
    }
}

AdministraPropiedad *Inmobiliaria::getAp(int codigoInmueble)
{
    AdministraPropiedad *res;
    for (std::set<AdministraPropiedad *>::iterator it = AdministraPropiedades.begin(); it != AdministraPropiedades.end(); ++it)
    {
        AdministraPropiedad *current = *it;
        int in = current->getCodigoInmueble();
        if (in == codigoInmueble)
        {
            res = current;
        }
    }
    return res;
}

void Inmobiliaria::representarPropietario(Propietario *p)
{
    this->propietariosRepresentados[p->getNickname()] = p;
    p->agregarInmobiliaria(this);
}

// hay que implementarlas no se la logica de Suscriptor
void Inmobiliaria::agregarSuscriptor(Suscriptor *sub)
{
    Usuario *u = dynamic_cast<Usuario *>(sub);

    if (u == nullptr)
    {
        throw std::runtime_error("El suscriptor no es un Usuario válido.");
    }

    String nicknameSuscriptor = u->getNickname();

    if (this->suscriptores.count(nicknameSuscriptor) == 0)
    {
        this->suscriptores[nicknameSuscriptor] = sub;
    }
}

bool Inmobiliaria::esSuscriptor(Suscriptor *sus)
{
    Usuario *u = dynamic_cast<Usuario *>(sus);

    if (u == nullptr)
    {
        throw std::runtime_error("El suscriptor no es un Usuario válido.");
    }

    String nicknameSuscriptor = u->getNickname();

    if (this->suscriptores.count(nicknameSuscriptor) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Inmobiliaria::notificar(DTNotificacion *dtNotificacion)
{
    for (SetSuscriptores::iterator it = this->suscriptores.begin(); it != this->suscriptores.end(); ++it)
    {
        Suscriptor *suscriptor = it->second;

        suscriptor->Notificar(dtNotificacion);
    }
}

void Inmobiliaria::eliminarSuscriptor(Suscriptor *sub)
{
    Usuario *u = dynamic_cast<Usuario *>(sub);

    if (u == nullptr)
    {
        throw std::runtime_error("El suscriptor no es un Usuario válido.");
    }

    String nicknameSuscriptor = u->getNickname();

    if (this->suscriptores.count(nicknameSuscriptor) > 0)
    {
        this->suscriptores.erase(nicknameSuscriptor);
    }
}
//
Inmobiliaria::~Inmobiliaria()
{
    while (!AdministraPropiedades.empty())
    {
        AdministraPropiedad *current = *AdministraPropiedades.begin();
        AdministraPropiedades.erase(AdministraPropiedades.begin());
        current->~AdministraPropiedad();
        current = *AdministraPropiedades.begin();
    }
}
