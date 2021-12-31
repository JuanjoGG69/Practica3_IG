/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/gl.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cube.h"
#include "object3d.h"
#include "ply.h"
#include "object3d_rotate.h"
#include "_cono.h"
#include "_cilindro.h"
#include "_esfera.h"
#include "rueda.h"
#include "_soporte.h"
#include "_soporte_torre.h"
#include "_carga_pluma.h"
#include "_cable.h"
#include "cable_polea.h"
#include  "_gancho.h"
#include "_mecanismo_agarre.h"
#include "_grua.h"

namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
  const float Y_MIN=-.1;
  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE, OBJECT_PLY, OBJECT_CILINDRO, OBJECT_ESFERA, OBJECT_CONO, OBJECT_SOPORTE, OBJECT_ANI_RUEDAD, OBJECT_ANI_RUEDAI, OBJECT_SOPORTE_TORRE, OBJECT_CARGA_PLUMA, OBJECT_PLUMAD, OBJECT_PLUMAI, OBJECT_CABLE, OBJECT_CABLED, OBJECT_CABLEA, OBJECT_CABLE_POLEA, OBJECT_GANCHO, OBJECT_GANCHOD, OBJECT_GANCHOI, OBJECT_MECANISMO_AGARRE, OBJECT_GRUA} _object;
}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;


private:
  _window *Window;

  _axis Axis;
  _tetrahedron Tetrahedron;
  _cube Cube;
  _ply Ply;
  _cilindro Cilindro;
  _cono Cono;
  _esfera Esfera;
  _rueda Rueda;
  _soporte Soporte;
  _soporte_torre Soporte_torre;
  _carga_pluma Carga_pluma;
  _cable Cable;
  _cable_polea Cable_polea;
  _gancho Gancho;
  _mecanismo_agarre Mecanismo_agarre;
  _grua Grua;

  _gl_widget_ne::_object Object;

  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;
  bool Draw_chess;

  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
};

#endif
