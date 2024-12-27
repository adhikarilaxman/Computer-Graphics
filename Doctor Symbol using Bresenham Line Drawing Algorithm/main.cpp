#include <GL/glut.h>
#include <iostream>
using namespace std;
void drawPixel(int x, int y) {
 glBegin(GL_POINTS);
 glColor3f(0.0f, 1.0f, 0.0f); // Green color
 glVertex2i(x, y);
 glEnd();
}
void init() {
 glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // White background
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0, 500, 0, 500); // Coordinate system
}
void drawLine(int x1, int y1, int x2, int y2) {
 int dx, dy, e, inc1, inc2, incx = 1, incy = 1;
 int x, y;
 dx = x2 - x1;
 dy = y2 - y1;
 if (dx < 0) dx = -dx;
 if (dy < 0) dy = -dy;
 if (x2 < x1) incx = -1;
 if (y2 < y1) incy = -1;
 x = x1;
 y = y1;
 if (dx > dy) {
 drawPixel(x, y);
 e = 2 * dy - dx;
 inc1 = 2 * (dy - dx);
 inc2 = 2 * dy;
 for (int i = 0; i < dx; i++) {
 if (e >= 0) {
 y += incy;
 e += inc1;
 } else {
 e += inc2;
 }
 x += incx;
 drawPixel(x, y);
 }
 } else {
 drawPixel(x, y);
 e = 2 * dx - dy;
 inc1 = 2 * (dx - dy);
 inc2 = 2 * dx;
 for (int i = 0; i < dy; i++) {
 if (e >= 0) {
 x += incx;
 e += inc1;
 } else {
 e += inc2;
 }
 y += incy;
 drawPixel(x, y);
 }
 }
}
void fillVerticalRect(int x1, int x2, int y1, int y2) {
 for (int x = x1; x <= x2; x++) {
 drawLine(x, y1, x, y2); // Fill each column of the rectangle
 }
}
void fillHorizontalRect(int x1, int x2, int y1, int y2) {
 for (int y = y1; y <= y2; y++) {
 drawLine(x1, y, x2, y);
 }
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 fillVerticalRect(230, 270, 100, 400);
 fillHorizontalRect(150, 350, 230, 270);
 glFlush();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Green Cross Symbol");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
