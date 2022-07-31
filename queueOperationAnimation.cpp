#include<glut.h>
#include<string.h>
#include<stdio.h>

int quebody[5][2] = { {200,252},{262,314},{324,376},{386,438},{448,500} };
char queindex[][10] = { {"0"}, {"1"},{"2"},{"3"},{"4"} };
char quetext[][10] = { {"1st in"}, {"2nd in"},{"3rd in"},{"4th in"},{"5th in"} };
char quetext1[][10] = { {"1st out"}, {"2nd out"},{"3rd out"},{"4th out"},{"5th out"} };

void* ff[] = { GLUT_BITMAP_HELVETICA_18,GLUT_BITMAP_TIMES_ROMAN_24 ,GLUT_BITMAP_8_BY_13,GLUT_BITMAP_9_BY_15,GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,GLUT_BITMAP_HELVETICA_10,GLUT_BITMAP_HELVETICA_12,GLUT_BITMAP_HELVETICA_18 };

int cnt = 1;
int q = 0;
float f = 0;
int fn = 0;
int loop = 0;
float tx = 700;
float ty = 60;
int color = 0;
int b = 25;

void* currentfont;
void MyTimerFunc(int value);
void color3();

void drawstring(float x, float y, float z, char strin[], int fn)
{
    char* ct;
    glRasterPos3f(x, y, z);

    for (ct = strin; *ct != '\0'; ct++)
    {
        glColor3f(0.0, 0.0, 0.0);
        //renders a bitmap character using OpenGL.
        glutBitmapCharacter(ff[fn], *ct);
    }
}

void initOpenGl()
{
    glClearColor(0.2, 0.6, 0.99, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 700, 0, 500);
    glMatrixMode(GL_MODELVIEW);
}

void developer()
{

    glColor3f(1, 1, 1);
    char text1[] = "Developed By:";
    drawstring(200, 335, 0.0, text1, 5);
    glColor3f(1, 1, 1);
    char text3[] = "Yuvaraja D";
    drawstring(200, 300, 0.0, text3, 3);
    glColor3f(1, 1, 1);
    char text31[] = "Sai ganesh ";
    drawstring(400, 300, 0.0, text31, 3);
    glColor3f(1, 1, 1);
    char text4[] = "Sindhu C S";
    drawstring(200, 250, 0.0, text4, 3);
    glColor3f(1, 1, 1);
    char text32[] = "Javali Vinutha";
    drawstring(400, 250, 0.0, text32, 3);
    glColor3f(1, 1, 1);
    char text2[] = "UBDTCE,CSE DEPARTMENT";
    drawstring(200, 200, 0.0, text2, 3);


}

void endmsg()
{
    color3();

    glColor3f(1, 1, 1);
    char text1[] = "That's it. Be Safe and Happy";
    drawstring(200, 355, 0.0, text1, 0);
    glColor3f(1, 1, 1);
    char text2[] = "Thank's all for watching.";
    drawstring(200, 315, 0.0, text2, 0);
    glColor3f(1, 1, 1);
    char text3[] = "The End.";
    drawstring(200, 275, 0.0, text3, 0);

}

void line1()
{
    glLoadIdentity();
    glColor3f(1, 1, 1);
    char text[] = "Animated Queue Operation";
    drawstring(280, 475, 0.0, text, 0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 460);
    glVertex2f(800, 460);
    glEnd();

}

void line2()
{
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(190, 190);
    glVertex2f(200, 200);
    glVertex2f(500, 200);
    glVertex2f(510, 190);
    glEnd();

}

void line3()
{
    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(190, 320);
    glVertex2f(200, 310);
    glVertex2f(500, 310);
    glVertex2f(510, 320);

    glEnd();

}

