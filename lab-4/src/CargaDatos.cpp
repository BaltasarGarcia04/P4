#include "CargaDatos.h"
#include <cstddef>
#include "Factory/Factory.h"

CargaDatos *CargaDatos::instance = NULL;

CargaDatos::CargaDatos()
{
    IAltaDeUsuario *user = Factory::getInstance()->getControladorUsuario();
    IAltaPublicacion *publi = Factory::getInstance()->getControladorPublicacion();
    IControladorFechaActual *fechaactual = Factory::getInstance()->getControladorFechaActual();
    IAltaDeAdministracionDePropiedad *admin = Factory::getInstance()->getControladorPublicacionAP();
    ISuscribirseANotificaciones *sus = Factory::getInstance()->getControladorSuscripcionesSuscribirse();

    user->altaCliente("luisito23", "qweasd12", "Luis", "luisito23@gmail.com", "Pérez", "46859342");
    user->finalizarAltaUsuario();

    user->altaCliente("anarojo88", "claveAna1", "Ana", "anarojo88@hotmail.com", "Rojo", "31287465");
    user->finalizarAltaUsuario();

    user->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "99876543", "123456789012");
    user->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
    user->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
    user->finalizarAltaUsuario();

    user->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "91234567", "987654321001");
    user->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
    user->finalizarAltaUsuario();

    user->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "92345678", "654321987654");
    user->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
    user->finalizarAltaUsuario();

    user->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "98765432", "321098765432");
    user->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
    user->finalizarAltaUsuario();

    user->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "97654321", "890123456789");
    user->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
    user->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
    user->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
    user->finalizarAltaUsuario();

    user->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com", "Canelones 2345", "https://casasur.com.uy", "24012345");
    user->representarPropietarios("marcelom");
    user->representarPropietarios("jorge88");
    user->finalizarAltaUsuario();

    user->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890", "https://vivaurbana.com", "29109876");
    user->representarPropietarios("robertarce");
    user->representarPropietarios("soledadf");
    user->finalizarAltaUsuario();

    user->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy", "Av. Italia 4567", "https://idealhome.uy", "99123456");
    user->representarPropietarios("marcelom");
    user->representarPropietarios("martagal");
    user->representarPropietarios("jorge88");
    user->finalizarAltaUsuario();

    // Asignación de administraciones
    fechaactual->setNewFechaActual(12, 12, 2015);
    admin->altaAdministraPropiedad("casasur123", 2);

    fechaactual->setNewFechaActual(25, 9, 2023);
    admin->altaAdministraPropiedad("idealhome", 1);

    fechaactual->setNewFechaActual(20, 7, 2022);
    admin->altaAdministraPropiedad("vivaurbana", 3);

    fechaactual->setNewFechaActual(1, 1, 2022);
    admin->altaAdministraPropiedad("vivaurbana", 4);

    fechaactual->setNewFechaActual(3, 7, 2010);
    admin->altaAdministraPropiedad("idealhome", 5);

    fechaactual->setNewFechaActual(4, 11, 2019);
    admin->altaAdministraPropiedad("casasur123", 6);

    fechaactual->setNewFechaActual(19, 5, 2020);
    admin->altaAdministraPropiedad("vivaurbana", 6);

    fechaactual->setNewFechaActual(19, 7, 2024);
    admin->altaAdministraPropiedad("idealhome", 6);

    fechaactual->setNewFechaActual(18, 9, 2023);
    admin->altaAdministraPropiedad("idealhome", 7);

    fechaactual->setNewFechaActual(19, 5, 2022);
    admin->altaAdministraPropiedad("vivaurbana", 8);

    // Publicaciones
    fechaactual->setNewFechaActual(9, 10, 2011);
    publi->altaPublicacion("idealhome", 5, Venta, "...", 47000);

    fechaactual->setNewFechaActual(15, 1, 2016);
    publi->altaPublicacion("casasur123", 2, Alquiler, "...", 28000);

    fechaactual->setNewFechaActual(5, 3, 2019);
    publi->altaPublicacion("casasur123", 2, Alquiler, "...", 29500);

    fechaactual->setNewFechaActual(3, 4, 2019);
    publi->altaPublicacion("idealhome", 5, Alquiler, "...", 38500);

    fechaactual->setNewFechaActual(12, 12, 2019);
    publi->altaPublicacion("casasur123", 6, Venta, "...", 375000);

    fechaactual->setNewFechaActual(12, 6, 2020);
    publi->altaPublicacion("casasur123", 2, Venta, "...", 390000);

    fechaactual->setNewFechaActual(20, 7, 2020);
    publi->altaPublicacion("vivaurbana", 6, Alquiler, "...", 23000);

    fechaactual->setNewFechaActual(4, 3, 2022);
    publi->altaPublicacion("vivaurbana", 4, Alquiler, "...", 26000);

    fechaactual->setNewFechaActual(12, 9, 2022);
    publi->altaPublicacion("vivaurbana", 3, Alquiler, "...", 27000);

    fechaactual->setNewFechaActual(1, 10, 2023);
    publi->altaPublicacion("idealhome", 1, Venta, "...", 520000);

    fechaactual->setNewFechaActual(18, 10, 2023);
    publi->altaPublicacion("idealhome", 7, Alquiler, "...", 32000);

    fechaactual->setNewFechaActual(19, 10, 2023);
    publi->altaPublicacion("idealhome", 7, Venta, "...", 455000);

    fechaactual->setNewFechaActual(20, 11, 2023);
    publi->altaPublicacion("idealhome", 7, Alquiler, "...", 31000);

    fechaactual->setNewFechaActual(20, 11, 2023);
    publi->altaPublicacion("idealhome", 7, Venta, "...", 450000);

    fechaactual->setNewFechaActual(8, 3, 2024);
    publi->altaPublicacion("vivaurbana", 3, Venta, "...", 430000);

    fechaactual->setNewFechaActual(5, 5, 2024);
    publi->altaPublicacion("idealhome", 7, Alquiler, "...", 33000);

    fechaactual->setNewFechaActual(1, 8, 2024);
    publi->altaPublicacion("idealhome", 6, Venta, "...", 400000);

    // Suscripciones
    sus->suscribirAInmobiliaria("luisito23", {"idealhome", "casasur123"});
    sus->suscribirAInmobiliaria("anarojo88", {"casasur123", "idealhome", "vivaurbana"});
    sus->suscribirAInmobiliaria("marcelom", {"idealhome"});
    sus->suscribirAInmobiliaria("robertarce", {"idealhome"});
    sus->suscribirAInmobiliaria("soledadf", {"vivaurbana"});
    sus->suscribirAInmobiliaria("martagal", {"vivaurbana"});
    sus->suscribirAInmobiliaria("jorge88", {"casasur123", "idealhome", "vivaurbana"});
}


CargaDatos *CargaDatos::getInstance()
{
    if (instance == 0)
    {
        instance = new CargaDatos();
    }
    return instance;
}