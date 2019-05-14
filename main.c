#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include <unistd.h>
#include "wall.h"
#include "spfunc.h"
#include "randoms.h"
int x,y;
int i,count;
char t[2];
float px=0.0,py=175.0;
int wall_count = 0;
int flag, df=10;
int diff = 0;
clock_t start,end;
void point()
{

	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2f(px, py);
	//printf("X: %f Y: %f\n", px, py);
	glEnd();
}
void point1()
{

 glColor3f(.0,1.0,0.0);
 glBegin(GL_POINTS);
 glVertex2f(0.0,175.0);
 glEnd();
}
void point2()
{

	glColor3f(1.0, 0.0, .0);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 165.0);
	glEnd();
}

void output(int x, int y, char *string)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void drawstring(int x, int y, char *string,void *font)
{
	int len, i;

	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}

 void frontscreen(void)
{

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1,1,1);
    drawstring(120,5," Press ENTER to go To next screen",GLUT_BITMAP_HELVETICA_18);
	drawstring(-45,5,"Maximize window for better view",GLUT_BITMAP_HELVETICA_12);
    glColor3f(1,1,1);
	output(5,160," PESIT - Bangalore South Campus");
	glColor3f(1,1,1);
	output(10.0,150,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glColor3f(1,1,1);
	output(60,130,"A Mini Project On:-");
	glColor3f(0,1,0.5);
	output(38,120,"\"DYNAMIC MAZE USING OPENGL\"");
	glColor3f(1,1,1);
	output(40,100,"By :");
	glBegin(GL_LINES);
	glVertex2f(40,98);
	glVertex2f(50,98);
	glEnd();
	glColor3f(1,1,1);
	output(40,90,"Anant Moudgalya and Aiyappa M A");

	glFlush();

}

void winscreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0, 1.0, 0.0);
	output(55, 120, "CONGRATULATIONS!");
	glColor3f(1.0, 0.0, 1.0);
	output(15, 100, "YOU HAVE SUCCEEDED IN SOLVING THE MAZE!");
	if(diff == 0){
		output(15, 80, "DIFFICULTY : EASY");
	}
	else if(diff == 1){
		output(15, 80, "DIFFICULTY : MEDIUM");
	}
	if(diff == 2){
		output(15, 80, "DIFFICULTY : HARD");
	}
	output(35, 60, "* PRESS ESC TO GO TO MAIN MENU");
	output(35, 45, "* PRESS 1 TO RESTART THE GAME");
	glFlush();
}
void startscreen()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	output(25, 140, "WELCOME TO DYNAMIC MAZE GAME!");
	output(50, 100, "1.NEW GAME");
	output(50, 80, "2.INSTRUCTIONS");
	output(50, 60, "3.QUIT");
	glFlush();
}

void instructions()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	output(45, 140, "INSTRUCTIONS:");
	glBegin(GL_LINES);
	glVertex2f(45, 138);
	glVertex2f(90, 138);
	glEnd();
	glColor3f(0, 1, 0);
	output(-20, 120, "* TO MOVE THE POINT USE ARROW KEYS");
	output(-20, 100, "* FIND THE WAY TO MOVE INTO THE MAZE AND GET OUT");
	output(-20, 80, "* GREEN COLOURED POINT INDICATE THE POINT FROM WHERE YOU HAVE TO START");
	output(-20, 60, "* RED COLOURED POINT INDICATE THE POINT WHERE YOU HAVE TO REACH");
	output(-20, 40, "* YOU WILL HAVE TO HURRY AS YOU HAVE LIMITED TIME");
	output(-20, 20, "* PRESS ESC TO GO TO MAIN MENU");
	glFlush();
}

void timeover()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 0);
	output(70, 110, "TIMEOVER");
	glColor3f(0, 1, 0);
	output(50, 100, "YOU HAVEE FAILED!");
	output(50, 90, "BETTER LUCK NEXT TIME");
	output(40, 40, "* PRESS ESC TO GO TO MAIN MENU");
	output(40, 30, "* PRESS 1 TO RESTART THE GAME");
	glFlush();
}

void idle()
{
	if (df == 1)
	{
		end = clock();
		count = (end - start) / CLOCKS_PER_SEC;
		if (count == 60)
		{
			df = 4;
		}
		else if ((count < 60) && ((px >= 0 && px <= 4) && (py >= 162 && py <= 168)))
		{
			df = 5;
		}
	}

	glutPostRedisplay();
}


void SpecialKey(int key, int x, int y)
{
	if(diff == 0){
		specFunc0(key);
	}
	if(diff == 1){
		specFunc1(key);
	}	
	if(diff == 2){
		specFunc2(key);
	}
}

void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	if (df == 10)
		frontscreen();

	else if (df == 0)
		startscreen();
	else if (df == 1)
	{
		output(-21, 172, "---->");
		output(-21, 163, "<----");
		glColor3f(0.0, 0.0, 1.0);
		output(185, 160, "TIME REMAINING : ");
		drawstring(190, 130, "HURRY UP", GLUT_BITMAP_HELVETICA_18);
		glColor3f(1, 0, 0);
		drawstring(190, 140, "Time is running out", GLUT_BITMAP_HELVETICA_18);
		sprintf(t, "%d", 60 - count);
		output(240, 160, t);
		glutPostRedisplay();
		point();
		point1();
		point2();
		//line();
		if(diff == 0){
			drawstring(190, 110, "DIFFICULTY : EASY", GLUT_BITMAP_HELVETICA_18);
		}
		else if(diff == 1){
			drawstring(190, 110, "DIFFICULTY : MEDIUM", GLUT_BITMAP_HELVETICA_18);
		}
		if(diff == 2){
			drawstring(190, 110, "DIFFICULTY : HARD", GLUT_BITMAP_HELVETICA_18);
		}
		//DISPLAY MAZE
		draw_wall(diff);
		glutPostRedisplay();
	}

	else if (df == 2)
		instructions();
	else if (df == 3)
	{
		exit(1);
	}
	else if (df == 4)
	{
		timeover();
	}
	else if (df == 5)
	{
		winscreen();
	}

	glFlush();
}
void keyboard(unsigned char key,int x,int y)
{

	if (df == 10 && key == 13)
		df = 0;

	else if ((df == 0 || df == 4 || df == 5) && key == '1')
	{
		//RANDOM LEVEL OF DIFFICULTY
		diff = randoms();
		df = 1;
		start = clock();
		glutPostRedisplay();
	}
	else if (df == 0 && key == '2')
		df = 2;
	else if (df == 0 && key == '3')
		df = 3;
	else if (key == 27)
	{
		df = 0;
	}
	if ((key == '0' || key == '1') && (df == 4 || df == 1))
	{
		px = 0.0;
		py = 175.0;
	}
	glutPostRedisplay();
}
void myinit()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glPointSize(18.0);

  glMatrixMode(GL_MODELVIEW);
  glClearColor(0.0,0.0,0.0,0.0);

}

void myreshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(45.0, 135.0, -2.0 * (GLfloat)h / (GLfloat)w, 180.0 * (GLfloat)h / (GLfloat)w);
	else
		gluOrtho2D(-45.0 * (GLfloat)w / (GLfloat)h, 135.0 * (GLfloat)w / (GLfloat)h, -2.0, 180.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Dynamic Maze Game");
	glutReshapeFunc(myreshape);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(keyboard);
	myinit();
	glutMainLoop();
	return 0;
}