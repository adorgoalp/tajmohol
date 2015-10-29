#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "drawing.h"
#include<glut.h>
#include "camera.h"
#include "listener.h"
#include"light.h"
#define GRID_SIZE 100
void display(){
	clearDisplay();
	setupCamera();
	//code here
	//drawWalls();
	//drawRoof();
	//drawBase();
	drawSmallDome();
	drawGrid(GRID_SIZE,CAMERA_DISTANCE,canDrawGrid);
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera
	glutPostRedisplay();	//this will call the display AGAIN
}




void init(){
	//codes for initialization
	initializeCamera();
	canDrawGrid = true;
	//clear the screen
	glClearColor(BLACK, 0);
	//lighting
	enableLighting();
	
	//initialize the matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
	loadCameraData();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(900	, 900);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Taj mahal 1005003 1005027");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}

