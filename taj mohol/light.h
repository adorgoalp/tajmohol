#include<glut.h>
void enableLighting()
{
	glEnable ( GL_LIGHTING ) ;
	glShadeModel(GL_SMOOTH);
	//glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
}