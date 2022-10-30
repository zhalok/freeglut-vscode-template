/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adju
 * using the + and - keys.
 */
//#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
float line(float x) { return (5.0 - 2 * x) / 3.0; }
float circle(float x) { return sqrt(sqrt(5.0 / 7.0) - x * x); }
int check(float i, float j) {
  if (abs(i * i + j * j - sqrt(5.0 / 7.0) - 0) <= 0.000001) {
    return 1;
  }
  return 0;
}
void bresenhams(int x1, int x2, int y1, int y2) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int p1 = 2 * dy - dx;
  int x = x1;
  int y = y1;
  while (x < x2) {
    x++;
    // cout << x << " " << y << endl;
    glVertex3f(x, y, 0);
    if (p1 < 0) {
      p1 += 2 * dy;
    } else {
      y++;
      p1 += (2 * dy - 2 * dx);
    }
  }
}
void dda(int x1, int x2, int y1, int y2) {

  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int step = dx < dy ? dx : dy;
  int x = x1;
  int y = y1;
  for (int i = 1; i <= step; i++) {
    glVertex3f(x, y, 0);
    x += (dx / step);
    y += (dy / step);
  }
}

static void display(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(5.0);
  glBegin(GL_POINTS);
  int x1, x2, y1, y2;
  // cin >> x1 >> x2 >> y1 >> y2;
  x1 = 2;
  x2 = 6;
  y1 = 6;
  y2 = 12;
  bresenhams(x1, x2, y1, y2);

  glEnd();

  // glBegin(GL_POINTS);
  // glVertex3f(1, 0, 0);
  // // glColor3f(GLfloat red, GLfloat green, GLfloat blue)

  // for (float i = -sqrt(sqrt(5.0 / 7.0)) - 2; i <= sqrt(sqrt(5.0 / 7.0)) + 2;
  //      i = i + 0.00001) {
  //   // cout<<i<<" "<<circle(i)<<"\n";
  //   glColor3f(1.0, 0.0, 0.0);
  //   glVertex3f(i, circle(i), 0.0);
  //   glVertex3f(i, -circle(i), 0.0);
  // }
  // for (float i = -3.0; i <= 3; i = i + 0.01) {
  //   for (float j = -0.3; j <= 3; j = j + 0.01) {
  //     if (check(i, j) == 1) {
  //       cout << i << " " << j << "\n";
  //       glColor3f(1.0, 0.0, 0.0);
  //       glVertex3f(i, j, 0.0);
  //     }
  //   }
  // }

  // glEnd();
  //   glBegin(GL_POINTS);
  // glColor3f(1,0,0);

  //   glEnd();
  glFlush();
}
void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100.0, 100.0, -100.0, 100.0, -1100.0, 100.0);
}
int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(10, 10);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

  glutCreateWindow("Demo");
  init();
  glutDisplayFunc(display);
  glutMainLoop();

  return 0;
}
/**

#include <windows.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;



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

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
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

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
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



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(glVertex3f(i,circle(i),0.0);GL_LESS);

    glEnable(GL_LIGHT0);
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

    glutMainLoop();

    return EXIT_SUCCESS;
}

**/
