/*
Implement
B) Bresenham line drawing algorithm
to draw: i) Simple Line ii) Dotted Line iii) Dashed Line iv) Solid line .Divide the screen in four
quadrants with center as (0, 0). The line should work for all the slopes positive as well as negative.
*/
#include<iostream>
#include<GL/glut.h>
using namespace std;
#define h 500
#define w 500
 
int x, y, x1, x2, y11, y2, dx, dy, s1, s2, interchange, e;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}

int Sign(int x)
{
 	if(x>0)
 	{
 		return 1;
 	}
 	else if(x==0)
 	{
 		return 0;
 	}
 	else
 	{
 		return -1;
 	}		
}	

void Plot(float x, float y)
{
	glVertex2i(x, y);
}

void Bresenham_Simple_Line(int x1, int y11, int x2, int y2)
{
	x = x1, y = y11;
	dx = abs(x2-x1);
	dy = abs(y2-y11);
	s1 = Sign(x2-x1);
	s2 = Sign(y2-y11);
	
	if(dy>dx)
	{
		swap(dx,dy);
		interchange = 1;
	}
	
	else
	{
		interchange = 0;
	}
	
	e = 2*dy - dx;
	
	Plot(x, y);
	
	for(int i = 1; i<=dx ; i++)
	{
		glBegin(GL_POINTS);
		Plot(x, y);	
		
		while(e>=0)
		{
			if(interchange == 1)
			{
				x = x + s1;
			}
			else
			{
				y = y + s2;
			}
			e = e - 2*dx;			
		}	
		
		if(interchange == 1)
		{
			y = y + s2;
		}
		else
		{
			x = x + s1;
		}
		e = e + 2*dy;
		glEnd();
	}
	//return x, y;
}	

