/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
  Esfera.vueltas(40);
  Cono.vueltas(40);
  Cilindro.vueltas(40);

}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:Object=OBJECT_TETRAHEDRON;break;
  case Qt::Key_2:Object=OBJECT_CUBE;break;
  case Qt::Key_3:Object=OBJECT_CONO;break;
  case Qt::Key_4:Object=OBJECT_CILINDRO;break;
  case Qt::Key_5:Object=OBJECT_ESFERA;break;
  case Qt::Key_6:Object=OBJECT_PLY;break;
  case Qt::Key_V:Object=OBJECT_SOPORTE_TORRE;break;
  case Qt::Key_I:Object=OBJECT_CARGA_PLUMA;break;
  case Qt::Key_M:Object=OBJECT_ANI_RUEDAD;break;
  case Qt::Key_N:Object=OBJECT_ANI_RUEDAI;break;
  case Qt::Key_W:Object=OBJECT_PLUMAD;break;
  case Qt::Key_Q:Object=OBJECT_PLUMAI;break;
  case Qt::Key_T:Object=OBJECT_CABLE_POLEA;break;
  case Qt::Key_D:Object=OBJECT_CABLEA;break;
  case Qt::Key_S:Object=OBJECT_CABLED;break;
  case Qt::Key_B:Object=OBJECT_MECANISMO_AGARRE;break;
  case Qt::Key_Z:Object=OBJECT_GANCHOI;break;
  case Qt::Key_X:Object=OBJECT_GANCHOD;break;
  case Qt::Key_U:Object=OBJECT_GRUA;break;

  case Qt::Key_P:Draw_point=!Draw_point;break;
  case Qt::Key_L:Draw_line=!Draw_line;break;
  case Qt::Key_F:Draw_fill=!Draw_fill;break;
  case Qt::Key_C:Draw_chess=!Draw_chess;break;

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_Minus:Observer_distance*=1.2;break;
  case Qt::Key_Plus:Observer_distance/=1.2;break;
  }

  update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_PLY:Ply.draw_point();break;
    case OBJECT_CILINDRO:Cilindro.draw_point();break;
    case OBJECT_CONO:Cono.draw_point();break;
    case OBJECT_ESFERA:Esfera.draw_point();break;
    case OBJECT_SOPORTE_TORRE:Soporte_torre.draw_soporte_torre(POINTS);break;
    case OBJECT_ANI_RUEDAD:Grua.animacion_grua(POINTS, GIRODRCHAR);break;
    case OBJECT_ANI_RUEDAI:Grua.animacion_grua(POINTS, GIROIZQDAR);break;
    case OBJECT_CARGA_PLUMA:Carga_pluma.draw_carga_pluma(POINTS);break;
    case OBJECT_PLUMAD:Grua.animacion_grua(POINTS, GIRODRCHAP);break;
    case OBJECT_PLUMAI:Grua.animacion_grua(POINTS, GIROIZQDAP);break;
    case OBJECT_CABLE_POLEA:Cable_polea.draw_cable_polea(POINTS);break;
    case OBJECT_CABLEA:Grua.animacion_grua(POINTS, BJDA);break;
    case OBJECT_CABLED:Grua.animacion_grua(POINTS, SBDA);break;
    case OBJECT_MECANISMO_AGARRE:Mecanismo_agarre.draw_mecanismo_agarre(POINTS);break;
    case OBJECT_GANCHOI:Grua.animacion_grua(POINTS, GIROIZQDAG);break;
    case OBJECT_GANCHOD:Grua.animacion_grua(POINTS, GIRODRCHG);break;
    case OBJECT_GRUA:Grua.draw_grua(POINTS);break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(3);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_PLY:Ply.draw_line();break;
    case OBJECT_CILINDRO:Cilindro.draw_line();break;
    case OBJECT_CONO:Cono.draw_line();break;
    case OBJECT_ESFERA:Esfera.draw_line();break;
    case OBJECT_SOPORTE_TORRE:Soporte_torre.draw_soporte_torre(LINES);break;
    case OBJECT_ANI_RUEDAD:Grua.animacion_grua(LINES, GIRODRCHAR);break;
    case OBJECT_ANI_RUEDAI:Grua.animacion_grua(LINES, GIROIZQDAR);break;
    case OBJECT_CARGA_PLUMA:Carga_pluma.draw_carga_pluma(LINES);break;
    case OBJECT_PLUMAD:Grua.animacion_grua(LINES, GIRODRCHAP);break;
    case OBJECT_PLUMAI:Grua.animacion_grua(LINES, GIROIZQDAP);break;
    case OBJECT_CABLE_POLEA:Cable_polea.draw_cable_polea(LINES);break;
    case OBJECT_CABLEA:Grua.animacion_grua(LINES, BJDA);break;
    case OBJECT_CABLED:Grua.animacion_grua(LINES, SBDA);break;
    case OBJECT_MECANISMO_AGARRE:Mecanismo_agarre.draw_mecanismo_agarre(LINES);break;
    case OBJECT_GANCHOI:Grua.animacion_grua(LINES, GIROIZQDAG);break;
    case OBJECT_GANCHOD:Grua.animacion_grua(LINES, GIRODRCHG);break;
    case OBJECT_GRUA:Grua.draw_grua(LINES);break;
    default:break;
    }
  }

  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
    case OBJECT_CUBE:Cube.draw_fill();break;
    case OBJECT_PLY:Ply.draw_fill();break;
    case OBJECT_CILINDRO:Cilindro.draw_fill();break;
    case OBJECT_CONO:Cono.draw_fill();break;
    case OBJECT_ESFERA:Esfera.draw_fill();break;
    case OBJECT_SOPORTE_TORRE:Soporte_torre.draw_soporte_torre(FILL);break;
    case OBJECT_ANI_RUEDAD:Grua.animacion_grua(FILL, GIRODRCHAR);break;
    case OBJECT_ANI_RUEDAI:Grua.animacion_grua(FILL, GIROIZQDAR);break;
    case OBJECT_CARGA_PLUMA:Carga_pluma.draw_carga_pluma(FILL);break;
    case OBJECT_PLUMAD:Grua.animacion_grua(FILL, GIRODRCHAP);break;
    case OBJECT_PLUMAI:Grua.animacion_grua(FILL, GIROIZQDAP);break;
    case OBJECT_CABLE_POLEA:Cable_polea.draw_cable_polea(FILL);break;
    case OBJECT_CABLEA:Grua.animacion_grua(FILL, BJDA);break;
    case OBJECT_CABLED:Grua.animacion_grua(FILL, SBDA);break;
    case OBJECT_MECANISMO_AGARRE:Mecanismo_agarre.draw_mecanismo_agarre(FILL);break;
    case OBJECT_GANCHOI:Grua.animacion_grua(FILL, GIROIZQDAG);break;
    case OBJECT_GANCHOD:Grua.animacion_grua(FILL, GIRODRCHG);break;
    case OBJECT_GRUA:Grua.draw_grua(FILL);break;
    default:break;
    }
  }

  if (Draw_chess){
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
    case OBJECT_CUBE:Cube.draw_chess();break;
    case OBJECT_PLY:Ply.draw_chess();break;
    case OBJECT_CILINDRO:Cilindro.draw_chess();break;
    case OBJECT_CONO:Cono.draw_chess();break;
    case OBJECT_ESFERA:Esfera.draw_chess();break;
    case OBJECT_SOPORTE_TORRE:Soporte_torre.draw_soporte_torre(CHESS);break;
    case OBJECT_ANI_RUEDAD:Grua.animacion_grua(CHESS, GIRODRCHAR);break;
    case OBJECT_ANI_RUEDAI:Grua.animacion_grua(CHESS, GIROIZQDAR);break;
    case OBJECT_CARGA_PLUMA:Carga_pluma.draw_carga_pluma(CHESS);break;
    case OBJECT_PLUMAD:Grua.animacion_grua(CHESS, GIRODRCHAP);break;
    case OBJECT_PLUMAI:Grua.animacion_grua(CHESS, GIROIZQDAP);break;
    case OBJECT_CABLE_POLEA:Cable_polea.draw_cable_polea(CHESS);break;
    case OBJECT_CABLEA:Grua.animacion_grua(CHESS, BJDA);break;
    case OBJECT_CABLED:Grua.animacion_grua(CHESS, SBDA);break;
    case OBJECT_MECANISMO_AGARRE:Mecanismo_agarre.draw_mecanismo_agarre(CHESS);break;
    case OBJECT_GANCHOI:Grua.animacion_grua(CHESS, GIROIZQDAG);break;
    case OBJECT_GANCHOD:Grua.animacion_grua(CHESS, GIRODRCHG);break;
    case OBJECT_GRUA:Grua.draw_grua(CHESS);break;
    default:break;
    }
  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;
  Draw_chess=false;
}
