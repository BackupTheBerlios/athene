/***************************************************************************
                          canvas.cpp  -  description
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
#include <GL/glu.h>
#include <boost/progress.hpp>
#include <boost/timer.hpp>

#include "canvas.h"
#include "simpleshader.h"



namespace Ah {

void getError()
{
    switch(glGetError()){
  	case GL_NO_ERROR : std::cout <<  "No Error"<<"\n"; break;
  	case GL_STACK_OVERFLOW : std::cout <<  "Stack Overflow" << "\n"; break;
  	case GL_STACK_UNDERFLOW : std::cout <<  "Stack Underflow" << "\n"; break;
	case GL_INVALID_OPERATION : std::cout <<  "Stack Underflow" << "\n"; break;
	case GL_INVALID_ENUM : std::cout <<  "Invalid Enum" << "\n"; break;
	case GL_INVALID_VALUE : std::cout <<  "Invalid Value" << "\n"; break;
	case GL_OUT_OF_MEMORY : std::cout <<  "Invalid Memory" << "\n"; break;
    default : std::cout <<  "Other Error" <<"\n"; break;
	}
}

int Canvas::renderingHint = 0;

Canvas::Canvas()
	: Group(), renderingTime(0), renderingTimeBound(0.20)
{
	modelview = ModelViewMatrixStack::instance();
	bgcolor = Color(1.0f, 1.0f, 1.0f, 0.0f);
    setShader(new SimpleShader());
}


void Canvas::predraw()
{
	Color color(getBackgroundColor());
	glClearColor(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
    glClear(GL_COLOR_BUFFER_BIT);
    modelview->identity();
	Group::predraw();
}

void Canvas::draw()
{
	boost::timer time;
	boost::progress_timer t;
	predraw();
    Group::draw();
    postdraw();
    setRenderingTime(time.elapsed());
    testRenderingTime();
}

void Canvas::postdraw()
{
	Group::postdraw();
	glFinish();
}

void Canvas::setViewport(int width, int height)
{



	float viewportWidth = static_cast<GLdouble>(width);
    float viewportHeight = static_cast<GLdouble>(height);
    glMatrixMode(GL_PROJECTION);
   	glLoadIdentity();
   	gluOrtho2D(0.0, viewportWidth, 0.0, viewportHeight);
    glViewport (0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
    getMatrix()->movePivotTo(viewportWidth/2.0, viewportHeight/2.0);

}

void Canvas::initilize()
{

	glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_FLAT);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//    glHint(GL_POLYGON_SMOOTH_HINT, GL_FASTEST);
//    glEnable(GL_POLYGON_SMOOTH);
}

Canvas::~Canvas()
{
}

void Canvas::testRenderingTime()
{
	if(renderingTime > renderingTimeBound) renderingHint = -1001;
	else if(renderingTime < 0.03) renderingHint = 1001;
    else renderingHint = 0;
}
};
