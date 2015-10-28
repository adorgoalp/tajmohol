#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<glut.h>
#include "values.h"
#define CAMERA_DISTANCE 1000
#define MOVE_STEP_SIZE 10
double cameraAngle;			
double cameraAngleV;		
double cameraRadius;
double cameraX;
double cameraY; 
double cameraZ;
double screw;
void initializeCamera()
{
	cameraAngle = FOURTY_FIVE_DEGREE;
	cameraAngleV = -FOURTY_FIVE_DEGREE;
	cameraRadius = CAMERA_DISTANCE;
	cameraX = -CAMERA_DISTANCE;
	cameraY = -CAMERA_DISTANCE;
	cameraZ = CAMERA_DISTANCE;
	screw = 0;
}
void setupCamera()
{
/********************	
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking? cameras position in 3d space
	//3. Which direction is the camera's UP direction? on z axis and regular

	//instead of CONSTANT information, we will define a circular path.
	//gluLookAt(-50,-50,100,	0,0,0,	0,0,1);

	gluLookAt(cameraX,cameraY, cameraZ,		
		cameraRadius*cos(cameraAngle)+cameraX, cameraRadius*sin(cameraAngle)+cameraY,cameraZ+cameraRadius*tan(cameraAngleV),	
		screw,0,1);
	//NOTE: the camera still CONSTANTLY looks at the center
	// cameraAngle is in RADIAN, since you are using inside COS and SIN
	
	
	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);
}
void moveForword()
{
	cameraX += MOVE_STEP_SIZE*cosf(cameraAngle);
	cameraY += MOVE_STEP_SIZE*sinf(cameraAngle);
}
void moveBackword()
{
	cameraX -= MOVE_STEP_SIZE*cosf(cameraAngle);
	cameraY -= MOVE_STEP_SIZE*sinf(cameraAngle);
}
void moveLeft()
{
	cameraX += MOVE_STEP_SIZE*cosf(cameraAngle+NINETEY_DEGREE);
	cameraY += MOVE_STEP_SIZE*sinf(cameraAngle+NINETEY_DEGREE);
}
void moveRight()
{
	cameraX -= MOVE_STEP_SIZE*cosf(cameraAngle+NINETEY_DEGREE);
	cameraY -= MOVE_STEP_SIZE*sinf(cameraAngle+NINETEY_DEGREE);
}
void moveUp()
{
	cameraZ+= MOVE_STEP_SIZE*cosf(cameraAngleV);
}
void moveDown()
{
	cameraZ-= MOVE_STEP_SIZE*cosf(cameraAngleV);
}
void lookLeft()
{
	cameraAngle += TWO_DEGREE;
}
void lookRight()
{
	cameraAngle -= TWO_DEGREE;
}
void lookUp()
{
	cameraAngleV += TWO_DEGREE;
}
void lookDown()
{
	cameraAngleV -= TWO_DEGREE;
}
void lookScrewLeft()
{
	screw+=TWO_DEGREE;
}
void lookScrewRight()
{
	screw-=TWO_DEGREE;
}
void resetCamera()
{
	initializeCamera();
}
void saveCameraData()
{
	FILE * fp;
	fp = fopen("cameraData.dat","w");
	if(fp == NULL)
	{
		printf("Error opening file");
	}else
	{
		fprintf(fp, "%lf %lf %lf %lf %lf %lf",cameraX,cameraY,cameraZ,cameraRadius,cameraAngle,cameraAngleV);
		fclose(fp);
	}
}
void loadCameraData()
{
	FILE * fp;
	fp = fopen("cameraData.dat","r");
	if(fp == NULL)
	{
		printf("Error opening file");
	}else
	{
		fscanf(fp, "%lf %lf %lf %lf %lf %lf",&cameraX,&cameraY,&cameraZ,&cameraRadius,&cameraAngle,&cameraAngleV);
		fclose(fp);
	}
}