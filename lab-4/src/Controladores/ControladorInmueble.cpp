#include "Controladores/ControladorInmueble.h"
#include "Manejadores/ManejadorInmueble.h"

ControladorInmueble *ControladorInmueble::instance = nullptr;

ControladorInmueble::ControladorInmueble() {}

ControladorInmueble *ControladorInmueble::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorInmueble();
    }
    return instance;
}

SetDTInmuebleListado ControladorInmueble::listarInmuebles()
{
    ManejadorInmueble *ManejadorInmueble = ManejadorInmueble::getInstance();
    return ManejadorInmueble->listarInmuebles();
}

DTInmueble *ControladorInmueble::detalleInmueble(int codigoInmueble)
{
    ManejadorInmueble *ManejadorInmueble = ManejadorInmueble::getInstance();
    Inmueble *inm = ManejadorInmueble->findInmueble(codigoInmueble);
    if (inm->getTipoInmueble() == TipoInmueble::Casa)
    {
        Casa *casa = static_cast<Casa *>(inm);
        return new DTCasa(casa->getcodigo(), casa->getDireccion(), casa->getnumeroPuerta(), casa->getsuperficie(), casa->getanoConstruccion(), casa->getesPH(), casa->getTipoTecho());
    }
    else
    {
        Apartamento *apartamento = static_cast<Apartamento *>(inm);
        return new DTApartamento(apartamento->getcodigo(), apartamento->getDireccion(), apartamento->getnumeroPuerta(), apartamento->getsuperficie(), apartamento->getanoConstruccion(), apartamento->getPiso(), apartamento->gettieneAscensor(), apartamento->getgastosComunes());
    }
}



void ControladorInmueble::eliminarInmueble(int codigoInmueble)
{
    ManejadorInmueble *instanciaManejador = ManejadorInmueble::getInstance();
    std::map<int, Inmueble *> &inmuebles = instanciaManejador->getInmuebles();
    instanciaManejador->quitarInmueble(inmuebles[codigoInmueble]);
    return;
}

ControladorInmueble::~ControladorInmueble() {}
