#include "_soporte.h"

_soporte::_soporte()
{

}

void _soporte::draw_soporte(_tipo tipo){

    glMatrixMode(GL_MODELVIEW);

    //Rueda trasera izquierda
    glPushMatrix();
    glTranslated(-0.5, 0, -0.5);
    ruedas.draw_rueda(tipo);
    glPopMatrix();

    //Rueda trasera derecha
    glPushMatrix();
    glTranslated(0.5, 0, -0.5);
    ruedas.draw_rueda(tipo);
    glPopMatrix();

    //Rueda delantera izquierda
    glPushMatrix();
    glTranslated(-0.5, 0, 0.5);
    ruedas.draw_rueda(tipo);
    glPopMatrix();

    //Rueda delantera derecha
    glPushMatrix();
    glTranslated(0.5, 0, 0.5);
    ruedas.draw_rueda(tipo);
    glPopMatrix();

    //base
    glPushMatrix();
    base.draw_base(tipo);
    glPopMatrix();
}


void _soporte::animacion_giro(_tipo tipo, _giro giro){
    switch(giro){
        case DRCHA:
           animacion_ruedas_drcha(tipo);
           break;

        case IZQDA:
           animacion_ruedas_izqda(tipo);
           break;

        default:
           break;

    }
}


void _soporte::animacion_ruedas_drcha(_tipo tipo){

     glMatrixMode(GL_MODELVIEW);

    //Rueda trasera izquierda
    glPushMatrix();
    glTranslated(-0.5, 0, -0.5);
    ruedas.animacion_giro(tipo, DRCHA);
    glPopMatrix();

    //Rueda trasera derecha
    glPushMatrix();
    glTranslated(0.5, 0, -0.5);
    ruedas.animacion_giro(tipo, DRCHA);
    glPopMatrix();

    //Rueda delantera izquierda
    glPushMatrix();
    glTranslated(-0.5, 0, 0.5);
    ruedas.animacion_giro(tipo, DRCHA);
    glPopMatrix();

    //Rueda delantera derecha
    glPushMatrix();
    glTranslated(0.5, 0, 0.5);
    ruedas.animacion_giro(tipo, DRCHA);
    glPopMatrix();

    //base
    glPushMatrix();
    base.draw_base(tipo);
    glPopMatrix();
}

void _soporte::animacion_ruedas_izqda(_tipo tipo){

     glMatrixMode(GL_MODELVIEW);

    //Rueda trasera izquierda
    glPushMatrix();
    glTranslated(-0.5, 0, -0.5);
    ruedas.animacion_giro(tipo, IZQDA);
    glPopMatrix();

    //Rueda trasera derecha
    glPushMatrix();
    glTranslated(0.5, 0, -0.5);
    ruedas.animacion_giro(tipo, IZQDA);
    glPopMatrix();

    //Rueda delantera izquierda
    glPushMatrix();
    glTranslated(-0.5, 0, 0.5);
    ruedas.animacion_giro(tipo, IZQDA);
    glPopMatrix();

    //Rueda delantera derecha
    glPushMatrix();
    glTranslated(0.5, 0, 0.5);
    ruedas.animacion_giro(tipo, IZQDA);
    glPopMatrix();

    //base
    glPushMatrix();
    base.draw_base(tipo);
    glPopMatrix();
}

_rueda _soporte::Ruedas(){
    return ruedas;
}
