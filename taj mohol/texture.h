#include <glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

GLuint textureBigDomeMain;
GLuint textureBrick;
GLuint textureDomeBaseUpper;
GLuint textureWall;
GLuint textureWhiteFloor;
GLuint textureRedFloor;

int num_texture = 0;

int loadBitmap(char *filename)
{
	int i, j=0;
	FILE *l_file;
	unsigned char *l_texture;

	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER infoheader;
	RGBTRIPLE rgb;

	num_texture++;

	if( (l_file = fopen(filename, "rb"))==NULL) return (-1);

	fread(&fileheader, sizeof(fileheader), 1, l_file);

	fseek(l_file, sizeof(fileheader), SEEK_SET);
	fread(&infoheader, sizeof(infoheader), 1, l_file);

	l_texture = (byte *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
	memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);

	for (i=0; i < infoheader.biWidth*infoheader.biHeight; i++)
	{
		fread(&rgb, sizeof(rgb), 1, l_file);

		l_texture[j+0] = rgb.rgbtRed;
		l_texture[j+1] = rgb.rgbtGreen;
		l_texture[j+2] = rgb.rgbtBlue;
		l_texture[j+3] = 255;
		j += 4;
	}
	fclose(l_file);

	glBindTexture(GL_TEXTURE_2D, num_texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);

	// glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);

	free(l_texture);

	printf("%d\n", num_texture);

	return (num_texture);
}


void initBitmaps() {
	textureBigDomeMain = loadBitmap("textures/big_dome_main.bmp");
	textureBrick = loadBitmap("textures/brick.bmp");
	textureDomeBaseUpper = loadBitmap("textures/dome_base_upper.bmp");
	textureWall = loadBitmap("textures/wall.bmp");
	textureWhiteFloor = loadBitmap("textures/whiteFloor.bmp");
	textureRedFloor = loadBitmap("textures/redFloor.bmp");
}