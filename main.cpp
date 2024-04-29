#if defined(linux) || defined(_WIN32)

#include <GL/glut.h> /*For Linux and Windows*/

#else

#include <GLUT/GLUT.h> /*For Mac OS*/

#endif

void reshape(int w, int h);

void display();

void processNormalKeys(unsigned char key, int x, int y);

void processSpecialKeys(int key, int x, int y);

int main(int argc, char* argv[])

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 800);

    glutCreateWindow("OpenGL lesson 6");

    glutReshapeFunc(reshape);

    glutDisplayFunc(display);

    glutKeyboardFunc(processNormalKeys);

    glutSpecialFunc(processSpecialKeys);

    glutMainLoop();

    return 0;

}

void reshape(int w, int h)

{

    //glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(60, 1, 1, 20);

    gluLookAt(5, 15, 5, -20, -150, 0, 0, 13, 10);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0, 0, -10);

    glClearColor(1, 1, 1, 0);

}

void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw netted square, black

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);

    for (GLfloat i = -50.0; i <= 50.0; i += 1.0)

    {

        glVertex3f(i, 0.0, -50.0);

        glVertex3f(i, 0.0, 50.0);

        glVertex3f(-50.0, 0.0, i);

        glVertex3f(50.0, 0.0, i);

    }

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINES);

    // Draw OX axis (red)

    glColor3f(1.0, 0.0, 0.0);

    glVertex3f(-10.0, 0.0, 0.0);

    glVertex3f(10.0, 0.0, 0.0);

    // Draw OY axis (green)

    glColor3f(0.0, 1.0, 0.0);

    glVertex3f(0.0, -10.0, 0.0);

    glVertex3f(0.0, 10.0, 0.0);

    // Draw OZ axis (blue)

    glColor3f(0.0, 0.0, 1.0);

    glVertex3f(0.0, 0.0, -10.0);

    glVertex3f(0.0, 0.0, 10.0);

    glEnd();

    //// Draw teapot at origin

    glColor3f(1.0, 0.0, 0.0); // red

    glutWireTeapot(5);

    glutSwapBuffers();

}

void processNormalKeys(unsigned char key, int x, int y)

{

    if (key == 27)

        exit(0);

    else if (key == '+')

        glScaled(1.1, 1.1, 1.1);

    else if (key == '-')

        glScaled(0.9, 0.9, 0.9);

    else if (key == 'W')

    {

        glMatrixMode(GL_MODELVIEW);

        glTranslated(5, 1, 0);

        display();

    }

    display();

}

void processSpecialKeys(int key, int x, int y)

{

    switch (key)

    {

    case GLUT_KEY_UP:

        glMatrixMode(GL_MODELVIEW);

        glTranslated(1, 0, 0);

        display();

        break;

    case GLUT_KEY_DOWN:

        glMatrixMode(GL_MODELVIEW);

        glTranslated(-1, 0, 0);

        display();

        break;

    case GLUT_KEY_LEFT:

        glMatrixMode(GL_MODELVIEW);

        glTranslated(1, 0, -1);

        display();

        break;

    case GLUT_KEY_RIGHT:

        glMatrixMode(GL_MODELVIEW);

        glTranslated(-1, 0, 1);

        display();

        break;

    case GLUT_KEY_HOME:

        glMatrixMode(GL_MODELVIEW);

        glRotated(-10, 1, 0, 0);

        display();

        break;

    case GLUT_KEY_END:

        glMatrixMode(GL_MODELVIEW);

        glRotated(-10, 0, 1, 0);

        display();

        break;

    case GLUT_KEY_PAGE_UP:

        glRotated(10, 1, 1, 1);

        break;

    case GLUT_KEY_PAGE_DOWN:

        glRotated(-10, 1, 1, 1);

        break;

    }

    display();

}
