/***************************************************************************
                          group.h  -  description
                             -------------------
    begin                : Tue Jul 2 2002
    copyright            : (C) 2002 by Marco Bubke
    email                : marco@bubke.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        *
 *   published by the Free Software Foundation;        version 2.1 of      *
 *   the License.                                                          *
 *                                                                         *
 ***************************************************************************/

#ifndef GROUP_H
#define GROUP_H

#include "node.h"



namespace Ah {

class Canvas;

//! Group Class
/*! \class Group
	The group class is something special. It can contain other nodes. There is
    the first and the last pointer, which point the first and the last node in the group.
    The previous pointer of the first node points to group and the next pointer of the last too.
*/
class Group : public Node
{
public:
	Group();


protected:
	//! drawing function
    virtual void draw();

    //! predraw function
    virtual void predraw();

    //!postdraw function
    virtual void postdraw();


};
};
#endif
