#include <GL/glut.h>
#include <stdio.h>
int x1, yy1, x2, y2;

void plot(int x, int y) {
    glBegin(GL_POINTS); glVertex2i(x, y); glEnd();
}

void bresenham(int x1, int yy1, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - yy1);
    int sx = x1 < x2 ? 1 : -1, sy = yy1 < y2 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        plot(x1, yy1);
        if (x1 == x2 && yy1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 <  dx) { err += dx; yy1 += sy; }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    bresenham(x1, yy1, x2, y2);
    glFlush();
}

void init() {
    gluOrtho2D(-500, 500, -500, 500);
    glClearColor(1, 1, 1, 0);
    glPointSize(2);
}

int main(int argc, char **argv) {
    printf("Enter x1 y1 x2 y2: ");
    scanf("%d%d%d%d", &x1, &yy1, &x2, &y2);
    glutInit(&argc, argv);
    glutCreateWindow("Bresenham");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
