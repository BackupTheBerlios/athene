####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = athene

## INCLUDES were found outside kdevelop specific part

athene_SOURCES = qcanvas.cpp canvas.cpp node.cpp context.cpp shader.cpp main.cpp 
athene_LDADD   = -lGLU -lGL -lm -lqt -lXext -lX11

SUBDIRS = docs 

EXTRA_DIST = main.cpp shader.cpp shader.h context.cpp context.h node.cpp node.h canvas.cpp canvas.h qcanvas.cpp qcanvas.h 

####### kdevelop will overwrite this part!!! (end)############
# set the include path found by configure
INCLUDES= $(all_includes)
 
# the library search path.
athene_LDFLAGS = $(all_libraries) 
                                                                                
