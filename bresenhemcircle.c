#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float h,k,r;
void Init() 
{
	
	glClearColor(1.0,1.0,1.0,0);
 	glColor3f(0.0,0.0,0.0);
  	gluOrtho2D(0 , 640 , 0 , 480);
}

void draw_pixel(int x,int y) 
{
	glBegin(GL_POINTS);
	glVertex2i(h+x, k+y);
  	glVertex2i(h+x, k-y);
  	glVertex2i(h+y, k+x);
  	glVertex2i(h+y, k-x);
  	glVertex2i(h-x, k-y);
  	glVertex2i(h-y, k-x);
  	glVertex2i(h-x, k+y);
  	glVertex2i(h-y, k+x);
	glEnd();
}

void bresenhem()
{
	int x=0,y=r;
	float decision_parameter = (5.0/4.0)-r;
	draw_pixel(x,y);
	while(y > x)
	{
		x++;
		if (decision_parameter > 0) 
        { 
            y--;  
            decision_parameter = decision_parameter + 2 * (x - y) + 1; 
        } 
        else
            decision_parameter = decision_parameter + 2 * x + 1; 
        draw_pixel( x, y); 
         
	}
	glFlush();

}

void createcircle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
  	bresenhem();
}


void main(int argc, char **argv) 
{
	
	printf("Input the center :\n");
	scanf("%f %f",&h,&k);
	printf("Input the radius of circle: \n");
	scanf("%f",&r);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(680, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Circle using Bresenhem's Algorithm!");
	glutDisplayFunc(createcircle);
	Init();
	glutMainLoop();
	
}