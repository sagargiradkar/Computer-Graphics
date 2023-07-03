/*
Implement following 2D transformations on the object with respect to axis i) Basic Tranformations
ii) Other transformations iii) Composite Transformations
*/
#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
#define h 700
#define w 700                                                                                                                                                               
int mati[100][100], k = 0;
int mato[100][100]; 
float tx,ty;
float Xm,Ym;
float sx,sy;
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void Plot(float x, float y)
{
	glVertex2i(x, y);
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(0.0, 0.0, 0.0);
	
	for(int i=-w; i<=w; i++)
	{
		Plot(i, 0);
		Plot(0, i);
	}	
		
	glEnd();
	glFlush();
}
void multMatrix(float  arrT[3][3])
	{
		for(int i=0;i<k;i++)
			{
				mato[i][0]=(float)(arrT[0][0]*mati[i][0]+arrT[0][1]*mati[i][1]+arrT[0][2]*mati[i][2]);
				mato[i][1]=(float)(arrT[1][0]*mati[i][0]+arrT[1][1]*mati[i][1]+arrT[1][2]*mati[i][2]);
				mato[i][2]=(float)(arrT[2][0]*mati[i][0]+arrT[2][1]*mati[i][1]+arrT[2][2]*mati[i][2]);
			}
	}
