#include<glut.h>
#include<stdio.h>
#include"color.h"
#include<math.h>
#define FINE 30
#define XY 0
#define YZ 1
#define ZX 2
#define SOLID 100
#define WIRE 200
#define OPEN 300
typedef struct sPoint
{
	GLdouble x;
	GLdouble y;
	GLdouble z;
}Point;
typedef struct cPoint
{
	float x;
	float y;
	float z;
}Color;
Point getPoint(GLdouble x, GLdouble y , GLdouble z)
{
	Point p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}
Color getColor(int x, int y , int z)
{
	Color p;
	p.x = x;
	p.y = y;
	p.z = z;
	return p;
}
void drawCircle(Point center, GLdouble radius, int r,int g, int b, int plane,GLdouble lineWidth)
{	
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		if(plane == XY)
		{
		}else if(plane == YZ)
		{
			glRotatef(90.0,1,0,0);
		}else if(plane == ZX)
		{
			glRotatef(90.0,0,1.0,0);
		}
		glTranslatef(0,0,center.z);
		
		glLineWidth(lineWidth);
		glBegin(GL_LINE_LOOP);
		for(int i = 0; i < 50; i++)
		{
			GLdouble theta = 2.0f * 3.1415926f * GLdouble(i) / GLdouble(50);//get the current angle

			GLdouble x = radius * cosf(theta);//calculate the x component
			GLdouble y = radius * sinf(theta);//calculate the y component
		
			glVertex2f(x + center.x, y + center.y);//output vertex

		}
		glEnd();
		glLineWidth(1.f);//reset
	}glPopMatrix();
}

void drawFilledCircle(Point center, GLdouble radius, int r,int g, int b, int plane)
{	
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		if(plane == XY)
		{
		}else if(plane == YZ)
		{
			glRotatef(90.0,1,0,0);
		}else if(plane == ZX)
		{
			glRotatef(90.0,0,1.0,0);
		}
		glBegin(GL_TRIANGLE_FAN);
		glVertex3f(center.x,center.y,center.z);
		for(int i = 0; i <= 30; i++)
		{
			GLdouble theta = 2.0f * 3.1415926f * GLdouble(i) / GLdouble(30);//get the current angle
			GLdouble x = radius * cosf(theta);//calculate the x component
			GLdouble y = radius * sinf(theta);//calculate the y component
			glVertex3f(x + center.x, y + center.y,center.z);//output vertex

		}
		glEnd();
	}glPopMatrix();
}
void drawCylinder(Point baseCenter, GLdouble radiusBase,GLdouble radiusTop,GLdouble height, int r,int g, int b, int type)
{
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		if(type == SOLID)
		{
			drawFilledCircle(baseCenter,radiusBase,r,g,b,XY);
			Point topCenter = getPoint(baseCenter.x,baseCenter.y,baseCenter.z+height);
			drawFilledCircle(topCenter,radiusBase,r,g,b,XY);
			glTranslatef(baseCenter.x,baseCenter.y,baseCenter.z);
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			gluCylinder(quadratic,radiusBase,radiusTop,height,30,30);
		}else if(type == WIRE)
		{
			int diff = height /10;
			GLdouble radDiff = (radiusTop*1.0 - radiusBase*1.0)/10.0;
			for(int i = 0; i < 10;i++)
			{
				int t = (baseCenter.z+i*diff);
				Point p = getPoint(baseCenter.x,baseCenter.y,t);
				drawCircle(p,radiusBase+i*radDiff,r,g,b,XY,1.0);
			}
		}else if(type == OPEN)
		{
			glTranslatef(baseCenter.x,baseCenter.y,baseCenter.z);
			GLUquadricObj *quadratic;
			quadratic = gluNewQuadric();
			gluCylinder(quadratic,radiusBase,radiusTop,height,30,30);
		}
		
		
	}glPopMatrix();
}
void drawOctaCylinder(Point baseCenter, GLdouble radiusBase,GLdouble radiusTop,GLdouble height, int r,int g, int b)
{
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		glTranslatef(baseCenter.x,baseCenter.y,baseCenter.z);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
		gluCylinder(quadratic,radiusBase,radiusTop,height,8,1);	
	}glPopMatrix();
}
void drawGrid(int spacing, int totalSize,int canDrawGrid)
{
	//some gridlines along the field
	int i;
	int muberOfLinesOnEachSide = totalSize/spacing;
	//WILL draw grid IF the "canDrawGrid" is true:

	if(canDrawGrid){
		glColor3ub(75,75,75);	//grey
		glBegin(GL_LINES);{
			for(i=-muberOfLinesOnEachSide;i<=muberOfLinesOnEachSide;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*spacing, -totalSize, 0);
				glVertex3f(i*spacing,  totalSize, 0);

				//lines parallel to X-axis
				glVertex3f(-totalSize, i*spacing, 0);
				glVertex3f( totalSize, i*spacing, 0);
			}
		}glEnd();
	}

	// draw the two AXES
	//glColor3ub(1, 1, 1);	//100% white
	glColor3ub(WHITE);
	glBegin(GL_LINES);{
		//Y axis
		glVertex3f(0, -totalSize-50, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  totalSize+50, 0);

		//X axis
		glVertex3f(-totalSize-50, 0, 0);
		glVertex3f( totalSize+50, 0, 0);

		//Z axis
		glVertex3f(0,0,totalSize+50);
		glVertex3f(0,0,-totalSize-50);
	}glEnd();
}
void drawSphere(Point center,int radius,int r,int g, int b, int type)
{
	glPushMatrix();	{
		glColor3ub(r,g,b);
		glTranslatef(center.x,center.y,center.z);
		if(type == SOLID)
		{
			glutSolidSphere(radius,FINE,FINE);
		}else if(type == WIRE)
		{
			glutWireSphere(radius,FINE,FINE);
		}
	}glPopMatrix();
}
void drawRect(Point topLeft, int width, int height, int r,int g, int b, int plane)
{
	glPushMatrix();{	//STORE the state
		glColor3ub(r,g,b);
		glBegin(GL_QUADS);{
			if(plane == XY)
			{
				glVertex3f(topLeft.x,topLeft.y,topLeft.z);
				glVertex3f(topLeft.x,topLeft.y+width,topLeft.z);
				glVertex3f(topLeft.x+height,topLeft.y+width,topLeft.z);
				glVertex3f(topLeft.x+height,topLeft.y,topLeft.z);
			}else if(plane == YZ)
			{

			}else if(plane == ZX)
			{
				//glRotated(90,1,0,0);
			}
			
		}glEnd();
	}glPopMatrix();		//the effect of rotation is not there now.
}
void drawCube(Point bottomLeftFront,GLdouble length,GLdouble width, GLdouble height, int r,int g, int b ,int type)
{
	GLdouble tx = bottomLeftFront.x + length/2;
	GLdouble ty = bottomLeftFront.y + width/2;
	GLdouble tz = bottomLeftFront.z + height/2;
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		glTranslatef(tx,ty,tz);
		glScalef(length,width,height);
		glutSolidCube(1);
	}glPopMatrix();
}
void drawCube( GLdouble length,GLdouble width, GLdouble height)
{
	glPushMatrix();
	{
		glScalef(length,width,height);
		glutSolidCube(1);
	}glPopMatrix();
}


