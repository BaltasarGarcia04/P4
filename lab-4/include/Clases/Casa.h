#ifndef CASA_H
#define CASA_H
#include "Clases/Inmueble.h"
#include "Dts/DTCasa.h"
#include "Enums/TipoTecho.h"

class Casa : public Inmueble
{
private:
    bool esPH;
    TipoTecho techo;

public:
    Casa(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo);
    DTInmueble* getDT() override;
    bool getesPH();
    TipoInmueble getTipoInmueble() override;
    TipoTecho getTipoTecho();
    ~Casa();
};

#endif