void line4()
{

    glLoadIdentity();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(550, 190);
    glVertex2f(700, 190);
    glEnd();

}
void color3()
{
    glLoadIdentity();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 490);
    glVertex2f(0, 500);
    glVertex2f(10, 500);
    glVertex2f(10, 490);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(10, 490);
    glVertex2f(10, 500);
    glVertex2f(20, 500);
    glVertex2f(20, 490);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(20, 490);
    glVertex2f(20, 500);
    glVertex2f(30, 500);
    glVertex2f(30, 490);
    glEnd();

}
void sbtitlebar()
{
    glLoadIdentity();
    glColor3f(0.0, 0.5, 0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 125);
    glVertex2f(800, 125);
    glVertex2f(800, 0);
    glEnd();
}
void enque_but()
{
    char text1[] = "press E to enque operation";
    drawstring(10, 445, 0.0, text1, 3);
}
void denque_but()
{
    char text1[] = "press D to dequeue operation";
    drawstring(440, 445, 0.0, text1, 3);

}
void del_but()
{
    glColor3f(0, 0, 0);
    char text1[] = "press X to End";
    drawstring(280, 425, 0.0, text1, 3);

}
void ins_but()
{
    glColor3f(1, 1, 1);
    char text1[] = "press A to start";
    drawstring(10, 445, 0.0, text1, 3);
    glColor3f(1, 1, 1);
    char text2[] = "press X to end";
    drawstring(500, 445, 0.0, text2, 3);
}
void ind_txt()
{
    glColor3d(0, 0, 0);
    char front[] = "front end";
    drawstring(160, 170, 1.0, front, 6);
    char index[] = "index";
    drawstring(330, 165, 1.0, index, 6);
    char back[] = "rear end";
    drawstring(510, 170, 1.0, back, 6);
}

char quetext3[][100] = { {"Enqueue Operation"}, //0
    {"Check whether the queue is full or not."},//1
    {"If the queue is full - print the overflow error "},//2
    {"If the queue is not empty - access the data where the front is pointing."},//3
    {"Increment the front pointer to point to the next available data element."},//4
    {"Return success."},//5
    {"Dequeue Operation"},//6
    {"If the queue is empty - print the underflow error."},//7
    {"If the queue is not empty - access the data where the front is pointing."},//8
    {"Increment the front pointer to point to the next available data element."},//9
    {"Return success."},//10
    {"Queue is Underflow"},//11
    {"Queue is Overflow"},//12
    {"Queue follows the FIFO (First - In - First Out) structure."},//13
    {"element inserted first will also be removed first."},//14
    {"Queue is a linear data structure."},
    {"You can`t insert to a full Queue"},//16
    {"You can`t delete from a empty Queue"} };//17

void queuebody2(float tx, float ty)
{


    glBegin(GL_POLYGON);
    glVertex2f(tx, ty);
    glVertex2f(tx, ty + 90);
    glVertex2f(tx + 52, ty + 90);
    glVertex2f(tx + 52, ty);
    glEnd();
    sbtitlebar();

}
void queuebody(int w1, int w2, int q)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1, 210);
    glVertex2f(w1, 300);
    glVertex2f(w2, 300);
    glVertex2f(w2, 210);
    glEnd();
    glColor3f(1, 1, 1);
    drawstring(w1 + 5, 255, 1.0, quetext[q], 6);
    drawstring(w1 + 20, 190, 1.0, queindex[q], 6);
    ind_txt();

}
void queuebody3(int w1, int w2, int q)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1, 210);
    glVertex2f(w1, 300);
    glVertex2f(w2, 300);
    glVertex2f(w2, 210);
    glEnd();
    glColor3f(1, 1, 1);
    drawstring(w1 + 5, 255, 1.0, quetext1[q], 6);
    drawstring(w1 + 20, 190, 1.0, queindex[q], 6);
    ind_txt();

}

void intro()
{
    glClear(GL_COLOR_BUFFER_BIT);
    color3();
    if (color == 0)
    {
        glClearColor(0.32, 0.36, 0.99, 0);
    }
    else if (color == 1)
    {
        glClearColor(0.255, 0.200, 0.50, 0);
    }
    else
    {
        glClearColor(0.42, 0.46, 0.49, 0);
    }
    line1();
    developer();
    glColor3f(0, 0, 0);
    char text21[] = "press S key";
    drawstring(330, 100, 0.0, text21, 3);
    glutSwapBuffers();
    glFlush();

}

