#include "Clases/Inmueble.h"

Inmueble::Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoconstruccion) : codigo(codigo), direccion(direccion), numeroPuerta(numeroPuerta), superficie(superficie), anoConstruccion(anoconstruccion) {}

int Inmueble::getcodigo()
{
    return codigo;
}

std::string Inmueble::getDireccion()
{
    return direccion;
}

std::string Inmueble::getNicknamePropietario()
{
    return p->getNickname();
}

int Inmueble::getnumeroPuerta()
{
    return numeroPuerta;
}

int Inmueble::getsuperficie()
{
    return superficie;
}

int Inmueble::getanoConstruccion()
{
    return anoConstruccion;
}

std::string Inmueble::getnicknamepropietario()
{
    return p->getNickname();
}

void Inmueble::agregarDuenio(Propietario *p_)
{
    this->p = p_;
}

Inmueble::~Inmueble()
{
}
