#include <windows.h>
#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif

void init(void){glClearColor (1, 1, 1, 1);}

void display(){
glClear (GL_COLOR_BUFFER_BIT);

glLineWidth(3.50);
glColor3f(1.0, 0.0, 0.0);
glBegin(GL_POLYGON);
glLineWidth(7);
glColor3f(0.0 , 0.0 , 0.0);
glBegin(GL_LINES);
glVertex3f(80, 80, 0);
glVertex3f(720, 80, 0);

glVertex3f(720, 80, 0);
glVertex3f(720, 720, 0);

glVertex3f(720, 720, 0);
glVertex3f(80, 720, 0);

glVertex3f(80, 720, 0);
glVertex3f(80, 80, 0);
glEnd();

  int x,y,color=0;
    int sh=8;
    for(x=1; x<=sh; x++){
        if(color==0){
           glColor3f(1, 1  , 1 );
            color++; } else{
            glColor3f (0, 0, 0);
            color=0;}

        for(y=1; y<=sh; y++){
            if(color==0){ glColor3f(1, 1, 1 );
                color++;}else{ glColor3f (0, 0  , 0); color=0;}

            glBegin(GL_QUADS);
            glVertex2f(80*x, 80*y);   // 80, 80,
            glVertex2f(80+80*x, 80*y); //160, 80
            glVertex2f(80+80*x, 80+80*y); //160, 160
            glVertex2f(80*x, 80+80*y);  // 80, 160
            glEnd();
        }
    }
    glFlush ();
}

void reshape (int w, int h)
{
    glViewport (1.0, 1.0, w, h);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
    gluOrtho2D (1.0, w, 1.0, h);
}


int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 1000);
glutInitWindowPosition (10, 10);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
