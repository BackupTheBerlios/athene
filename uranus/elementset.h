/***************************************************************************
                          elementset.h  -  description
                             -------------------
    begin                : Tue Jul 26 2002
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

#ifndef ELEMENTSET_H
#define ELEMENTSET_H

#include "element.h"
#include "referencecounter.h"

namespace Ah {



/*!\class ElementSet
	Holds the ElementCovers
*/


class ElementSet
{
public:
	ElementSet();

    void removeElement(ElementHolder* element);
	void addElement(ElementHolder* element);
};

};
#endif
