#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-100, -100);
    glVertex2f(0, 200);
    glVertex2f(100, -100);
    glVertex2f(-100, 100);
    glVertex2f(0, -200);
    glVertex2f(100, 100);
    glEnd();
    glFlush();
}
void menu(int id)
{
    if (id == 1)
        glTranslatef(-10, 0, 0);
    if (id == 2)
        glTranslatef(10, 0, 0);
    if (id == 3)
        glTranslatef(0, 10, 0);
    if (id == 4)
        glTranslatef(0, -10, 0);
    if (id == 5)
        glRotatef(10, 0, 0, 1);
    if (id == 6)
        glRotatef(-10, 0, 0, 1);
    if (id == 7)
        glScalef(0.5, 0.5, 0);
    if (id == 8)
        glScalef(1.5, 1.5, 0);
    glutPostRedisplay();
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("2D Transformations");
    init();
    glutDisplayFunc(display);
    int translate = glutCreateMenu(menu);
    glutAddMenuEntry("Left", 1);
    glutAddMenuEntry("Right", 2);
    glutAddMenuEntry("Up", 3);
    glutAddMenuEntry("Down", 4);
    int rotation = glutCreateMenu(menu);
    glutAddMenuEntry("Anticlockwise", 5);
    glutAddMenuEntry("Clockwise", 6);
    int scaling = glutCreateMenu(menu);
    glutAddMenuEntry("Minimize", 7);
    glutAddMenuEntry("Maximize", 8);
    glutCreateMenu(menu);
    glutAddSubMenu("Translate", translate);
    glutAddSubMenu("Rotate", rotation);
    glutAddSubMenu("Scaling", scaling);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}