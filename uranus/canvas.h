/***************************************************************************
                          canvas.h  -  description
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

#ifndef CANVAS_H
#define CANVAS_H


#include "color.h"
#include "group.h"
#include "modelviewmatrixstack.h"
//! The abstract canvas class
/*!
  *
  */
namespace Ah {

class Canvas : public Group {
public:
	Canvas();
	~Canvas();



    //!set the viewport of the canvas
    void setViewport(int width, int height);

    void setBackgroundColor(Color& color) { bgcolor = color;}
    Color& getBackgroundColor() const { return bgcolor;}

	//!get the model view matrix stack
    ModelViewMatrixStack* getModelViewMatrixStack() const { return modelview;}
    
 	//!sets the virtual limit for the rendering of one frame
	void setRenderingTimeBound(double bound) { renderingTimeBound = bound;}

 	//!gives back, if the renderingtime to slow or very fast
    /*!
    	negative values means to slow, positives it is very fast,
        zero means is ok.
    */
    static int getRenderingHint() { return renderingHint;}

protected:
    virtual void predraw();
	virtual void draw();
    virtual void postdraw();
    virtual void initilize();

    //! sets the rendering time
    /*!
    	its a hint to let the stuff be fluid
     */
    void setRenderingTime(double elapsed) { renderingTime = elapsed;}

    //!get the rendering time of teh last frame
    double getRenderingTime() const{return renderingTime;}

    //!get the limit for the rendering time
    double getRenderingTimeBound() const{return renderingTimeBound;}



    //!test the rendering time changed value
    void testRenderingTime();

private:

	mutable Color bgcolor;
	ModelViewMatrixStack* modelview;
        
	//! rendering time
    double renderingTime;

    //! rendering time bound
    double renderingTimeBound;

    //! rendering time changed negative to slow, positive to fast :-)
    static int	renderingHint;

};
};
#endif
