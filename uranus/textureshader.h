/***************************************************************************
                          simpleshader.h  -  description
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


#ifndef TEXTURESHADER_H
#define TEXTURESHADER_H

#include "simpleshader.h"
#include "texture.h"

/**
  *@author Marco Bubke
  */

namespace Ah {

/*!\brief texture shader class
	This class is implementing also texturing*/

class TextureShader : public SimpleShader {
public:
    TextureShader(Texture* texture = 0, Color* color = 0, Color* outlineColor = 0, float outlineWidth = 1, int border = 0);

    ~TextureShader();

    //!draw flat shaded
    virtual bool drawShaded();

    //!sets some stuff for the shading
    virtual void beginShading();

    //!sets some stuff back for the shading
    virtual void endShading();

    //!set GL stuff
	virtual void initilize();



private:
	Texture* texture;
    int border;
    unsigned int textureObject;

};
};

#endif
