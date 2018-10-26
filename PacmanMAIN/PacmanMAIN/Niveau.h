#pragma once 
#include "GL/glut.h" 
#include "SOIL/SOIL.h" 
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Niveau 
{ 

private:  
	int nbLignes;  
	int nbColonnes;  
	int** tableau;  
	vector<GLuint> texture; 

public:  
		 Niveau(int, int, string);    
		 void dessiner();  
		 void LoadGLTextures(string name);
		 int getNbLignes();  
		 int getNbColonnes(); 
		 bool passagepossible(int x, int y);
		 int getTypeCase(int x, int y); 
		 void setTypeCase(int x, int y, int n);
};
