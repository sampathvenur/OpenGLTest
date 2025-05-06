#include <GL/glut.h>

void draw() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-100, -100); glVertex2f(0, 200); glVertex2f(100, -100);
    glVertex2f(-100, 100); glVertex2f(0, -200); glVertex2f(100, 100);
    glEnd();
    glFlush();
}

void menu(int id) {
    if (id == 1) glTranslatef(-10, 0, 0);
    if (id == 2) glTranslatef(10, 0, 0);
    if (id == 3) glTranslatef(0, 10, 0);
    if (id == 4) glTranslatef(0, -10, 0);
    if (id == 5) glRotatef(10, 0, 0, 1);
    if (id == 6) glRotatef(-10, 0, 0, 1);
    if (id == 7) glScalef(0.5, 0.5, 1);
    if (id == 8) glScalef(1.5, 1.5, 1);
    glutPostRedisplay();
}

void setup() {
    gluOrtho2D(-500, 500, -500, 500);
}

int main(int a, char **b) {
    glutInit(&a, b);
    glutCreateWindow("2D Transform");
    setup();
    glutDisplayFunc(draw);

    int t = glutCreateMenu(menu);
    glutAddMenuEntry("Left", 1);  glutAddMenuEntry("Right", 2);
    glutAddMenuEntry("Up", 3);    glutAddMenuEntry("Down", 4);
    int r = glutCreateMenu(menu);
    glutAddMenuEntry("Anticlock", 5); glutAddMenuEntry("Clock", 6);
    int s = glutCreateMenu(menu);
    glutAddMenuEntry("Shrink", 7); glutAddMenuEntry("Grow", 8);

    glutCreateMenu(menu);
    glutAddSubMenu("Move", t);
    glutAddSubMenu("Rotate", r);
    glutAddSubMenu("Scale", s);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
