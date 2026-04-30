#include "Clases/Apartamento.h"

Apartamento::Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion,
                         int piso, bool tieneAscensor, float gastosComunes) : Inmueble(codigo, direccion, numeroPuerta, superficie, anoConstruccion),
                                                                              piso(piso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes) {

                                                                              };

int Apartamento::getPiso()
{
    return piso;
};

bool Apartamento::gettieneAscensor()
{
    return tieneAscensor;
}

float Apartamento::getgastosComunes()
{
    return gastosComunes;
};

DTInmueble *Apartamento::getDT()
{
    return new DTApartamento(this->codigo, this->direccion, this->numeroPuerta, this->superficie, this->anoConstruccion, this->piso, this->tieneAscensor, this->gastosComunes);
}

TipoInmueble Apartamento::getTipoInmueble()
{
    return TipoInmueble::Apartamento;
}

Apartamento::~Apartamento() {

};
