#include "_base.h"

_base::_base()
{

}

void _base::draw_base(_tipo tipo){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslated(0, 0.5, 0);
    base.draw(tipo);
    glPopMatrix();
}
