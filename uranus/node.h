/***************************************************************************
                          node.h  -  description
                             -------------------
    begin                : Tue Jul 23 2002
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


#ifndef NODE_H
#define NODE_H

#include <GL/gl.h>

#include "element.h"
#include "modelviewmatrixstack.h"
#include "shader.h"


/*!
  	This this the abstract Node Interface, every Node should implement it.
  */

namespace Ah {

static ModelViewMatrixStack* modelview = ModelViewMatrixStack::instance();

class Group;
class Canvas;

class Node :public Element
{
friend class Group;
friend class Canvas;
public:
	//! default constructor of all nodes
	Node();
	virtual ~Node();


    //!sets the matrix of the node
    void setMatrix(Matrix* matrix);

    //!get the matrix
    Matrix* getMatrix();

    //!sets the shader of teh node
	void setShader(Shader* shader);

    //!get the shader
    Shader* getShader();


protected:

	//! the drawing function
    virtual void draw() = 0;

	//! the predrawing function
    /*!
		It should be called before all the draw stuff is called
     */
	virtual void predraw();

    //! the postdrawing function
    /*!
		It should be called after all the draw stuff is called
     */
    virtual void postdraw();

	//!selection function calls draw()
    virtual void select();

    //! multiply the matrix with the modelview matrix and push it on the stack
	void pushMultiplyMatrix();
    
    //! multiply the matrix with the modelview matrix
	void multiplyMatrix();


    //! pop matrix off the matrix stack
	void popMatrix();
    
    //!give the display list back
    GLuint getDisplayList();


    //!gives back if the cache is ok
    bool isCached() const {return cached;}

    //!set the if the cache is ok
	void setChanged();

	//! set the beginning of a display list
	/*!
		Set this function before you want begin the display list of the node
		If you want draw multipass than set it before every pass. beginList(); if(!getCacheState()) {render some stuff}
    	endList(); do something beginList(); if(!getCacheState()) {render the some stuff} endList();. Why should
    	I do something so stupid?
    	beginList() try to set a display list. so the second stuff will proberly never called. Instead the display list
     	will be rendered.
	*/
	void beginList();

    //! set the ending of a display list
    void endList();




private:

    //!matrix of the node
    Matrix *matrix;

    //!shader of the node
    Shader *shader;

    //!displaylist for chaching
    GLuint displaylist;

    //!is cache ok
    bool cached;
    
    //!generate list
    bool generateList;
};
};
#endif
