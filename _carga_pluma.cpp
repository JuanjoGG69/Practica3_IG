#include "_carga_pluma.h"

_carga_pluma::_carga_pluma()
{
    angulo = 0;
}

void _carga_pluma::draw_carga_pluma(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);

//    glPushMatrix();
//    glTranslated(4, 5.5, -0.05);
//    cable.draw_cable(tipo);
//    glPopMatrix();

//    glPushMatrix();
//    glTranslated(4, 5.5, 0.05);
//    cable.draw_cable(tipo);
//    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    pluma.draw_pluma(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    carga.draw_carga(tipo);
    glPopMatrix();
}

void _carga_pluma::animacion_carga_pluma(_tipo tipo, _giro giro){
    switch (giro){
        case DRCHA:
            animacion_drcha(tipo);
            break;
        case IZQDA:
            animacion_izqda(tipo);
            break;
        default:
            break;
    }
}

void _carga_pluma::animacion_drcha(_tipo tipo){
    angulo += 3;

    glMatrixMode(GL_MODELVIEW);

//    glPushMatrix();
//    glRotated(angulo, 0, 1, 0);
//    glTranslated(4, 5.5, -0.05);
//    cable.draw_cable(tipo);
//    glPopMatrix();

//    glPushMatrix();
//    glRotated(angulo, 0, 1, 0);
//    glTranslated(4, 5.5, 0.05);
//    cable.draw_cable(tipo);
//    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    pluma.draw_pluma(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    carga.draw_carga(tipo);
    glPopMatrix();
}

void _carga_pluma::animacion_izqda(_tipo tipo){
    angulo -= 3;

    glMatrixMode(GL_MODELVIEW);

//    glPushMatrix();
//    glRotated(angulo, 0, 1, 0);
//    glTranslated(4, 5.5, -0.05);
//    cable.draw_cable(tipo);
//    glPopMatrix();

//    glPushMatrix();
//    glRotated(angulo, 0, 1, 0);
//    glTranslated(4, 5.5, 0.05);
//    cable.draw_cable(tipo);
//    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    pluma.draw_pluma(tipo);
    glPopMatrix();

    glPushMatrix();
    glRotated(angulo, 0, 1, 0);
    carga.draw_carga(tipo);
    glPopMatrix();
}

double _carga_pluma::Angulo(){
    return angulo;
}
