/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation; 2.1 of the License.        *
 *                                                                         *                                                                         *
 ***************************************************************************/

#include "matrix.h"

namespace Ah {

template<class T> MatrixStack<T>::MatrixStack()
{
}

template<class T> MatrixStack<T>* MatrixStack<T>::_instance = 0;

template<class T> MatrixStack<T>* MatrixStack<T>::instance()
{
	if(_instance =0) {
    	_instance = new MatrixStack<T>;
     }
	return _instance;
}
};