/***************************************************************************
                          group.cpp  -  description
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

#include "group.h"



namespace Ah {

Group::Group()
	: Node()
{
}


void Group::predraw()
{
	beginSelection();
	pushMultiplyMatrix();
}

void Group::draw()
{
	Element* node = getFirst();
    while(node)
    {
		node->predraw();
    	node->draw();
    	node->postdraw();
		node = node->getNext();
	}
}

void Group::postdraw()
{
	endSelection();
    popMatrix();
}



};
