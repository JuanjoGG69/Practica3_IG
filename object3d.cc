/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glBegin(GL_TRIANGLES);
        glColor3fv((GLfloat *) &BLACK);
        for(unsigned int i = 0; i < Triangles.size(); i++){
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._2]);
        }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
        glColor3fv((GLfloat * ) &YEllOW);
        for(unsigned int i = 0; i < Triangles.size(); i++){
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._2]);
        }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

    glBegin(GL_TRIANGLES);
        for(unsigned int i = 0; i < Triangles.size(); i++){

            glColor3fv((GLfloat *) &RED);
            if(i % 2 == 0)
                glColor3fv((GLfloat *) &GREEN);

            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) & Vertices[Triangles[i]._2]);
        }
    glEnd();

}

void _object3D::draw(_tipo tipo){
    switch (tipo){
        case POINTS: draw_point(); break;
        case LINES: draw_line(); break;
        case FILL: draw_fill(); break;
        case CHESS: draw_chess(); break;
        default:break;
    }
}
