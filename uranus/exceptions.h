/***************************************************************************
                          exeptions.h  -  description
                             -------------------
    begin                : Tue Jul 24 2002
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

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H



namespace Ah {

/*!
  	This
  */

class Exception {};

class NoNullPointer : public Exception {};

class NoShader : public Exception {};

class HasNode : Exception{};

class HasParent :public HasNode {};

class HasPredecessor :public HasNode {};

class HasSuccessor :public HasNode {};

class NoElement : public Exception {};

};

#endif
