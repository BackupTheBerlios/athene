/***************************************************************************
                          shader.h  -  description
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


#ifndef SHADER_H
#define SHADER_H


#include "referencecounter.h"
#include "color.h"
/**
  *@author Marco Bubke
  */

namespace Ah {

/*!\brief abstract shader class
	The Shader class is implemented by the composite pattern. So Shader
    set the complett interface and the derived classes implemenet a part of it.
*/

class Shader : public ReferenceCounter{
public:
	Shader();
	virtual ~Shader();

    //!draws the shaded stuff
    virtual bool drawShaded() = 0;

    //!draw the outline
    virtual bool drawOutline() = 0;
    
    //!sets some stuff
    virtual void beginShader();

    //!sets some stuff back
    virtual void endShader() = 0;

    //!sets some stuff for the shading
    virtual void beginShading() = 0;

    //!sets some stuff back for the shading
    virtual void endShading() = 0;

    //!sets some stuff for the outline
    virtual void beginOutline() = 0;

    //!sets some stuff back for the outline
    virtual void endOutline() = 0;
    
    //! initilize the gl stuff
    /*!
    	You can't construct OpenGl before the OpenGL Context is there. In this function
        you do the initial OpenGL stuff, which is called if you try to paint the first time
    */
    virtual void initilize();

        //!gives the color back
    virtual Color* getColor() const = 0;


protected:
	//!you can set the if the quality is the lowest
    void setLowestQuality(bool qualitity) {lowestQuality = qualitity;}


private:
    bool initilized;
    bool lowestQuality;
};
};

#endif
