#include "Clases/Publicacion.h"
#include "Controladores/ControladorFechaActual.h"

Publicacion::Publicacion(int codigo, DTFecha *fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa) : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa)
{
}

int Publicacion::getCodigo()
{
    return codigo;
}

DTFecha *Publicacion::getDTFecha()
{
    return fecha;
}

TipoPublicacion Publicacion::getTipoPublicacion()
{
    return tipo;
}

std::string Publicacion::getTextoPublicacion()
{
    return texto;
}

float Publicacion::getPrecio()
{
    return precio;
}

bool Publicacion::isActiva()
{
    return activa == true;
}

void Publicacion::setActiva()
{
    this->activa = true;
}

void Publicacion::setInActiva()
{
    this->activa = false;
}

TipoInmueble Publicacion::getTipoInmueble()
{
    return this->ap->getTipoinmueble();
}
std::string Publicacion::getNicknameInmobiliaria()
{
    return ap->getNicknameInmobiliaria();
}

DTPublicacion *Publicacion::getDTPublicacion()
{

    // Declaracion parámetros para crear DTPublicacion.
    int p_codigo;
    DTFecha *p_fecha;
    String p_texto;
    float p_precio;
    String p_nombreInmobiliaria;

    // Asignación a parámetros para crear DTPublicacion.
    p_codigo = this->codigo;
    p_fecha = this->fecha;
    p_texto = this->texto;
    p_precio = this->precio;
    p_nombreInmobiliaria = this->ap->getNombreInmobiliaria();

    // Creo DTPublicacion.
    DTPublicacion *dtp = new DTPublicacion(p_codigo, p_fecha, p_texto, p_precio, p_nombreInmobiliaria);

    // Retorno puntero a dtp.
    return dtp;
}

DTInmueble *Publicacion::getDTInmueble()
{
    return this->ap->getDTInmueble();
}

Publicacion::~Publicacion()
{
    delete this->fecha;
}
