#include "Manejadores/ManejadorPublicacion.h"


ManejadorPublicacion* ManejadorPublicacion::instancia = nullptr;

ManejadorPublicacion::ManejadorPublicacion(){
    codigoUltimaPublicacion = 0;
}

void ManejadorPublicacion::incrementarCodigoUltimaPublicacion(){
    codigoUltimaPublicacion++;
}

int ManejadorPublicacion::getCodigoUltimaPublicacion(){
    return codigoUltimaPublicacion;
}

ManejadorPublicacion * ManejadorPublicacion::getInstance(){
    if (instancia == nullptr){
        instancia = new ManejadorPublicacion();
    }
    return instancia;
}


Publicacion* ManejadorPublicacion::crearPublicacion(AdministraPropiedad* ap, TipoPublicacion tipoPublicacion, std::string texto, float precio){
    DTFecha* fechact = ControladorFechaActual::getInstance()->getFechaActual();
    int codigoUltima = getCodigoUltimaPublicacion();
    codigoUltima++;
    Publicacion* p = new Publicacion(codigoUltima,fechact,tipoPublicacion,texto,precio,true);

    ap->agregarPublicacion(p);
    publicaciones.insert({codigoUltima,p});
    incrementarCodigoUltimaPublicacion();
    return p;
    
}


SetDTPublicacion ManejadorPublicacion::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble){
    SetDTPublicacion SetDTp;
    std::map<int,Publicacion*>::iterator it;
    for(it = publicaciones.begin(); it != publicaciones.end(); it++){
        if(it->second->getTipoPublicacion() == tipoPublicacion && it->second->getPrecio() >= precioMinimo && it->second->getPrecio() <= precioMaximo){
            Publicacion* p = it->second;
            DTPublicacion* dtp = new DTPublicacion(p->getCodigo(),p->getDTFecha(),
                                                    p->getTextoPublicacion(),p->getPrecio(),p->getNicknameInmobiliaria());
            SetDTp.insert(dtp);
        }
    }
    return SetDTp; 
}

SetDTUsuario ManejadorPublicacion::listarInmobiliarias(){
    ManejadorUsuario* ManejadorUsuario = ManejadorUsuario::getInstance();
    return ManejadorUsuario->listarInmobiliarias();
}

Publicacion* ManejadorPublicacion::getPublicacion(int codigoPublicacion){
    return publicaciones[codigoPublicacion];
}

ManejadorPublicacion::~ManejadorPublicacion(){
    SetPublicacion::iterator it;
    for(it = publicaciones.begin();it!=publicaciones.end();++it){
        delete it->second;
    }
    publicaciones.clear();
}