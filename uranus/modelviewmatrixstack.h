/***************************************************************************
                          modelviewmatrixstack.h  -  description
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

#ifndef MODELVIEWMATRIXSTACK_H
#define MODELVIEWMATRIXSTACK_H

#include "matrix.h"

namespace Ah {


class ModelViewMatrixStack
{
public:

    //!pop the matrix off the stack
    static void pop();

    //!push the matrix on the stack
    static void push();

    //!push the matrix on the stack and multiply
    static void pushmultiply(Matrix* matrix);

    //!set the identity matrix
    static void identity();

    //!multiplay matrix with stack
    static void multiply(Matrix* matrix);

    //!give the instance back
    static ModelViewMatrixStack* instance();

protected:

	ModelViewMatrixStack();

private:

	static ModelViewMatrixStack* _instance;

};
};

#endif
