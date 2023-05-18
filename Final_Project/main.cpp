#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * rightarm = NULL;
GLMmodel * righthand = NULL;
int show[4] = {1,1,1,1};
int ID = 2;
float teapotX = 0, teapotY = 0;
FILE * fout = NULL;
FILE * fin = NULL;
void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL){
        head = glmReadOBJ("model/head.obj");
        body = glmReadOBJ("model/body.obj");
        rightarm = glmReadOBJ("model/rightarm.obj");
        righthand = glmReadOBJ("model/righthand.obj");
        ///glmUnitize(head);
    }
    glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        glPushMatrix();
            glTranslatef(teapotX, teapotY, 0);

            if(ID==0) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if (show[0]) glmDraw(head, GLM_MATERIAL);
        glPopMatrix();

        if(ID==1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if (show[1]) glmDraw(body, GLM_MATERIAL);

        if(ID==2) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if (show[2]) glmDraw(rightarm, GLM_MATERIAL);

        if(ID==3) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if (show[3]) glmDraw(righthand, GLM_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0, oldY=0;
void  mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
    }
}
void motion(int x, int y){
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week13");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
