#ifndef _MECANISMO_AGARRE_H
#define _MECANISMO_AGARRE_H
#include "_gancho.h"
#include "cable_polea.h"

typedef enum{SUBIDA, BAJADA, GIROD, GIROI, QUIETO} _movimientos;

class _mecanismo_agarre
{
private:
    _gancho gancho_polea;
    _cable_polea polea_gancho;
    double posicion;
    void animacion_gancho(_tipo tipo, double translado);
    void animacion_ganchoD(_tipo tipo);
    void animacion_ganchoI(_tipo tipo);
    void posicion_cable_polea(_tipo tipo);

public:
    _mecanismo_agarre();
    void draw_mecanismo_agarre(_tipo tipo);
    void animacion_mecanismo(_tipo tipo, _movimientos movimiento);
    _cable_polea Polea_gancho();
};

#endif // _MECANISMO_AGARRE_H
