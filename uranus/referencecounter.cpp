/***************************************************************************
                          referencecounter.cpp  -  description
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



#include "referencecounter.h"



namespace Ah {

ReferenceCounter::ReferenceCounter()
	: counter(0)
{
}

void ReferenceCounter::unref()
{
    if(--counter < 1)   delete this;
}
};
