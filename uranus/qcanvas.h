/***************************************************************************
                          qcanvas.h  -  description
                             -------------------
    begin                : Tue Jul 23 2002
    copyright            : (C) 2002 by Marco Bubke
    email                : marco@bubke.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation;        version 2.1 of      *
 *   the License.                                                          *
 *                                                                         *
 ***************************************************************************/


#ifndef QCANVAS_H
#define QCANVAS_H

#include <qgl.h>

#include "canvas.h"


/**
  *@author Marco Bubke
  */
namespace Ah {

class QCanvas : public Canvas, public QGLWidget{
public: 
	QCanvas(QWidget* parent);
	~QCanvas();

    virtual void initilizeGL();
    virtual void paintGL();
    virtual void resizeGL(int width, int height);


protected:
	    //!only for testing
    virtual void keyPressEvent(QKeyEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void postdraw();
private:
	Node* element;
};
};
#endif
