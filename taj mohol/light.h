#ifndef __LIGHT_H_
#define __LIGHT_H_

#include<glut.h>

// Light mode can be either 'd' (day) or 'n' (night)
char lightMode = 'd';

void setLightMode(char mode) {
	GLfloat dayAmbient[] = { 0.55, 0.55, 0.5, 1.0 }; 
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
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);

	if (lightMode == 'd') {
		glClearColor(LIGHT_WHITE, 1.0);
	}
	else {
		glClearColor(BLACK, 0.0);
	}
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