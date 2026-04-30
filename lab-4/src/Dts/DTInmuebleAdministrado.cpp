#include "Dts/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha *fechaComienzo) : codigo(codigo), direccion(direccion), fechaComienzo(fechaComienzo)
{
}

int DTInmuebleAdministrado::getCodigo()
{
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion()
{
    return direccion;
}

DTFecha *DTInmuebleAdministrado::getFechaComienzo()
{
    return fechaComienzo;
}

DTInmuebleAdministrado::~DTInmuebleAdministrado()
{
    delete fechaComienzo;
}