void drawCone(Point baseCenter, GLdouble baseRadius,GLdouble height,int r,int g, int b,int type)
{
	glPushMatrix();{
		glColor3ub(r,g,b);
		glTranslatef(baseCenter.x,baseCenter.y,baseCenter.z);
		if(type == WIRE)
		{
			glutWireCone(baseRadius,height,30,30);
		}else if(type == SOLID)
		{
			glutSolidCone(baseRadius,height,30,30);
		}else if(type == OPEN)
		{
		
		}
	}glPopMatrix();
}

void drawLifeBoya(Point center,GLdouble radius,GLdouble thikness,int r,int g, int b, int plane,int type)
{
	int mult = radius/20;
	if(mult == 0)
	{
		mult = 1;
	}
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		glTranslatef(center.x,center.y,center.z);
		if(plane == XY)
		{
		}else if(plane == YZ)
		{
			glRotatef(90.0,1,0,0);
		}else if(plane == ZX)
		{
			glRotatef(90.0,0,1.0,0);
		}
		if(type == SOLID)
		{
			glutSolidTorus(thikness,radius,FINE*mult,FINE*mult);
		}
		else if (type == WIRE)
		{
			glutWireTorus(thikness,radius,FINE*mult,FINE*mult);
		}
	}glPopMatrix();
}
void drawOctaLifeBoya(Point center,GLdouble radius,GLdouble thikness,int r,int g, int b)
{
	int mult = radius/20;
	if(mult == 0)
	{
		mult = 1;
	}
	glPushMatrix();
	{
		glColor3ub(r,g,b);
		glTranslatef(center.x,center.y,center.z);
		glutSolidTorus(thikness,radius,8,8);
	}glPopMatrix();
}
void clearDisplay()
{
	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClearColor(BLACK, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}