int Bresenham_Dotted_Line(int x1, int y11, int x2, int y2)
{
	int temp;

	x = x1, y = y11;
	dx = abs(x2-x1);
	dy = abs(y2-y11);
	s1 = Sign(x2-x1);
	s2 = Sign(y2-y11);
	
	if(dy>dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	
	else
	{
		interchange = 0;
	}
	
	e = 2*dy - dx;
	
	Plot(x, y);
	
	for(int i = 1; i<=dx ; i++)
	{
		glBegin(GL_POINTS);
		
		if(i%20 == 0)
		{	
			Plot(x,y);
		}
				
		while(e>=0)
		{
			if(interchange == 1)
			{
				x = x + s1;
			}
			else
			{
				y = y + s2;
			}
			e = e - 2*dx;			
		}	
		
		if(interchange == 1)
		{
			y = y + s2;
		}
		else
		{
			x = x + s1;
		}
		e = e + 2*dy;
		glEnd();
	}
	return x, y;
}

int Bresenham_Dashed_Line(int x1, int y11, int x2, int y2)
{
	int temp;

	x = x1, y = y11;
	dx = abs(x2-x1);
	dy = abs(y2-y11);
	s1 = Sign(x2-x1);
	s2 = Sign(y2-y11);
	
	if(dy>dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	
	else
	{
		interchange = 0;
	}
	
	e = 2*dy - dx;
	
	Plot(x, y);
	
	for(int i = 1; i<=dx ; i++)
	{
		glBegin(GL_POINTS);

		if(i%2==0 && i%15!=0 )
		{
			Plot(x,y);
		}
		
		while(e>=0)
		{
			if(interchange == 1)
			{
				x = x + s1;
			}
			else
			{
				y = y + s2;
			}
			e = e - 2*dx;			
		}	
		
		if(interchange == 1)
		{
			y = y + s2;
		}
		else
		{
			x = x + s1;
		}
		e = e + 2*dy;
		glEnd();
	}
	return x, y;
}

int Bresenham_Center_Dot_Line(int x1, int y11, int x2, int y2)
{
	int temp;

	x = x1, y = y11;
	dx = abs(x2-x1);
	dy = abs(y2-y11);
	s1 = Sign(x2-x1);
	s2 = Sign(y2-y11);
	
	if(dy>dx)
	{
		temp = dx;
		dx = dy;
		dy = temp;
		interchange = 1;
	}
	
	else
	{
		interchange = 0;
	}
	
	e = 2*dy - dx;
	
	Plot(x, y);
	
	for(int i = 1; i<=dx ; i++)
	{
		glBegin(GL_POINTS);
				
		if(i%20<=10 || i%20==15)
		{
			Plot(x,y);
		}
		
		while(e>=0)
		{
			if(interchange == 1)
			{
				x = x + s1;
			}
			else
			{
				y = y + s2;
			}
			e = e - 2*dx;			
		}	
		
		if(interchange == 1)
		{
			y = y + s2;
		}
		else
		{
			x = x + s1;
		}
		e = e + 2*dy;
		glEnd();
	}
	return x, y;
}

void Menu(int n)
{
	switch(n)
	{
		case 1:
			Bresenham_Simple_Line(x1, y11, x2, y2);	
			break;
				
		case 2:
			Bresenham_Dotted_Line(x1, y11, x2, y2);
			break;
			
		case 3:
			Bresenham_Dashed_Line(x1, y11, x2, y2);	
			break;
			
		case 4:
			Bresenham_Center_Dot_Line(x1, y11, x2, y2);
			break;
			
		case 5:
			glColor3f(1.0,0.0,1.0);
			Bresenham_Simple_Line(40, 40, 40, 160);	
			Bresenham_Simple_Line(40, 160, 180, 160);	
			Bresenham_Simple_Line(180, 160, 180, 40);				
			Bresenham_Simple_Line(180, 40, 40, 40);		
			glColor3f(0.0,0.0,1.0);
			Bresenham_Simple_Line(40, 100, 110, 160);	
			Bresenham_Simple_Line(110, 160, 180, 100);	
			Bresenham_Simple_Line(180, 100, 110, 40);
			Bresenham_Simple_Line(110, 40, 40, 100);
			glColor3f(0.0,0.0,0.0);
			Bresenham_Simple_Line(75, 130, 145, 130);	
			Bresenham_Simple_Line(145, 130, 145, 70);	
			Bresenham_Simple_Line(145, 70, 75, 70);
			Bresenham_Simple_Line(75, 70, 75, 130);						
			break;		
			
		case 6:
			exit(0);
	}	
	
}	

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
	for(int i=-w; i<=w; i++)
	{
		Plot(i, 0);
		Plot(0, i);
	}	
		
	glEnd();
	glFlush();
}
		
int main(int argc, char **argv)
{				
		cout<<"\n\n\t\t =================================== \n";
		cout<<"\t\t ||  Bresenham Line Drawing Algo  || \n";
		cout<<"\t\t =================================== \n\n";
		
			cout<<"\n Enter The Start Point :: \n\n >> x1 = ";
			cin>>x1;
			cout<<" >> y1 = ";
			cin>>y11;
			
			cout<<"\n Enter The End Point :: \n\n >> x2 = ";
			cin>>x2;
			cout<<" >> y2 = ";
			cin>>y2;
				
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(1080,720);
			glutInitWindowPosition(50,100);
			glutCreateWindow("Bresenhams Line Algorithm");
			myInit();
			glutDisplayFunc(myDisplay);
			glutCreateMenu(Menu); //Menu Creation
				glutAddMenuEntry(" 1. Simple Line ", 1);
				glutAddMenuEntry(" 2. Dotted Line ", 2);
				glutAddMenuEntry(" 3. Dashed Line ", 3);
				glutAddMenuEntry(" 4. Center Dotted Line ", 4);
				glutAddMenuEntry(" 5. Draw Diagram ", 5);
				glutAddMenuEntry(" 6. Exit ", 6);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	
	return 0;	
}


	
