#include "Controladores/ControladorPublicacion.h"
#include "Manejadores/ManejadorPublicacion.h"
#include "Manejadores/ManejadorUsuario.h"

ControladorPublicacion *ControladorPublicacion::instance = NULL;

ControladorPublicacion::ControladorPublicacion() {}

ControladorPublicacion *ControladorPublicacion::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorPublicacion();
    }
    return instance;
}

bool ControladorPublicacion::altaPublicacion(String nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, String texto, float precio)
{
    ManejadorUsuario *ManejadorUsuario = ManejadorUsuario::getInstance();
    Inmobiliaria *i = ManejadorUsuario->getInmobiliaria(nicknameInmobiliaria);
    AdministraPropiedad *ap = i->getAp(codigoInmueble);
    ManejadorPublicacion *manejadorPublicacion = ManejadorPublicacion::getInstance();
    Publicacion *p = manejadorPublicacion->crearPublicacion(ap, tipoPublicacion, texto, precio);
    DTFecha *fechact = ControladorFechaActual::getInstance()->getFechaActual();
    bool exitosa = p->isActiva() || (!p->isActiva() && (p->getDTFecha() == fechact));
    return exitosa;
}

SetDTPublicacion ControladorPublicacion::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)
{
    ManejadorPublicacion *ManejadorPublicacion = ManejadorPublicacion::getInstance();
    return ManejadorPublicacion->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);
}

DTInmueble *ControladorPublicacion::detalleInmueblePublicacion(int codigoPublicacion)
{
    ManejadorPublicacion *manejadorPublicacion = ManejadorPublicacion::getInstance();

    Publicacion *p = manejadorPublicacion->getPublicacion(codigoPublicacion);

    return p->getDTInmueble();
}

SetDTInmuebleAdministrado ControladorPublicacion::listarInmueblesAdministrados(String nicknameInmobiliaria)
{
    ManejadorUsuario *ManejadorUsuario = ManejadorUsuario::getInstance();
    return ManejadorUsuario->listarInmueblesAdministrados(nicknameInmobiliaria);
}

SetDTInmuebleListado ControladorPublicacion::listarInmueblesNoAdministradosInmobiliaria(String nicknameInmobiliaria)
{
    ManejadorUsuario *ManejadorUsuario = ManejadorUsuario::getInstance();
    return ManejadorUsuario->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
}

SetDTUsuario ControladorPublicacion::listarInmobiliarias()
{
    ManejadorUsuario *ManejadorUsuario = ManejadorUsuario::getInstance();
    return ManejadorUsuario->listarInmobiliarias();
}

void ControladorPublicacion::altaAdministraPropiedad(String nicknameInmobiliaria, int codigoInmueble)
{
    ManejadorUsuario *ManejadorUsuario = ManejadorUsuario::getInstance();
    ManejadorInmueble *ManejadorInmueble = ManejadorInmueble::getInstance();
    DTFecha *fechact = ControladorFechaActual::getInstance()->getFechaActual();
    Inmobiliaria *i = ManejadorUsuario->getInmobiliaria(nicknameInmobiliaria);
    Inmueble *in = ManejadorInmueble->findInmueble(codigoInmueble);
    AdministraPropiedad *ap = new AdministraPropiedad(fechact, in, i);
    i->agregarAdministraPropiedad(ap);
    // falta agregar el ap a la coleccion de aps y asociarAdministracionPropiedad(ap)
}

ControladorPublicacion::~ControladorPublicacion()
{
}
