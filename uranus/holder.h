/***************************************************************************
                          holder.h  -  description
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

#ifndef HOLDER_H
#define HOLDER_H

#include "group.h"
#include "referencecounter.h"

namespace Ah {

/*!\class Holder
	A Holder is a class which points to the element. It have implemented
    reference counting, so it is shareable. It's for handling of a class outside the scene
    graph. Don't delete Holder, use unref().
	\todo copy mechanismen
*/



template<class T = Element> class Holder :  public ReferenceCounter
{
friend class Element;
public:
//    T* operator*() const {return element;}
//    T* operator->() const {return element;}
	T* getObject() const {return dynamic_cast<T*>(element);}

protected:
	~Holder();
private:
	Holder(T* element) : element(element) {}
	T* element;
};

};
#endif

