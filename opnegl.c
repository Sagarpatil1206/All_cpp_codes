//#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>

void renderFunction(void){
    glClearColor(0.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    gluOrtho2D(0.0,640.0,0.0,480.0);

    glBegin(GL_LINE_LOOP);
    glVertex2i(0,100);
    glVertex2i(100,0);
    glVertex2i(50,100);

    glEnd();
    glFlush();
}

int main(int argc,char**argv){
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400,300);
    glutInitWindowPosition(50,100);
    glutCreateWindow("First OpenGL programs");
    glutDisplayFunc(renderFunction);
}