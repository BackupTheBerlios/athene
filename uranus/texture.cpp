/***************************************************************************
                          texture.cpp -  description
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

#include "texture.h"
#include "cstring"
namespace Ah {

Texture::Texture(unsigned char *data, int colordepth, unsigned int width, unsigned int height, unsigned int depth)
	:  width(width), height(height), depth(depth), colordepth(colordepth), format(GL_RGBA)
{
	unsigned int count = colordepth * width * height * depth;
    texture = new unsigned char[count];
	std::memcpy(texture, data, count);
}

Texture::~Texture()
{
	delete [] texture;

}

};
