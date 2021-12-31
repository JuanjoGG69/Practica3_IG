#ifndef _CARGA_PLUMA_H
#define _CARGA_PLUMA_H
#include "carga.h"
#include "_pluma.h"
#include "_cable.h"


class _carga_pluma
{
private:
    _carga carga;
    _pluma pluma;
    _cable cable;
    double angulo;
    void animacion_drcha(_tipo tipo);
    void animacion_izqda(_tipo tipo);

public:
    _carga_pluma();
    void draw_carga_pluma(_tipo tipo);
    void animacion_carga_pluma(_tipo tipo, _giro giro);
    double Angulo();
};

#endif // _CARGA_PLUMA_H
