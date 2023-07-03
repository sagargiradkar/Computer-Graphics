/*
Implement the following polygon filling methods : i) Flood fill / Seed fill ii) Boundary fill ; using
mouse click, keyboard interface and menu driven programming
*/
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define w 500
#define h 500

using namespace std;

int algo = 0;
float boundaryColor[3]={0,0,0};
float interiorColor[3]={1,1,1};
float fillColor[3]={0,0,1};
float readpixel[3];

void myInit (void) {
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
    glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

void SetPixel(int p, int q)
{
  	glColor3fv(fillColor);
	glBegin(GL_POINTS);
	glVertex2f(p,q);
	glEnd();
}

void GetPixel(int p, int q, float *color)
{
	glReadPixels(p, q, 1, 1, GL_RGB, GL_FLOAT, color);
}
// Boundary Fill Algorithm
// Function for BoundaryFill4
void BoundaryFill4(int x, int y)
{
	GetPixel(x, y, interiorColor);
	if((x<0)|| (x >= w)) return;
	if((y<0)|| (y >= h)) return;
	
	if((interiorColor[0]!= boundaryColor[0] && interiorColor[1]!= boundaryColor[1] && interiorColor[2]!= boundaryColor[2]) || (interiorColor[0] != fillColor[0] && interiorColor[1]!= fillColor[1] && interiorColor[2] != fillColor[2]))
	{
		SetPixel(x, y);
		
		BoundaryFill4(x+1, y);
		BoundaryFill4(x-1, y);
		BoundaryFill4(x, y+1);
		BoundaryFill4(x, y-1);
		glEnd();
		glFlush();		
	}
}
	
// Flood Fill Algorithm
// Function for FloodFill4
void FloodFill4(int x, int y)
{
	GetPixel(x, y, readpixel);

	if( readpixel[0] == interiorColor[0] && readpixel[1] == interiorColor[1] && readpixel[2] == interiorColor[2])
	{
		SetPixel(x, y);

		FloodFill4(x+1,y);
		FloodFill4(x-1,y);
		FloodFill4(x,y+1);
		FloodFill4(x,y-1);
		glEnd();	
		glFlush();		
	}
}

void Menu(int n)
{
	switch(n)
	{
		case 1:
		   	// BoundaryFill4
			algo = 1;
			break;
				
		case 2:
			// FloodFill4
			algo = 2;
			break;	
			
		case 3:
			exit(0);
	}	
	
}	

// Mouse Interfacing Method
void Mouse(int btn, int state, int x, int y)
{
	if((btn == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (algo == 1))
	{
		BoundaryFill4(x,480-y);
	}	 

	if((btn == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (algo == 2))
	{
		FloodFill4(x,480-y);
	}	 
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(200,200);
	glVertex2f(200,400);
	glVertex2f(400,400);
	glVertex2f(400,200);
		
	glEnd();
	glFlush();
}
		
int main(int argc, char **argv)
{
			glutInit( & argc, argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(640, 480);
			glutInitWindowPosition(100, 150);
			glutCreateWindow(" Polygon Fill Algorithm ");
			myInit();
			glutDisplayFunc(myDisplay);
			glutMouseFunc(Mouse);
			glutCreateMenu(Menu); //Menu Creation
				glutAddMenuEntry(" 1. Boundary Fill Algorithm ", 1);
				glutAddMenuEntry(" 2. Flood Fill Algorithm ", 2);
				glutAddMenuEntry(" 3. Exit ", 3);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	
	return 0;	
}
