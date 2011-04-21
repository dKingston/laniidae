// qt-gui -- A Qt GUI interface to liblaniidae.
// Copyright (c) 2011 Michael Rodriguez et al.
// Rights to this code are documented in `docs/LICENSE`.

#ifndef QT_GUI_OPENGL_HPP
#define QT_GUI_OPENGL_HPP

#include <QtOpenGL>
#include <QPainter>

// Forward class declarations.
class QPaintEvent;

class GLWidget : public QGLWidget
{
 public:
     GLWidget(void);
     ~GLWidget(void);

 public slots:
     void draw(void);

 protected:
     void paint_event(QPaintEvent *event);
};

#endif
