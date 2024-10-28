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

    int x = 0, r = 100, y = r, h = 320, k = 240; // (h, k) is center
    int d = 3 - 2*r;

    while(x<=y)
    {
        glBegin(GL_POINTS);
          glVertex2i(x+h, y+k);
          glVertex2i(-x+h, y+k);
          glVertex2i(x+h, -y+k);
          glVertex2i(-x+h, -y+k);

          glVertex2i(y+h, x+k);
          glVertex2i(-y+h, x+k);
          glVertex2i(y+h, -x+k);
          glVertex2i(-y+h, -x+k);
        glEnd();

        if(d<0) //Outside Pixel T is Chosen
        {
            d = d + 4*x + 6;
        }
        else if(d>=0) //Inside Pixel S is Chosen
        {
            d = d + 4*(x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Bresenham's Circle Drawing Algorithm");
    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();

    return 0;
}
