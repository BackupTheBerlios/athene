/***************************************************************************
                          shader.cpp  -  description
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


#include "shader.h"
#include "canvas.h"

namespace Ah {

Shader::Shader() : ReferenceCounter(), initilized(false), lowestQuality(false)
{
}

Shader::~Shader() {}

void Shader::initilize()
{
}

void Shader::beginShader()
{
	if(!initilized || (Canvas::getRenderingHint()&& !lowestQuality))
    {
    	initilize();
		initilized = true;
	}
}

};

