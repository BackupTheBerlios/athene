/***************************************************************************
                          main.cpp  -  description
                             -------------------
    begin                : Tue Jul 23 17:43:26 CEST 2002
    copyright            : (C) 2002 by Marco Bubke
    email                : marco@bubke.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/



#include <qapplication.h>

#include "qcanvas.h"
#include "rectangle.h"
#include "color.h"
#include "simpleshader.h"
#include "texture.h"
#include "textureshader.h"
#include "qimage.h"
#include <stdlib.h>



int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    Ah::QCanvas* canvas = new Ah::QCanvas(0);


    for (int i2 = 0; i2 < 10; i2++)
    {
      Ah::Group* group = new Ah::Group();
      canvas->appendChild(group);

      group->getMatrix()->move((0.5 - drand48())*1000, (0.5 - drand48()) *1000);
	  group->getMatrix()->rotate(drand48()*3.14);

      for(int i = 0; i< 20; i++)
      	{
    	Ah::Rectangle* rect = new Ah::Rectangle(0.0, 0.0, 10, 10);
        Ah::SimpleShader* shader = new Ah::SimpleShader(new Ah::Color(drand48(), drand48(), drand48(), 0.0));
        rect->getMatrix()->move((0.5 - drand48())*1000, (0.5 - drand48()) *1000);
        rect->getMatrix()->scale(drand48());
        rect->setShader(shader);
        rect->getMatrix()->rotate(drand48()*3.14);
    	group->appendChild(rect);
    	}
       for(int i = 0; i< 2; i++)
      	{
    	Ah::Rectangle* rect = new Ah::Rectangle(0.0, 0.0, 10, 10);
        Ah::SimpleShader* shader = new Ah::SimpleShader(new Ah::Color(drand48(), drand48(), drand48(), 0.0), \
        												new Ah::Color(drand48(), drand48(), drand48(), 0.0));
        rect->getMatrix()->move((0.5 - drand48())*1000, (0.5 - drand48()) *1000);
		rect->getMatrix()->scale(drand48());
		rect->getMatrix()->rotate(drand48()*3.14);
        rect->setShader(shader);
    	group->appendChild(rect);
    	}


    }
	Ah::Rectangle* rect = new Ah::Rectangle(0.0, 0.0, 1.0, 1.0);
    rect->getMatrix()->movePivotTo(0.5, 0.5);
	Ah::Rectangle* rect2 = new Ah::Rectangle(0., 0., 300., 300.);
    rect2->getMatrix()->movePivotTo(150., 150.);
    rect->getMatrix()->move(-500., -500.0);
    rect->getMatrix()->scale(1000);

	QImage buf, tex;
	buf.load("traum.bmp");
    tex  = QGLWidget::convertToGLFormat( buf );
    Ah::Texture* texture = new Ah::Texture(tex.bits(), 4, tex.width(), tex.height());
    Ah::TextureShader* shader = new Ah::TextureShader(texture, new Ah::Color(1., 1.0, 1.0, 0.5),new Ah::Color(0., .0, 1.0, 0.0) );
	Ah::SimpleShader* shader2 = new Ah::SimpleShader(new Ah::Color(.9, .9, .9, 0.0));
    rect->setShader(shader);
    rect2->setShader(shader2);
    canvas->appendChild(rect2);
    canvas->appendChild(rect);


    a.setMainWidget( canvas );
    canvas->show();
    return a.exec();
}
