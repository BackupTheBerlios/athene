/***************************************************************************
                          selector.cpp  -  description
                             -------------------
    begin                : Tue Jul 29 2002
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


#include "selector.h"
#include "exceptions.h"

namespace Ah {

Selector::Selector(SelectionArray* array)
 :  pointer(array->array), array(array)
{
}

Selector::~Selector()
{
	//here is a memory leak!
	delete array;
}

Holder<Element>* Selector::next()
{
	if (array->count==0) return 0;
    unsigned int lastPosition;
	unsigned int id;
	unsigned int position = 3;
    Holder<Element>* holder = 0;

    Element * elem = array->root;
	array->count--;
	lastPosition = *pointer + 2; //get the position of the last id

 	while(true){
  		id = pointer[position];
    	while(true) {
			if(elem->selectionNumber == id) break;
   			elem = elem->getNext();
      		if(!elem) throw NoElement();
       		}
		if(position < lastPosition)
  		{
    		elem = elem->getFirst();
      		position++;
        }
        else
        	break;
	}

    pointer +=(*pointer)+3;

    holder = elem->getHolder();
    holder->ref();

	return holder;

}


};
