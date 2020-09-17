#include<stdio.h> 
#include<GL/glut.h>
#include<math.h>
#include<vector>
#include<windows.h>
#include<mmsystem.h>
#include <bits/stdc++.h>
#include"triee.h"

using namespace std;

GLfloat yrot;

void reshape(int width, int height)
{
     glViewport(0,0,width,height);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-1,1,-1,1,-1,1);
     glMatrixMode(GL_MODELVIEW);
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
     glLoadIdentity();
     glRotatef(yrot,0,1,0);
     //Brazo derecho
     glBegin(GL_LINES);
      glColor3f(1,0.6,0.6);
      glVertex3f(0.2,0.1,0);
      glVertex3f(0.5,0.5,0);
     glEnd();
     //Brazo izquierdo
     glBegin(GL_LINES);
      glColor3f(1,0.6,0.6);
      glVertex3f(-0.2,0.1,0);
      glVertex3f(-0.5,0.5,0);
     glEnd();
     //Piernas
     glBegin(GL_TRIANGLES);
      glColor3f(1,0.6,0.6);
      glVertex3f(-0.3,-0.5,0);
      glVertex3f(-0,-0.9,0);
      glVertex3f(0.3,-0.5,0);
     glEnd();
     //Cuerpo
     glBegin(GL_TRIANGLES);
      glColor3f(0,1,0); glVertex3f(-0.5,-0.5,0);
      glColor3f(0,1,0); glVertex3f(0.5,-0.5,0);
      glColor3f(0,0,0); glVertex3f(0,0.5,0);
    glEnd();
    glTranslatef(0.0,0.6,0.0);
    glColor3f(1,0.6,0.6);
    //Cabeza
    glBegin(GL_POLYGON);
   	glVertex3f(0.2,0.1,0.0);
      glVertex3f(0.1,0.2,0.0);
      glVertex3f(-0.1,0.2,0.0);
      glVertex3f(-0.2,0.1,0.0);
      glVertex3f(-0.2,-0.1,0.0);
      glVertex3f(-0.1,-0.2,0.0);
      glVertex3f(0.1,-0.2,0.0);
      glVertex3f(0.2,-0.1,0.0);
    glEnd();
    
    yrot += 0.05;
    
    glutSwapBuffers();
}

void init()
{
	glClearColor(0,0,0,0);
}

int main(int argc, char **argv)
{

cout<<"enter playlist name" <<endl;
string s=	main1();

 cout<<s;
//	main1(argc,argv);
string my_str = s;
   LPTSTR strr = new TCHAR[my_str.size() + 1]; 
   
   strcpy(strr, my_str.c_str());
  
PlaySound(strr,NULL,SND_ASYNC); // use snd_async instead pf sync so that music will be played in background not step wise first music than animation

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
    glutCreateWindow("Music");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
