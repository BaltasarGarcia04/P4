#include "Clases/AdministraPropiedad.h"

AdministraPropiedad::AdministraPropiedad(DTFecha *fecha, Inmueble *Inmueble, Inmobiliaria *Inmobiliaria)
    : fecha(fecha), inmueble(Inmueble), inmobiliaria(Inmobiliaria)
{
    activas[0] = NULL;
    activas[1] = NULL;
}

DTFecha *AdministraPropiedad::getDTfecha()
{
    return fecha;
}

TipoInmueble AdministraPropiedad::getTipoinmueble()
{
    return inmueble->getTipoInmueble();
}

std::string AdministraPropiedad::getNicknameInmobiliaria()
{
    return inmobiliaria->getNickname();
}

String AdministraPropiedad::getNombreInmobiliaria()
{
    return this->inmobiliaria->getNombre();
}

int AdministraPropiedad::getCodigoInmueble()
{
    return inmueble->getcodigo();
}

std::string AdministraPropiedad::getDireccionInmobiliaria()
{
    return inmobiliaria->getDireccion();
}

std::string AdministraPropiedad::getDireccionInmueble()
{
    return inmueble->getDireccion();
}

DTInmueble *AdministraPropiedad::getDTInmueble()
{
    return this->inmueble->getDT();
}

void AdministraPropiedad::agregarPublicacion(Publicacion *p)
{
    // DTFecha *fechact = ControladorFechaActual::getInstance()->getFechaActual();
    TipoPublicacion tipo = p->getTipoPublicacion();
    int celda = (tipo == Venta) ? 1 : 0;
    if (!p->isActiva())
    {
        inactivas.insert(p);
    }
    else if (activas[celda] == NULL)
    {
        activas[celda] = p;
    }
    else if (p->getDTFecha() <= activas[celda]->getDTFecha())
    {
        p->setInActiva();
        inactivas.insert(p);
    }
    else
    {
        activas[celda]->setInActiva();
        inactivas.insert(activas[celda]);
        activas[celda] = p;
    }
}

void AdministraPropiedad::eliminarPublicacion(Publicacion *p)
{
    if (!p->isActiva())
    {
        inactivas.erase(p);
    }
    else
    {
        int celda = (p->getTipoPublicacion() == Venta) ? 1 : 0;
        activas[celda] = NULL;
    }
}

bool AdministraPropiedad::existePublicacionActiva(DTFecha *Fecha, TipoPublicacion tipoPublicacion)
{
    int celda = (tipoPublicacion == Venta) ? 1 : 0;
    Publicacion *res = NULL;
    if (activas[celda]->getDTFecha() == Fecha)
    {
        res = activas[celda];
    }
    return (res == NULL) ? false : true;
}

Publicacion *AdministraPropiedad::getPublicacionActiva(TipoPublicacion tipoPublicacion)
{
    int celda = (tipoPublicacion == Venta) ? 1 : 0;
    return activas[celda];
}

DTPublicacion AdministraPropiedad::getDTPublicacionActiva(TipoPublicacion tipoPublicacion)
{
    int celda = (tipoPublicacion == Venta) ? 1 : 0;
    int num = activas[celda]->getCodigo();
    DTPublicacion dt(num, activas[celda]->getDTFecha(), activas[celda]->getTextoPublicacion(), activas[celda]->getPrecio(), inmobiliaria->getNickname());
    return dt;
}

AdministraPropiedad::~AdministraPropiedad() {}
