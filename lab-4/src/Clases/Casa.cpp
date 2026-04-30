#include "Clases/Casa.h"

Casa::Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)
    : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion), esPH(esPH), techo(techo) {}

bool Casa::getesPH()
{
    return esPH;
}

TipoTecho Casa::getTipoTecho()
{
    return techo;
}

TipoInmueble Casa::getTipoInmueble()
{
    return TipoInmueble::Casa;
}

DTInmueble* Casa::getDT() {
    return new DTCasa(this->codigo, this->direccion, this->numeroPuerta, this->superficie, this->anoConstruccion, this->esPH, this->techo);
}

Casa::~Casa()
{
}
