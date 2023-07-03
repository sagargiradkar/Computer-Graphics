/*
Implement Bresenham circle drawing algorithm to draw any object. i) Simple circle ii) Concentric
circle iii) Olympic ring iv) Spiral .The object should be displayed in all the quadrants with respect to
center and radius
*/
#include <iostream>
#include <GL/glut.h>
using namespace std;
#define he 1300
#define wi 1300

int h, k, r, d, x, y, no, turns;

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(3.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-wi / 2, wi / 2, -he / 2, he / 2);
}
void Circle(int r)
{
	d = 3 - 2 * r;

	x = 0;
	y = r;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	while (x <= y)
	{
		if (d <= 0)
		{
			d = d + 4 * x + 6;
			x++;
		}
		else
		{
			d = d + 4 * (x - y) + 10;
			x++;
			y--;
		}
		glBegin(GL_POINTS);
		glVertex2i(x + h, y + k);
		glVertex2i(-x + h, -y + k);
		glVertex2i(y + h, x + k);
		glVertex2i(-y + h, -x + k);
		glVertex2i(-y + h, x + k);
		glVertex2i(y + h, -x + k);
		glVertex2i(-x + h, y + k);
		glVertex2i(x + h, -y + k);
		glEnd();
	}
}

void Olympic_Ring(int r, int h, int k)
{
	d = 3 - 2 * r;

	x = 0;
	y = r;
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	while (x <= y)
	{
		if (d <= 0)
		{
			d = d + 4 * x + 6;
			x++;
		}
		else
		{
			d = d + 4 * (x - y) + 10;
			x++;
			y--;
		}
		glBegin(GL_POINTS);
		glVertex2i(x + h, y + k);
		glVertex2i(-x + h, -y + k);
		glVertex2i(y + h, x + k);
		glVertex2i(-y + h, -x + k);
		glVertex2i(-y + h, x + k);
		glVertex2i(y + h, -x + k);
		glVertex2i(-x + h, y + k);
		glVertex2i(x + h, -y + k);
		glEnd();
	}
}

// Spiral
void Spiral_Curve_1()
{

	int radius = 10;
	glBegin(GL_POINTS);
	glVertex2i(x + h, y + h);
	glEnd();
	for (int i = 0; i < turns; i++)
	{
		h = h + 10;
		d = 3 - 2 * radius;
		x = 0, y = radius;
		while (x <= y)
		{
			if (d <= 0)
			{
				d = d + 4 * x + 6;
				x = x + 1;
			}
			else
			{
				d = d + 4 * (x - y) + 10;
				x = x + 1;
				y = y - 1;
			}
			glBegin(GL_POINTS);
			glVertex2i(x + h, y + k);
			glVertex2i(-x + h, y + k);
			glVertex2i(y + h, x + k);
			glVertex2i(-y + h, x + k);
			glEnd();
		}
		radius = radius + 10;
		h = h - 10;
		d = 3 - 2 * radius;
		x = 0, y = radius;
		while (x <= y)
		{
			if (d <= 0)
			{
				d = d + 4 * x + 6;
				x = x + 1;
			}
			else
			{
				d = d + 4 * (x - y) + 10;
				x = x + 1;
				y = y - 1;
			}
			glBegin(GL_POINTS);
			glVertex2i(x + h, -y + k);
			glVertex2i(-x + h, -y + k);
			glVertex2i(y + h, -x + k);
			glVertex2i(-y + h, -x + k);
			
			
			glEnd();
		}
		radius = radius + 10;
	}
}
void Menu(int n)
{
	switch (n)
	{
	case 1:
		Circle(r);
		break;

	case 2:
		// Upper Rings
		glColor3f(0.0, 0.0, 1.0);
		Olympic_Ring(r, 2 * r, 6 * r);
		glColor3f(0.0, 0.0, 0.0);
		Olympic_Ring(r, 3.6 * r, 6 * r);
		glColor3f(1.0, 0.0, 0.0);
		Olympic_Ring(r, 5.2 * r, 6 * r);

		// Lower Rings

		glColor3f(1.0, 1.0, 0.0);
		Olympic_Ring(r, 2.8 * r, 4.8 * r);
		glColor3f(0.0, 1.0, 0.0);
		Olympic_Ring(r, 4.4 * r, 4.8 * r);
		glColor3f(0.0, 0.0, 0.0);
		break;

	case 3:
		
		for (int i = 1; i <= no; i++)
		{
			Circle(r);
			r += 20;
		}
		break;

	case 4:
		Spiral_Curve_1();
		break;
	case 5:
		exit(0);
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2i(wi / 2, 0);
	glVertex2i(-wi / 2, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(0, he / 2);
	glVertex2i(0, -he / 2);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	cout << "\n\n\t\t ===================================== \n";
	cout << "\t\t ||  Bresenham Circle Drawing Algo  || \n";
	cout << "\t\t ===================================== \n\n";

	cout << "\n >>> Enter the Radius of the Circle : \n >> Radius = ";
	cin >> r;

	cout << "\n\n >>> Enter the No of Circle's you want : \n >> No = ";
	cin >> no;

	cout << "\n\n >>> Enter Number of turns you want : \n >> No = ";
	cin >> turns;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Circle Algorithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutCreateMenu(Menu); // Menu Creation
	glutAddMenuEntry(" 1. Simple Circle ", 1);
	glutAddMenuEntry(" 2. Olympic Ring", 2);
	glutAddMenuEntry(" 3. Concentric Circle  ", 3);
	glutAddMenuEntry(" 4. ClockWise Spiral Curve ", 4);

	glutAddMenuEntry(" 5. Exit ", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}