//ending
void ending()
{
    //end message
    glClear(GL_COLOR_BUFFER_BIT);
    if (color == 0)
    {
        glClearColor(0.32, 0.36, 0.99, 0);
    }
    else if (color == 1)
    {
        glClearColor(0.255, 0.200, 0.50, 0);
    }
    else
    {
        glClearColor(0.42, 0.46, 0.49, 0);
    }
    color3();
    line1();
    endmsg();

    glutSwapBuffers();
    glFlush();

}
//emprty queue
void display3()
{
    glClear(GL_COLOR_BUFFER_BIT);
    line1();
    line2();
    line3();
    sbtitlebar();
    color3();
    glColor3d(1, 1, 1);
    enque_but();
    glColor3d(1, 0, 0);
    denque_but();
    del_but();
    ind_txt();
    glColor3d(1, 1, 1);
    drawstring(20, 105, 1.0, quetext3[11], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 90, 1.0, quetext3[17], 3);
    glutSwapBuffers();
    glFlush();

}
//full queue
void display4()
{
    glClear(GL_COLOR_BUFFER_BIT);
    line1();
    line2();
    line3();
    sbtitlebar();
    color3();
    glColor3d(1, 0, 0);
    enque_but();
    glColor3d(1, 1, 1);
    denque_but();
    del_but();
    for (int i = 0; i < 5; i++)
    {
        queuebody(quebody[i][0], quebody[i][1], i);
    }
    glColor3d(1, 1, 1);
    drawstring(20, 105, 1.0, quetext3[12], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 90, 1.0, quetext3[16], 3);
    glutSwapBuffers();
    glFlush();

}

//deletion of queue
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    line1();
    line2();
    line3();
    color3();
    sbtitlebar();
    ind_txt();
    if (cnt < 500)
    {
        if ((quebody[loop][1] - cnt) >= 0)
        {
            glColor3f(1.0, 0.0, 0.0);
            queuebody2(quebody[loop][0] - cnt, 210.0);

            for (int i = loop + 1; i < 5; i++)
            {
                queuebody3(quebody[i][0], quebody[i][1], i);
            }
        }
        else {
            cnt = cnt + (loop + 1) * 10;
        }
    }
    else {
        cnt = 0;
        loop += 1;
    }

    glColor3d(1, 1, 1);
    drawstring(20, 105, 1.0, quetext3[6], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 90, 1.0, quetext3[7], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 75, 1.0, quetext3[8], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 60, 1.0, quetext3[9], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 45, 1.0, quetext3[10], 3);


    glutSwapBuffers();
    glFlush();
}
//insertion of queue
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    line1();
    line2();
    line3();
    sbtitlebar();

    color3();
    ind_txt();
    if (cnt < 500)
    {
        if ((tx - cnt) >= (quebody[loop][0]))
        {
            glColor3f(0.0, 1.0, 0.0);
            queuebody2(tx - cnt, 210.0);
            for (int i = 0; i < loop; i++)
            {
                queuebody(quebody[i][0], quebody[i][1], i);
            }
        }
        else {
            cnt = cnt + loop * 50;
        }
    }
    else {
        cnt = 0;
        loop += 1;
    }
    glColor3d(1, 1, 1);
    drawstring(20, 105, 1.0, quetext3[0], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 90, 1.0, quetext3[1], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 75, 1.0, quetext3[2], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 60, 1.0, quetext3[3], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 45, 1.0, quetext3[4], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 30, 1.0, quetext3[5], 3);
    glutSwapBuffers();
    glFlush();
}


//structure of queue
void display0()
{
    glClear(GL_COLOR_BUFFER_BIT);
    line1();
    line2();
    line3();
    sbtitlebar();

    glColor3d(1, 1, 1);
    drawstring(20, 105, 1.0, quetext3[15], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 90, 1.0, quetext3[13], 3);
    glColor3d(1, 1, 1);
    drawstring(20, 75, 1.0, quetext3[14], 3);

    color3();
    for (int i = 0; i < 5; i++)
    {
        queuebody(quebody[i][0], quebody[i][1], i);
    }
    ins_but();
    glutSwapBuffers();
    glFlush();

}
//mouse function
void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (x < 10 && x>0 && y > 0 && y < 10)
        {
            color = 1;
        }
        else if (x < 20 && x>10 && y > 0 && y < 10) {
            color = 0;
        }
        else if (x < 30 && x>20 && y > 0 && y < 10) {
            color = 2;
        }
    }
    if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        printf("%d %d\n", x, y);
    if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        printf("%d %d\n", x, y);
}


