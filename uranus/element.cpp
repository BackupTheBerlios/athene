/***************************************************************************
                          element.cpp  -  description
                             -------------------
    begin                : Tue Jul 26 2002
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

#include <GL/glu.h>
#include <iostream>

#include "element.h"
#include "holder.h"


namespace Ah {




unsigned int Element::selectionCounter = 1;

bool Element::selectionMode = false;

Element::Element()
	: next(0), previous(0), parent(0), first(0), last(0), holder(0), stopdrawing(false)
{
	selectionNumber = selectionCounter++;
}

Element::~Element()
{
	holder = 0;
    if(first) first->remove();
    next = 0;
    previous = 0;
    parent = 0;
    first = 0;
    last = 0;
}

void Element::remove()
{
	if(next && next) {
    	previous->setNext(next);
    	next->setPrevious(previous); }
 	else if (previous) {
		parent->setLast(previous);
		previous->setNext(0);}
  	else if(next) {
		parent->setFirst(next);
		next->setPrevious(0);}
  	else {
		parent->setLast(0);
        parent->setFirst(0);
        }
    if(!holder)
    	delete this;
    else
    {
    next = 0;
    previous = 0;
    parent = 0;
    }
}

Element* Element::takeout()
{
	if(next && next) {
    	previous->setNext(next);
    	next->setPrevious(previous); }
 	else if (previous) {
		parent->setLast(previous);
		previous->setNext(0);}
  	else if(next) {
		parent->setFirst(next);
		next->setPrevious(0);}
  	else {
		parent->setLast(0);
        parent->setFirst(0);
        }


    next = 0;
    previous = 0;
    parent = 0;
    return this;
}

void Element::appendElement(Element* element)
{
	element->setPrevious(this);
    element->setNext(next);
    if(next)
		next->setPrevious(element);
 	else
    	parent->setLast(element);
    next = element;
    element->setParent(parent);
    element->initilize();
}

void Element::prependElement(Element* element)
{
	element->setPrevious(previous);
    element->setNext(this);
    if(previous)
    	previous->setNext(element);
    else
		parent->setFirst(element);
	previous = element;
    element->setParent(parent);
    element->initilize();
}

void Element::appendChild(Element* element)
{
	if(last)
		last->appendElement(element);
  	else
    {
    	last = element;
        first = element;
        element->setNext(0);
        element->setPrevious(0);
        element->setParent(this);
     	}
}

void Element::prependChild(Element* element)
{
	if(first)
    	first->prependElement(element);
	else
    {
    	last = element;
        first = element;
        element->setNext(0);
        element->setPrevious(0);
        element->setParent(this);
        }
}

void Element::setParent(Element* element)
{
	parent = element;

}

void Element::setPrevious(Element* element)
{
	previous = element;

}

void Element::setNext(Element* element)
{
	next = element;

}

void Element::setFirst(Element* element)
{
	first = element;

}

void Element::setLast(Element* element)
{
	last = element;

}

void Element::initilize()
{
}

void Element::removeHolder()
{
	holder=0;
}

Holder<>* Element::getHolder()
{
	if(!holder)
		holder = new Holder<>(this);
  	holder->ref();
    return holder;
}

void Element::beginSelection() const
{
	if(selectionMode)
    	if(getFirst())
        	{
            glLoadName(selectionNumber);
    		glPushName(selectionNumber);
            }

      	else
			glLoadName(selectionNumber);
}

void Element::endSelection() const
{
	if(selectionMode)
    	if(getFirst())
			glPopName();


}

SelectionArray* Element::getSelections(double x, double y, double width, double height)
{

	unsigned int selectionBufferDepth = selectionCounter;
	unsigned int* selectionBuffer = 0;
    int hits = 0;
    int viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);





    selectionMode = true;
	do {
    	if(selectionBuffer) delete selectionBuffer;
		selectionBuffer = new unsigned int[selectionBufferDepth];
        glSelectBuffer(selectionBufferDepth, selectionBuffer);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluPickMatrix(x, y, width, height, viewport);
        gluOrtho2D(static_cast<GLdouble>(viewport[0]), static_cast<GLdouble>(viewport[2]), \
        			static_cast<GLdouble>(viewport[1]), static_cast<GLdouble>(viewport[3]));
        glMatrixMode(GL_MODELVIEW);
  		glRenderMode(GL_SELECT);
        glInitNames();
        glPushName(0); //initial ID
		select();
    	hits = glRenderMode(GL_RENDER);
		std::cout << "hits "<<hits<<"\n";
        glMatrixMode(GL_PROJECTION);
 	    glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		selectionBufferDepth *= 2;
	}
	while(hits == -1);
    selectionMode = false;
    SelectionArray* selectionArray = new SelectionArray(selectionBuffer, hits, this);

	return selectionArray;

}


};

