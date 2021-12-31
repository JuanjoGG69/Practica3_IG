#include "_mecanismo_agarre.h"

_mecanismo_agarre::_mecanismo_agarre()
{
    posicion = 0;
}

void _mecanismo_agarre::draw_mecanismo_agarre(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    gancho_polea.draw_gancho(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0.3, 0);
    polea_gancho.draw_cable_polea(tipo);
    glPopMatrix();

}

void _mecanismo_agarre::animacion_mecanismo(_tipo tipo, _movimientos movimiento){

    switch(movimiento){
        case SUBIDA:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, 0.3, 0);
            polea_gancho.animar_cable_polea(tipo, ENCOGER);
            glPopMatrix();

            if(polea_gancho.Cable().Tamanio() >= 0.5){
                glPushMatrix();
                animacion_gancho(tipo, (polea_gancho.Cable().Tamanio() * 0.01) * 2);
                glPopMatrix();
            }else{
                glPushMatrix();
                animacion_gancho(tipo, 0);
                glPopMatrix();
            }

            break;

        case BAJADA:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, 0.3, 0);
            polea_gancho.animar_cable_polea(tipo, AGRANDAR);
            glPopMatrix();

            if(polea_gancho.Cable().Tamanio() <= 4){
                glPushMatrix();
                animacion_gancho(tipo, -(polea_gancho.Cable().Tamanio() * 0.01) * 2);
                glPopMatrix();
            }else{
                glPushMatrix();
                animacion_gancho(tipo, 0);
                glPopMatrix();
            }

            break;

        case GIROD:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, 0.3, 0);
            posicion_cable_polea(tipo);
            glPopMatrix();

            glPushMatrix();
            animacion_ganchoD(tipo);
            glPopMatrix();
            break;

        case GIROI:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, 0.3, 0);
            posicion_cable_polea(tipo);
            glPopMatrix();

            glPushMatrix();
            animacion_ganchoI(tipo);
            glPopMatrix();
            break;

        case QUIETO:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, 0.3, 0);
            posicion_cable_polea(tipo);
            glPopMatrix();

            glPushMatrix();
            animacion_gancho(tipo, 0);
            glPopMatrix();

            break;

        default:
            break;
    }
}

void _mecanismo_agarre::animacion_gancho(_tipo tipo, double translado){
    posicion = posicion + translado;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0, posicion, 0);
    gancho_polea.draw_gancho(tipo);
    glPopMatrix();

}

void _mecanismo_agarre::animacion_ganchoD(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0, posicion, 0);
    gancho_polea.animar_gancho(tipo, DRCHA);
    glPopMatrix();
}

void _mecanismo_agarre::animacion_ganchoI(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0, posicion, 0);
    gancho_polea.animar_gancho(tipo, IZQDA);
    glPopMatrix();
}


void _mecanismo_agarre::posicion_cable_polea(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    polea_gancho.draw_cable_polea(tipo);
    glPopMatrix();
}

_cable_polea _mecanismo_agarre::Polea_gancho(){
    return polea_gancho;
}
