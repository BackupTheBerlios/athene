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


#ifndef SIMPLESHADER_H
#define SIMPLESHADER_H

#include "shader.h"
#include "color.h"

/**
  *@author Marco Bubke
  */

namespace Ah {

/*!\brief simple shader class
	This class is implementing only the color part
*/

class SimpleShader : public Shader {
public:
    SimpleShader(Color* color = 0, Color* outlineColor = 0, float outlineWidth = 1);

    //!draw flat shaded
    virtual bool drawShaded();

    //!draw flat shaded
    virtual bool drawOutline();


    //!sets some stuff back
    virtual void endShader() {};

    //!sets some stuff for the shading
    virtual void beginShading();

    //!sets some stuff back for the shading
    virtual void endShading();

    //!sets some stuff for the outline
    virtual void beginOutline();

    //!sets some stuff back for the outlne
    virtual void endOutline();

    //!set the color
    void setColor(Color* color);

    //!set outline Color
    void setOutlineColor(Color* outlineColor);

    //! set the width of the outline
    void setOutlineWidth(float width);
    
    //!gives the color back, don't forget to call ref()
    virtual Color* getColor() const {return color;}
private:
	Color* color;
    Color* outlineColor;
    float  outlineWidth;
};
};

#endif
