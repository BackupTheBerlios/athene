/***************************************************************************
                          node.cpp  -  description
                             -------------------
    begin                : Tue Jul 23 2002
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

#include "node.h"
#include "exceptions.h"
#include "group.h"



namespace Ah {



Node::Node()
	: Element(), matrix(0), shader(0), displaylist(0),
    	cached(false)
{
}

//! \todo Implement the destructor right
Node::~Node()
{
	if(matrix) matrix->unref();
    if(shader) shader->unref();
}

/*!
	predraw() pushes the matrix stack one up and than multiplay the node node matrix with the
    matrixstack. After that it sets a display list on, if possible.
*/
void Node::predraw()
{
	pushMultiplyMatrix();
	beginSelection();
}

/*!
	postdraw() calls the displaylist if possible, sets the cache state true, pops the
    matrix off the stack and
    calls the draw() function of the next node.
*/

void Node::postdraw()
{
	endSelection();
	popMatrix();
}

void Node::select()
{
	draw();
}

void Node::beginList()
{
    if(!cached)
    	if(displaylist)
     	{
    		glNewList(displaylist, GL_COMPILE_AND_EXECUTE);
            generateList = true;
      	}
		else
        {
			displaylist = glGenLists(1);
        	if(displaylist)
            {
				glNewList(displaylist, GL_COMPILE_AND_EXECUTE);
				generateList = true;
    		}
    	}
    else
    	if(!displaylist)
    	{
			displaylist = glGenLists(1);
        	if(displaylist)
         	{
				glNewList(displaylist, GL_COMPILE_AND_EXECUTE);
				generateList = true;
    		}
    		else
            	cached = false;
    	}
}

void Node::endList()
{

	if(cached && displaylist)
    	glCallList(displaylist);
	if(generateList)
 	{
    	glEndList();
    	cached = true;
		generateList = false;
    }
}




void Node::pushMultiplyMatrix()
{
	if(matrix) modelview->pushmultiply(matrix);
}

void Node::multiplyMatrix()
{
	if(matrix) modelview->multiply(matrix);
}



void Node::popMatrix()
{
	if(matrix) modelview->pop();
}

Matrix* Node::getMatrix()
{
	if(!matrix) matrix = new Matrix();
    matrix->ref();
	return matrix;
}

Shader* Node::getShader()
{
	if(shader) return shader;
    if(getParent()) 
    	{
        Node* node = dynamic_cast<Node*>(getParent());
        if(node)
        	node->getShader();
        }
    throw NoShader();

}

void Node::setMatrix(Matrix* newmatrix)
{
	newmatrix->ref();
    if(matrix) matrix->unref();
    matrix = newmatrix;
}

void Node::setShader(Shader* newshader)
{
	newshader->ref();
    if(shader) shader->unref();
    shader = newshader;
}

void Node::setChanged()
{
	cached = false;
}


GLuint Node::getDisplayList()
{
	if(displaylist)
    	return displaylist;
	else
    	return displaylist = glGenLists(1);
}

};
