#include <GL/glut.h>
#include <iostream>
using namespace std;
void drawPixel(int x, int y) {
 glBegin(GL_POINTS);
 glVertex2i(x, y);
 glEnd();
}
void init() {
 glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0, 500, 0, 500);
}
void drawline(int x1, int y1, int x2, int y2) {
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
void drawHouse() {
 //wall
 drawline(50,50,50,200);
 drawline(50,200,150,200);
 drawline(150,200,150,50);
 drawline(150,50,50,50);
 //traingle
 drawline(50,200,100,300);
 drawline(100,300,150,200);
 //side
 drawline(100,200,400,200);
 drawline(400,200,400,50);
 drawline(400,50,100,50);
 //roof
 drawline(100,300,350,300);
 drawline(350,300,400,200);
 //door
 drawline(75,50,75,125);
 drawline(75,125,125,125);
 drawline(125,125,125,50);
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 drawHouse();
 glFlush();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("House Drawing using Bresenham's Algorithm");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
