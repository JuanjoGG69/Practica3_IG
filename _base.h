#ifndef _BASE_H
#define _BASE_H
#include "cube.h"
#include "object3d.h"

class _base
{
private:
    _cube base;
public:
    _base();
    void draw_base(_tipo tipo);
};

#endif // _BASE_H
