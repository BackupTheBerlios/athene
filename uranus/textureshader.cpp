/***************************************************************************
                          textureshader.cpp -  description
                             -------------------
    begin                : Tue Jul 27 2002
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

#include "textureshader.h"
#include <GL/glu.h>

#include "canvas.h"

namespace Ah {


TextureShader::TextureShader(Texture* texture, Color* color, Color* outlineColor, float outlineWidth, int border)
	: SimpleShader(color, outlineColor, outlineWidth), texture(texture), border(border), textureObject(0)
{}

TextureShader::~TextureShader()
{
	if(textureObject) glDeleteTextures(1, &textureObject);
}
void TextureShader::beginShading()
{
	SimpleShader::beginShading();
	glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);


}

bool TextureShader::drawShaded()
{
	SimpleShader::drawShaded();
    glBindTexture(GL_TEXTURE_2D, textureObject);
    return true;
}
void TextureShader::endShading()
{
	glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	SimpleShader::endShading();
}

void TextureShader::initilize()
{

	SimpleShader::initilize();
	glGenTextures(1, &textureObject);

    glBindTexture(GL_TEXTURE_2D, textureObject);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    if(Canvas::getRenderingHint() < 1000) {
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        setLowestQuality(true);
	}
    else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		setLowestQuality(false);
	}
    gluBuild2DMipmaps(GL_TEXTURE_2D, texture->getColorDepth(), texture->getWidth(), texture->getHeight(), \
		texture->getFormat(), GL_UNSIGNED_BYTE, texture->getArray());

//  	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
}
};
