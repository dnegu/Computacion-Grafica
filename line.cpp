#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
float dx,dy,p0,p1;
float slope,tdy,dev,tdx;
float x2,y,x,y2;
int count=0;


void myInit(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glColor3f(1.0f,1.0f,1.0f);
 
 glLoadIdentity();
 //gluOrtho2D(0.0,640.0,0.0,480.0);
 glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void myline()
{
 glClear(GL_COLOR_BUFFER_BIT);
 slope= dy/dx;
 if(dy<=dx)
 {
 while(count<=dx)
  {
  if(p0<0)
   {
   p0= p0+tdy;
   
   }
  else{ 
   
   p0=p0+dev;
   y=y+1;
  }
 count++; 
 x=x+1;
 glBegin(GL_POINTS);
 glVertex2f(x/100,y/100);
 glEnd();
 glFlush();

 }
 }
 return ;
}

main(int argc,char *argv[])
{
 float swap;
 printf("Ingresa la primera coordenada x1 y y1:\n");
 scanf("%f %f",&x,&y);
 printf("Ingrese la segunda coordenada x2 y y2:\n");
 scanf("%f %f",&x2,&y2);
 if(x2<x)
  {
  swap=x;
  x=x2;
  x2=swap;
  }
 if(y2<y)
  {
  swap=y;
  y=y2;
  y2=swap;
  }
 dx=x2-x;
 dy=y2-y;
 tdy=2*dy;
 tdx=2*dx;
 dev=tdy-tdx;
 
 p0=tdy-dx;
 
 
 
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE);
 glutInitWindowSize(300,300);
 glutInitWindowPosition(100,100);
 glutCreateWindow("draw line");
 glutDisplayFunc(myline);
 myInit();
 glutMainLoop();
 return 0;
} 
