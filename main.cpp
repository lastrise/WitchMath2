#include "GLUT/glut.h"
#include "RigidBody/RigidBody.h"


#define DEF_D 5
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))


RigidBody rigidBody = RigidBody();

void solve(RigidBody &body, double h) {
    RigidBody k1{}, k2{}, k3{}, k4{};

    k1 = body.f();
    k2 = (body + k1 * (h / 3)).f();
    k3 = (body + ((k1 * (-h / 3)) + (k2 * h))).f();
    k4 = (body + ((k1 * h) + (k2 * (-h)) + (k3 * h))).f();
    body = body + ((k1 * (1.0 / 8)) + (k2 * (3.0 / 8)) + (k3 * (3.0 / 8)) + (k4 * (1.0 / 8))) * h;

    body.q = body.q.normalize();
    body.R = body.q.toMatrix();
}

void Idle() {
    glutPostRedisplay();
}

void drawCylinder() {
    int j, i, k;
    glBegin(GL_QUAD_STRIP);
    for (j=0;j<=360;j+=DEF_D) {
        glColor3f(Cos(j),Sin(j),0.5);
        glVertex3f(Cos(j),+1,Sin(j));
        glColor3f(0.2,Cos(j),Sin(j));
        glVertex3f(Cos(j),-1,Sin(j));
    }
    glEnd();

    for (i=1;i>=-1;i-=2) {
        glBegin(GL_TRIANGLE_FAN);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(0,i,0);
        for (k=0;k<=360;k+=DEF_D) {
            glColor3f(1,0.0,0.0);
            glVertex3f(i*Cos(k),i,Sin(k));
        }
        glEnd();
    }
    glBegin(GL_QUAD_STRIP);
    for (j=0;j<=0;j+=DEF_D) {
        glColor3f(1,1,0.0);
        glVertex3f(Cos(j),+1,Sin(j));
        glColor3f(0.0,1,0.0);
        glVertex3f(Cos(j),-1,Sin(j));
    }
    glEnd();
}

void Display() {
    glViewport(0, 0, 600, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    solve(rigidBody, 0.000001);
    glPushMatrix();
    glTranslated(rigidBody.r.x, rigidBody.r.y, rigidBody.r.z - 5);
    glRotated(acos(rigidBody.q.r) * 360 / M_PI, rigidBody.q.i, rigidBody.q.j, rigidBody.q.k);
    drawCylinder();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char * argv []) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("WitchMath 2");
    glutDisplayFunc(Display);
    glutIdleFunc(Idle);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();

    return 0;
}