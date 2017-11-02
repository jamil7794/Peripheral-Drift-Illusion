//
//  main.cpp
//  project2
//
//  Created by Jamil Jalal on 10/12/17.
//  Copyright © 2017 Jamil Jalal. All rights reserved.
//



#include <iostream>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <math.h>

GLfloat rectangle[4][3] = {{10,6,0},{-10,6,0},{-10,-6,0},{10,-6,0}};
GLfloat quad1p[4][3]={{-12,0,0},{-12,-8,0},{12,-8,0},{12,0,0}};
GLfloat quad2p[4][3]={{-12,0,0},{-12,8,0},{12,8,0},{12,0,0}};

int radius = 60;
int widthOfWindow=800;
int heightOfWindow=400;

void bluebox(void){
   glBegin(GL_POLYGON);
        for(int i=0;i<4;i++){
            glColor3f(0, 0, 1);
            glVertex3fv(rectangle[i]);
        }
    glEnd();
}

void quad1(int t){
    glBegin(GL_POLYGON);
    for(int i=0;i<4;i++){
        glColor3f(0, 0, 0);
        if(t%2==0){
            glVertex3fv(quad1p[i]);
        }else{
            glVertex3fv(quad2p[i]);
        }
    }
    glEnd();
}

void quad2(int t){
    glBegin(GL_POLYGON);
    for(int i=0;i<4;i++){
        glColor3f(1, 1, 1);
        if(t%2==0){
            glVertex3fv(quad2p[i]);
        }else{
            glVertex3fv(quad1p[i]);
        }
        
    }
    glEnd();
}

void drawRing(GLint t){
    
    for(int r=0;r<360;r+=45){
        glPushMatrix();
        glRotated(r, 0, 0, 1);
        glTranslated(radius,0, 0);
        glScaled(1.5, 1.5, 0);
        quad2(t);
        quad1(t);
        bluebox();
        glPopMatrix();
    }
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    int w = widthOfWindow/4;
    int h= heightOfWindow/2;
    int x=-(widthOfWindow/2)+(w/2);
    int y=h/2;
    for(int i=0;i<4;i++){
        glPushMatrix();
        glTranslated(x, y, 0);
        x+=widthOfWindow/4;
        drawRing(i);
        glPopMatrix();
    }
    x=-(widthOfWindow/2)+(w/2);
    
    for(int i=0;i<4;i++){
        glPushMatrix();
        glTranslated(x, -y, 0);
        x+=widthOfWindow/4;
        drawRing(i+1);
        glPopMatrix();
    }
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
   
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(widthOfWindow, heightOfWindow);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("project2");
    glClearColor(0.80, 0.80, 0.0, 0.0);
    //glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-400.0, 400.0, -200.0, 200,0,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
