/***************************************************************************
                          matrix.h  -  description
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

#ifndef MATRIX_H
#define MATRIX_H

#include "referencecounter.h"

namespace Ah {

class Matrix : public ReferenceCounter
{
public:
	Matrix();
    //! relative move
    void move(float x, float y);
    void zoom(float zoom);
    void rotate(float angle);
    void scale(float x, float y);
    void scale(float factor);
    //!move the origin relative
    void movePivot(float x, float y);
    //!move the origin to this point
	void movePivotTo(float x, float y);
    void setIdentity();
    inline float* getArray() const { return matrix;}
private:
    float pivotx;
    float pivoty;
    mutable float matrix[16];
};
};

#endif
