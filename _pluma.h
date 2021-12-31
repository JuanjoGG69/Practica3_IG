#ifndef _PLUMA_H
#define _PLUMA_H
#include "cube.h"
#include "rueda.h"
#include "basic_object3d.h"

class _pluma
{
private:
    _cube pluma;

public:
    _pluma();
    void draw_pluma(_tipo tipo);
};

#endif // _PLUMA_H
