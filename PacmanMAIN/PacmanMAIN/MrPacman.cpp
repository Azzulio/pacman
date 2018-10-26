#include "pch.h"
#include "MrPacman.h"


MrPacman::MrPacman()
{
	x =0;
	y = 11;
}

void MrPacman::depFinal(int depX, int depY)
{
	x = x + depX;
	y = y + depY;
	glutPostRedisplay();
}


void MrPacman::dessiner(int lo)
{    
				glEnable(GL_TEXTURE_2D);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glBindTexture(GL_TEXTURE_2D, texture[lo]);
				glBegin(GL_QUADS);
				glColor3d(1.0, 1.0, 1.0);
				glTexCoord2f(0.0f, 0.0f); glVertex2d(x, y+1);
				glTexCoord2f(1.0f, 0.0f); glVertex2d(x+1, y + 1);
				glTexCoord2f(1.0f, 1.0f); glVertex2d(x+1, y);
				glTexCoord2f(0.0f, 1.0f); glVertex2d(x, y);
				glEnd();
				glDisable(GL_TEXTURE_2D);
}

void MrPacman::LoadGLTextures(string name)
{
	GLuint essai = SOIL_load_OGL_texture(name.c_str(), 
		SOIL_LOAD_AUTO, 
		SOIL_CREATE_NEW_ID, 
		SOIL_FLAG_INVERT_Y);
	texture.push_back(essai);
}

int MrPacman::getPosY()
{
	return y;
}

int MrPacman::getPosX()
{
	return x;
}