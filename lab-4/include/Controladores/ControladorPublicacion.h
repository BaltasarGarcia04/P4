#ifndef CONTROLADORPUBLICACION_H
#define CONTROLADORPUBLICACION_H

#include "Enums/TipoPublicacion.h"
#include "Enums/TipoInmueble.h"
#include "Dts/DTPublicacion.h"
#include "Dts/DTUsuario.h"
#include "Dts/DTInmuebleAdministrado.h"
#include <string>
#include <set>
#include "Manejadores/ManejadorUsuario.h"
#include "Manejadores/ManejadorPublicacion.h"
#include "Manejadores/ManejadorInmueble.h"
#include "Interfaces/IConsultaDePublicacion.h"
#include "Interfaces/IAltaPublicacion.h"
#include "Interfaces/IAltaDeAdministracioDePropiedad.h"
#include "Tipos.h"

class ControladorPublicacion : public IConsultaDePublicacion, public IAltaPublicacion, public IAltaDeAdministracionDePropiedad
{
private:
    static ControladorPublicacion *instance;
    ControladorPublicacion();

public:
    static ControladorPublicacion *getInstance();

        bool altaPublicacion(String nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, String texto, float precio) override;
        
        SetDTUsuario listarInmobiliarias() override;
        void altaAdministraPropiedad(String nicknameInmobiliaria, int codigoInmueble);
        SetDTInmuebleAdministrado listarInmueblesAdministrados(String nicknameInmobiliaria);
        SetDTInmuebleListado listarInmueblesNoAdministradosInmobiliaria(String nicknameInmobiliaria);
        SetDTPublicacion listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) override;
        DTInmueble* detalleInmueblePublicacion(int codigoPublicacion) override;

    // Añadir override a listarInmueblesNoAdministrados y altaAdministraPropiedad cuando se añada , public <interfaz de esos dos metodos>.

    ~ControladorPublicacion();
};

#endif
