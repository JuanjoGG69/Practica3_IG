#ifndef OBJECT3D_ROTATE_H
#define OBJECT3D_ROTATE_H
#include "object3d.h"
#include <cmath>


class _object3D_Rotate:public _object3D
{

    public:

        void vueltas(int n_caras);
        void rellenar_triangulos(int n_caras, int tam);
};

#endif // OBJECT3D_ROTATE_H
