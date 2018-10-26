#pragma once
#include "GL/glut.h" 
#include "SOIL/SOIL.h" 
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class MrPacman
{
private:
	int x;
	int y;
	vector<GLuint> texture;
public:
	MrPacman();
	void depFinal(int depX, int depY);
	void dessiner(int lo);
	void LoadGLTextures(string name);
	int getPosY();
	int getPosX();
};

