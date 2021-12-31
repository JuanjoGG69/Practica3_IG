#include "_esfera.h"

_esfera::_esfera()
{
    float Size = 0.5;
    int tam = 40;
    Vertices.clear();
    Vertices.resize(40);
    double angulo = M_PI/tam;

    for(int i = 0; i < tam; i++){
        Vertices[i]=_vertex3f((Size/2)*sin(angulo*i),(Size/2)*cos(angulo*i) ,0);
    }
}
