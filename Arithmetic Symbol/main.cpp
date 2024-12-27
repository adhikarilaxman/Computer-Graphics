#include <GL/glut.h>
void display() {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 0.0, 0.0);
 glBegin(GL_LINES);
 glColor3f(0.0, 0.0, 1.0);
 glVertex2i(10, 60);
 glVertex2i(30, 60);
 glVertex2i(20, 50);
 glVertex2i(20, 70);
 glEnd();
 glBegin(GL_LINES);
 glColor3f(0.0, 1.0, 0.0);
 glVertex2i(40, 60);
 glVertex2i(60, 60);
 glEnd();
 glBegin(GL_LINES);
 glColor3f(1.0, 0.0, 0.0);
 glVertex2i(70, 50);
 glVertex2i(90, 70);
 glVertex2i(70, 70);
 glVertex2i(90, 50);
 glEnd();
 glPointSize(5);
 glBegin(GL_POINTS);
 glColor3f(1.0, 0.0, 1.0);
 glVertex2i(110, 70);
 glVertex2i(110, 50);
 glEnd();
 glBegin(GL_LINES);
 glVertex2i(100, 60);
 glVertex2i(120, 60);
 glEnd();
 glBegin(GL_LINES);
 glVertex2i(130, 55);
 glVertex2i(150, 55);
 glVertex2i(130, 65);
 glVertex2i(150, 65);
 glEnd();
 glBegin(GL_LINES);
 glColor3f(1.0,0.0,1.0);
 glVertex2i(170, 60);
 glVertex2i(190, 70);
 glVertex2i(170, 60);
 glVertex2i(190, 50);
 glEnd();
 glBegin(GL_LINES);
 glVertex2i(210, 70);
 glVertex2i(230, 60);
 glVertex2i(210, 50);
 glVertex2i(230, 60);
 glEnd();
 glutSwapBuffers();
}
void init() {
 glClearColor(0.0, 0.0, 0.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(0, 240, 0, 100,0,240);
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE);
 glutInitWindowSize(800, 600);
 glutCreateWindow("Arithmetic Operators");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
