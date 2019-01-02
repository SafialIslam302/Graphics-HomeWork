#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;

static int slices = 16;
static int stacks = 16;

GLfloat no_mat1[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient1[] = { 0.5, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess1[] = {10};

GLfloat no_mat2[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient2[] = { 0.0, 0.5, 0.0, 1.0 };
GLfloat mat_diffuse2[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat mat_specular2[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess2[] = {10};

GLfloat no_mat3[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient3[] = { 0.0, 0.0, 0.5, 1.0 };
GLfloat mat_diffuse3[] = { 0.0, 0.0, 1.0, 1.0 };
GLfloat mat_specular3[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess3[] = {10};

GLfloat no_mat4[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient4[] = { 0.0, 0.5, 0.5, 1.0 };
GLfloat mat_diffuse4[] = { 0.0, 0.5, 1.0, 1.0 };
GLfloat mat_specular4[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess4[] = {10};

GLfloat no_mat5[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient5[] = { 0.75, 0.5, 0.5, 1.0 };
GLfloat mat_diffuse5[] = { 0.5, 0.5, 1.0, 1.0 };
GLfloat mat_specular5[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess5[] = {10};

GLfloat no_mat6[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient6[] = { 0.75, 1.0, 0.5, 1.0 };
GLfloat mat_diffuse6[] = { 0.25, 1.0, 1.0, 1.0 };
GLfloat mat_specular6[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess6[] = {10};

GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1 };
GLfloat light_specular[] = { 1, 1, 1, 1 };
GLfloat light_position[] = { 2.0, 25.0, 3.0, 1.0 };

void main_pilar()
{
    float hig = 3.0, dip1 = 0.0, dip2 = 0.3, dip3 = 0.3, dip4 = 0.0;
    float tempdip1, tempdip4;
    tempdip1 = dip1;
    tempdip4 = dip4;
    int i;
    float fhig = 0.0,fside = 0.0;
    //glColor3d(0.91,0.76,0.65);
    for(int i=0; i<2; i++)
    {
        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient2);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse2);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular2);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess2);

        glBegin(GL_QUADS);
        //top
        glVertex3d( -2.5+fside, 0.1f+fhig,  1-fside ); // front left
        glVertex3d(        3.5, 0.1f+fhig,  1-fside ); // front right
        glVertex3d(        3.5, 0.1f+fhig, -1+fside ); // back right
        glVertex3d( -2.5+fside, 0.1f+fhig, -1+fside ); // back left

        //front
        glVertex3d( -2.5+fside, 0.1f+fhig,  1-fside ); // up left
        glVertex3d(        3.5, 0.1f+fhig,  1-fside ); // up right
        glVertex3d(        3.5, 0.0f+fhig,  1-fside ); // down right
        glVertex3d( -2.5+fside, 0.0f+fhig,  1-fside ); // down left

        //left side
        glVertex3d( -2.5+fside, 0.1f+fhig,  1-fside ); // up front
        glVertex3d( -2.5+fside, 0.1f+fhig, -1+fside ); // up back
        glVertex3d( -2.5+fside, 0.0f+fhig, -1+fside ); // down back
        glVertex3d( -2.5+fside, 0.0f+fhig,  1-fside ); // down front

        //right side
        glVertex3d( 3.5, 0.1f+fhig,  1-fside ); // up front
        glVertex3d( 3.5, 0.1f+fhig, -1+fside ); // up back
        glVertex3d( 3.5, 0.0f+fhig, -1+fside ); // down back
        glVertex3d( 3.5, 0.0f+fhig,  1-fside ); // down front

        //back
        glVertex3d( -2.5+fside, 0.1f+fhig, -1+fside ); // up left
        glVertex3d(        3.5, 0.1f+fhig, -1+fside ); // up right
        glVertex3d(        3.5, 0.0f+fhig, -1+fside ); // down right
        glVertex3d( -2.5+fside, 0.0f+fhig, -1+fside ); // down left

        glEnd();

        fhig = 0.1;
        fside = 0.1;
    }

    for(i=1; i<=3; i++)
    {
        //glColor3d(0.8,0.8,0.8);
        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient1);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse1);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular1);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess1);

        glBegin(GL_QUADS);
        //left pillar
        //down
        glVertex3d( dip1, 0.0f, 0.0f  );
        glVertex3d( dip2, 0.0f, 0.0f  );
        glVertex3d( dip2, 0.0f, -dip3 );
        glVertex3d( dip4, 0.0f, -dip3 );

        //up
        glVertex3d( dip1,  hig, 0.0f );
        glVertex3d( dip2,  hig, 0.0f );
        glVertex3d( dip2,  hig, -dip3 );
        glVertex3d( dip4,  hig, -dip3 );

        //front side
        glVertex3d( dip1, 0.0f, 0.0f  );
        glVertex3d( dip2, 0.0f, 0.0f  );
        glVertex3d( dip2,  hig, 0.0f );
        glVertex3d( dip1,  hig, 0.0f );

        //back side
        glVertex3d( dip2, 0.0f, -dip3 );
        glVertex3d( dip4, 0.0f, -dip3 );
        glVertex3d( dip4,  hig, -dip3 );
        glVertex3d( dip2,  hig, -dip3 );

        //left side
        glVertex3d( dip1, 0.0f, 0.0f  );
        glVertex3d( dip4, 0.0f, -dip3 );
        glVertex3d( dip4,  hig, -dip3 );
        glVertex3d( dip1,  hig, 0.0f );

        //right side
        glVertex3d( dip2, 0.0f, 0.0f  );
        glVertex3d( dip2, 0.0f, -dip3 );
        glVertex3d( dip2,  hig, -dip3 );
        glVertex3d( dip2,  hig, 0.0f );

        //bar top
        glVertex3d( dip1, hig+0.8, dip3 );
        glVertex3d( dip2, hig+0.8, dip3 );
        glVertex3d( dip2, hig+0.8, dip3+0.4 );
        glVertex3d( dip4, hig+0.8, dip3+0.4 );

        //bar front
        glVertex3d( dip4, hig+0.8, dip3+0.4 );
        glVertex3d( dip2, hig+0.8, dip3+0.4 );
        glVertex3d( dip2, hig, 0.0f );
        glVertex3d( dip1, hig, 0.0f );

        //bar back
        glVertex3d( dip2, hig+0.8, dip3 );
        glVertex3d( dip1, hig+0.8, dip3 );
        glVertex3d( dip4,  hig, -dip3 );
        glVertex3d( dip2,  hig, -dip3 );

        //bar right
        glVertex3d( dip2, hig+0.8, dip3+0.4 );
        glVertex3d( dip2, hig+0.8,     dip3 );
        glVertex3d( dip2,     hig,    -dip3 );
        glVertex3d( dip2,     hig,     0.0f );

        //bar left
        glVertex3d( dip4, hig+0.8, dip3+0.4 );
        glVertex3d( dip1, hig+0.8,     dip3 );
        glVertex3d( dip4,     hig,    -dip3 );
        glVertex3d( dip1,     hig,     0.0f );

        //Top Bar
        glVertex3d( tempdip1, hig+0.8, dip3     );
        glVertex3d(     dip2, hig+0.8, dip3     );
        glVertex3d(     dip2, hig+0.8, dip3+0.4 );
        glVertex3d( tempdip4, hig+0.8, dip3+0.4 );

        //Top Bar front
        glVertex3d( tempdip1, hig+0.8, dip3+0.4 );
        glVertex3d( tempdip1, hig+0.6, dip3+0.2 );
        glVertex3d(     dip4, hig+0.8, dip3+0.4 );
        glVertex3d(     dip4, hig+0.6, dip3+0.2 );

        glEnd();
        dip1 = dip1 + 0.5;
        dip2 = dip2 + 0.5;
        dip4 = dip4 + 0.5;
    }

    //draw Circle
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * 3.1416;
    GLfloat x = 0.64;
    GLfloat y = 1.8;
    GLfloat radius = 0.8;

    //glColor3d(1,0,0);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 0; i <= triangleAmount; i++)
    {
        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient3);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse3);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular3);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess3);

        glVertex3d(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)),
            -0.31
        );
    }
    glEnd();

}

