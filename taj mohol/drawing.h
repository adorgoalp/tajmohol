#include "color.h"
#include "ifta.h"
#include "texture.h"

void railingBigPiller();
void drawDownFacePrism(Point p, GLdouble length, GLdouble width, GLdouble down, unsigned short rb, unsigned short gb, unsigned short bb, unsigned short rf, unsigned short gf, unsigned short bf)
{
	Point t;
	GLdouble side = down*2;
	drawCube(p,length,down,side,rb,gb,bb,SOLID);
	t = getPoint(p.x,p.y,p.z+width-side);
	drawCube(t,length,down,side,rb,gb,bb,SOLID);
	t = getPoint(p.x,p.y,p.z+side);
	drawCube(t,side,down,width-side*2,rb,gb,bb,SOLID);
	t = getPoint(p.x+length-side,p.y,p.z+side);
	drawCube(t,side,down,width-side*2,rb,gb,bb,SOLID);
	t = getPoint(p.x+side,p.y+down,p.z+side);
	drawCube(t,length-side*2,5,width-side*2,rf,gf,bf,SOLID);
}
void drawArc()
{
	Point p;
	GLdouble h;
	double c1[] = {1,0,0,0};
	glClipPlane(GL_CLIP_PLANE0,c1);
	glEnable(GL_CLIP_PLANE0);
	double c2[] = {-1,0,0,35};
	glClipPlane(GL_CLIP_PLANE1,c2);
	glEnable(GL_CLIP_PLANE1);
	for(int i = 1 ; i<=20 ;i++)
	{
		h = 10*log(i+3.0)-10*log(i+1.0);
		p = getPoint(i-25,0,10*log(i*1.0));
		drawCube(p,25,1,h,MEDIUM_CREAM,SOLID);
		
		p = getPoint(35-i,0,10*log(i*1.0));
		drawCube(p,25,1,h,MEDIUM_CREAM,SOLID);
	}
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
}
void drawBox(Point p,GLdouble length, GLdouble height, GLdouble width, GLdouble depth,int r,int g,int b)
{
	Point q;
	drawCube(p,length,width,depth,r,g,b,SOLID);
	q = getPoint(p.x,p.y,p.z+height-depth);
	drawCube(q,length,width,depth,r,g,b,SOLID);
	q = getPoint(p.x,p.y,p.z+depth);
	drawCube(q,depth-4,width,height-depth*2,r,g,b,SOLID);
	q = getPoint(p.x+length-depth+4,p.y,p.z+depth);
	drawCube(q,depth-4,width,height-depth*2,r,g,b,SOLID);
}
void draw90DegreeSideInOrigin()
{
	GLdouble down = 3.0;
	Point p;
	glPushMatrix();
	{
		glRotatef(-90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,192,50,down,WOOD4,DEEP_CREAM);
		for(int i = 0 ; i < 3 ; i++)
		{
			for(int j = 0 ; j < 3 ;j ++)
			{
				p = getPoint(0+j*64,0,50+i*84);
				drawDownFacePrism(p,64,85,down,WOOD4,DEEP_CREAM);
			}
		}
	}glPopMatrix();
}
void drawFrontDoor()
{
	GLdouble down = 3.0;
	Point p;
	//MIDDLE DOOR START
	//bottom row
	p = getPoint(0,0,0);
	drawDownFacePrism(p,43,70,down,WOOD4,DEEP_CREAM);
	p = getPoint(43,0,0);
	drawDownFacePrism(p,33,57,down,WOOD4,DEEP_CREAM);
	p = getPoint(-33,0,0);
	drawDownFacePrism(p,33,57,down,WOOD4,DEEP_CREAM);
	//middle row
	p = getPoint(0,0,70);
	drawDownFacePrism(p,43,76,down,WOOD4,DEEP_CREAM);
	p = getPoint(43,0,57);
	drawDownFacePrism(p,33,70,down,WOOD4,DEEP_CREAM);
	p = getPoint(-33,0,57);
	drawDownFacePrism(p,33,70,down,WOOD4,DEEP_CREAM);
	//top row
	p = getPoint(0,0,146);
	drawDownFacePrism(p,43,70,down,WOOD4,DEEP_CREAM);
	p = getPoint(43,0,127);
	drawDownFacePrism(p,33,57,down,WOOD4,DEEP_CREAM);
	p = getPoint(-33,0,127);
	drawDownFacePrism(p,33,57,down,WOOD4,DEEP_CREAM);
	//boundary
	p = getPoint(-41,0,-8);
	drawDownFacePrism(p,125,270,down+1,WOOD4,LIGHT_CREAM);
	p = getPoint(-33,0,232);
	drawCube(p,109,4,8,WOOD4,SOLID);
	//MIDDLE DOOR END
	//DOOR SIDE START
	// 0 degree sides  START
	p = getPoint(84,0,0);
	drawDownFacePrism(p,140,50,down,WOOD4,LIGHT_CREAM);
	p = getPoint(-182,0,0);
	drawDownFacePrism(p,140,50,down,WOOD4,LIGHT_CREAM);
	for(int i = 0 ; i < 3;i++)
	{
		p = getPoint(124,0,50+i*85);
		drawDownFacePrism(p,50,85,down,WOOD4,LIGHT_CREAM);
		p = getPoint(174,0,50+i*85);
		drawDownFacePrism(p,50,85,down,WOOD4,LIGHT_CREAM);

		p = getPoint(-182,0,50+i*85);
		drawDownFacePrism(p,50,85,down,WOOD4,LIGHT_CREAM);
		p = getPoint(-132,0,50+i*85);
		drawDownFacePrism(p,50,85,down,WOOD4,LIGHT_CREAM);
	}
	//0 degree sides end
	//90 degree sides start
	glPushMatrix();
	{
		glTranslatef(224,0,0);
		draw90DegreeSideInOrigin();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-182,0,0);
		glRotatef(-180,0,0,1);
		glTranslatef(0,192,0);
		draw90DegreeSideInOrigin();
	}glPopMatrix();
	//90 degree sides end
	//DOOR SIDE END
	//back cover
	p = getPoint(-82,8,50);
	drawCube(p,206,5,255,LIGHT_CREAM,SOLID);
	//arc
	glPushMatrix();{
		glTranslatef(-190,-190,300);
		glScalef(12,190,5);
		drawArc();
	}glPopMatrix();
	p = getPoint(-190,0,305);
	drawCube(p,420,5,150,SILVER,SOLID);
	//drawBox
	p = getPoint(-215,-200,-25);
	drawBox(p,470,505,200,25,BLACKEN_SILVER);
	//side gap
	p = getPoint(-315,-190,-25);
	drawCube(p,100,5,600,SILVER,SOLID);
	p = getPoint(-215,-190,475);
	drawCube(p,470,5,100,SILVER,SOLID);
	p = getPoint(255,-190,-25);
	drawCube(p,100,5,600,SILVER,SOLID);
}
void drawSmallDoorType1()
{
	GLdouble down = 3.0;
	Point p;
	//0 degree part
	p = getPoint(-25,0,0);
	drawDownFacePrism(p,50,90,down,WOOD4,LIGHT_CREAM);
	p = getPoint(-25,0,90);
	drawDownFacePrism(p,50,40,down,WOOD4,LIGHT_CREAM);
	p = getPoint(25,0,0);
	drawDownFacePrism(p,50,60,down,WOOD4,LIGHT_CREAM);
	p = getPoint(25,0,60);
	drawDownFacePrism(p,50,70,down,WOOD4,LIGHT_CREAM);
	p = getPoint(-75,0,0);
	drawDownFacePrism(p,50,60,down,WOOD4,LIGHT_CREAM);
	p = getPoint(-75,0,60);
	drawDownFacePrism(p,50,70,down,WOOD4,LIGHT_CREAM);
	//90 degree part
	glPushMatrix();
	{
		glTranslatef(75,0,0);
		glRotatef(-90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,50,60,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,60);
		drawDownFacePrism(p,50,70,down,WOOD4,LIGHT_CREAM);
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-75,0,0);
		glRotatef(90,0,0,1);
		p = getPoint(-50,0,0);
		drawDownFacePrism(p,50,60,down,WOOD4,LIGHT_CREAM);
		p = getPoint(-50,0,60);
		drawDownFacePrism(p,50,70,down,WOOD4,LIGHT_CREAM);
	}glPopMatrix();
	//arc
	glPushMatrix();
	{
		glTranslatef(-80,-50,130);
		glScalef(4.5,50,2.0);
		drawArc();
	}glPopMatrix();
	p = getPoint(-75,0,130);
	drawCube(p,150,5,60,SILVER,SOLID);
	//box
	p = getPoint(-104,-60,-25);
	drawBox(p,208,240,60,25,BLACKEN_SILVER);
	//side
	p = getPoint(-144,-50,-25);
	drawCube(p,40,5,280,SILVER,SOLID);
	p = getPoint(104,-50,-25);
	drawCube(p,40,5,280,SILVER,SOLID);
	p = getPoint(-104,-50,215);
	drawCube(p,208,5,40,SILVER,SOLID);
}
void drawHeadOfPiller()
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();	
	glPushMatrix();
	{
		glColor3ub(GOLDEN);
		gluCylinder(quadratic,12,24,32,8,3);
		glTranslatef(0,0,32);
		double c[] ={0,0,1,0};
		glClipPlane(GL_CLIP_PLANE0,c);
		glEnable(GL_CLIP_PLANE0);
		glutSolidSphere(24,20,20);
		glDisable(GL_CLIP_PLANE0);
	}glPopMatrix();
	Point p = getPoint(0,0,51);
	drawCone(p,15,10,GOLDENROD,SOLID);
	p = getPoint(0,0,65);
	drawSphere(p,5,GOLDEN,SOLID);
	
	p = getPoint(0,0,80);
	drawSphere(p,10,GOLDEN,SOLID);
	p = getPoint(0,0,85);
	drawCylinder(p,5,0,15,GOLDENROD,OPEN);
}
void drawPiller(Point center, GLdouble height, GLdouble radius,int r,int g,int b,int rr,int gr,int br)
{
	Point p;
	drawOctaCylinder(center,radius,radius,height,r,g,b);
	for(int i = 25; i < height; i+=200)
	{
		p = getPoint(center.x,center.y,center.z+i);
		drawOctaLifeBoya(p,radius,10,rr,gr,br);
	}
	glPushMatrix();
	{
		glTranslatef(center.x,center.y,center.z+height);
		drawHeadOfPiller();
	}glPopMatrix();
}
void drawSmallDoorSetType1WithPiller(bool isLeft)
{
	drawSmallDoorType1();
	glPushMatrix();
	{
		glTranslatef(0,0,275);
		drawSmallDoorType1();
	}glPopMatrix();
	if(isLeft)
	{
		Point p = getPoint(-152,-50,-25);
		drawPiller(p,700,12,BLACKEN_SILVER,GOLDEN);
		p = getPoint(144,-50,-25);
		drawPiller(p,900,12,BLACKEN_SILVER,GOLDEN);
	}else
	{
		Point p = getPoint(-152,-50,-25);
		drawPiller(p,900,12,BLACKEN_SILVER,GOLDEN);
		p = getPoint(144,-50,-25);
		drawPiller(p,700,12,BLACKEN_SILVER,GOLDEN);
	}
}
void drawFrontPanel()
{
	drawFrontDoor();
	glPushMatrix();{
		glTranslatef(500,-145,0);
		drawSmallDoorSetType1WithPiller(false);
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(-470,-145,0);
		drawSmallDoorSetType1WithPiller(true);
	}glPopMatrix();
}
void draw45DegreeGate()
{
	GLdouble down = 3.0;
	Point p;
	//0 degree section
	p = getPoint(-25,0,0);
	drawDownFacePrism(p,50,90,down,WOOD4,LIGHT_CREAM);
	p = getPoint(-25,0,90);
	drawDownFacePrism(p,50,40,down,WOOD4,LIGHT_CREAM);
	p = getPoint(-25,0,130);
	drawCube(p,50,4,60,SILVER,SOLID);
	//45 degree section
	glPushMatrix();{
		glTranslatef(25,0,0);
		glRotatef(-45,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,84,50,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,84,80,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,130);
		drawCube(p,84,4,50,SILVER,SOLID);
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(-84,-59,0);
		glRotatef(45,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,84,50,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,84,80,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,130);
		drawCube(p,84,4,50,SILVER,SOLID);
	}glPopMatrix();
	//90 degree section
	glPushMatrix();{
		glTranslatef(84,-59,0);
		glRotatef(-90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,20,50,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,20,80,down,WOOD4,LIGHT_CREAM);
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(-84,-79,0);
		glRotatef(90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,20,50,down,WOOD4,LIGHT_CREAM);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,20,80,down,WOOD4,LIGHT_CREAM);
	}glPopMatrix();
	//arc
	glPushMatrix();
	{
		glTranslatef(-90,-80,130);
		glScalef(5.1,85,2.0);
		drawArc();
	}glPopMatrix();
	//border
	p = getPoint(-114,-85,-25);
	drawBox(p,227,240,90,25,BLACKEN_SILVER);
	//side
	p = getPoint(-154,-50,-25);
	drawCube(p,40,5,280,SILVER,SOLID);
	p = getPoint(114,-50,-25);
	drawCube(p,40,5,280,SILVER,SOLID);
	p = getPoint(-114,-50,215);
	drawCube(p,228,5,40,SILVER,SOLID);
}
void draw45DegreeGateSet()
{
	draw45DegreeGate();
	glPushMatrix();
	{
		glTranslatef(0,0,280);
		draw45DegreeGate();
	}glPopMatrix();
}
void drawWalls()
{
	drawFrontPanel();
	//45 degree sides
	glPushMatrix();
	{
		glTranslatef(730,-50,0);
		glRotatef(45,0,0,1);
		draw45DegreeGateSet();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-700,-40,0);
		glRotatef(-45,0,0,1);
		draw45DegreeGateSet();
	}glPopMatrix();
	//sides
	glPushMatrix();
	{
		glTranslatef(685,655,0);
		glRotatef(90,0,0,1);
		drawFrontPanel();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-665,680,0);
		glRotatef(-90,0,0,1);
		drawFrontPanel();
	}glPopMatrix();
	//45 degree sides
	glPushMatrix();
	{
		glTranslatef(725,1395,0);
		glRotatef(135,0,0,1);
		glScalef(1.1,1,1);
		draw45DegreeGateSet();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-710,1385,0);
		glRotatef(-135,0,0,1);
		draw45DegreeGateSet();
	}glPopMatrix();
	//back panel
	glPushMatrix();
	{
		glTranslatef(10,1350,0);
		glRotatef(180,0,0,1);
		drawFrontPanel();
	}glPopMatrix();
}
void drawRoof()
{
	Point p;
	p = getPoint(-870,-200,530);
	double c1[] = {1,1,0,820};
	glClipPlane(GL_CLIP_PLANE0,c1);
	double c2[] = {-1,1,0,860};
	glClipPlane(GL_CLIP_PLANE1,c2);
	double c3[] = {-1,-1,0,2200};
	glClipPlane(GL_CLIP_PLANE2,c3);
	double c4[] = {1,-1,0,2200};
	glClipPlane(GL_CLIP_PLANE3,c4);

	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	glEnable(GL_CLIP_PLANE2);
	glEnable(GL_CLIP_PLANE3);
	drawCube(p,1760,1750,10,SILVER,SOLID);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glDisable(GL_CLIP_PLANE2);
	glDisable(GL_CLIP_PLANE3);
}
void drawBaseBasicUnit()
{
	GLdouble down = 4.0;
	Point p;
	//p = getPoint(0,0,0);
	//drawDownFacePrism(p,80,190,down,GOLDEN,DARK_WHITE);
	//p = getPoint(27,0,90);
	//drawCube(p,28,down,45,GOLDEN,SOLID);
	p = getPoint(0,0,165);
	drawCube(p,320,down,100,GOLDEN,textureWall);
	/*for(int i = 0 ; i < 5 ; i++)
	{
		p = getPoint(4,0,165-2*(i+1));
		drawCube(p,36-i,down,2,GOLDEN,SOLID);
		p = getPoint(40+i,0,165-2*(i+1));
		drawCube(p,36-i,down,2,GOLDEN,SOLID);
	}
	for(int i = 0 ; i < 5 ; i++)
	{
		p = getPoint(4,0,155-2*(i+1));
		drawCube(p,20-i,down,2,GOLDEN,SOLID);
		p = getPoint(56+i,0,155-2*(i+1));
		drawCube(p,20-i,down,2,GOLDEN,SOLID);
	}
	for(int i = 0 ; i < 5 ; i++)
	{
		p = getPoint(4,0,145-2*(i+1));
		drawCube(p,5-i,down,2,GOLDEN,SOLID);
		p = getPoint(71+i,0,145-2*(i+1));
		drawCube(p,5-i,down,2,GOLDEN,SOLID);
	}*/
	//p = getPoint(0,0,190);
	//drawDownFacePrism(p,80,35,down,WOOD4,WHITE2);
	//p = getPoint(0,-10,225);
	//drawCube(p,80,16,10,GOLDEN,SOLID);

	/*p = getPoint(3,-4,235);
	drawCube(p,6,10,32,WHITE4,SOLID);
	p = getPoint(71,-4,235);
	drawCube(p,6,10,32,WHITE4,SOLID);*/

	//p = getPoint(0,0,235);
	//drawCube(p,3,2,32,BLACKEN_SILVER,SOLID);
	//p = getPoint(77,0,235);
	//drawCube(p,3,2,32,BLACKEN_SILVER,SOLID);

	//p = getPoint(9,0,235);
	//drawDownFacePrism(p,62,32,down,WOOD4,LIGHT_CREAM);
}

