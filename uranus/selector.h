/***************************************************************************
                          selector.h  -  description
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

#ifndef SELECTOR_H
#define SELECTOR_H

#include "referencecounter.h"
#include "holder.h"

namespace Ah {

/*!\class Holder
	Traverse the graph and find the selected elements
*/


class Selector
{
public:
	/*!
    	\param root the selection root element, typicly the canvas
		\param array the selection array
	*/
	Selector(SelectionArray* array);
    
    ~Selector();

	//!gives you the next element back
    Holder<Element>* next();
private:
    unsigned int* pointer;
	SelectionArray* array;
};

};
#endif
