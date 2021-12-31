#ifndef CABLE_POLEA_H
#define CABLE_POLEA_H
#include "_polea.h"
#include "_cable.h"

class _cable_polea
{
private:
    _polea polea;
    _cable cable;
    double posicion;
    void subir(_tipo tipo);
    void bajar(_tipo tipo);

public:
    _cable_polea();
    void draw_cable_polea(_tipo tipo);
    void animar_cable_polea(_tipo tipo, _tamanio tamanio);
    _cable Cable();
    _polea Polea();
    double Posicion();
};

#endif // CABLE_POLEA_H
