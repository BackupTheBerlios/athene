/***************************************************************************
                          referencecounter.h  -  description
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

#ifndef REFERENCECOUNTER_H
#define REFERENCECOUNTER_H



namespace Ah {

class ReferenceCounter
{
public:
	ReferenceCounter();
    //!counts the reference one up
	void ref() { counter++; }
    //!counts the reference one down
    /*!
    	If the counter zero than delete the object
     */
	void unref();

private:
	int counter;
};
};

#endif
