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
	GLfloat dayAmbient[] = { 0.60, 0.60, 0.55, 1.0 }; 
	GLfloat nightAmbient[] = { .25, .25, .50, 1.0 }; 

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
	GLfloat position[] = {diffuseLightRadius*cos(diffuseLightAngle), diffuseLightRadius*sin(diffuseLightAngle), diffuseLightHeight, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, position); 
	GLfloat light_emission_white[] = {.2, .2, .2, 1};
	GLfloat light_emission_blue[] = {.0, .0, .2, 1};
	GLfloat unset[]={0,0,0,1};
	glMaterialfv(GL_FRONT, GL_EMISSION, (diffuseLightColor == 'w' ? light_emission_white : light_emission_blue));

	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

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

	glEnable (GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
}

#endif