/***************************************************************************
                          element.h  -  description
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

#ifndef ELEMENT_H
#define ELEMENT_H

#include <stack>

namespace Ah {

template<class T> class Holder;

class Selector;

class Element;

struct SelectionArray
{
	SelectionArray(unsigned int* array, int count, Element* root)
    	: array(array), count(count), root(root) {}
	unsigned int* array;
 	int count;
    Element* root;
};

//!the element class
/*!\class Element
	Never delete Elements, if you have pointer to elements, this can be dangerous!
    Better hide them.
*/


class Element
{
friend class Holder<Element>;
friend class Selector;
public:
	Element();


	//! the drawing function
    virtual void draw() = 0;

	//! the predrawing function
    /*!
		It should be called before all the draw stuff is called
     */
	virtual void predraw() = 0;

    //! the postdrawing function
    /*!
		It should be called after all the draw stuff is called
     */
    virtual void postdraw() = 0;
    
    //! selection function
    virtual void select() = 0;

    //!get the next node
    Element* getNext() const {return next;}

    //!get previous node
    Element* getPrevious() const {return previous;}

    //!get parent node
	Element* getParent() const {return parent;}

    //!get first node in group
    Element* getFirst() const {return first;}

    //!get last node in group
    Element* getLast() const {return last;}



    //! is appending node after this element
    void appendElement(Element* element);

    //! is prepending node before this element
    void prependElement(Element* element);

    //! append a node at the end of the group
	void appendChild(Element* element);

    //! prepend a node before the beginning of the group
    void prependChild(Element* element);

    //!use remove instead of the delete operator
    /*!
    	This function checks if there are a holder, if so, it dount delete this element, it takes it only
        out of the scene graph.
    */
    void remove();

    //!takes the element out of the scene graph
    Element* takeout();

    //!add teh holder
    Holder<Element>* getHolder();

    //!get the selections
	SelectionArray* getSelections(double x, double y, double width, double height);

 //   void event(Event* event);

 


protected:

	//!\todo Child removing
    virtual ~Element();


    //!sets the parent of the node
    /*!

    	\param parent Pointer to the parent element
	*/
    inline void setParent(Element* parent);

    //!sets the previous node
    /*!

    	\param parent Pointer to the previous element
	*/
	inline void setPrevious(Element* previous);

    //!sets the next node
    /*!

    	\param parent Pointer to the next element
	*/
    inline void setNext(Element* next);

    //!sets the first node
    /*!

    	\param parent Pointer to the first element
	*/
    inline void setFirst(Element* first);

    //!sets the last node
    /*!

    	\param parent Pointer to the last element
	*/
    inline void setLast(Element* last);

    //!initilize function
    /*!
    	The initilize function will be called at the inserting in the scene graph.
    */
    virtual void initilize();

    //! set the stopper for drawing
    /*!
    	after this element the drawing will be stoppt
    */
	void setStopDrawing(bool stopper = true) {stopdrawing = stopper;}

    //!get the stopper state
    bool isDrawingStopped() const {return stopdrawing;}

    //!begin the selection
    void beginSelection() const;

    //!end the selection range
    void endSelection() const;
    


private:
    //!remove the holder
    void removeHolder();

	//! points to the next drawed element
	Element *next;

    //! points to the previous element
    Element *previous;

    //! points to the parent element
    Element *parent;

	//!first element in the element
    Element *first;

    //!last element in the element
    Element *last;

    //!element set
    Holder<Element> *holder;

    //! selection number
    unsigned int selectionNumber;

    //! selection counter
    static unsigned int selectionCounter;

    //! stop drawing in this element
    bool stopdrawing;

    //! tell if mode is selection mode
    static bool selectionMode;


};
};

#endif
