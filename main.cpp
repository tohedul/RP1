#include <iostream>
#include <GL/glut.h>
using namespace std;


float xr=0;
float yr=0;


void myInit (void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-420.0, 420.0, -420.0, 420.0);
}



void Display()
{
	glClear (GL_COLOR_BUFFER_BIT);

	glColor3ub(68.0, 200.0, 215.0); // water color
	glPointSize(5.0);

    glBegin(GL_POLYGON);  //water area
        glVertex2i(250,-420);
        glVertex2i(250,420);
        glVertex2i(-250,420);
        glVertex2i(-250,-420);
    glEnd();

    glBegin(GL_POLYGON);   // boat
    glColor3f(0.25,0.25,0.25); //boat color
    glVertex2i(25+xr,-350+yr);
    glVertex2i(25+xr,-290+yr);
    glVertex2i(18+xr,-260+yr);
    glVertex2i(0+xr,-230+yr);
    glVertex2i(0+xr,-230+yr);
    glVertex2i(-18+xr,-260+yr);
    glVertex2i(-25+xr,-290+yr);
    glVertex2i(-25+xr,-350+yr);



    glEnd();


    glutSwapBuffers();
}

void SpecialKey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        yr++;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        yr--;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        xr++;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        xr--;
        glutPostRedisplay();
        break;
    }

}

int main(int argc, char** argv)
{



	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (840, 840);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("NFS Boat");
	glutDisplayFunc(Display);
	glutSpecialFunc(SpecialKey);
	myInit ();
	glutMainLoop();

}
