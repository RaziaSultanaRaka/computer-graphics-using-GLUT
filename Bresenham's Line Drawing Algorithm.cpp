#include<windows.h>
#include<GL/glut.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);

    gluOrtho2D(0.0, 640.0, 0.0, 480);
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4.0);

    int x1 = 20, y1 = 20, xn = 400, yn = 250; // 0<m<1
    int x = x1, y = y1;
    int dx = xn - x1, dy = yn - y1;

    int dS = 2*dy;
    int dT = 2*(dy - dx);

    int d = 2*dy - dx;

    glBegin(GL_POINTS);
      glVertex2i(x, y);
    glEnd();

    while(x<xn)
    {
        x++;
        if(d<0) //Bottom Pixel S is Chosen
        {
            d = d + dS;
        }
        else if(d>=0) //Top Pixel T is Chosen
        {
            y = y + 1;
            d = d + dT;
        }

        glBegin(GL_POINTS);
           glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Bresenham's Line Drawing Algorithm [ID: 200018]");
    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();

    return 0;
}
