/***************************************************************************
                          color.h  -  description
                             -------------------
    begin                : Tue Jul 23 2002
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
#ifndef COLOR_H
#define COLOR_H

#include "referencecounter.h"


namespace Ah {

//! Color Class
/*!\class Color
	This is the Color class. It used floats to represent
    the 4 Elements red, green, blue and alpha. Alpha stand for the transparency.
  */
class Color : public ReferenceCounter{
public:
	/*!
    	\param red  0.0 means no red, 1.0 full red.
		\param green 0.0 means no green, 1.0 full green.
        \param blue 0.0 means no red, 1.0 full blue.
        \param alpha 0.0 means opaque, 1.0 full transparency.
	*/
	Color(const float red = 1.0, const float green = 1.0, const float blue = 1.0, const float alpha = 0.0);
    //! get back a float array of 4 elements
    float getRed() const { return color[0];}
    float getGreen() const { return color[1];}
    float getBlue() const { return color[2];}
    float getAlpha() const { return color[3];}
    const float* getArray() const { return color;}
    void setRed(const float red) {color[0] = red;}
	void setGreen(const float green) {color[1] = green;}
	void setBlue(const float blue) {color[2] = blue;}
	void setAlpha(const float alpha) {color[3] = alpha;}
    void setColor(const float red, const float green, const float blue, const float alpha)
    	{color[0] = red; color[1] = green; color[2] = blue; color[3] = alpha;}
private:

	 float color[4];
};
};
#endif
