#ifndef _CABLE_H
#define _CABLE_H
#include "_cilindro.h"

typedef enum{ENCOGER, AGRANDAR} _tamanio;

class _cable
{
private:
    _cilindro cable;
    double escalado;
    double tamanio;
    void aumentar_tamanio(_tipo tipo);
    void disminuir_tamanio(_tipo tipo);

public:
    _cable();
    void draw_cable(_tipo tipo);
    void animacion_cable(_tipo tipo, _tamanio tamanio);
    double Escalado();
    double Tamanio();
};

#endif // _CABLE_H