void Translation(float tx ,float ty)
	{
		
		float arrT[3][3]={1,0,tx,0,1,ty,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void scaling(float sx , float sy)
	{
		float Sx=sx;
		float Sy=sy;
		float arrT[3][3]={Sx,0,0,0,Sy,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Rotation(float angle)
	{	
		float arrT[3][3]={cos(angle),-(sin(angle)),0,sin(angle),cos(angle),0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Reflection_X_axis()
	{
	float arrT[3][3]={1,0,0,0,-1,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Reflection_Y_axis()
	{
	float arrT[3][3]={-1,0,0,0,1,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Reflection_X_equal_Y_axis()
	{
	float arrT[3][3]={0,1,0,1,0,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Reflection_About_Origin()
	{
	float arrT[3][3]={-1,0,0,0,-1,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Reflection_X_equal_minus_Y_axis()
	{
	float arrT[3][3]={-1,0,0,0,-1,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void shearing_X_axis()
	{
	float shx;
	cout<<"Enter the value of shx  :";
   cin>>shx;
	float arrT[3][3]={1,shx,0,0,1,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void shearing_Y_axis()
	{
	float shy;
	cout<<"Enter the value of shy  :";
   cin>>shy;
	float arrT[3][3]={1,0,0,shy,1,0,0,0,1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Rotation_about_arbitory()
	{			float angle;
				cout<<"Enter the Rotaion angle : ";
				cin>>angle;
				angle=(angle*(3.142/180));
				cout<<"Enter the value of Xm :";
				cin>>Xm;
			 	cout<<"Enter the value of Ym :";
		        cin>>Ym;
	float arrT[3][3]={cos(angle),sin(angle),0,-sin(angle),cos(angle),0,(-Xm*cos(angle)+Ym*sin(angle)+Xm),(-Xm*sin(angle)-Ym*cos(angle)+Ym),1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void Scalling_about_Fixed()
	{			
				cout<<"Enter the value of Xm :";
				cin>>Xm;
			 	cout<<"Enter the value of Ym :";
		        cin>>Ym;
		        	cout<<"Enter the value of Sx  :";
					cin>>sx;
					cout<<"Enter the value of Sy :";
					cin>>sy;
	float arrT[3][3]={sx,0,0,0,sy,0,((Xm)*(1-sx)),((Ym)*(1-sy)),1};
		multMatrix(arrT);
		glColor3f(0.0f,0.0f,0.0f);
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<k;i++)
			{
			Plot(mato[i][0],mato[i][1]);
			}
		glColor3f(1.0f,0.0f,0.0f);
		glEnd();
		glFlush();	
	}
void MouseClick(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			mati[k][0] = (float)(x-350);
			mati[k][1] = (float)(350-y);
			mati[k][2] = (float)(1);
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_POINTS);
			glVertex2f(mati[k][0], mati[k][1]);
			glEnd();
			k++;
			glFlush();
		}
		
		if(button == GLUT_RIGHT_BUTTON)
		{
			glBegin(GL_LINE_LOOP);
			for(int i = 0; i<k; i++)
			{
				glVertex2f(mati[i][0], mati[i][1]);
			}
			glEnd();
			glFlush();
		}
	}		
}
void menu(int ch) {
glBegin(GL_POINTS);
myDisplay();
}
void translation_menu(int i){
	
	switch(i) {
	
		case 1:
					cout<<"Enter the value of tx :";
					cin>>tx;
					Translation(tx,ty);
                       
			break;
			
		case 2:
					cout<<"Enter the value of ty :";
					cin>>ty;
					Translation(tx,ty);
			
			break;
		
		case 3:cout<<"Enter the value of tx :";
				  cin>>tx;
			 	  cout<<"Enter the value of ty :";
		          cin>>ty;
			      Translation(tx,ty);
			break;
	}
}
void scaling_menu(int i){
	switch(i) {
		case 1:
			cout<<"Enter the value of Sx  :";
			cin>>sx;
			cout<<"Enter the value of Sy :";
			cin>>sy;
			scaling(sx,sy);
			break;
	}
}
void rotaion_menu(int i) {
	float angle;
	cout<<"Enter the Rotaion angle : ";
	cin>>angle;
	angle=(angle*(3.142/180));
	
	switch(i) {
		case 1:Rotation(-(angle));
		       break;
		case 2:Rotation(angle);
			break;
	}
} 
void Reflection_menu(int i){
   switch(i){
      case 1:Reflection_X_axis();
             break;
      case 2:Reflection_Y_axis();
	     break;
      case 3:Reflection_X_equal_Y_axis();
	     break;
      case 4:Reflection_About_Origin();
             break;
      case 5: Reflection_X_equal_minus_Y_axis();
             break;
   }
}
void shearing_menu(int i){
	switch(i) {
	
		case 1:
				shearing_X_axis();
			break;
				
		case 2:shearing_Y_axis();
			break;
	}
}
void rotaion_arbitory_menu(int i) {
	switch(i) {
		case 1:Rotation_about_arbitory();
		       break;
	}
} 
void scalling_arbitory_menu(int i) {
	switch(i) {
		case 1: Scalling_about_Fixed();
		       break;
	}
} 
int main(int argc, char **argv)
{			
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(700,700);
			glutInitWindowPosition(0,0);
			glutCreateWindow("Transformation");
			myInit();
			
			glutDisplayFunc(myDisplay);
			glutMouseFunc(MouseClick);
			
			int translation_id = glutCreateMenu(translation_menu);
			glutAddMenuEntry("1] Along x-axis ",1);
			glutAddMenuEntry("2] Along y-axis ",2);
			glutAddMenuEntry("3] Along xy-axis ",3);
			
			int scaling_id = glutCreateMenu(scaling_menu);
			glutAddMenuEntry("1] Along xy-axis ",1);
			
			int rotation_id = glutCreateMenu(rotaion_menu);
			glutAddMenuEntry("1] Clockwise",1);
			glutAddMenuEntry("2] Anticlockwise",2);
			
			int reflection_id=glutCreateMenu(Reflection_menu);
			glutAddMenuEntry("1] About X-axis ",1);
			glutAddMenuEntry("2] About Y-axis ",2);
			glutAddMenuEntry("3] About XY-axis ",3);
			glutAddMenuEntry("4] About Origin ",4);
			glutAddMenuEntry("5] About X=-Y Axis ",5);
			
			int shearing_id=glutCreateMenu(shearing_menu);
			glutAddMenuEntry("1] About X-axis ",1);
			glutAddMenuEntry("2] About Y-axis ",2);
			
			int rota_arbi_id=glutCreateMenu(rotaion_arbitory_menu);
			glutAddMenuEntry("Rotation about arbitory point ",1);
			
			int scalling_arbi_id=glutCreateMenu(scalling_arbitory_menu);
			glutAddMenuEntry("Scalling about arbitory point ",1);
			
			glutCreateMenu(menu);
		    glutAddSubMenu("1] Translation",translation_id);
		   glutAddSubMenu("2] Scaling",scaling_id);
		   glutAddSubMenu("3] Rotation",rotation_id);
		   glutAddSubMenu("4] Reflection",reflection_id);
		  glutAddSubMenu("5] Shearing",shearing_id);
		  glutAddSubMenu("6] Rotation about arbitory point ", rota_arbi_id);
		  glutAddSubMenu("7] Scalling about arbitory point ", scalling_arbi_id);
		  
		    glutAttachMenu(GLUT_MIDDLE_BUTTON);
			glutMainLoop();
	return 0;	
}	