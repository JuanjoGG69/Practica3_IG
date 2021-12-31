#include "torre.h"

_torre::_torre()
{

}

void _torre::draw_torre(_tipo tipo){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0, 6, 0);
    glScaled(0.7, 10, 0.7);
    torre.draw(tipo);
    glPopMatrix();

}
