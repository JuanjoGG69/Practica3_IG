#include "_grua.h"

_grua::_grua()
{
    posicion = 0;
}

void _grua::draw_grua(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(5.5, 4, 0);
    gancho_util.draw_mecanismo_agarre(tipo);
    glPopMatrix();

    glPushMatrix();
    torre_util.draw_soporte_torre(tipo);
    glPopMatrix();

    glPushMatrix();
    pluma_util.draw_carga_pluma(tipo);
    glPopMatrix();
}

void _grua::animacion_grua(_tipo tipo, _movs movs){

    switch(movs){
        case GIROIZQDAR:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, posicion, 0);
            glRotated(pluma_util.Angulo(), 0, 1, 0);
            glTranslated(5.5, 4, 0);
            gancho_util.animacion_mecanismo(tipo, QUIETO);
            glPopMatrix();

            glPushMatrix();
            pluma_util.draw_carga_pluma(tipo);
            glPopMatrix();

            glPushMatrix();
            torre_util.animacion_giro(tipo, IZQDA);
            glPopMatrix();

            break;

        case GIRODRCHAR:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            glTranslated(0, posicion, 0);
            glRotated(pluma_util.Angulo(), 0, 1, 0);
            glTranslated(5.5, 4, 0);
            gancho_util.animacion_mecanismo(tipo, QUIETO);
            glPopMatrix();

            glPushMatrix();
            pluma_util.draw_carga_pluma(tipo);
            glPopMatrix();

            glPushMatrix();
            torre_util.animacion_giro(tipo, DRCHA);
            glPopMatrix();
            break;

        case GIRODRCHAP:
            glMatrixMode(GL_MODELVIEW);


            glPushMatrix();
            pluma_util.animacion_carga_pluma(tipo, DRCHA);
            glPopMatrix();

            glPushMatrix();
            glTranslated(0, posicion, 0);
            glRotated(pluma_util.Angulo(), 0, 1, 0);
            glTranslated(5.5, 4, 0);
            gancho_util.animacion_mecanismo(tipo, QUIETO);
            glPopMatrix();

            glPushMatrix();
            torre_util.draw_soporte_torre(tipo);
            glPopMatrix();
            break;

        case GIROIZQDAP:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            pluma_util.animacion_carga_pluma(tipo, IZQDA);
            glPopMatrix();

            glPushMatrix();
            glRotated(pluma_util.Angulo() , 0, 1, 0);
            glTranslated(0, posicion, 0);
            glTranslated(5.5, 4, 0);
            gancho_util.animacion_mecanismo(tipo, QUIETO);
            glPopMatrix();


            glPushMatrix();
            torre_util.draw_soporte_torre(tipo);
            glPopMatrix();
            break;

        case SBDA:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            pluma_util.draw_carga_pluma(tipo);
            glPopMatrix();

            glPushMatrix();
            glRotated(pluma_util.Angulo() , 0, 1, 0);
            glTranslated(5.5, 4, 0);
            animacion_gancho_util(tipo, (gancho_util.Polea_gancho().Cable().Tamanio() * 0.01) * 2, SUBIDA);
            glPopMatrix();

            glPushMatrix();
            torre_util.draw_soporte_torre(tipo);
            glPopMatrix();

            break;

        case BJDA:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            pluma_util.draw_carga_pluma(tipo);
            glPopMatrix();

            glPushMatrix();
            glRotated(pluma_util.Angulo() , 0, 1, 0);
            glTranslated(5.5, 4, 0);
            animacion_gancho_util(tipo, (gancho_util.Polea_gancho().Cable().Tamanio() * 0.01) * 2, BAJADA);
            glPopMatrix();

            glPushMatrix();
            torre_util.draw_soporte_torre(tipo);
            glPopMatrix();
            break;

        case GIRODRCHG:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            pluma_util.draw_carga_pluma(tipo);
            glPopMatrix();

            glPushMatrix();
            glRotated(pluma_util.Angulo() , 0, 1, 0);
            glTranslated(5.5, 4, 0);
            animacion_gancho_util(tipo, 0, GIROD);
            glPopMatrix();

            glPushMatrix();
            torre_util.draw_soporte_torre(tipo);
            glPopMatrix();
            break;

        case GIROIZQDAG:
            glMatrixMode(GL_MODELVIEW);

            glPushMatrix();
            pluma_util.draw_carga_pluma(tipo);
            glPopMatrix();

            glPushMatrix();
            glRotated(pluma_util.Angulo() , 0, 1, 0);
            glTranslated(5.5, 4, 0);
            animacion_gancho_util(tipo, 0, GIROI);
            glPopMatrix();

            glPushMatrix();
            torre_util.draw_soporte_torre(tipo);
            glPopMatrix();
            break;
        default:
            break;
    }
}

void _grua::animacion_gancho_util(_tipo tipo, double translado, _movimientos movi){
    switch(movi){
        case SUBIDA:
            if(gancho_util.Polea_gancho().Cable().Tamanio() >= 0.5){
            glPushMatrix();
            glTranslated(0, posicion, 0);
            gancho_util.animacion_mecanismo(tipo, SUBIDA);
            glPopMatrix();
            posicion = posicion + translado;
            }

            else{
                glPushMatrix();
                glTranslated(0, posicion, 0);
                gancho_util.animacion_mecanismo(tipo, SUBIDA);
                glPopMatrix();
            }
            break;

        case BAJADA:
            if(gancho_util.Polea_gancho().Cable().Tamanio() <= 4){
                glPushMatrix();
                glTranslated(0, posicion, 0);
                gancho_util.animacion_mecanismo(tipo, BAJADA);
                glPopMatrix();
                posicion = posicion - translado;
            }

            else{
                glPushMatrix();
                glTranslated(0, posicion, 0);
                gancho_util.animacion_mecanismo(tipo, BAJADA);
                glPopMatrix();
            }
            break;

        case GIROD:
            glPushMatrix();
            glTranslated(0, posicion, 0);
            gancho_util.animacion_mecanismo(tipo, GIROD);
            glPopMatrix();
            break;

        case GIROI:
            glPushMatrix();
            glTranslated(0, posicion, 0);
            gancho_util.animacion_mecanismo(tipo, GIROI);
            glPopMatrix();
            break;

        default:
            break;

    }
}
