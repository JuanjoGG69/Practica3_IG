#ifndef PLY_H
#define PLY_H

#include "file_ply_stl.h"
#include "object3d.h"
#include "QString"

class _ply:public _object3D
{
private:
    vector<float> coordenadas;
    vector<unsigned int> posiciones;
public:
    _ply();
};

#endif // PLY_H
