#include "carga.h"

_carga::_carga()
{

}

void _carga::draw_carga(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(-3.2, 8.5, 0);
    carga.draw(tipo);
    glPopMatrix();

}
