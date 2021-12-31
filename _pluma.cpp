#include "_pluma.h"

_pluma::_pluma()
{

}

void _pluma::draw_pluma(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(1.5, 8.5, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.5, 8.5, 0.5);
    pluma.draw(tipo);
    glPopMatrix();
}
