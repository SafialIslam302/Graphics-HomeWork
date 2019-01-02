#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<bits/stdc++.h>
#include<math.h>
static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */
using namespace std;
static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void spilar()
{
    float x1,x2,z1,z2,x11,x22,z11,z22;

    for(float i=0; i<15;)
    {
        float rad222=7;
        float rad111=4;
        z1=0;
        z2=0;
        float dx=10;
        for(float j=5; j<=360; j+=dx)
        {
            x1=-rad222*cos(3.1416/180.0*j*1.0);
            x11=-rad111*cos(3.1416/180.0*(j)*1.0);
            x2=-rad222*cos(3.1416/180.0*(j+dx)*1.0);
            x22=-rad111*cos(3.1416/180.0*(j+dx)*1.0);
            z1=-rad222*sin(3.1416/180.0*j*1.0);
            z11=-rad111*sin(3.1416/180.0*(j)*1.0);
            z2=-rad222*sin(3.1416/180.0*(j+dx)*1.0);
            z22=-rad111*sin(3.1416/180.0*(j+dx)*1.0);
            glBegin(GL_QUAD_STRIP);
            glColor3d(1,1,1);
            glVertex3f(x1,i,z1);//right down
            glVertex3f(x11,i,z11);//left down
            i+=.06;
            glVertex3f(x2,i,z2);//left down
            glVertex3f(x22,i,z22);//right down

            glEnd();
        }


    }
}


static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 2000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
    glTranslated(-.2,-7,-35);
    // glRotated(60,1,0,0);
    //glRotated(a,0,1,0);
    spilar();
    glPopMatrix();


    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT National Memorial");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,1);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

    /*glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    */
    glutMainLoop();

    return EXIT_SUCCESS;
}
