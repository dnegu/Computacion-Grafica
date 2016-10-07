/**
Nombre: David Rolando Neyra Gutierrez
Comando: g++ hyperbola.cpp -w -lGL -lGLU -lglut -o hyperbola
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int wide=300, high=300;   
int winX=40, winY=40;	  


void DrawMyStuff()  
{ 
    double x,y;
    glColor3f(1.0, 1.0, 0.0);		
    glBegin( GL_POINTS );		
        for (x = -1; x <= 1; x += .001) 
          { y =  4* x -  4* x * x ;     
            glVertex3f(x, y, 0.0);      
          }
   glEnd();				
} 

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT);
   DrawMyStuff();			
   glFlush(); 
}

void myinit(void)
{ 
   glClearColor(0.5, 0.5, 0.5, 0.0);    

   glMatrixMode(GL_PROJECTION);			
   glLoadIdentity();				
   glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);   	
}

int main(int argc, char* argv[])
{  
   glutInit(&argc, argv);   
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	
   glutInitWindowSize(wide, high);  	
   glutInitWindowPosition(winX,winY); 	
   glutCreateWindow("Hyperbola");	
   myinit();				

   glutDisplayFunc(display);		 
   glutMainLoop();			
   return 0;
}










