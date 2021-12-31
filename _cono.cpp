#include "_cono.h"

_cono::_cono()
{
    float Size = 0.5;
    Vertices.clear();
    Vertices.resize(3);

    Vertices[0] = _vertex3f(0, -Size, 0);
    Vertices[1] = _vertex3f(Size, -Size, 0);
    Vertices[2] = _vertex3f(0, Size, 0);
}
