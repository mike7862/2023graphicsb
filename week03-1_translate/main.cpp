#include <GL/glut.h>
void display()
{
    glPushMatrix();///備分矩陣
        glTranslatef( 0.5, 0.5, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();///還原矩陣

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("week03");
glutDisplayFunc(display);
glutMainLoop();
}
