/***************************************************************************
                          matrixstack.h  -  description
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

#ifndef MATRIXSTACK_H
#define MATRIXSTACK_H

#include "matrix.h"

namespace Ah {

template <class T> class MatrixStack
{
public:

    //!pop the matrix off the stack
    static void pop() = 0;

    //!push the matrix on the stack
    static void push() = 0;

    //!push the matrix on the stack and multiply
    static void pushmultiply(Matrix* matrix) = 0;
    
    //!give the instance back
    static MatrixStack<T>* instance();

protected:

	MatrixStack();

private:

	static MatrixStack<T>* _instance;

};
};



#endif
