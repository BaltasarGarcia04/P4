#include "../include/Manejadores/ManejadorUsuario.h"
#include "../include/Manejadores/ManejadorInmueble.h"
#include "../include/Clases/Cliente.h"
#include "../include/Clases/Inmobiliaria.h"
#include "../include/Clases/Inmueble.h"
#include "../include/Clases/Propietario.h"
#include <stdexcept>

ManejadorUsuario *ManejadorUsuario::instancia = nullptr;

ManejadorUsuario::ManejadorUsuario() {}

ManejadorUsuario *ManejadorUsuario::getInstance()
{
    if (instancia == nullptr)
    {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

bool ManejadorUsuario::altaCliente(String nickname, String contrasena, String nombre, String email, String apellido, String documento)
{

    // Si la cantidad de instancias en map con nickname > 0, entonces existe en el map.
    if (this->usuarios.count(nickname) > 0)
    {
        return false;
    }

    Usuario *u = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    usuarios[nickname] = u;

    return true;
}

bool ManejadorUsuario::altaInmobiliaria(String nickname, String contrasena, String nombre, String email, String direccion, String url, String telefono)
{

    // Si la cantidad de instancias en map con nickname > 0, entonces existe en el map.
    if (this->usuarios.count(nickname) > 0)
    {
        return false;
    }

    Inmobiliaria *u = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    usuarios[nickname] = u;

    //  ¿Donde se usa esto? Podemos iterar sobre los usuarios con dynamic_cast.
    //  En caso de usarlo, se debe chequear que no exista, sino vamos a tener perdidas de memoria.
    //  Inmobiliarias[nickname] = i;

    return true;
}

bool ManejadorUsuario::altaPropietario(String nickname, String contrasena, String nombre, String email, String cuentaBancaria, String telefono)
{

    // Si la cantidad de instancias en map con nickname > 0, entonces existe en el map.
    if (this->usuarios.count(nickname) > 0)
    {
        return false;
    }

    Usuario *u = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    usuarios[nickname] = u;

    return true;
}

SetDTUsuario ManejadorUsuario::listarPropietarios()
{
    SetDTUsuario setDTU;

    for (MapUsuario::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        Usuario *u = it->second;

        // Compruebo si es Propietario.
        Propietario *p = dynamic_cast<Propietario *>(u);
        if (p != nullptr)
        {
            setDTU.insert(u->getDT());
        }
    }

    return setDTU;
}

SetDTUsuario ManejadorUsuario::listarInmobiliarias()
{
    SetDTUsuario setDTU;

    for (MapUsuario::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        Usuario *u = it->second;

        // Compruebo si es Inmobiliaria.
        Inmobiliaria *i = dynamic_cast<Inmobiliaria *>(u);
        if (i != nullptr)
        {
            setDTU.insert(u->getDT());
        }
    }

    return setDTU;
}

SetDTUsuario ManejadorUsuario::listarClientes()
{
    SetDTUsuario setDTU;

    for (MapUsuario::iterator it = this->usuarios.begin(); it != this->usuarios.end(); ++it)
    {
        Usuario *u = it->second;

        // Compruebo si es Cliente.
        Cliente *c = dynamic_cast<Cliente *>(u);
        if (c != nullptr)
        {
            setDTU.insert(u->getDT());
        }
    }

    return setDTU;
}

Propietario *ManejadorUsuario::getPropietario(String nicknamePropietario)
{

    Usuario *u = this->usuarios[nicknamePropietario];
    Propietario *p = dynamic_cast<Propietario *>(u);

    if (p == nullptr)
    {
        throw std::runtime_error("El usuario '" + nicknamePropietario + "' no es propietario.");
    }

    return p;
}

Inmobiliaria *ManejadorUsuario::getInmobiliaria(String nicknameInmobiliaria)
{
    Usuario *u = this->usuarios[nicknameInmobiliaria];
    Inmobiliaria *i = dynamic_cast<Inmobiliaria *>(u);

    if (i == nullptr)
    {
        throw std::runtime_error("El usuario '" + nicknameInmobiliaria + "' no es inmobiliaria.");
    }

    return i;
}

Cliente *ManejadorUsuario::getCliente(String nicknameCliente)
{
    Usuario *u = this->usuarios[nicknameCliente];
    Cliente *c = dynamic_cast<Cliente *>(u);

    if (c == nullptr)
    {
        throw std::runtime_error("El usuario '" + nicknameCliente + "' no es cliente.");
    }

    return c;
}

Suscriptor *ManejadorUsuario::getSuscriptor(String nicknameSuscriptor)
{
    Usuario *u = this->usuarios[nicknameSuscriptor];
    Suscriptor *s = dynamic_cast<Suscriptor *>(u);

    if (s == nullptr)
    {
        throw std::runtime_error("El usuario '" + nicknameSuscriptor + "' no es suscriptor.");
    }

    return s;
}

std::set<Inmobiliaria *> ManejadorUsuario::getInmobiliarias()
{
    return Inmobiliarias;
}

SetDTInmuebleAdministrado ManejadorUsuario::listarInmueblesAdministrados(String nicknameInmobiliaria)
{
    SetDTInmuebleAdministrado dtia;
    Inmobiliaria *i = this->getInmobiliaria(nicknameInmobiliaria);
    std::set<AdministraPropiedad *> apcolection = i->getPropiedadesAdministradas();
    std::set<AdministraPropiedad *>::iterator it;
    for (it = apcolection.begin(); it != apcolection.end(); it++)
    {
        AdministraPropiedad *ap = *it;
        // esto no se si es necesario pero esta en el dcc
            DTInmuebleAdministrado *dtin = new DTInmuebleAdministrado(ap->getCodigoInmueble(), ap->getDireccionInmobiliaria(), ap->getDTfecha());
            dtia.insert(dtin);
    }
    return dtia;
}

SetDTInmuebleListado ManejadorUsuario::listarInmueblesNoAdministradosInmobiliaria(String nicknameInmobiliaria)
{
    SetDTInmuebleListado listatotal; // No voy a seguir el dcc la idea es hacer una listatotal de Inmuebles y sacarle los que administra la inmobiliaria de nombre = nicknameInmobiliaria
    ManejadorInmueble *ManejadorInmueble = ManejadorInmueble::getInstance();
    SetInmueble::iterator it;
    for (it = ManejadorInmueble->getInmuebles().begin(); it != ManejadorInmueble->getInmuebles().end(); it++)
    {
        Inmueble *in = it->second;
        DTInmuebleListado *inlis = new DTInmuebleListado(in->getcodigo(), in->getDireccion(), in->getnicknamepropietario()); // !!! new delete
        listatotal.insert(inlis);
    }

    ManejadorUsuario *m = ManejadorUsuario::getInstance();
    std::set<Inmobiliaria *>::iterator it_ci = m->Inmobiliarias.begin();
    Inmobiliaria *i = *it_ci;
    while (it_ci != m->Inmobiliarias.end() && i->getNickname() != nicknameInmobiliaria)
    {
        it_ci++;
    };
    i = *it_ci;

    SetDTInmuebleListado::iterator it_list;
    for (it_list = listatotal.begin(); it_list != listatotal.end();)
    {
        DTInmuebleListado *current = *it_list;
        String nombre_propietario_actual = current->getPropietario();
        SetPropietario setprop;
        SetPropietario::iterator it_prop;
        for (it_prop = setprop.begin(); it_prop != setprop.end(); it_prop++)
        {
            Propietario *p = it_prop->second;
            if (p->getNickname() == nombre_propietario_actual)
            {
                it_list = listatotal.erase(it_list);
            }
        }
        if (it_list != listatotal.end())
        {
            it_list++;
        }
    }

    return listatotal;
}

/* ManejadorUsuario* m = ManejadorUsuario::getInstance();
std::set<Inmobiliaria*>::iterator it_ci = m->Inmobiliarias.begin();
Inmobiliaria* ci = *it_ci;
while(it_ci != m->Inmobiliarias.end() && ci->getNickname() != nicknameInmobiliaria){
    it_ci++;
};
ci = *it_ci;
SetPropietario::iterator it_p;
for(it_p = ci->getsetpropietariosrepresentados().begin(); it_p != ci->getsetpropietariosrepresentados().end(); it_p++){
    Propietario* p = it_p->second;
    SetInmueble Inmuebles = p->getInmuebles();
    SetInmueble::iterator it_in;
    bool administrado;
    for(it_in = Inmuebles.begin(); it_in != Inmuebles.end(); it_in++){
        Inmueble* in = it_in->second;
        std::set<AdministraPropiedad *> coleccionap = ci->getPropiedadesAdministradas();
        std::set<AdministraPropiedad *>::iterator it_ap;
        bool administra = true;
        for(it_ap = coleccionap.begin(); it_ap != coleccionap.end() && administra; it_ap++){
            AdministraPropiedad* ap = *it_ap;
            administra = ci->getAp(in->getcodigo()) == ap;
            administrado = administra;
        }

    }

}
  */

ManejadorUsuario::~ManejadorUsuario()
{
    for (MapUsuario::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
    {
        delete it->second;
    }
    usuarios.clear();

    for (std::set<Inmobiliaria *>::iterator ti = Inmobiliarias.begin(); ti != Inmobiliarias.end(); ++ti)
    {
        delete *ti;
    }
    Inmobiliarias.clear();
}
