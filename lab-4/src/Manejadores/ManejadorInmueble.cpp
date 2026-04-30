#include "Manejadores/ManejadorInmueble.h"
#include "Clases/Casa.h"
#include "Clases/Apartamento.h"
#include "Clases/Inmueble.h"

ManejadorInmueble *ManejadorInmueble::instancia = nullptr;

ManejadorInmueble::ManejadorInmueble()
{
    UltimoCodigoInmueble = 0;
}

ManejadorInmueble *ManejadorInmueble::getInstance()
{
    if (instancia == nullptr)
    {
        instancia = new ManejadorInmueble();
    }
    return instancia;
}

Inmueble *ManejadorInmueble::getUltimoInmueble()
{
    return inmuebles[UltimoCodigoInmueble];
}

void ManejadorInmueble::altaCasa(String direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)
{
    int codigo = ++UltimoCodigoInmueble;
    Inmueble *nueva = new Casa(codigo, direccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
    Casas[codigo] = nueva;
    inmuebles[codigo] = nueva;
}

void ManejadorInmueble::altaApartamento(std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)
{
    int codigo = ++UltimoCodigoInmueble;
    Inmueble *nuevo = new ::Apartamento(codigo, direccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
    Apartamentos[codigo] = nuevo;
    inmuebles[codigo] = nuevo;
}

void ManejadorInmueble::quitarInmueble(Inmueble *Inmueble)
{
    int codigo = Inmueble->getcodigo();
    TipoInmueble tipo = Inmueble->getTipoInmueble();
    if (tipo == TipoInmueble::Casa)
    {
        Casas.erase(codigo);
    }
    else if (tipo == TipoInmueble::Apartamento)
    {
        Apartamentos.erase(codigo);
    }
    inmuebles.erase(codigo);
}

SetInmueble &ManejadorInmueble::getInmuebles()
{
    return inmuebles;
}

Inmueble *ManejadorInmueble::findInmueble(int codigoInmueble)
{
    return inmuebles[codigoInmueble];
}




SetDTInmuebleListado ManejadorInmueble::listarInmuebles()
{
    SetDTInmuebleListado dtil;
    SetInmueble::iterator it;
    for (it = inmuebles.begin(); it != inmuebles.end(); it++)
    {
        Inmueble *in = it->second;
        DTInmuebleListado *il = new DTInmuebleListado(in->getcodigo(), in->getDireccion(), in->getnicknamepropietario());
        dtil.insert(il);
    }
    return dtil;
}

ManejadorInmueble::~ManejadorInmueble()
{
    for (SetInmueble::iterator it = inmuebles.begin(); it != inmuebles.end(); ++it)
    {
        delete it->second;
    }
    inmuebles.clear();
    Casas.clear();
    Apartamentos.clear();
}