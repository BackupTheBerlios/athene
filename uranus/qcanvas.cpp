/***************************************************************************
                          qcanvas.cpp  -  description
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

#include <GL/gl.h>


#include <qapplication.h>
#include <iostream>
#include <stdlib.h>

#include "qcanvas.h"
#include "holder.h"
#include "selector.h"


namespace Ah {

QCanvas::QCanvas(QWidget* parent = 0)
 : Canvas(), QGLWidget(QGLFormat(Rgba | DoubleBuffer | NoAccumBuffer | NoStereoBuffers | NoDepthBuffer | StencilBuffer | AlphaChannel), parent),
	element(this)
{
}

QCanvas::~QCanvas()
{
}

void QCanvas::initilizeGL()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
	setViewport(width(), height());
}

void QCanvas::paintGL()
{
	initilize();
	draw();
}

void QCanvas::resizeGL(int width, int height)
{
	setViewport(width, height);

}

void QCanvas::postdraw()
{
	Canvas::postdraw();
	swapBuffers();
}


void QCanvas::mouseReleaseEvent(QMouseEvent* event)
{
	Holder<>* holder = 0;
    Holder<>* tmp = 0;
    SelectionArray* array = getSelections(static_cast<double>(event->x()),static_cast<double>(height() - event->y()), 10.0, 10.0);
	Selector selector(array);
    do {
		tmp = selector.next();
        if (tmp) holder = tmp;
	} while(tmp);
    tmp = 0;
    if(holder) 
    {
    	element = dynamic_cast<Node*>(holder->getObject());
    	paintGL();
    	holder->unref();
    }
}

void QCanvas::keyPressEvent(QKeyEvent* event)
{
	//std::cout << "Key event:\n";
	switch(event->key()) {
    case Qt::Key_Left : element->getMatrix()->move(10.0, 0.0); break;
	case Qt::Key_Right : element->getMatrix()->move(-10.0, 0.0); break;
    case Qt::Key_Up : element->getMatrix()->move(0.0, -10.0); break;
    case Qt::Key_Down : element->getMatrix()->move(0.0, 10.0); break;
    case Qt::Key_Plus : element->getMatrix()->zoom(0.95); break;
    case Qt::Key_Minus : element->getMatrix()->zoom(1.05); break;
    case Qt::Key_End : element->getMatrix()->rotate(0.1); break;
    case Qt::Key_Next : element->getMatrix()->rotate(-0.1); break;
    case Qt::Key_X : element->getMatrix()->scale(0.8); break;
    case Qt::Key_C : element->getMatrix()->scale(1.2); break;
    case Qt::Key_I : element->getMatrix()->setIdentity(); break;
	case Qt::Key_Q : qApp->quit(); break;
    case Qt::Key_A : if(element->getPrevious()) element = dynamic_cast<Node*>(element->getPrevious()); break;
    case Qt::Key_S : if(element->getNext()) element = dynamic_cast<Node*>(element->getNext()); break;
    case Qt::Key_W : if(element->getFirst()) element = dynamic_cast<Node*>(element->getFirst()); break;
    case Qt::Key_Z : if(element->getParent()) element = dynamic_cast<Node*>(element->getParent()); break;
    }
	paintGL();
//	std::cout << "\n\n";
}

};


