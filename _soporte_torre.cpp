#include "_soporte_torre.h"

_soporte_torre::_soporte_torre()
{

}

void _soporte_torre::draw_soporte_torre(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    torre.draw_torre(tipo);
    glPopMatrix();

    glPushMatrix();
    soporte.draw_soporte(tipo);
    glPopMatrix();
}

void _soporte_torre::animacion_giro(_tipo tipo, _giro giro){
    glPushMatrix();
    torre.draw_torre(tipo);
    glPopMatrix();

    glPushMatrix();
    soporte.animacion_giro(tipo, giro);
    glPopMatrix();
}

_soporte _soporte_torre::Soporte(){
    return soporte;
}
