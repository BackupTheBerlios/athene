/***************************************************************************
                          rectangle.cpp  -  description
                             -------------------
    begin                : Tue Jul 24 2002
    copyright            : (C) 2002 by Marco Bubke
    email                : marco@bubke.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; 2.1 of the License.        *
 *                                                                         *                                                                         *
 ***************************************************************************/

#include <GL/gl.h>

#include "rectangle.h"
#include <iostream>


namespace Ah {

Rectangle::Rectangle(float x, float y, float width, float height)
	: Shape(), x(x), y(y), width(width), height(height)
{
}

void Rectangle::draw()
{
	getShader()->beginShader();
    if (getShader()->drawShaded()) {
		getShader()->beginShading();
    	beginList();
    	if(!isCached())
    	{
			glRectf(x, y, width, height);
		}
    	endList();
 	    getShader()->endShading();
	}
    if (getShader()->drawOutline()) {
    	getShader()->beginOutline();
		beginList();
    	if(!isCached())
    	{
			glRectf(x, y, width, height);
		}
    	endList();
    	getShader()->endOutline();

    }
    getShader()->endShader();
}

};
