#include <iostream>
#include <GL/freeglut.h>

#include "render.hh"

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    initGL();
    glutMainLoop();
    return 0;
}