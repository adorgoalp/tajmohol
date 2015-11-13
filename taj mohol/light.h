#ifndef __LIGHT_H_
#define __LIGHT_H_

#include<glut.h>

// Light mode can be either 'd' (day) or 'n' (night)
char lightMode = 'n';
// Diffuse light color can be either 'w' (white) or blue ('b')
char diffuseLightColor = 'w';
double diffuseLightAngle = 0;

double diffuseLightRadius = 2000;
double diffuseLightHeight = 1000;

void setLightMode(char mode) {
	GLfloat dayAmbient[] = { 0.45, 0.45, 0.40, 1.0 }; 
	GLfloat nightAmbient[] = { .15, .15, .20, 1.0 }; 

	if (lightMode == 'd') {
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, dayAmbient);
	}
	else {
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, nightAmbient);
	}
}

void toggleLightMode() {
	if (lightMode == 'd')
		lightMode = 'n';
	else
		lightMode = 'd';

	setLightMode(lightMode);
}

void displayLighting() {

	// configure diffuse light source
	GLfloat position[] = {diffuseLightRadius*cos(diffuseLightAngle), diffuseLightRadius*sin(diffuseLightAngle), diffuseLightHeight, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, position); 
	GLfloat light_emission[] = {.3, .3, .3, 1};
	glMaterialfv(GL_FRONT, GL_EMISSION, light_emission);

	// draw diffuse light source
	glPushMatrix();
	glTranslatef (diffuseLightRadius*cos(diffuseLightAngle), diffuseLightRadius*sin(diffuseLightAngle), diffuseLightHeight);
	glutSolidSphere(50, 36, 36);
	glPopMatrix();

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

	/*if (lightMode == 'd') {
		glClearColor(BLACK, 1.0);
	}
	else {
		glClearColor(BLACK, 0.0);
	}*/
}

void enableLighting()
{
	glShadeModel(GL_SMOOTH);
	setLightMode(lightMode); 
	
	GLfloat diffusePoint[] = {0.5, 0.5, 0.5, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusePoint); 

	glEnable (GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
}

#endif