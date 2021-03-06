/***************************************************************************
                          color.cpp  -  description
                             -------------------
    begin                : Tue Jul 23 2002
    copyright            : (C) 2002 by Marco Bubke
    email                : marco@bubke.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation;         2.1 of             *
 *   the License.                                                          *
 *                                                                         *
 ***************************************************************************/

#include "color.h"
 
namespace Ah {

Color::Color(float red, float green, float blue, float alpha)
{
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = alpha;
}

};
