#include "_gancho.h"

_gancho::_gancho()
{
    punta_gancho.vueltas(40);
    angulo = 0;
}

void _gancho::draw_gancho(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0,0.1,0);
    glScaled(0.1,0.2,0.1);
    soporte.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0.1, -0.05, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.1, 0.3, 0.1);
    soporte.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0.2, 0.075, 0);
    glScaled(0.05, 0.15, 0.05);
    punta_gancho.draw(tipo);
    glPopMatrix();
}

void _gancho::animar_gancho(_tipo tipo, _giro giro){
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

void _gancho::giro_drcha(_tipo tipo){
    angulo += 3;
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0,0.1,0);
    glScaled(0.1,0.2,0.1);
    soporte.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0.1, -0.05, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.1, 0.3, 0.1);
    soporte.draw(tipo);
    soporte.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0.2, 0.075, 0);
    glScaled(0.05, 0.15, 0.05);
    punta_gancho.draw(tipo);
    glPopMatrix();
}

void _gancho::giro_izqda(_tipo tipo){
    angulo -= 3;
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0,0.1,0);
    glScaled(0.1,0.2,0.1);
    soporte.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0.1, -0.05, 0);
    glRotated(90, 0, 0, 1);
    glScaled(0.1, 0.3, 0.1);
    soporte.draw(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    glTranslated(0.2, 0.075, 0);
    glScaled(0.05, 0.15, 0.05);
    punta_gancho.draw(tipo);
    glPopMatrix();
}

