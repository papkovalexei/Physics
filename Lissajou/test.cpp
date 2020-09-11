#include <GL/glut.h>
#include <cmath>
 
const int TIME = 50;
const int WIDTH = 640;
const int HEIGHT = 480;
int N = 1;

float A = 3, a = 1000;
float B = 4, b = 1500;
float sdvig = 3*M_PI/8.0;


void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(0, 1, 0);
       for (float t = 0; t < 500; t += 0.0001)
       {
           glVertex2f(sin((a*t)*(M_PI/180.0) +sdvig), sin((b*t)*(M_PI/180.0))); //grad* (pi/180)
       }
    glEnd();
    glFlush();
}
 
void timer(int = 0)
{
    glutTimerFunc(TIME, timer, 0);
    a++;
    b++;

    if (a > 20)
    {
        a = 1;
        b = 2;
    }
    displayMe();
}

void init()
{
    glClearColor(0, 0, 0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glOrtho(-1.5, 1.5, -1.5, 1.5, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Phys");
    init();
    glutTimerFunc(TIME, timer, 0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}