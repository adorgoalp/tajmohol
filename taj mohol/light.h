#ifndef __LIGHT_H_
#define __LIGHT_H_

#include<glut.h>

// Light mode can be either 'd' (day) or 'n' (night)
char lightMode = 'n';
// Diffuse light color can be either 'w' (white) or blue ('b')
char diffuseLightColor = 'w';
double diffuseLightAngle = 0;
double diffuseLightAngleDelta = 0.1;

double diffuseLightRadius = 2000;
double diffuseLightHeight = 1000;

void setLightMode(char mode) {
	GLfloat dayAmbient[] = { 0.60, 0.60, 0.55, 0.0 }; 
	GLfloat nightAmbient[] = { .25, .25, .50, 0.0 }; 

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

void toggleDiffuseLightColor() {
	diffuseLightColor = (diffuseLightColor == 'w' ? 'b' : 'w');
}

void displayLighting() {
	// configure diffuse light source
	GLfloat diffusePosition[] = {diffuseLightRadius*cos(diffuseLightAngle), diffuseLightRadius*sin(diffuseLightAngle), 
		diffuseLightHeight, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, diffusePosition); 
	GLfloat lightEmission[] = {0.3, 0.3, 0.3, 1};
	glMaterialfv(GL_FRONT, GL_EMISSION, lightEmission);

	GLfloat spotLightPosition[] = {0, 1000, 000};
	GLfloat cutOffAngle[] = {60.0};
	glLightfv(GL_LIGHT1, GL_POSITION, spotLightPosition); 
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, cutOffAngle);
	GLfloat spotDirection[] = {0, 1, -1};
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotDirection);

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse_white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse_blue[] = { 0.6, 0.6, 1.0, 1.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseLightColor == 'w' ? mat_diffuse_white : mat_diffuse_blue);

	// draw diffuse light source
	glPushMatrix();
	glColor3ub(diffuseLightColor == 'w' ? WHITE : BLUE);
	glTranslatef (diffuseLightRadius*cos(diffuseLightAngle), diffuseLightRadius*sin(diffuseLightAngle), diffuseLightHeight);
	glutSolidSphere(50, 36, 36);
	glPopMatrix();

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
	GLfloat spotLightPoint[] = {0.8, 0.8, 0.5, 1.0}; 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, spotLightPoint);

	glEnable (GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
}

#endif