#include "color.h"
#include "ifta.h"
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
		drawCube(p,25,1,h,SKY_BLUE,SOLID);
		
		p = getPoint(35-i,0,10*log(i*1.0));
		drawCube(p,25,1,h,SKY_BLUE,SOLID);
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
		drawDownFacePrism(p,192,50,down,VIOLATE,EBONY);
		for(int i = 0 ; i < 3 ; i++)
		{
			for(int j = 0 ; j < 3 ;j ++)
			{
				p = getPoint(0+j*64,0,50+i*84);
				drawDownFacePrism(p,64,85,down,LIGHT_WOOD,MEDIUM_WOOD);
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
	drawDownFacePrism(p,43,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(43,0,0);
	drawDownFacePrism(p,33,57,down,BLACKEN_SILVER,VIOLATE);
	p = getPoint(-33,0,0);
	drawDownFacePrism(p,33,57,down,BLACKEN_SILVER,VIOLATE);
	//middle row
	p = getPoint(0,0,70);
	drawDownFacePrism(p,43,76,down,BLACKEN_SILVER,VIOLATE);
	p = getPoint(43,0,57);
	drawDownFacePrism(p,33,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(-33,0,57);
	drawDownFacePrism(p,33,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	//top row
	p = getPoint(0,0,146);
	drawDownFacePrism(p,43,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(43,0,127);
	drawDownFacePrism(p,33,57,down,BLACKEN_SILVER,VIOLATE);
	p = getPoint(-33,0,127);
	drawDownFacePrism(p,33,57,down,BLACKEN_SILVER,VIOLATE);
	//boundary
	p = getPoint(-41,0,-8);
	drawDownFacePrism(p,125,270,down+1,EBONY,WOOD4);
	p = getPoint(-33,0,232);
	drawCube(p,109,4,8,VIOLATE,SOLID);
	//MIDDLE DOOR END
	//DOOR SIDE START
	// 0 degree sides  START
	p = getPoint(84,0,0);
	drawDownFacePrism(p,140,50,down,VIOLATE,EBONY);
	p = getPoint(-182,0,0);
	drawDownFacePrism(p,140,50,down,VIOLATE,EBONY);
	for(int i = 0 ; i < 3;i++)
	{
		p = getPoint(124,0,50+i*85);
		drawDownFacePrism(p,50,85,down,VIOLATE,EBONY);
		p = getPoint(174,0,50+i*85);
		drawDownFacePrism(p,50,85,down,VIOLATE,EBONY);

		p = getPoint(-182,0,50+i*85);
		drawDownFacePrism(p,50,85,down,VIOLATE,EBONY);
		p = getPoint(-132,0,50+i*85);
		drawDownFacePrism(p,50,85,down,VIOLATE,EBONY);
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
	drawCube(p,206,5,255,GREEN,SOLID);
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
	drawBox(p,470,505,200,25,VIOLATE);
	//side gap
	p = getPoint(-315,-190,-25);
	drawCube(p,100,5,600,WOOD4,SOLID);
	p = getPoint(-215,-190,475);
	drawCube(p,470,5,100,WOOD4,SOLID);
	p = getPoint(255,-190,-25);
	drawCube(p,100,5,600,WOOD4,SOLID);
}
void drawSmallDoorType1()
{
	GLdouble down = 3.0;
	Point p;
	//0 degree part
	p = getPoint(-25,0,0);
	drawDownFacePrism(p,50,90,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(-25,0,90);
	drawDownFacePrism(p,50,40,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(25,0,0);
	drawDownFacePrism(p,50,60,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(25,0,60);
	drawDownFacePrism(p,50,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(-75,0,0);
	drawDownFacePrism(p,50,60,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(-75,0,60);
	drawDownFacePrism(p,50,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	//90 degree part
	glPushMatrix();
	{
		glTranslatef(75,0,0);
		glRotatef(-90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,50,60,down,MEDIUM_WOOD,LIGHT_WOOD);
		p = getPoint(0,0,60);
		drawDownFacePrism(p,50,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	}glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(-75,0,0);
		glRotatef(90,0,0,1);
		p = getPoint(-50,0,0);
		drawDownFacePrism(p,50,60,down,MEDIUM_WOOD,LIGHT_WOOD);
		p = getPoint(-50,0,60);
		drawDownFacePrism(p,50,70,down,MEDIUM_WOOD,LIGHT_WOOD);
	}glPopMatrix();
	//arc
	glPushMatrix();
	{
		glTranslatef(-80,-50,130);
		glScalef(4.5,50,2.0);
		drawArc();
	}glPopMatrix();
	p = getPoint(-75,0,130);
	drawCube(p,150,5,60,SKY_BLUE,SOLID);
	//box
	p = getPoint(-104,-60,-25);
	drawBox(p,208,240,60,25,EARTH);
	//side
	p = getPoint(-144,-50,-25);
	drawCube(p,40,5,280,GREEN,SOLID);
	p = getPoint(104,-50,-25);
	drawCube(p,40,5,280,GREEN,SOLID);
	p = getPoint(-104,-50,215);
	drawCube(p,208,5,40,GREEN,SOLID);
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
		drawPiller(p,700,12,SKY_BLUE,VIOLATE);
		p = getPoint(144,-50,-25);
		drawPiller(p,900,12,SKY_BLUE,VIOLATE);
	}else
	{
		Point p = getPoint(-152,-50,-25);
		drawPiller(p,900,12,SKY_BLUE,VIOLATE);
		p = getPoint(144,-50,-25);
		drawPiller(p,700,12,SKY_BLUE,VIOLATE);
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
	drawDownFacePrism(p,50,90,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(-25,0,90);
	drawDownFacePrism(p,50,40,down,MEDIUM_WOOD,LIGHT_WOOD);
	p = getPoint(-25,0,130);
	drawCube(p,50,4,60,VIOLATE,SOLID);
	//45 degree section
	glPushMatrix();{
		glTranslatef(25,0,0);
		glRotatef(-45,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,84,50,down,VIOLATE,GREEN);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,84,80,down,VIOLATE,GREEN);
		p = getPoint(0,0,130);
		drawCube(p,84,4,50,WOOD4,SOLID);
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(-84,-59,0);
		glRotatef(45,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,84,50,down,VIOLATE,GREEN);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,84,80,down,VIOLATE,GREEN);
		p = getPoint(0,0,130);
		drawCube(p,84,4,50,WOOD4,SOLID);
	}glPopMatrix();
	//90 degree section
	glPushMatrix();{
		glTranslatef(84,-59,0);
		glRotatef(-90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,20,50,down,EBONY,SKY_BLUE);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,20,80,down,EBONY,SKY_BLUE);
	}glPopMatrix();
	glPushMatrix();{
		glTranslatef(-84,-79,0);
		glRotatef(90,0,0,1);
		p = getPoint(0,0,0);
		drawDownFacePrism(p,20,50,down,EBONY,SKY_BLUE);
		p = getPoint(0,0,50);
		drawDownFacePrism(p,20,80,down,EBONY,SKY_BLUE);
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
	drawBox(p,227,240,90,25,VIOLATE);
	//side
	p = getPoint(-154,-50,-25);
	drawCube(p,40,5,280,GREEN,SOLID);
	p = getPoint(114,-50,-25);
	drawCube(p,40,5,280,GREEN,SOLID);
	p = getPoint(-114,-50,215);
	drawCube(p,228,5,40,GREEN,SOLID);
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
}