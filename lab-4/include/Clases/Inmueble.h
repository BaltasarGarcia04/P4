#ifndef INMUEBLE_H
#define INMUEBLE_H
#include <string>
#include <map>
#include "Enums/TipoInmueble.h"
#include "Clases/Propietario.h"
#include "Dts/DTInmueble.h"
#include "Tipos.h"

class Inmueble
{
protected:
    int codigo;
    std::string direccion;
    int numeroPuerta;
    int superficie;
    int anoConstruccion;
    Propietario *p;

public:
    Inmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion);
    void agregarDuenio(Propietario *p_);
    virtual DTInmueble *getDT() = 0;
    int getcodigo();
    std::string getDireccion();
    std::string getNicknamePropietario();
    int getnumeroPuerta();
    int getsuperficie();
    int getanoConstruccion();
    std::string getnicknamepropietario();
    virtual TipoInmueble getTipoInmueble() = 0;
    virtual ~Inmueble();
};
#endif
