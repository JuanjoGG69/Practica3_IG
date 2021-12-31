#include "cube.h"

_cube::_cube(float size)
{
    Vertices.resize(8);

    //cara delantera
    Vertices[0] = _vertex3f(size, size, size);
    Vertices[1] = _vertex3f(size, -size, size);
    Vertices[2] = _vertex3f(-size, size, size);
    Vertices[3] = _vertex3f(-size, -size, size);

    //cara trasera
    Vertices[4] = _vertex3f(size, size, -size);
    Vertices[5] = _vertex3f(size, -size, -size);
    Vertices[6] = _vertex3f(-size, size, -size);
    Vertices[7] = _vertex3f(-size, -size, -size);

    //Triangles
    Triangles.resize(12);

    //cara delantera
    Triangles[0] = _vertex3ui(0,2,3);
    Triangles[1] = _vertex3ui(0,1,3);

    //cara de arriba
    Triangles[2] = _vertex3ui(2,6,0);
    Triangles[3] = _vertex3ui(0,4,6);

    //cara lateral izquierda
    Triangles[4] = _vertex3ui(2,3,6);
    Triangles[5] = _vertex3ui(3,6,7);

    //cara lateral derecha
    Triangles[6] = _vertex3ui(0,1,5);
    Triangles[7] = _vertex3ui(0,4,5);

    //cara  de abajo
    Triangles[8] = _vertex3ui(1,3,5);
    Triangles[9] = _vertex3ui(3,5,7);

    //cara trasera
    Triangles[10] = _vertex3ui(4, 5, 6);
    Triangles[11] = _vertex3ui(5,6,7);
}
