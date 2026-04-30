#include "Clases/Suscriptor.h"


void Suscriptor::Notificar(DTNotificacion* dt){
    notificaciones.push_back(new DTNotificacion(*dt));
}

SetDTNotificacion Suscriptor::consultarNotificaciones(){
    return notificaciones;
}

void Suscriptor::eliminarNotificaciones(){

    for (SetDTNotificacion::iterator it = this->notificaciones.begin(); it != this->notificaciones.end(); ++it) {
        DTNotificacion* dtn = *it;
        delete dtn;
    }

    notificaciones.clear();
}

Suscriptor::~Suscriptor() {
    this->eliminarNotificaciones();
}
