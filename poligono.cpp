/**
Nombre: David Rolando Neyra Gutierrez
Comando: g++ poligono.cpp -w -lGL -lGLU -lglut -o poligono
Puede precionar las teclas F3,F4,F5,F6,F7,F8,F9,F10,F11 y F12
**/

//#include "stdafx.h" con window
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846
using namespace std;

GLfloat xi = 0.0;
GLfloat yi = 0.0;
GLint numLados=9;
GLint escala = 1;
GLdouble puntosx[13];
GLdouble puntosy[13];
GLdouble angulo = 0;

void init(void){
	glClearColor(0.0, 0.0, 1.0, 0.0);
}


void ArrowKey(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		if (xi < 10)
			xi += 0.5;
		break;

	case GLUT_KEY_LEFT:
		if (xi > -10)
			xi -= 0.5;
		break;

	case GLUT_KEY_UP:
		if (yi < 10)
			yi += 0.5;
		break;

	case GLUT_KEY_DOWN:
		if (yi > -10)
			yi -= 0.5;
		break;
	case GLUT_KEY_F3:
		numLados = 3;
		//triangulo
		break;

	case GLUT_KEY_F4:
		numLados = 4;
		//cuadrado
		break;
	case GLUT_KEY_F5:
		numLados = 5;
		//pentagono
		break;
	case GLUT_KEY_F6:
		numLados = 6;
		//hexagono
		break;

	case GLUT_KEY_F7:
		numLados = 7;
		//heptagono
		break;
	case GLUT_KEY_F8:
		numLados = 8;
		//octagono
		break;

	case GLUT_KEY_F9:
		numLados = 9;
		//
		break;

	case GLUT_KEY_F10:
		numLados = 10;
		//
		break;
	case GLUT_KEY_F11:
		numLados = 11;
		//
		break;
	case GLUT_KEY_F12:
		numLados = 12;
		//
		break;
	
	case GLUT_KEY_HOME:
		if (escala > 5)
			escala = 5;
		cout << "Aumentando Escala" << endl;
		escala = escala + 1;
		break;
	case GLUT_KEY_PAGE_UP:
		if (escala <=1)
			escala = 1;
		cout << "Reduciendo Escala" << endl;
		escala = escala - 1;
		break;

	case GLUT_KEY_PAGE_DOWN:
		cout << "Rotando positivamente" << endl;
		angulo +=5;
		break;

	case GLUT_KEY_END:
		cout << "Rotando negativamente" << endl;
		angulo -=5;
		break;

	default:
		break;
	}

}

void inline drawString (char *s)
{
 unsigned int i;
 for (i=0; i<strlen(s); i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, s[i]);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	static char label[100];
	char *nombre="Puede precionar las teclas F3,F4,F5,F6,F7,F8,F9,F10,F11 y F12 ";
	init();
	glColor3f(0.1, 1.0, 0.1);
 	sprintf(label,"%s", nombre);
 	glRasterPos2f(300, 200);
 	drawString (label);
	init();
	gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(xi, yi, 0);
	glScaled(escala, escala, 1.0);
	glRotated(angulo, 0.0, 0.0, 1.0);

	double grados = (360 / numLados);
	double aux = grados;

	for (int i = 0; i<numLados; i++)
	{
		GLdouble px = ((2 * (cos((M_PI*grados) / 180))) + xi);
		GLdouble py = ((2 * (sin((M_PI*grados) / 180))) + yi);

		puntosx[i] = px;
		puntosy[i] = py;

		grados = grados + aux;
	}
	
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.5,0.0);
	for (int i = 0; i<numLados; i++)
	{
		glVertex2d(puntosx[i], puntosy[i]);
        }
	glEnd();
	glPopMatrix(); 
	glFlush();
	glutSwapBuffers();
}
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.00, 10.0, 0.1, 20.0); 
	glMatrixMode(GL_MODELVIEW); 

}
void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}





int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Poligonos Regular");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(ArrowKey);
	glutMainLoop();



	return 0;
}
