#ifndef RUEDA_H
#define RUEDA_H
#include "_cilindro.h"
#include "object3d.h"

typedef enum{DRCHA, IZQDA} _giro;

class _rueda
{
private:
    _cilindro rueda;
    double angulo;
    void giro_drcha(_tipo tipo);
    void giro_izqda(_tipo tipo);

public:
    _rueda();
    void draw_rueda(_tipo tipo);
    void animacion_giro(_tipo tipo,_giro giro);
    double Angulo();
};

#endif // RUEDA_H
