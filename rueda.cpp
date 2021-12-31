#include "rueda.h"

_rueda::_rueda()
{
    angulo = 0;
    rueda.vueltas(10);
}

void _rueda::draw_rueda(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.2, 0.1, 0.2);
    rueda.draw(tipo);
    glPopMatrix();
}

void _rueda::animacion_giro(_tipo tipo, _giro giro){

    switch(giro){
        case DRCHA:
           giro_drcha(tipo);
           break;

        case IZQDA:
           giro_izqda(tipo);
           break;

        default:
           break;

    }
}

void _rueda::giro_drcha(_tipo tipo){
    if(angulo <= 60)
      angulo += 3;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.2, 0.1, 0.2);
    rueda.draw(tipo);
    glPopMatrix();
}

void _rueda::giro_izqda(_tipo tipo){
    if(angulo >= -60)
      angulo -= 3;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.2, 0.1, 0.2);
    rueda.draw(tipo);
    glPopMatrix();
}

double _rueda::Angulo(){
    return angulo;
}
