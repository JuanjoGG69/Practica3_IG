#ifndef _GANCHO_H
#define _GANCHO_H
#include "cube.h"
#include "_cono.h"
#include  "rueda.h"


class _gancho
{
private:
    _cono punta_gancho;
    _cube soporte;
    double angulo;
    void giro_drcha(_tipo tipo);
    void giro_izqda(_tipo tipo);


public:
    _gancho();
    void draw_gancho(_tipo tipo);
    void animar_gancho(_tipo tipo, _giro giro);
};

#endif // _GANCHO_H
