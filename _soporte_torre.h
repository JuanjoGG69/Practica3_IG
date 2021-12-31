#ifndef _SOPORTE_TORRE_H
#define _SOPORTE_TORRE_H
#include "_soporte.h"
#include "torre.h"

class _soporte_torre
{
private:
    _soporte soporte;
    _torre torre;

public:
    _soporte_torre();
    void draw_soporte_torre(_tipo tipo);
    void animacion_giro(_tipo tipo, _giro giro);
    _soporte Soporte();
};

#endif // _SOPORTE_TORRE_H
