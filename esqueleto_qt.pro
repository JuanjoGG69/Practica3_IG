HEADERS += \
  _base.h \
  _cable.h \
  _carga_pluma.h \
  _cilindro.h \
  _cono.h \
  _esfera.h \
  _gancho.h \
  _grua.h \
  _mecanismo_agarre.h \
  _pluma.h \
  _polea.h \
  _soporte.h \
  _soporte_torre.h \
  cable_polea.h \
  carga.h \
  colors.h \
  basic_object3d.h \
  cube.h \
  file_ply_stl.h \
  object3d.h \
  axis.h \
  object3d_rotate.h \
  ply.h \
  rueda.h \
  tetrahedron.h \
  glwidget.h \
  torre.h \
  window.h

SOURCES += \
  _base.cpp \
  _cable.cpp \
  _carga_pluma.cpp \
  _cilindro.cpp \
  _cono.cpp \
  _esfera.cpp \
  _gancho.cpp \
  _grua.cpp \
  _mecanismo_agarre.cpp \
  _pluma.cpp \
  _polea.cpp \
  _soporte.cpp \
  _soporte_torre.cpp \
  basic_object3d.cc \
  cable_polea.cpp \
  carga.cpp \
  cube.cpp \
  file_ply_stl.cpp \
  object3d.cc \
  axis.cc \
  object3d_rotate.cpp \
  ply.cpp \
  rueda.cpp \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  torre.cpp \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
