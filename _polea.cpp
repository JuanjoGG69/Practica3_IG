#include "_polea.h"

_polea::_polea()
{
    polea.vueltas(40);
    posicion = 0;
}

void _polea::draw_polea(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(90, 0, 0, 1);
    glScaled(0.1, 0.05, 0.1);
    polea.draw(tipo);
    glPopMatrix();
}

void _polea::animar_polea(_tipo tipo, double translado){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0, posicion + translado, 0);
    draw_polea(tipo);
    glPopMatrix();

    posicion += translado;
}

