/***************************************************************************
                          simpleshader.cpp  -  description
                             -------------------
    begin                : Tue Jul 25 2002
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

#include "simpleshader.h"
#include <GL/gl.h>

namespace Ah {



SimpleShader::SimpleShader(Color* color, Color* outlineColor, float outlineWidth)
	: Shader(), color(color), outlineColor(outlineColor), outlineWidth(outlineWidth)
{
}

bool SimpleShader::drawShaded()
{
	if(!color) return false;
		glColor4fv(color->getArray());
	return true;
}

bool SimpleShader::drawOutline()
{
	if(!outlineColor) return false;
		glColor4fv(outlineColor->getArray());
	return true;
}


void SimpleShader::beginShading()
{

	if(color->getAlpha() > 0.0)
		glEnable(GL_BLEND);
}

void SimpleShader::endShading()
{
	glDisable(GL_BLEND);
}

void SimpleShader::beginOutline()
{
	if(color->getAlpha() > 0.0)
		glEnable(GL_BLEND);
  	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   	glLineWidth(outlineWidth);

}

void SimpleShader::endOutline()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_BLEND);
}

void SimpleShader::setColor(Color* newcolor)
{
	if (color) color->unref();
	color = newcolor;
    color->ref();
}

void SimpleShader::setOutlineColor(Color* newcolor)
{
	if (outlineColor) outlineColor->unref();
	outlineColor = newcolor;
	outlineColor->ref();
}

void SimpleShader::setOutlineWidth(float width)
{
	outlineWidth = width;
}


};
