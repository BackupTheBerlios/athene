/***************************************************************************
                          texture.h  -  description
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

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>

#include "referencecounter.h"

namespace Ah {

class Texture : public ReferenceCounter
{
public:
	Texture(unsigned char* texture = 0, int colordepth = 4, unsigned int width = 1, unsigned int height = 1, unsigned int depth = 1);
	~Texture();
	unsigned int getWidth() const {return width;}
    unsigned int getHeight() const {return height;}
    unsigned int getDepth() const {return depth;}
    int getColorDepth() const {return colordepth;}
    GLenum getFormat() const {return format;}
    unsigned char* getArray() const {return texture;}

private:
	unsigned int width;
    unsigned int height;
    unsigned int depth;
    int colordepth;
    GLenum format;
    unsigned char* texture;
};
};

#endif
