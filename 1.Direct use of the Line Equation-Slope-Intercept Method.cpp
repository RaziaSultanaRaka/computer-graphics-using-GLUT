#include<windows.h>
#include<GL/glut.h>
#include<math.h>

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

    int x1 = 20, y1 = 20, xn = 400, yn = 250; // |m|<=1
    //int x1 = 250, y1 = 20, xn = 20, yn = 400; // |m|>1
    int dx = xn - x1, dy = yn - y1;

    float m = ((float)dy)/dx;
    float b = y1 - m*x1;

    glBegin(GL_POINTS);
      glVertex2i(x1, y1);
      glVertex2i(xn, yn);
    glEnd();

    float x = x1, y = y1, x_r, y_r;

    if(fabsf(m)<=1)
    {
        while(x<xn)
        {
            x = x + 1;
            y = m*x + b;
            y_r = round(y);

            glBegin(GL_POINTS);
              glVertex2i(x, y_r);
            glEnd();
        }
    }
    else if(fabsf(m)>1)
    {
        while(y<yn)
        {
            y = y + 1;
            x = (y - b)/m;
            x_r = round(x);

            glBegin(GL_POINTS);
              glVertex2i(x_r, y);
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Direct use of the Line Equation/Slope-Intercept Method");
    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();

    return 0;
}
