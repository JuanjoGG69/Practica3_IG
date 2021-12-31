#ifndef _SOPORTE_H
#define _SOPORTE_H
#include "rueda.h"
#include "object3d.h"
#include "_base.h"

class _soporte
{
private:
    _rueda ruedas;
    _base base;
    void animacion_ruedas_drcha(_tipo tipo);
    void animacion_ruedas_izqda(_tipo tipo);

public:
    _soporte();
    void draw_soporte(_tipo tipo);
    void animacion_giro(_tipo tipo, _giro giro);
    _rueda Ruedas();

};

#endif // _SOPORTE_H
