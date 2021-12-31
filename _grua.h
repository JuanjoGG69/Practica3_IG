#ifndef _GRUA_H
#define _GRUA_H
#include "_carga_pluma.h"
#include "_mecanismo_agarre.h"
#include "_soporte_torre.h"

typedef enum{BJDA, SBDA, GIROIZQDAG, GIRODRCHG, GIROIZQDAP, GIRODRCHAP, GIROIZQDAR, GIRODRCHAR} _movs;
class _grua
{
private:
    _mecanismo_agarre gancho_util;
    _carga_pluma pluma_util;
    _soporte_torre torre_util;
    double posicion;

public:
    _grua();
    void draw_grua(_tipo tipo);
    void animacion_grua(_tipo tipo, _movs movs);
    void animacion_gancho_util(_tipo tipo, double translado, _movimientos movi);
};

#endif // _GRUA_H
