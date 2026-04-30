#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "Dts/DTFecha.h"
#include "Enums/TipoPublicacion.h"
#include <string>
#include <map>
#include "AdministraPropiedad.h"
#include "Tipos.h"

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;
    AdministraPropiedad* ap;
public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, std::string texto, float precio, bool activa);
    int getCodigo();
    DTFecha* getDTFecha();
    TipoPublicacion getTipoPublicacion();
    std::string getTextoPublicacion();
    std::string getNicknameInmobiliaria();
    TipoInmueble getTipoInmueble();
    DTPublicacion* getDTPublicacion();
    DTInmueble* getDTInmueble();
    float getPrecio();
    bool isActiva();
    void setActiva();
    void setInActiva();
    ~Publicacion();
};

#endif
