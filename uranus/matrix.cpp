/***************************************************************************
                          matrix.cpp  -  description
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

#include "matrix.h"
#include "math.h"

namespace Ah {

Matrix::Matrix()
	: ReferenceCounter(), pivotx(0), pivoty(0)
{
	setIdentity();
}

void Matrix::setIdentity()
{
	matrix[0] = 1.0;
    matrix[1] = 0.0;
    matrix[2] = 0.0;
    matrix[3] = 0.0;
    matrix[4] = 0.0;
    matrix[5] = 1.0;
    matrix[6] = 0.0;
    matrix[7] = 0.0;
	matrix[8] = 0.0;
    matrix[9] = 0.0;
    matrix[10] = 1.0;
    matrix[11] = 0.0;
    matrix[12] = 0.0;
    matrix[13] = 0.0;
    matrix[14] = 0.0;
    matrix[15] = 1.0;
}

void Matrix::scale(float x, float y)
{
	matrix[0] *= x;
    matrix[1] *= x;
    matrix[4] *= y;
    matrix[5] *= y;
}

void Matrix::scale(float factor)
{
	matrix[0] *= factor;
    matrix[1] *= factor;
    matrix[4] *= factor;
    matrix[5] *= factor;
}

void Matrix::move(float x, float y)
{
	matrix[12] += -x * matrix[0] + -y * matrix[4];
    matrix[13] += -x * matrix[1] + -y * matrix[5];
}

void Matrix::zoom(float factor)
{
	matrix[0] *= 1/factor;
    matrix[1] *= 1/factor;
    matrix[4] *= 1/factor;
    matrix[5] *= 1/factor;
}

void Matrix::rotate(float angle)
{
	matrix[12] += pivotx * matrix[0] + pivoty * matrix[4];
    matrix[13] += pivotx * matrix[1] + pivoty * matrix[5];
    float cosinus = cosf(angle);
    float sinus = sinf(angle);
 	float tmp0 = matrix[0] * cosinus + matrix[4] * sinus;
    float tmp1 = matrix[1] * cosinus + matrix[5] * sinus;
    matrix[4] = matrix[0] * -sinus + matrix[4] * cosinus;
	matrix[5] = matrix[1] * -sinus + matrix[5] * cosinus;
    matrix[0] = tmp0;
    matrix[1] = tmp1;
    matrix[12] += -pivotx * matrix[0] + -pivoty * matrix[4];
    matrix[13] += -pivotx * matrix[1] + -pivoty * matrix[5];
 }

void Matrix::movePivot(float x, float y)
{
	pivotx += x;
    pivoty += y;
}

void Matrix::movePivotTo(float x, float y)
{
	pivotx = x;
    pivoty = y;
}

/*
void Matrix::rotate(float angle)
{
	float cosinus = cosf(angle);
    float sinus = sinf(angle);
    float  tmp1 = cosinus * matrix[0] + -sinus * matrix[1];
    matrix[1] = sinus * matrix[0] + cosinus * matrix[1];
    matrix[0] = tmp1;
    float tmp4 = cosinus * matrix[4] + -sinus * matrix[5];
    matrix[5] = sinus * matrix[4] + cosinus * matrix[5];
    matrix[4] = tmp4;
    float tmp12 = cosinus * matrix[12] + -sinus * matrix[13];
    matrix[13] = sinus * matrix[12] + cosinus * matrix[13];
    matrix[12] = tmp12;
}

void Matrix::move(float x, float y)
{
	matrix[12] += -x * matrix[15];
    matrix[13] += -y * matrix[15];
}

void Matrix::zoom(float zoom)
{
	matrix[15] *= zoom;
}

void Matrix::scale(float x, float y)
{
	matrix[0] *= x;
    matrix[1] *= x;
    matrix[4] *= y;
    matrix[5] *= y;
    matrix[12] *=  x;
    matrix[13] *=  y;
}

void Matrix::scale(float factor)
{
	matrix[0] *= factor;
    matrix[1] *= factor;
    matrix[4] *= factor;
    matrix[5] *= factor;
    matrix[12] *= factor;
    matrix[13] *= factor;

}
*/
};
