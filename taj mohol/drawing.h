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
	drawCube(t,length-side*2,1,width-side*2,rf,gf,bf,SOLID);
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
}
void drawFrontPanel()
{
	drawFrontDoor();
}