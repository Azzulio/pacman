#pragma once 
#include "GL/glut.h" 
#include "SOIL/SOIL.h" 
#include <vector>
#include <iostream>
#include <string>
#include "pch.h" 
#include "Niveau.h"
#include "fstream"


Niveau::Niveau(int l, int c, string chemin) 
{
	nbLignes = l;  
	nbColonnes = c;  
	tableau = new int*[l];  
	for (int i = 0; i < l; i++) tableau[i] = new int[c];
	
	ifstream fichier(chemin, ios::in);    
	if (fichier) 
	{ 
		int i = 0;  
		string ligne;    
		while (getline(fichier, ligne)) 
		{ 
			for (int j = 0; j < nbColonnes; j++)  tableau[i][j] = ligne[j] - 48;    i++; 
		}   
		fichier.close(); }

	else cerr << "Impossible d'ouvrir le fichier !" << endl;
}
void Niveau::dessiner() {
	int i = 0, j = 0;  
	for (i = 0; i < nbColonnes; i++)
	{
		for (j = 0; j < nbLignes; j++)
		{
			switch (tableau[j][i]) 
			{
				case 0: // sol     
					glEnable(GL_TEXTURE_2D);     
					glBindTexture(GL_TEXTURE_2D, texture[0]);     
					glBegin(GL_QUADS);     
					glColor3d(1.0, 1.0, 1.0);     
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j);     
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j);     
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j + 1);     
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j + 1);     
					glEnd();     
					glDisable(GL_TEXTURE_2D);     
					break; 
				case 1: // mur     
					glEnable(GL_TEXTURE_2D); 
					glBindTexture(GL_TEXTURE_2D, texture[1]);     
					glBegin(GL_QUADS);     
					glColor3d(1.0, 1.0, 1.0);     
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();     
					glDisable(GL_TEXTURE_2D);     
					break;
				case 2: // sol + point
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[2]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0);
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
				case 3: // Porte ennemi
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[3]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0); 
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j+1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j+1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j );
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j );
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
				case 4: // Pass
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[4]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0);
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
				case 5: // Clé
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[5]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0);
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
				case 6: // Coffre fermé
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[6]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0);
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
				case 7: // Coffre ouvert plein
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[7]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0);
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
				case 8: // Coffre ouvert vide
					glEnable(GL_TEXTURE_2D);
					glBindTexture(GL_TEXTURE_2D, texture[8]);
					glBegin(GL_QUADS);
					glColor3d(1.0, 1.0, 1.0);
					glTexCoord2f(0.0f, 0.0f); glVertex2d(i, j + 1);
					glTexCoord2f(1.0f, 0.0f); glVertex2d(i + 1, j + 1);
					glTexCoord2f(1.0f, 1.0f); glVertex2d(i + 1, j);
					glTexCoord2f(0.0f, 1.0f); glVertex2d(i, j);
					glEnd();
					glDisable(GL_TEXTURE_2D);
					break;
			}
		}
	}
}

void Niveau::LoadGLTextures(string name) 
{ 
	GLuint essai = SOIL_load_OGL_texture(name.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);  
	texture.push_back(essai); 
}

int Niveau::getNbLignes() 
{ 
	return nbLignes; 
}

int Niveau::getNbColonnes() 
{
	return nbColonnes;
}

bool Niveau::passagepossible(int x, int y)
{
	if (tableau[y][x] !=1 && tableau[y][x] != 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Niveau::getTypeCase(int x, int y)
{
	return tableau[y][x];
}

void Niveau::setTypeCase(int x, int y, int n)
{
	tableau[y][x]=n;
}