/***************************************************************************
                          rectangle.h  -  description
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

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Ah {

class Rectangle : public Shape
{
public:
	Rectangle(float x, float y, float width, float height);

protected:
    virtual void draw();

private:
	float x;
	float y;
    float width;
    float height;

};
};

#endif
