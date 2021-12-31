#include "cable_polea.h"

_cable_polea::_cable_polea()
{
    posicion = 2;
}

void _cable_polea::draw_cable_polea(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);


    glPushMatrix();
    glTranslated(0, 2, 0.05);
    cable.draw_cable(tipo);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 2, -0.05);
    cable.draw_cable(tipo);
    glPopMatrix();

    glPushMatrix();
    polea.animar_polea(tipo, 0);
    glPopMatrix();
}

void _cable_polea::animar_cable_polea(_tipo tipo, _tamanio tamanio){
    switch (tamanio){
        case AGRANDAR:
            bajar(tipo);
            break;
        case ENCOGER:
            subir(tipo);
            break;
        default:
            break;
    }
}

void _cable_polea::subir(_tipo tipo){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslated(0, 2, 0.05);
    cable.animacion_cable(tipo, ENCOGER);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 2, -0.05);
    cable.animacion_cable(tipo, ENCOGER);
    glPopMatrix();

    if(cable.Tamanio() >= 0.5){
        glPushMatrix();
        polea.animar_polea(tipo, (cable.Tamanio() * 0.01) * 2);
        glPopMatrix();
    }else{
        glPushMatrix();
        polea.animar_polea(tipo, 0);
        glPopMatrix();
    }

      posicion += cable.Tamanio() * 0.01 * 2;

}

void _cable_polea::bajar(_tipo tipo){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0, 2, 0.05);
    cable.animacion_cable(tipo, AGRANDAR);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 2, -0.05);
    cable.animacion_cable(tipo, AGRANDAR);
    glPopMatrix();

    if(cable.Tamanio() <= 4){
        glPushMatrix();
        polea.animar_polea(tipo, -((cable.Tamanio() * 0.01) * 2));
        glPopMatrix();
    }else{
        glPushMatrix();
        polea.animar_polea(tipo, 0);
        glPopMatrix();
    }

    posicion += cable.Tamanio() * 0.01 * 2;

}

_cable _cable_polea::Cable(){
    return cable;
}

_polea _cable_polea::Polea(){
    return polea;
}
