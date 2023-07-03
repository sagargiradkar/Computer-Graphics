/*
Install and explore the OpenGL. Draw a object in OPENGL
*/
#include<iostream>
#include<GL/glut.h>

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1080.0,0.0,720.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
		glVertex2i(400,300);
		glVertex2i(400,500);
		glVertex2i(600,500);
		glVertex2i(600,300);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(670,240);
		glVertex2i(670,480);
		glVertex2i(770,480);
		glVertex2i(770,240);
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,1.0);
		glVertex2i(670,240);
		glVertex2i(670,480);
		glVertex2i(770,480);
		glVertex2i(770,240);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(674,244);
		glVertex2i(674,476);
		glVertex2i(766,476);
		glVertex2i(766,244);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
		glVertex2i(480, 270);	
		glVertex2i(480, 300);
		glVertex2i(520, 300);
		glVertex2i(520, 270);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(460,240);
		glVertex2i(460,270);
		glVertex2i(540,270);
		glVertex2i(540,240);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(370,120);
		glVertex2i(370,200);
		glVertex2i(630,200);
		glVertex2i(630,120);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(375,125);
		glVertex2i(375,195);
		glVertex2i(625,195);
		glVertex2i(625,125);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(690,400);
		glVertex2i(690,415);
		glVertex2i(750,415);
		glVertex2i(750,400);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(710,300);
		glVertex2i(710,320);
		glVertex2i(730,320);
		glVertex2i(730,300);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(410,310);
		glVertex2i(410,490);
		glVertex2i(590,490);
		glVertex2i(590,310);
	glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.0,.0,1.0);
		glVertex2i(410,310);
		glVertex2i(410,490);
		glVertex2i(590,490);
		glVertex2i(590,310);
	glEnd();
	// Keyboard Outline
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(370,120);
		glVertex2i(370,200);
		glVertex2i(630,200);
		glVertex2i(630,120);
	glEnd();
	
	// Keyboard Inline
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(375,125);
		glVertex2i(375,195);
		glVertex2i(625,195);
		glVertex2i(625,125);
	glEnd();
	
	//Keyboard Keys 1
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(380,130);
		glVertex2i(380,140);
		glVertex2i(390,140);
		glVertex2i(390,130);
	glEnd();
	
	// 2
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(395,130);
		glVertex2i(395,140);
		glVertex2i(405,140);
		glVertex2i(405,130);
	glEnd();
	
	// 3
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(410,130);
		glVertex2i(410,140);
		glVertex2i(420,140);
		glVertex2i(420,130);
	glEnd();
	
	// 4
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(425,130);
		glVertex2i(425,140);
		glVertex2i(435,140);
		glVertex2i(435,130);
	glEnd();
	
	// 5
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(440,130);
		glVertex2i(440,140);
		glVertex2i(515,140);
		glVertex2i(515,130);
	glEnd();
	
	// 6
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(520,130);
		glVertex2i(520,140);
		glVertex2i(530,140);
		glVertex2i(530,130);
	glEnd();
	
	// 7
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(535,130);
		glVertex2i(535,140);
		glVertex2i(545,140);
		glVertex2i(545,130);
	glEnd();
	
	// 8
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(550,130);
		glVertex2i(550,140);
		glVertex2i(560,140);
		glVertex2i(560,130);
	glEnd();
	
	// 9
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(565,130);
		glVertex2i(565,135);
		glVertex2i(575,135);
		glVertex2i(575,130);
	glEnd();
	
	// 10
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(580,130);
		glVertex2i(580,135);
		glVertex2i(590,135);
		glVertex2i(590,130);
	glEnd();
	
	// 11
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(595,130);
		glVertex2i(595,135);
		glVertex2i(605,135);
		glVertex2i(605,130);
	glEnd();
	
	// 12
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(580,140);
		glVertex2i(580,145);
		glVertex2i(590,145);
		glVertex2i(590,140);
	glEnd();
	
	// 13
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(610,130);
		glVertex2i(610,140);
		glVertex2i(620,140);
		glVertex2i(620,130);
	glEnd();
	
	// Upper 14
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(380,150);
		glVertex2i(380,160);
		glVertex2i(390,160);
		glVertex2i(390,150);
	glEnd();
	
	// Upper 15
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(395,150);
		glVertex2i(395,160);
		glVertex2i(405,160);
		glVertex2i(405,150);
	glEnd();
	
	// Upper 16
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(410,150);
		glVertex2i(410,160);
		glVertex2i(420,160);
		glVertex2i(420,150);
	glEnd();
	
	// Upper 17
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(425,150);
		glVertex2i(425,160);
		glVertex2i(435,160);
		glVertex2i(435,150);
	glEnd();
	
	// Upper 18
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(440,150);
		glVertex2i(440,160);
		glVertex2i(450,160);
		glVertex2i(450,150);
	glEnd();
	
	// Upper 19
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(455,150);
		glVertex2i(455,160);
		glVertex2i(465,160);
		glVertex2i(465,150);
	glEnd();
	
	// Upper 20
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(470,150);
		glVertex2i(470,160);
		glVertex2i(480,160);
		glVertex2i(480,150);
	glEnd();
	
	// Upper 21
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(485,150);
		glVertex2i(485,160);
		glVertex2i(495,160);
		glVertex2i(495,150);
	glEnd();
	
	// Upper 22
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(505,150);
		glVertex2i(505,160);
		glVertex2i(515,160);
		glVertex2i(515,150);
	glEnd();
	
	// Upper 23
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(520,150);
		glVertex2i(520,160);
		glVertex2i(530,160);
		glVertex2i(530,150);
	glEnd();
	
	// Upper 24 Enter Key
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(535,150);
		glVertex2i(535,160);
		glVertex2i(565,160);
		glVertex2i(565,150);
	glEnd();
	
	// Upper 25
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(580,150);
		glVertex2i(580,160);
		glVertex2i(590,160);
		glVertex2i(590,150);
	glEnd();
	
	// Upper 26
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(595,150);
		glVertex2i(595,160);
		glVertex2i(605,160);
		glVertex2i(605,150);
	glEnd();
	
	// Upper 27
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(610,150);
		glVertex2i(610,160);
		glVertex2i(620,160);
		glVertex2i(620,150);
	glEnd();
	
	// Upper1 27
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(580,150);
		glVertex2i(580,160);
		glVertex2i(590,160);
		glVertex2i(590,150);
	glEnd();
	
	// Upper1 29
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(580,170);
		glVertex2i(580,180);
		glVertex2i(590,180);
		glVertex2i(590,170);
	glEnd();
	
	// Upper1 30
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(595,170);
		glVertex2i(595,180);
		glVertex2i(605,180);
		glVertex2i(605,170);
	glEnd();
	
	// Upper1 31
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(610,170);
		glVertex2i(610,180);
		glVertex2i(620,180);
		glVertex2i(620,170);
	glEnd();
	
	// Upper2 32
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(380,170);
		glVertex2i(380,180);
		glVertex2i(390,180);
		glVertex2i(390,170);
	glEnd();
	
	// Upper2 33
	glBegin(GL_LINE_LOOP);	
		glColor3f(0.0,0.0,0.0);
		glVertex2i(395,170);
		glVertex2i(395,180);
		glVertex2i(405,180);
		glVertex2i(405,170);
	glEnd();
	
	// Upper2 34
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(410,170);
		glVertex2i(410,180);
		glVertex2i(420,180);
		glVertex2i(420,170);
	glEnd();
	
	// Upper2 34
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(425,170);
		glVertex2i(425,180);
		glVertex2i(435,180);
		glVertex2i(435,170);
	glEnd();
	
	// Upper2 34
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(440,170);
		glVertex2i(440,180);
		glVertex2i(450,180);
		glVertex2i(450,170);
	glEnd();
	
	// Upper2 35
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(455,170);
		glVertex2i(455,180);
		glVertex2i(465,180);
		glVertex2i(465,170);
	glEnd();
	
	// Upper2 35
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(470,170);
		glVertex2i(470,180);
		glVertex2i(480,180);
		glVertex2i(480,170);
	glEnd();
	
	// Upper2 36
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(485,170);
		glVertex2i(485,180);
		glVertex2i(495,180);
		glVertex2i(495,170);
	glEnd();
	
	// Upper2 37
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(500,170);
		glVertex2i(500,180);
		glVertex2i(510,180);
		glVertex2i(510,170);
	glEnd();
	
	// Upper2 38
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(515,170);
		glVertex2i(515,180);
		glVertex2i(525,180);
		glVertex2i(525,170);
	glEnd();
	
	// Upper2 39
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(530,170);
		glVertex2i(530,180);
		glVertex2i(540,180);
		glVertex2i(540,170);
	glEnd();
	
	// Upper2 40
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(545,170);
		glVertex2i(545,180);
		glVertex2i(555,180);
		glVertex2i(555,170);
	glEnd();
	
	// Upper 41
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(560,170);
		glVertex2i(560,180);
		glVertex2i(570,180);
		glVertex2i(570,170);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(690,400);
		glVertex2i(690,415);
		glVertex2i(750,415);
		glVertex2i(750,400);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(710,300);
		glVertex2i(710,320);
		glVertex2i(730,320);
		glVertex2i(730,300);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(410,310);
		glVertex2i(410,490);
		glVertex2i(590,490);
		glVertex2i(590,310);
	glEnd();
	
	
	glFlush();	
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(100,150);
	glutCreateWindow("My Computer");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
}