void sub_pilar1()
{
    float hig = 1.5, dip1 = -1.8, dip2 = 0.2, dip3 = 0.2, dip4 = 0.0;
    float temphig = hig;
    int i;
    for(i=1; i<=8; i++)
    {
        //glColor3d(0.8,0.8,0.8);
        glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient4);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse4);
        glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular4);
        glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess4);

        glBegin(GL_QUADS);
        //down
        glVertex3d(        dip1, 0.0f, 0.0f  );
        glVertex3d( dip1 - dip2, 0.0f, 0.0f  );
        glVertex3d( dip1 - dip2, 0.0f, -dip3 );
        glVertex3d(        dip1, 0.0f, -dip3 );

        //up
        glVertex3d(        dip1,  hig, 0.0f  );
        glVertex3d( dip1 - dip2,  hig, 0.0f  );
        glVertex3d( dip1 - dip2,  hig, -dip3 );
        glVertex3d(        dip1,  hig, -dip3 );

        //front side
        glVertex3d(        dip1, 0.0f, 0.0f  );
        glVertex3d( dip1 - dip2, 0.0f, 0.0f  );
        glVertex3d( dip1 - dip2,  hig, 0.0f  );
        glVertex3d(        dip1,  hig, 0.0f  );

        //back side
        glVertex3d( dip1 - dip2, 0.0f, -dip3 );
        glVertex3d(        dip1, 0.0f, -dip3 );
        glVertex3d(        dip1,  hig, -dip3 );
        glVertex3d( dip1 - dip2,  hig, -dip3 );

        //left side
        glVertex3d(        dip1, 0.0f, 0.0f  );
        glVertex3d(        dip1, 0.0f, -dip3 );
        glVertex3d(        dip1,  hig, -dip3 );
        glVertex3d(        dip1,  hig, 0.0f  );

        //right side
        glVertex3d( dip1 - dip2, 0.0f, 0.0f  );
        glVertex3d( dip1 - dip2, 0.0f, -dip3 );
        glVertex3d( dip1 - dip2,  hig, -dip3 );
        glVertex3d( dip1 - dip2,  hig, 0.0f  );

        glEnd();

        if(i == 1 || i==2 || i == 3 || i == 5 || i == 6 || i == 7 || i == 8)
        {
            if(i == 1 || i == 3 || i == 5 || i == 7 )
            {
                glBegin(GL_QUADS);
                //top bar front
                glVertex3d(       dip1 - dip2,      hig, 0.0f  );
                glVertex3d(       dip1 - dip2,  hig-0.2, 0.0f  );
                glVertex3d( dip1 - dip2 + 0.5,  hig-0.2, 0.0f  );
                glVertex3d( dip1 - dip2 + 0.5,      hig, 0.0f  );

                //top bar back
                glVertex3d(       dip1 - dip2,      hig, -dip3  );
                glVertex3d(       dip1 - dip2,  hig-0.2, -dip3  );
                glVertex3d( dip1 - dip2 + 0.5,  hig-0.2, -dip3  );
                glVertex3d( dip1 - dip2 + 0.5,      hig, -dip3  );

                //top bar up
                glVertex3d(       dip1 - dip2,      hig, 0.0f  );
                glVertex3d(       dip1 - dip2,      hig, -dip3 );
                glVertex3d( dip1 - dip2 + 0.5,      hig, -dip3 );
                glVertex3d( dip1 - dip2 + 0.5,      hig, 0.0f  );

                glEnd();
            }

            if(i == 2)
            {
                hig = hig + 1.0;
            }
            else if (i == 6 )
            {
                hig = hig - 1;
            }

            dip1 = dip1 + 0.5;
        }
        else if (i == 4)
        {
            dip1 = dip1 + 2.0;
        }
    }

    //glColor3d(0,0,0);
    glBegin(GL_QUADS); // 1st pillar 1st lod
    glVertex3d( -1.72, 0, -0.1 );
    glVertex3d( -1.68, 0, -0.1 );
    glVertex3d( -1.68, 1.5, -0.1 );
    glVertex3d( -1.72, 1.5, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 1st pillar 2nd lod
    glVertex3d( -1.62, 0, -0.1 );
    glVertex3d( -1.58, 0, -0.1 );
    glVertex3d( -1.58, 1.5, -0.1 );
    glVertex3d( -1.62, 1.5, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 1st pillar rod
    glVertex3d( -1.78, 0.50, -0.1 );
    glVertex3d( -1.48, 0.50, -0.1 );
    glVertex3d( -1.48, 0.53, -0.1 );
    glVertex3d( -1.78, 0.53, -0.1 );

    glVertex3d( -1.78, 0.90, -0.1 );
    glVertex3d( -1.48, 0.90, -0.1 );
    glVertex3d( -1.48, 0.93, -0.1 );
    glVertex3d( -1.78, 0.93, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 2nd pillar 1st lod
    glVertex3d( -0.72, 0, -0.1 );
    glVertex3d( -0.68, 0, -0.1 );
    glVertex3d( -0.68, 2.28, -0.1 );
    glVertex3d( -0.72, 2.28, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 2nd pillar 2nd lod
    glVertex3d( -0.60, 0, -0.1 );
    glVertex3d( -0.56, 0, -0.1 );
    glVertex3d( -0.56, 2.28, -0.1 );
    glVertex3d( -0.60, 2.28, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 2nd pillar rod
    glVertex3d( -0.78, 0.70, -0.1 );
    glVertex3d( -0.48, 0.70, -0.1 );
    glVertex3d( -0.48, 0.74, -0.1 );
    glVertex3d( -0.78, 0.74, -0.1 );

    glVertex3d( -0.78, 1.50, -0.1 );
    glVertex3d( -0.48, 1.50, -0.1 );
    glVertex3d( -0.48, 1.54, -0.1 );
    glVertex3d( -0.78, 1.54, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 3rd pillar 1st lod
    glVertex3d( 0.40,   0, -0.1 );
    glVertex3d( 0.44,   0, -0.1 );
    glVertex3d( 0.44, 2.5, -0.1 );
    glVertex3d( 0.40, 2.5, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 3rd pillar 2nd lod
    glVertex3d( 0.86,   0, -0.1 );
    glVertex3d( 0.90,   0, -0.1 );
    glVertex3d( 0.90, 2.5, -0.1 );
    glVertex3d( 0.86, 2.5, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 3rd pillar Upper lod
    glVertex3d( 0.44, 2.5, -0.1 );
    glVertex3d( 0.44, 4.0,  0.0 );
    glVertex3d( 0.40, 4.0,  0.0 );
    glVertex3d( 0.40, 2.5, -0.1 );

    glVertex3d( 0.90, 2.5, -0.1 );
    glVertex3d( 0.90, 4.0,  0.0 );
    glVertex3d( 0.86, 4.0,  0.0 );
    glVertex3d( 0.86, 2.5, -0.1 );


    glEnd();
    glBegin(GL_QUADS); // 3rd pillar rod
    glVertex3d( 0.98, 0.80, -0.1 );
    glVertex3d( 0.30, 0.80, -0.1 );
    glVertex3d( 0.30, 0.84, -0.1 );
    glVertex3d( 0.98, 0.84, -0.1 );

    glVertex3d( 0.98, 1.70, -0.1 );
    glVertex3d( 0.30, 1.70, -0.1 );
    glVertex3d( 0.30, 1.74, -0.1 );
    glVertex3d( 0.98, 1.74, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 4th pillar 1st lod
    glVertex3d( 1.78,    0, -0.1 );
    glVertex3d( 1.82,    0, -0.1 );
    glVertex3d( 1.82, 2.28, -0.1 );
    glVertex3d( 1.78, 2.28, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 4th pillar 2nd lod
    glVertex3d( 1.88,    0, -0.1 );
    glVertex3d( 1.92,    0, -0.1 );
    glVertex3d( 1.92, 2.28, -0.1 );
    glVertex3d( 1.88, 2.28, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 4th pillar rod
    glVertex3d( 1.98, 0.70, -0.1 );
    glVertex3d( 1.68, 0.70, -0.1 );
    glVertex3d( 1.68, 0.74, -0.1 );
    glVertex3d( 1.98, 0.74, -0.1 );

    glVertex3d( 1.98, 1.50, -0.1 );
    glVertex3d( 1.68, 1.50, -0.1 );
    glVertex3d( 1.68, 1.54, -0.1 );
    glVertex3d( 1.98, 1.54, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 5th pillar 1st lod
    glVertex3d( 2.80,   0, -0.1 );
    glVertex3d( 2.84,   0, -0.1 );
    glVertex3d( 2.84, 1.5, -0.1 );
    glVertex3d( 2.80, 1.5, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 5th pillar 2nd lod
    glVertex3d( 2.90,   0, -0.1 );
    glVertex3d( 2.94,   0, -0.1 );
    glVertex3d( 2.94, 1.5, -0.1 );
    glVertex3d( 2.90, 1.5, -0.1 );
    glEnd();
    glBegin(GL_QUADS); // 5th pillar rod
    glVertex3d( 2.70, 0.50, -0.1 );
    glVertex3d( 2.98, 0.50, -0.1 );
    glVertex3d( 2.98, 0.54, -0.1 );
    glVertex3d( 2.70, 0.54, -0.1 );

    glVertex3d( 2.70, 0.90, -0.1 );
    glVertex3d( 2.98, 0.90, -0.1 );
    glVertex3d( 2.98, 0.94, -0.1 );
    glVertex3d( 2.70, 0.94, -0.1 );
    glEnd();
}

void table()
{
    float x=4.0;

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient5);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse5);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular5);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess5);

    glBegin(GL_QUADS);
    //glColor3d(0.64,0.16,0.16);
    glVertex3d(-x+1, 0,  1.5); //front left
    glVertex3d(   x, 0,  1.5); //front right
    glVertex3d(   x, 0, -2.0); //back right
    glVertex3d(-x+1, 0, -2.0); //back left
    glEnd();

    float d=-.1;
    glBegin(GL_QUADS);
    //glColor3d(0.64,0.16,0.16);
    glVertex3d(-x+1, d, 1.5);//front left
    glVertex3d(   x, d, 1.5);//front right
    glVertex3d(   x, d, -2.0);//back right
    glVertex3d(-x+1, d, -2.0);//back left
    glEnd();

    //front thickness
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(-x+1, 0, 1.5); // left top
    glVertex3d(   x, 0, 1.5); //right top
    glVertex3d(   x, d, 1.5); //right down
    glVertex3d(-x+1, d, 1.5); //left down
    glEnd();

    //right thickness
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(x, 0,  1.5); //left top
    glVertex3d(x, 0, -2.0); //right top
    glVertex3d(x, d, -2.0); //right down
    glVertex3d(x, d,  1.5); //left down
    glEnd();

    //back thickness
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(   x, 0, -2.0); //left top
    glVertex3d(-x+1, 0, -2.0); //right top
    glVertex3d(-x+1, d, -2.0); //right down
    glVertex3d(   x, d, -2.0); //left down
    glEnd();

    //left thickness
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d( -x+1, 0, 1.5); // front  top
    glVertex3d( -x+1, d, 1.5); // front down
    glVertex3d(-x+1,  d, -2.0); // back  down
    glVertex3d(-x+1,  0, -2.0); // back   top

    glEnd();

    float lw=.2, lh=2,margin=1.0;

    //front left leg
    //front
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(   -x+1+margin,   d, 1.5);// left top
    glVertex3d(   -x+1+margin, -lh, 1.5);//right top
    glVertex3d(-x+1+margin+lw, -lh, 1.5);//right down
    glVertex3d(-x+1+margin+lw,   d, 1.5);//left down
    glEnd();

    //right
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(-x+1+margin+lw,   d, -lw+1.5);//right down
    glVertex3d(-x+1+margin+lw, -lh, -lw+1.5);//left down
    glVertex3d(-x+1+margin+lw, -lh,     1.5);//right down
    glVertex3d(-x+1+margin+lw,   d,     1.5);//left down
    glEnd();

    //back
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(-x+1+margin+lw,   d, -lw+1.5);//right down
    glVertex3d(-x+1+margin+lw, -lh, -lw+1.5);//left down
    glVertex3d(   -x+1+margin, -lh, -lw+1.5);//right down
    glVertex3d(   -x+1+margin,   d, -lw+1.5);//left down
    glEnd();

    //left
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(-x+1+margin,   d, -lw+1.5);//right down
    glVertex3d(-x+1+margin, -lh, -lw+1.5);//left down
    glVertex3d(-x+1+margin, -lh,     1.5);//right down
    glVertex3d(-x+1+margin,   d,     1.5);//left down
    glEnd();

    //front right leg
    //front
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(x-margin,      d, 1.5);// left top
    glVertex3d(x-margin,    -lh, 1.5);//right top
    glVertex3d(x-margin-lw, -lh, 1.5);//right down
    glVertex3d(x-margin-lw,   d, 1.5);//left down
    glEnd();

    //right
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(x-margin,   d,  -lw+1.5);//right down
    glVertex3d(x-margin, -lh,  -lw+1.5);//left down
    glVertex3d(x-margin, -lh,      1.5);//right down
    glVertex3d(x-margin,   d,      1.5);//left down
    glEnd();

    //back
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(   x-margin,   d, -lw+1.5);//right down
    glVertex3d(   x-margin, -lh, -lw+1.5);//left down
    glVertex3d(x-margin-lw, -lh, -lw+1.5);//right down
    glVertex3d(x-margin-lw,   d, -lw+1.5);//left down
    glEnd();

    //left
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(x-margin-lw,   d, -lw+1.5);//right down
    glVertex3d(x-margin-lw, -lh, -lw+1.5);//left down
    glVertex3d(x-margin-lw, -lh,     1.5);//right down
    glVertex3d(x-margin-lw,   d,     1.5);//left down
    glEnd();

    //back right leg
    //front
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(   x-margin,   d, -3+margin+lw);// left top
    glVertex3d(   x-margin, -lh, -3+margin+lw);//right top
    glVertex3d(x-margin-lw, -lh, -3+margin+lw);//right down
    glVertex3d(x-margin-lw,   d, -3+margin+lw);//left down
    glEnd();

    //right
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(x-margin,   d, -3+margin+lw);//right down
    glVertex3d(x-margin, -lh, -3+margin+lw);//left down
    glVertex3d(x-margin, -lh,    -3+margin);//right down
    glVertex3d(x-margin,   d,    -3+margin);//left down
    glEnd();

    //back
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(   x-margin,   d, -3+margin);//right down
    glVertex3d(   x-margin, -lh, -3+margin);//left down
    glVertex3d(x-margin-lw, -lh, -3+margin);//right down
    glVertex3d(x-margin-lw,   d, -3+margin);//left down
    glEnd();

    //left
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(x-margin-lw,   d,    -3+margin);//right down
    glVertex3d(x-margin-lw, -lh,    -3+margin);//left down
    glVertex3d(x-margin-lw, -lh, -3+margin+lw);//right down
    glVertex3d(x-margin-lw,   d, -3+margin+lw);//left down
    glEnd();

    //back left leg
    //front
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(   -x+1+margin,   d, -3+margin+lw);// left top
    glVertex3d(   -x+1+margin, -lh, -3+margin+lw);//right top
    glVertex3d(-x+1+margin+lw, -lh, -3+margin+lw);//right down
    glVertex3d(-x+1+margin+lw,   d, -3+margin+lw);//left down
    glEnd();

    //right
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(-x+1+margin+lw,   d, -3+margin+lw);//right down
    glVertex3d(-x+1+margin+lw, -lh, -3+margin+lw);//left down
    glVertex3d(-x+1+margin+lw, -lh,    -3+margin);//right down
    glVertex3d(-x+1+margin+lw,   d,    -3+margin);//left down
    glEnd();

    //back
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(-x+1+margin+lw,   d, -3+margin);//right down
    glVertex3d(-x+1+margin+lw, -lh, -3+margin);//left down
    glVertex3d(   -x+1+margin, -lh, -3+margin);//right down
    glVertex3d(   -x+1+margin,   d, -3+margin);//left down
    glEnd();

    //left
    glBegin(GL_QUADS);
    //glColor3d(0.44,0.26,0.26);
    glVertex3d(-x+1+margin,   d,    -3+margin);//right down
    glVertex3d(-x+1+margin, -lh,    -3+margin);//left down
    glVertex3d(-x+1+margin, -lh, -3+margin+lw);//right down
    glVertex3d(-x+1+margin,   d, -3+margin+lw);//left down
    glEnd();
}

void walls()
{
    float d=-2.0,x=6;

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient6);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse6);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular6);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess6);

    //floor
    glBegin(GL_QUADS);
    //glColor3d(0.13,0.13,0.56);
    glVertex3d(-x, d,  2.5); //right down
    glVertex3d( x, d,  2.5); //left down
    glVertex3d( x, d, -4.5); //right down
    glVertex3d(-x, d, -4.5); //left down

    glEnd();
    glBegin(GL_QUADS);
    //glColor3d(0.13,0.13,0.56);
    glVertex3d(-x, d-0.3,  2.5); //right down
    glVertex3d( x, d-0.3,  2.5); //left down
    glVertex3d( x, d-0.3, -4.5); //right down
    glVertex3d(-x, d-0.3, -4.5); //left down
    glEnd();

    //floor front width
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(-x,     d, 2.5); //right down
    glVertex3d(-x, d-0.3, 2.5); //left down
    glVertex3d( x, d-0.3, 2.5); //right down
    glVertex3d( x,     d, 2.5); //left down
    glEnd();

    //floor right width
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(x,     d,  2.5);//left down
    glVertex3d(x, d-0.3,  2.5);//right down
    glVertex3d(x, d-0.3, -4.5);//left down
    glVertex3d(x,     d, -4.5);//left down
    glEnd();

    //floor back width
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d( x,     d, -4.5);//left down
    glVertex3d( x, d-0.3, -4.5);//right down
    glVertex3d(-x, d-0.3, -4.5);//left down
    glVertex3d(-x,     d, -4.5);//left down
    glEnd();

    //floor left width
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(-x,     d,  2.5);//left down
    glVertex3d(-x, d-0.3,  2.5);//right down
    glVertex3d(-x, d-0.3, -4.5);//left down
    glVertex3d(-x,     d, -4.5);//left down
    glEnd();

    float wh=6,wt=0.4;

    //left wall
    //outer part
    glBegin(GL_QUADS);
    //glColor3d(0.2,0.6,0.8);
    glVertex3d(-x,    d,  2.5); //left up
    glVertex3d(-x,    d, -4.5); //right down
    glVertex3d(-x, d+wh, -4.5); //left down
    glVertex3d(-x, d+wh,  2.5); //right down
    glEnd();

    //inner part
    glBegin(GL_QUADS);
    //glColor3d(0.2,0.6,0.8);
    glVertex3d(-x+wt,    d,  2.5); //left up
    glVertex3d(-x+wt,    d, -4.5); //right down
    glVertex3d(-x+wt, d+wh, -4.5); //left down
    glVertex3d(-x+wt, d+wh,  2.5); //right down
    glEnd();

    //front part
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(   -x,    d, 2.5); //left up
    glVertex3d(-x+wt,    d, 2.5); //right down
    glVertex3d(-x+wt, d+wh, 2.5); //left down
    glVertex3d(   -x, d+wh, 2.5); //right down
    glEnd();

    //top part
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(   -x, d+wh,  2.5); //left up
    glVertex3d(-x+wt, d+wh,  2.5); //right down
    glVertex3d(-x+wt, d+wh, -4.5); //left down
    glVertex3d(   -x, d+wh, -4.5); //right down
    glEnd();

    //back part
    glBegin(GL_QUADS);
    //glColor3d(0,0.5,1);
    glVertex3d(   -x,    d, -4.5); //left up
    glVertex3d(-x+wt,    d, -4.5); //right down
    glVertex3d(-x+wt, d+wh, -4.5); //left down
    glVertex3d(   -x, d+wh, -4.5); //right down
    glEnd();


    //back wall
    //outer wall
    glBegin(GL_QUADS);
    //glColor3d(0,0.5,1);
    glVertex3d(-x,    d, -4.5); //left up
    glVertex3d( x,    d, -4.5); //right down
    glVertex3d( x, d+wh, -4.5); //left down
    glVertex3d(-x, d+wh, -4.5); //right down
    glEnd();

    //inner wall
    glBegin(GL_QUADS);
    //glColor3d(0,0.5,1);
    glVertex3d(-x,    d, -4.5+wt); //left up
    glVertex3d( x,    d, -4.5+wt); //right down
    glVertex3d( x, d+wh, -4.5+wt); //left down
    glVertex3d(-x, d+wh, -4.5+wt); //right down
    glEnd();

    //top part
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(-x, d+wh,    -4.5); //left up
    glVertex3d(-x, d+wh, -4.5+wt); //right down
    glVertex3d( x, d+wh, -4.5+wt); //left down
    glVertex3d( x, d+wh,    -4.5); //right down
    glEnd();

    //right part
    glBegin(GL_QUADS);
    //glColor3d(0.62,0.62,0.37);
    glVertex3d(x,    d, -4.5+wt); //left up
    glVertex3d(x,    d,    -4.5); //right down
    glVertex3d(x, d+wh,    -4.5); //left down
    glVertex3d(x, d+wh, -4.5+wt); //right down
    glEnd();
}
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


float cx=0,cy=.2,cz=10, ox=0,oy=0,oz=0;
float angel=0, dis=cz, disHead=cz;
float angelHead = 0;

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 2000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
    //glTranslated(-.2,-1,-12);
    //glRotated(60,1,0,0);
    //glRotated(a,0,1,0);
    gluLookAt(cx,cy,cz,ox,oy,oz,0,1,0);
    main_pilar();
    sub_pilar1();
    table();
    walls();
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
    //Zoom In
    case 'Z':
        cx=cx+.08*cx;
        cz=cz+.08*cz;
        break;
    //Zoom Out
    case 'z':
        cx=cx-.08*cx;
        cz=cz-.08*cz;
        break;
    //Around the object
    case 'A':
        angel+=2;
        dis=sqrt(cx*cx+cz*cz);
        cx=dis*sin(angel*3.1416/180.0);
        cz=dis*cos(angel*3.1416/180.0);
        cout<<dis<<" "<<cx<<" "<<cz<<endl;
        break;
    //Around the object
    case 'a':
        angel-=2;
        dis=sqrt(cx*cx+cz*cz);
        cx=dis*sin(angel*3.1416/180.0);
        cz=dis*cos(angel*3.1416/180.0);
        cout<<dis<<" "<<cx<<" "<<cz<<endl;
        break;
    //Look Right
    case 'R':
        angelHead+=5;
        if(angelHead <= 45)
        {
            ox=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    //Look left
    case 'L':
        angelHead-=5;
        if(angelHead >= -45)
        {
            ox=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    //Look Down
    case 'D':
        angelHead-=5;
        if(angelHead >= -15)
        {
            oy=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
    //Look Up
    case 'U':
        angelHead+=5;
        if(angelHead <= 15)
        {
            oy=disHead*sin(angelHead*3.1416/180.0);
            oz=disHead-disHead*cos(angelHead*3.1416/180.0);
        }
        break;
        /*case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;*/
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1040,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0,0,0,0);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHTING);

    glEnable( GL_LIGHT0);

    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);

    glutMainLoop();

    return EXIT_SUCCESS;
}
