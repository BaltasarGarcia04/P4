#ifndef MANEJADORINMUEBLE_H
#define MANEJADORINMUEBLE_H

#include <map>
#include <string>
#include "Clases/Inmueble.h"
#include "Dts/DTApartamento.h"
#include "Dts/DTCasa.h"
#include "Clases/Casa.h"
#include "Clases/Apartamento.h"
#include "Enums/TipoTecho.h"
#include "Tipos.h"
#include "Dts/DTInmuebleListado.h"

class Casa;
class Apartamento;
class ManejadorInmueble
{
private:
    static ManejadorInmueble *instancia;
    int UltimoCodigoInmueble;
    ManejadorInmueble();
    SetInmueble Casas;
    SetInmueble Apartamentos;
    SetInmueble inmuebles;

public:
    static ManejadorInmueble *getInstance();

    Inmueble *getUltimoInmueble();
    SetDTInmuebleListado listarInmuebles();

    void altaCasa(String direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
    void altaApartamento(String direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);

    Inmueble *getInmueble(int cod);

    void quitarInmueble(Inmueble *Inmueble);
    SetInmueble &getInmuebles();
    // Operaciones de coleccion
    Inmueble *findInmueble(int codigoInmueble);
    //
    ~ManejadorInmueble();
};

#endif