void drawBase()
{
	int repetations = 10;
	int distance = 320;
	int offset = -240;
	glPushMatrix();
	{
		glTranslatef(-1700,-850,-260);
		glTranslatef(offset,-0,-0);
		for(int i = 0 ; i < repetations ;i++)
		{
			glTranslatef(distance,0,0);
			drawBaseBasicUnit();
		}
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-1625,2430,-260);
		glRotatef(-90,0,0,1);
		glTranslatef(offset,-0,-0);
		for(int i = 0 ; i < repetations ;i++)
		{
			glTranslatef(distance,0,0);
			drawBaseBasicUnit();
		}
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(1580,-930,-260);
		glRotatef(90,0,0,1);
		glTranslatef(offset,-0,-0);
		for(int i = 0 ; i < repetations ;i++)
		{
			glTranslatef(distance,0,0);
			drawBaseBasicUnit();
		}
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(1660,2350,-260);
		glRotatef(180,0,0,1);
		glTranslatef(offset,-0,-0);
		for(int i = 0 ; i < repetations ;i++)
		{
			glTranslatef(distance,0,0);
			drawBaseBasicUnit();
		}
	}glPopMatrix();
	Point p = getPoint(-1620,-850,-50);
	drawCube(p,3200,3200,25,DARK_WHITE,SOLID);
}
void drawSmallDomeBasicUnit()
{
	Point p;
	double y = -155;
	p = getPoint(-65,y,0);
	drawCube(p,15,15,270,ORANGE,SOLID);
	p = getPoint(50,y,0);
	drawCube(p,15,15,270,ORANGE,SOLID);
	p = getPoint(-65,y,230);
	drawCube(p,115,15,40,ORANGE,SOLID);
	glPushMatrix();
	{
		glTranslatef(-50,y,137);
		glScalef(2.9,15,3);
		drawArc();
	}glPopMatrix();
	
}
void drawSmallDome()
{
	glPushMatrix();
	{
		for(int i = 0 ; i < 8 ;i++)
		{
			glRotatef(45,0,0,1);
			drawSmallDomeBasicUnit();
		}
	}glPopMatrix();
	//base
	glColor3ub(GOLDENROD);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glPushMatrix();
	{
		glRotatef(22.5,0,0,1);
		glPushMatrix();
		{
			glTranslatef(0,0,-15);
			gluCylinder(quadratic,170,170,15,8,1);	
		}glPopMatrix();
		gluDisk(quadratic,0,170,8,8);
	}glPopMatrix();
	glPushMatrix();
	{
		glRotatef(22.5,0,0,1);
		glPushMatrix();
		{
		glTranslatef(0,0,246);
		gluDisk(quadratic,0,200,8,1);
		}glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(0,0,270);
			gluDisk(quadratic,0,170,8,1);
		}glPopMatrix();
	}glPopMatrix();
	//gombuj
	Point p = getPoint(0,0,270);
	double c[] = {0,0,1,-270};
	glClipPlane(GL_CLIP_PLANE0,c);
	glEnable(GL_CLIP_PLANE0);
	drawSphere(p,120,GOLDEN,SOLID);
	glDisable(GL_CLIP_PLANE0);

	p = getPoint(0,0,380);
	drawCone(p,50,30,GOLDENROD,SOLID);
	p = getPoint(0,0,420);
	drawSphere(p,10,GOLDEN,SOLID);
	p = getPoint(0,0,450);
	drawSphere(p,20,GOLDEN,SOLID);
	p = getPoint(0,0,480);
	drawSphere(p,10,GOLDEN,SOLID);
	p = getPoint(0,0,485);
	drawCylinder(p,5,5,15,GOLDENROD,SOLID);
	p = getPoint(0,0,500);
	drawCone(p,5,10,GOLDEN,SOLID);
}
void drawSmallDomeType2BasicUnit()
{
	Point p;
	double y = -155;
	p = getPoint(-69,y,0);
	drawCube(p,15,15,45,GOLDENROD,SOLID);
	drawCube(p,130,15,30,GOLDENROD,SOLID);
	p = getPoint(-69+7,y+7,45);
	drawCylinder(p,7,7,140,ORANGE,SOLID);

	p = getPoint(-65,y,185);
	drawCube(p,15,15,45,GOLDEN,SOLID);

	p = getPoint(-65,y,230);
	drawCube(p,130,15,40,GOLDENROD,SOLID);

	p = getPoint(50,y,185);
	drawCube(p,15,15,45,GOLDEN,SOLID);

	glPushMatrix();
	{
		glTranslatef(-50,y,185);
		glScalef(2.9,15,1.5);
		drawArc();
	}glPopMatrix();
	
}
void drawSmallDomeType2()
{
	glPushMatrix();
	{
		for(int i = 0 ; i < 8 ;i++)
		{
			glRotatef(45,0,0,1);
			drawSmallDomeType2BasicUnit();
		}
	}glPopMatrix();
	//base
	glColor3ub(GOLDENROD);
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();
	glPushMatrix();
	{
		glColor3ub(GOLDEN);
		glRotatef(22.5,0,0,1);
		glPushMatrix();
		{
			glTranslatef(0,0,-15);
			gluCylinder(quadratic,170,170,15,8,1);	
		}glPopMatrix();
		gluDisk(quadratic,0,170,8,8);
	}glPopMatrix();
	glPushMatrix();
	{
		glColor3ub(GOLDENROD);
		glRotatef(22.5,0,0,1);
		glPushMatrix();
		{
			glTranslatef(0,0,246);
			gluDisk(quadratic,0,200,8,1);
		}glPopMatrix();
		glPushMatrix();
		{

			glTranslatef(0,0,270);
			gluDisk(quadratic,0,170,8,1);
		}glPopMatrix();
	}glPopMatrix();
	//gombuj

	Point p = getPoint(0,0,270);
	double c[] = {0,0,1,-270};
	glClipPlane(GL_CLIP_PLANE0,c);
	glEnable(GL_CLIP_PLANE0);
	drawSphere(p,120,GOLDEN,SOLID);
	glDisable(GL_CLIP_PLANE0);

	p = getPoint(0,0,380);
	drawCone(p,50,30,GOLDENROD,SOLID);
	p = getPoint(0,0,420);
	drawSphere(p,10,GOLDEN,SOLID);
	
	p = getPoint(0,0,450);
	drawSphere(p,20,GOLDEN,SOLID);
	p = getPoint(0,0,480);
	drawSphere(p,10,GOLDEN,SOLID);
	p = getPoint(0,0,485);
	drawCylinder(p,5,5,15,GOLDENROD,SOLID);
	p = getPoint(0,0,500);
	drawCone(p,5,10,GOLDEN,SOLID);
}

