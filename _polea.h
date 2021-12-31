#ifndef _POLEA_H
#define _POLEA_H
#include "_cilindro.h"


class _polea
{
private:
    _cilindro polea;
    double posicion;

public:
    _polea();
    void draw_polea(_tipo tipo);
    void animar_polea(_tipo tipo, double translado);
};

#endif // _POLEA_H
