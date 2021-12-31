#include "_cable.h"

_cable::_cable()
{
    cable.vueltas(40);
    escalado = 1;
    tamanio = 2;
}

void _cable::draw_cable(_tipo tipo){

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glScaled(0.02, tamanio, 0.02);
    cable.draw(tipo);
    glPopMatrix();

}

void _cable::animacion_cable(_tipo tipo, _tamanio tamanio){
    switch(tamanio){
        case AGRANDAR:
            aumentar_tamanio(tipo);
            break;
        case ENCOGER:
            disminuir_tamanio(tipo);
            break;
        default:
            break;
    }
}

void _cable::aumentar_tamanio(_tipo tipo){

    if(escalado <= 1)
        escalado = 1.01;

    if (tamanio >= 4)
        escalado = 1;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glScaled(1, escalado, 1);
    draw_cable(tipo);
    glPopMatrix();

    tamanio = tamanio * escalado;
}

void _cable::disminuir_tamanio(_tipo tipo){
    if(escalado >= 1)
        escalado = 0.99;
    if(tamanio <= 0.5)
        escalado = 1;

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glScaled(1, escalado, 1);
    draw_cable(tipo);
    glPopMatrix();

    tamanio = tamanio * escalado;
}

double _cable::Escalado(){
    return escalado;
}

double _cable::Tamanio(){
    return tamanio;
}
