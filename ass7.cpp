/*
Generate fractal patterns using i) Koch Curve
*/
#include<iostream>
#include<math.h>
#include<iostream>
#include<GL/glut.h>
using namespace std;
GLfloat oldx=-0.7,oldy=0.5;
int k=0,c;
void drawkoch(GLfloat dir,GLfloat len,GLint iter)
{
	GLdouble dirRad=0.0174533*dir;
	GLfloat newx=oldx+ len*cos(dirRad);
	GLfloat newy=oldy+ len*sin(dirRad);
	glBegin(GL_LINE_LOOP);
	if(iter==0)
	{
		glVertex2f(newx,newy);
		glVertex2f(oldx,oldy);
		oldx=newx;
		oldy=newy;
	}
	else
	{
		iter--;
		drawkoch(dir,len,iter);
		dir+=60;
		drawkoch(dir,len,iter);
		dir-=120;
		drawkoch(dir,len,iter);
		dir+=60;
		drawkoch(dir,len,iter);
	}
	glEnd();
}
void mydisplay(void)
{
	int n;
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0f,0.0f,0.0f);
	glLineWidth(5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	cout<<"\nEnter the number of interation\n";
	cin>>n;
	drawkoch(0.0,0.05,n);
	drawkoch(-120.0,0.05,n);
	drawkoch(120.0,0.05,n);
	glEnd();
	glFlush();
	
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(0,0);
	glutCreateWindow("koch");
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;

}