//keyboard function
void NormalKey(unsigned char key, GLint x, GLint y)
{
    if (key == 's')
    {
        b = 25;
        glutTimerFunc(0, MyTimerFunc, 0);
    }
    if (key == 'a' or key == 'A')
    {
        b = 75;

    }
    if (key == 'e' or key == 'E')
    {
        b = 100;
    }
    if (key == 'd' or key == 'D')
    {
        b = 50;
    }
    if (key == 'x' or key == 'X')
    {
        b = 0;
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);


    glutInitWindowSize(700, 500);
    glutInitWindowPosition(400, 100);

    glutCreateWindow("Animated Queue Opertaion");

    initOpenGl();

    glutDisplayFunc(intro);
    glutIdleFunc(intro);

    glutKeyboardFunc(NormalKey);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}

void MyTimerFunc(int value)
{
    if (color == 0)
    {
        glClearColor(0.32, 0.36, 0.99, 0);
    }
    else if (color == 1)
    {
        glClearColor(0.255, 0.200, 0.50, 0);
    }
    else
    {
        glClearColor(0.42, 0.46, 0.49, 0);
    }
    if (value == 0)
    {
        //printf("structure of queue\n");
        glutDisplayFunc(display0);
        glutIdleFunc(display0);
        if (b == 75) {
            //simulation
            glutTimerFunc(0, MyTimerFunc, 1);
        }
        else if (b == 0)
        {//exit
            glutTimerFunc(0, MyTimerFunc, 5);
        }
        else {
            //loop
            glutTimerFunc(0, MyTimerFunc, 0);

        }
    }
    else if (value == 1)
    {
        //empty queue
        glutDisplayFunc(display3);
        glutIdleFunc(display3);
        if (b == 100) {
            //insertion
            glutTimerFunc(0, MyTimerFunc, 2);
        }
        else if (b == 50)
        {
            //deletion
            // //not allowed
            glutTimerFunc(0, MyTimerFunc, 1);
        }
        else if (b == 0)
        {//exit
            glutTimerFunc(0, MyTimerFunc, 5);
        }
        else {
            //loop
            glutTimerFunc(0, MyTimerFunc, 1);
        }
    }
    else if (value == 2)
    {
        //printf("insertion of queue\n");

        if (loop != 5) {
            glutDisplayFunc(display1);
            glutIdleFunc(display1);
            cnt += 1;
            //loop
            glutTimerFunc(500 / 300, MyTimerFunc, 2);
        }
        else {
            b = 75;
            cnt = 0;
            loop = 0;
            //move to full queue
            glutTimerFunc(0, MyTimerFunc, 8);
        }
    }
    else if (value == 4)
    {
        //printf("deletion of queue\n");
        if (loop != 5) {
            //loop
            glutDisplayFunc(display2);
            glutIdleFunc(display2);
            cnt += 1;
            glutTimerFunc(500 / 300, MyTimerFunc, 4);
        }
        else {
            b = 75;
            cnt = 0;
            loop = 0;
            glutTimerFunc(0, MyTimerFunc, 1);
        }
    }
    else if (value == 8)
    {
        //full stack
        glutDisplayFunc(display4);
        glutIdleFunc(display4);
        if (b == 100) {
            //insertion
            // not allowed 
            glColor3f(0, 0, 0);
            char text21[] = "insertion not allowed!Queue is full";
            drawstring(330, 100, 0.0, text21, 3);
            glutTimerFunc(0, MyTimerFunc, 8);
        }
        else if (b == 0)
        {//exit
            glutTimerFunc(0, MyTimerFunc, 5);
        }
        else if (b == 50)
        {
            //deletion
            glutTimerFunc(0, MyTimerFunc, 4);
        }
        else {
            glutTimerFunc(0, MyTimerFunc, 8);
        }
    }
    else if (value == 5)
    {
        glutDisplayFunc(ending);
        glutIdleFunc(ending);
        glutTimerFunc(5000, MyTimerFunc, 6);
    }
    else if (value == 6)
    {
        exit(0);
    }
}