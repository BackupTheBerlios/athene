/***************************************************************************
                          holder.cpp  -  description
                             -------------------
    begin                : Tue Jul 28 2002
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

#include "holder.h"


namespace Ah {



template<class T> Holder<T>::~Holder()
{
	element->removeHolder();
}
};
