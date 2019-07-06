#include <iostream>
#include <math.h>
#include <GL/freeglut.h>
#include "render.hh"

#define WIDTH  640
#define HEIGHT 640

void poly(GLfloat x, GLfloat y, GLfloat sizex, GLfloat sizey, GLfloat sides, GLfloat rotation, GLenum SHAPE_MODE)
{
    GLfloat angleIncrement = (360.0f / sides) * M_PI / 180.0f;
    glBegin(SHAPE_MODE);
        GLfloat angle = 0.0f - rotation;
        for (size_t _k = 0; _k < sides; ++_k) {
            glVertex2f(x + (sizex * cos(angle)), y + (sizey * sin(angle)));
            angle += angleIncrement;
        }
    glEnd();
}

void initGL(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2220, 200);
    glutCreateWindow("Grafkom-Asdos-Tugas2");

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(renderDisplay);
    glutTimerFunc(50, updateDisplay, 50);

    gluOrtho2D(0, WIDTH, HEIGHT, 0);
}

void updateDisplay(int value){
    glutPostRedisplay();
    glutSwapBuffers();
    glutTimerFunc(value, updateDisplay, value);
}

void renderDisplay(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glScalef(1, 0.7, 1);
    glTranslatef(1, 80, 1);
    int cone_size_x,
        cone_size_y;
    int hole_size_x,
        hole_size_y;
    for(int i=0; i<=100; i+=20){
        cone_size_x = 280 - (i*2),
        cone_size_y = 280 - (i*2);
        hole_size_x = cone_size_x - 20,
        hole_size_y = cone_size_y - 20;

        for(int j=0; j<=cone_size_x*2; j+=1){
            glColor3f(1, 0, 0);
            poly(320, 320+(j), cone_size_x-(j/2), cone_size_y-(j/2), 720, 0, GL_TRIANGLE_FAN);
        }

        glColor3f(1, 1, 1);
        poly(320, 320, hole_size_x, hole_size_y, 720, 0, GL_TRIANGLE_FAN);
    }

    for(int j=0; j<=80; j++){
        glColor3f(1, 0, 0);
        poly(320, 320+(j), 40-(j/2), 40-(j/2), 720, 0, GL_TRIANGLE_FAN);
    }

    glPointSize(5);
    glColor3f(0, 0, 0);
    poly(320, 320, 280, 280, 90, 0, GL_POINTS);

    glPopMatrix();

    glutSwapBuffers();
}