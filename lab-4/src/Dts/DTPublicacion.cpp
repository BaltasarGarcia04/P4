#include "Dts/DTPublicacion.h"

DTPublicacion::DTPublicacion(int codigo, DTFecha *fecha, std::string texto, float precio, std::string inmobiliaria) : codigo(codigo), texto(texto), precio(precio), inmobiliaria(inmobiliaria)
{
}

int DTPublicacion::getCodigo()
{
    return codigo;
}

DTFecha *DTPublicacion::getFecha()
{
    return fecha;
}

std::string DTPublicacion::getTexto()
{
    return texto;
}

float DTPublicacion::getPrecio()
{
    return precio;
}

std::string DTPublicacion::getInmobiliaria()
{
    return inmobiliaria;
}

DTPublicacion::~DTPublicacion()
{
    delete fecha;
}