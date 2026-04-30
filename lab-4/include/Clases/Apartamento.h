#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Clases/Inmueble.h"
#include"Dts/DTApartamento.h"

class Apartamento : public Inmueble
{
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;
public:
    Apartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes);
    DTInmueble* getDT() override;
    int getPiso();
    TipoInmueble getTipoInmueble() override;
    bool gettieneAscensor();
    float getgastosComunes();
    ~Apartamento();
};

#endif
