/***************************************************************************
                          modelviewmatrixstack.cpp  -  description
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

#include "modelviewmatrixstack.h"

namespace Ah {

ModelViewMatrixStack::ModelViewMatrixStack()
{
	glLoadIdentity();

}

void ModelViewMatrixStack::pop()
{
	glPopMatrix();
}

void ModelViewMatrixStack::push()
{
	glPushMatrix();
}

void ModelViewMatrixStack::pushmultiply(Matrix* matrix)
{
    glPushMatrix();
	glMultMatrixf(matrix->getArray());
}

void ModelViewMatrixStack::multiply(Matrix* matrix)
{
	glMultMatrixf(matrix->getArray());
}

void ModelViewMatrixStack::identity()
{
	glLoadIdentity();
}

ModelViewMatrixStack* ModelViewMatrixStack::_instance = 0;

ModelViewMatrixStack* ModelViewMatrixStack::instance()
{
	if(_instance == 0) {
    	_instance = new ModelViewMatrixStack;
     }
	return _instance;
}
};