void drawBigDome()
{
	GLUquadric *q;
	q = gluNewQuadric();
	glPushMatrix();
	{
		glColor3ub(GOLDENROD);
		glTranslatef(-50,600,540);
		gluCylinder(q,500,500,100,30,1);
		
		glColor3ub(WHITE4);
		// Dome base lower
		glTranslatef(0,0,100);
		gluDisk(q,480,500,30,1);
		gluCylinder(q,480,480,100,30,1);

		// Dome base upper
		glEnable(GL_TEXTURE_2D);
		glMatrixMode (GL_TEXTURE);
		glPushMatrix(); {
			glScalef(30, 0.5, 10);
			glBindTexture(GL_TEXTURE_2D, textureBrick);
			gluQuadricNormals(q, GLU_SMOOTH);
			gluQuadricTexture(q, GLU_TRUE);

			glMatrixMode(GL_MODELVIEW);
			glTranslatef(0,0,100);
			gluCylinder(q,480,480,50,30,1);
			glMatrixMode (GL_TEXTURE);
		} glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glMatrixMode(GL_MODELVIEW);

		//glColor3ub(GOLDENROD);
		glTranslatef(0,0,50);
		glutSolidTorus(10,480,30,30);

		// The fat big sphere
		// glColor3ub(SKY_BLUE);
		glTranslatef(0,0,180);

		glEnable(GL_TEXTURE_2D);
		glMatrixMode (GL_TEXTURE);
		glPushMatrix(); {
			glScalef (40, 20, 10);
			glBindTexture(GL_TEXTURE_2D, textureBigDomeMain);
			gluQuadricNormals(q, GLU_SMOOTH);
			gluQuadricTexture(q, GLU_TRUE);

			glMatrixMode(GL_MODELVIEW);
			gluSphere(q,500,30,30);
			glMatrixMode (GL_TEXTURE);
		} glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		glMatrixMode(GL_MODELVIEW);

		glColor3ub(GOLDENROD);
		glTranslatef(0,0,490);
		gluCylinder(q,100,0,50,15,1);
		glColor3ub(GOLDEN);
		glTranslatef(0,0,75);
		gluSphere(q,30,10,10);
		glTranslatef(0,0,85);
		gluSphere(q,60,10,10);
		glTranslatef(0,0,85);
		gluSphere(q,30,10,10);
		glTranslatef(0,0,15);
		gluCylinder(q,15,0,100,15,1);
	} glPopMatrix();
}
void drawDomes()
{
	drawBigDome();
	glPushMatrix();
	{
		glTranslatef(-580,80,555);
		drawSmallDome();
		glTranslatef(0,1200,0);
		drawSmallDome();
		glTranslatef(1200,0,0);
		drawSmallDome();
		glTranslatef(0,-1200,0);
		drawSmallDome();
	}glPopMatrix();
}
void drawFloors()
{
	Point p;
	p = getPoint(-2000,-1300,-285);
	drawCube(p,4400,4400,25,WHITE,SOLID);
	//left side
	p = getPoint(-2000,-1850,-285);
	drawCube(p,4400,550,25,LIGHT_BRICK,SOLID);
	p = getPoint(-2000,-4650,-285);
	drawCube(p,4400,2350,25,LIGHT_BRICK,SOLID);
	p = getPoint(-2000,-2350,-285);
	drawCube(p,1985,550,25,LIGHT_BRICK,SOLID);
	p = getPoint(435,-2350,-285);
	drawCube(p,1985,550,25,LIGHT_BRICK,SOLID);
	//other side
	p = getPoint(-2000,3100,-285);
	drawCube(p,4400,550,25,LIGHT_BRICK,SOLID);
	p = getPoint(-2000,4100,-285);
	drawCube(p,4400,2350,25,LIGHT_BRICK,SOLID);
	p = getPoint(-2000,3600,-285);
	drawCube(p,1985,550,25,LIGHT_BRICK,SOLID);
	p = getPoint(435,3600,-285);
	drawCube(p,1985,550,25,LIGHT_BRICK,SOLID);
	//water baths
	p = getPoint(0,0,0);
	glPushMatrix();
	{
		glTranslatef(-40,-2350,-250);
		glRotatef(-90,1,0,0);
		drawDownFacePrism(p,530,530,50,MEDIUM_BRICK,SKY_BLUE);
		glTranslatef(0,2350,0);
		drawDownFacePrism(p,530,530,50,MEDIUM_BRICK,SKY_BLUE);
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-40,3600,-250);
		glRotatef(-90,1,0,0);
		drawDownFacePrism(p,530,530,50,MEDIUM_BRICK,SKY_BLUE);
	}glPopMatrix();
}
void drawSmallBuildingBigDoor()
{
	Point p;
	p = getPoint(-260,0,-25);
	drawBox(p,520,700,200,25,DEEP_BRICK);
	glPushMatrix();
	{
		glTranslatef(-245,0,280);
		glScalef(14,200,12);
		drawArc();
	}glPopMatrix();
	p = getPoint(-260,200,-25);
	drawCube(p,520,25,700,MEDIUM_BRICK,SOLID);
	p = getPoint(-400,25,-25);
	drawCube(p,140,25,840,MEDIUM_BRICK,SOLID);
	p = getPoint(260,25,-25);
	drawCube(p,140,25,840,MEDIUM_BRICK,SOLID);
	p = getPoint(-260,25,675);
	drawCube(p,520,25,140,MEDIUM_BRICK,SOLID);
}
void drawSmallDoorBuilding2()
{
	GLdouble down = 3.0;
	Point p;
	//0 degree part
	p = getPoint(-25,0,0);
	drawDownFacePrism(p,50,90,down,MEDIUM_BRICK,LIGHT_BRICK);
	p = getPoint(-25,0,90);
	drawDownFacePrism(p,50,40,down,MEDIUM_BRICK,LIGHT_BRICK);
	p = getPoint(25,0,0);
	drawDownFacePrism(p,50,130,down,MEDIUM_BRICK,LIGHT_BRICK);
	p = getPoint(-75,0,0);
	drawDownFacePrism(p,50,130,down,MEDIUM_BRICK,LIGHT_BRICK);
	p = getPoint(-75,0,60);
	//90 degree part
	glPushMatrix();
	{
		glTranslatef(75,0,0);
		glRotatef(-90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,50,130,down,MEDIUM_BRICK,LIGHT_BRICK);
	
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-75,0,0);
		glRotatef(90,0,0,1);
		p = getPoint(-50,0,0);
		drawDownFacePrism(p,50,130,down,MEDIUM_BRICK,LIGHT_BRICK);
		
	}glPopMatrix();
	//arc
	glPushMatrix();
	{
		glTranslatef(-80,-50,130);
		glScalef(4.5,50,2.0);
		drawArc();
	}glPopMatrix();
	p = getPoint(-75,0,130);
	drawCube(p,150,5,60,MEDIUM_BRICK,SOLID);
	//box
	p = getPoint(-104,-60,-25);
	drawBox(p,208,240,60,25,DEEP_BRICK);
	//side
	p = getPoint(-144,-50,-25);
	drawCube(p,40,5,280,MEDIUM_BRICK,SOLID);
	p = getPoint(104,-50,-25);
	drawCube(p,40,5,280,MEDIUM_BRICK,SOLID);
	p = getPoint(-104,-50,215);
	drawCube(p,208,5,40,MEDIUM_BRICK,SOLID);
}
void drawBuilding2Window()
{
	Point p;
	//box
	p = getPoint(-104,-50,-25);
	drawDownFacePrism(p,208,208,7,DEEP_BRICK,LIGHT_BRICK);
	p = getPoint(-65,-50,-25);
	drawDownFacePrism(p,130,130,3,DEEP_BRICK,WHITE4);

	//side
	p = getPoint(-144,-50,-25);
	drawCube(p,40,5,248,MEDIUM_BRICK,SOLID);
	p = getPoint(104,-50,-25);
	drawCube(p,40,5,248,MEDIUM_BRICK,SOLID);
	p = getPoint(-104,-50,183);
	drawCube(p,208,5,40,MEDIUM_BRICK,SOLID);
}
void drawSmallDoorBuilding21WithPiller(bool isLeft)
{
	drawSmallDoorBuilding2();
	glPushMatrix();
	{
		glTranslatef(0,0,280);
		drawBuilding2Window();
	}glPopMatrix();
	if(isLeft)
	{
		Point p = getPoint(-152,-50,-25);
		drawPiller(p,700,12,MEDIUM_BRICK,GOLDEN);
		p = getPoint(144,-50,-25);
		drawPiller(p,900,12,MEDIUM_BRICK,GOLDEN);
	}else
	{
		Point p = getPoint(-152,-50,-25);
		drawPiller(p,900,12,MEDIUM_BRICK,GOLDEN);
		p = getPoint(144,-50,-25);
		drawPiller(p,700,12,MEDIUM_BRICK,GOLDEN);
	}
}
void drawBuilding2BigPillerBasicUnit()
{
	Point p;
	p = getPoint(-30,-72,0);
	drawDownFacePrism(p,60,45,2,MEDIUM_BRICK,LIGHT_BRICK);
	p = getPoint(-30,-72,45);
	drawDownFacePrism(p,60,15,2,MEDIUM_BRICK,LIGHT_BRICK);
}
void drawBuilding2BigPiller()
{
	glPushMatrix();
	{
		for(int i = 0 ; i < 14; i++)
		{
			for(int j = 0 ; j < 8 ;j++)
			{
				glRotatef(45,0,0,1);
				drawBuilding2BigPillerBasicUnit();
			}
			glTranslatef(0,0,60);
		}	
		glScalef(.5,.5,.5);
		drawSmallDomeType2();
	}glPopMatrix();
}
void drawBuilding2Side()
{
	glPushMatrix();
	{

		glScalef(0.7,1,1.5);
		for(int i = 0 ; i < 4 ;i++)
		{
			drawSmallDoorBuilding2();
			glTranslatef(0,0,280);
			drawBuilding2Window();
			glTranslatef(285,0,-280);
		}

	}glPopMatrix();
}
void drawBigOctaDome()
{
	Point p;
	
		glPushMatrix();
		{
			for(int i = 0 ; i < 8; i++)
			{
				glRotatef(45,0,0,1);
				p = getPoint(-100,-255,0);
				drawCube(p,200,50,300,DEEP_BRICK,SOLID);
				glPushMatrix();
				{
					glTranslatef(0,-10,300);
					glScalef(1.5,1.5,1);
					drawSmallDomeBasicUnit();
				}glPopMatrix();

			}
			glTranslatef(0,0,290);
			glScalef(3.5,3.5,3.5);
			railingBigPiller();
			glTranslatef(0,0,80);
			railingBigPiller();
			glTranslatef(0,0,10);
			glScalef(0.4,0.4,0.4);
			drawSmallDomeType2();
		}glPopMatrix();
		
	
}
void drawSmallBuilding()
{
	//
	drawSmallBuildingBigDoor();
	glPushMatrix();
	{
		glTranslatef(-620,100,0);
		glScalef(1.5,1.5,1.5);
		drawSmallDoorBuilding21WithPiller(true);
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(620,100,0);
		glScalef(1.5,1.5,1.5);
		drawSmallDoorBuilding21WithPiller(false);
	}glPopMatrix();
	
	//side before piller
	Point p = getPoint(-980,10,0);
	drawCube(p,120,25,760,MEDIUM_BRICK,SOLID);
	p = getPoint(830,10,0);
	drawCube(p,120,25,760,MEDIUM_BRICK,SOLID);

	//big piller
	glPushMatrix();
	{
		glTranslatef(-1052,0,0);
		drawBuilding2BigPiller();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(1020,0,0);
		drawBuilding2BigPiller();
	}glPopMatrix();

	//sides
	glPushMatrix();
	{
		glTranslatef(970,150,0);
		glRotatef(90,0,0,1);
		drawBuilding2Side();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-990,760,0);
		glRotatef(-90,0,0,1);
		drawBuilding2Side();
	}glPopMatrix();
	//back side
	glPushMatrix();
	{
		glTranslatef(0,875,0);
		glRotatef(180,0,0,1);
		drawSmallBuildingBigDoor();
		glPushMatrix();
		{
			glTranslatef(-620,100,0);
			glScalef(1.5,1.5,1.5);
			drawSmallDoorBuilding21WithPiller(true);
		}glPopMatrix();
		glPushMatrix();
		{
			glTranslatef(620,100,0);
			glScalef(1.5,1.5,1.5);
			drawSmallDoorBuilding21WithPiller(false);
		}glPopMatrix();
		//side before piller
		Point p = getPoint(-1020,10,-25);
		drawCube(p,160,25,795,MEDIUM_BRICK,SOLID);
		p = getPoint(830,10,-25);
		drawCube(p,210,25,795,MEDIUM_BRICK,SOLID);
	}glPopMatrix();
	//roof
	p = getPoint(-1030,30,750);
	drawCube(p,2050,830,25,DEEP_BRICK,SOLID);
	glPushMatrix();
	{
		glTranslatef(0,0,400);
		glScalef(0.7,0.7,0.7);
		drawBigDome();
		glTranslatef(1000,200,200);
		glScalef(0.7,0.7,0.7);
		drawBigDome();
		glTranslatef(-2800,0,0);
		drawBigDome();
		glTranslatef(-500,1300,500);
		drawSmallDomeType2();
		glTranslatef(3750,0,0);
		drawSmallDomeType2();
	}glPopMatrix();
	//wing
	p = getPoint(1000,800,0);
	drawCube(p,800,50,300,DEEP_BRICK,SOLID);
	p = getPoint(1000,650,0);
	drawCube(p,800,50,300,DEEP_BRICK,SOLID);
	glPushMatrix();
	{
		glTranslatef(2000,700,0);
		drawBigOctaDome();
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0,1500,0);
		glRotatef(180,0,0,1);
		p = getPoint(1000,800,0);
		drawCube(p,800,50,300,DEEP_BRICK,SOLID);
		p = getPoint(1000,650,0);
		drawCube(p,800,50,300,DEEP_BRICK,SOLID);
		glPushMatrix();
		{
			glTranslatef(2000,700,0);
			drawBigOctaDome();
		}glPopMatrix();
	}glPopMatrix();
}
void railingBigPiller()
{
	GLUquadric *q;
	q = gluNewQuadric();
	Point p,p2,p3;
	p = getPoint(-20,-112,0);
	p2 = getPoint(10,-115,0);
	p3 = getPoint(12.5,-112.5,30);
	glPushMatrix();
	{
		for(int i = 0 ; i < 20 ;i++)
		{
			glRotatef(18,0,0,1);
			drawCube(p,30,5,20,GOLDEN,SOLID);
			drawCube(p2,10,10,25,GOLDEN,SOLID);
			drawSphere(p3,5,GOLDEN,SOLID);
		}
		gluDisk(q,60,112,20,3);
	}glPopMatrix();
}
void drawMainBuildingSingleBigPiller()
{
	GLUquadric *q;
	q = gluNewQuadric();
	Point p = getPoint(0,0,200);
	glPushMatrix();
	{
		for(int i = 0 ; i < 5 ;i++)
		{
			glRotatef(45,0,0,1);
			glPushMatrix();
			{
				glTranslatef(-40,-100,0);
				drawBaseBasicUnit();
			}glPopMatrix();
		}
		glTranslatef(0,0,230);
		glRotatef(22.5,0,0,1);
		gluDisk(q,50,105,8,3);
		glTranslatef(0,0,-230);
		drawCylinder(p,85,60,1200,WHITE,OPEN);//the piller
		glTranslatef(0,0,200);
		for(int i = 0 ; i < 3 ;i++) // railing
		{
			glTranslatef(0,0,400);
			railingBigPiller();
		}
		glTranslatef(0,0,10);
		glScalef(0.5,0.5,0.5);
		drawSmallDomeType2();
	}glPopMatrix();
	
}

void drawMainBuildingBigPillers()
{
	glPushMatrix();
	{
		glTranslatef(1550,2300,-260);
		drawMainBuildingSingleBigPiller();
		glTranslatef(-3100,0,0);
		glRotatef(90,0,0,1);
		drawMainBuildingSingleBigPiller();
		glTranslatef(-3100,0,0);
		glRotatef(90,0,0,1);
		drawMainBuildingSingleBigPiller();
		glTranslatef(-3100,0,0);
		glRotatef(90,0,0,1);
		drawMainBuildingSingleBigPiller();
	}glPopMatrix();
}