#include "_cilindro.h"

_cilindro::_cilindro()
{
    Vertices.clear();
    Vertices.resize(4);
    float Size = 1.0;
    Vertices[0]=_vertex3f(0,-Size,0);
    Vertices[1]=_vertex3f(Size,-Size,0);
    Vertices[2]=_vertex3f(Size,Size,0);
    Vertices[3]=_vertex3f(0,Size,0);
}
