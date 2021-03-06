// PacmanMAIN.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h" 
#include "Niveau.h" 
#include "MrPacman.h"
// Création d’un objet de type niveau 
Niveau n(26,27, "niveau1.txt"); // colonne puis ligne
// Création d’un objet de type MrPacman
MrPacman p;
// Déclarations de fonctions 
void LabyAffichage(); 
void LabyRedim(int x, int y); 
void traitementClavier(int key, int x, int y);
void timer(int pi);

int sens = 4;
bool notouche = true;
int depX;
int depY;

int main() 
{ // Gestion de la fenêtre , postion, taille et mode affichage + titre
	glutInitWindowPosition(0, 0);  
	glutInitWindowSize(432, 520); // ligne puis colonne
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);  
	glutCreateWindow("Labyrinthe"); 

 // Appel de la fuonction LoadGLTextures qui permet d’ajouter des textures au vecteur de textures du niveau n  
	n.LoadGLTextures("textures/0.bmp");    
	n.LoadGLTextures("textures/1.bmp"); 
	n.LoadGLTextures("textures/2.bmp");
	n.LoadGLTextures("textures/3.bmp");
	n.LoadGLTextures("textures/4.bmp");
	n.LoadGLTextures("textures/5.bmp");
	n.LoadGLTextures("textures/6.bmp");
	n.LoadGLTextures("textures/7.bmp");
	n.LoadGLTextures("textures/8.bmp");
	p.LoadGLTextures("textures/11.png");
	p.LoadGLTextures("textures/12.png");
	p.LoadGLTextures("textures/13.png");
	p.LoadGLTextures("textures/14.png");
	p.LoadGLTextures("textures/15.png");



  // Gestion des événements  
	glutSpecialFunc(traitementClavier);
	glutDisplayFunc(LabyAffichage);  
	glutReshapeFunc(LabyRedim); 
	glutTimerFunc(0, timer, 0);
	glutMainLoop();
}
// Evénement d'affichage 
void LabyAffichage() 
{  
	glClearColor(1.0, 1.0, 1.0, 1.0);  
	glClear(GL_COLOR_BUFFER_BIT);  
	glMatrixMode(GL_MODELVIEW);  
	n.dessiner(); // dessin du niveau  
	p.dessiner(sens); // dessin du perso
	glFlush(); 
} 

 // Evénement de redimensionnement 
void LabyRedim(int x, int y) 
{ 
	glViewport(0, 0, x, y);  
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();  
	gluOrtho2D(0.0, (double)n.getNbColonnes(), (double)n.getNbLignes(), 0.0); 
} 

void timer(int pi)
{
			if (n.passagepossible(p.getPosX()+depX, p.getPosY()+depY) == true) // detection du mur
			{
					p.depFinal(depX, depY);
					if (n.getTypeCase(p.getPosX(), p.getPosY()) == 2) // si case = sol + point
					{
						n.setTypeCase(p.getPosX(), p.getPosY(), 0); // on transforme en sol
					}
					if (n.getTypeCase(p.getPosX(), p.getPosY()) == 4) // si case = sol + point
					{
						n.setTypeCase(p.getPosX(), p.getPosY(), 0); // on transforme en sol
						n.setTypeCase(13, 9, 0);
					}

					if (n.getTypeCase(p.getPosX(), p.getPosY()) == 5) // si case = sol + point
					{
						n.setTypeCase(p.getPosX(), p.getPosY(), 0); // on transforme en sol
						n.setTypeCase(25, 24, 7);
					}

					if (n.getTypeCase(p.getPosX(), p.getPosY()) == 7) // si case = sol + point
					{
						n.setTypeCase(p.getPosX(), p.getPosY(), 8); // on transforme en sol
					}

					glutPostRedisplay();
					
			}
			glutTimerFunc(100, timer, pi);
}



void traitementClavier(int key, int x, int y)
{
		if (key == GLUT_KEY_UP)
		{
			sens = 2;
			depX = 0;
			depY = -1;
		}

		else if (key == GLUT_KEY_DOWN)
		{
			sens = 3;
			depX = 0;
			depY =1;
		}

		else if (key == GLUT_KEY_RIGHT)
		{
			sens = 1;
			depX = 1;
			depY = 0;
		}

		else if (key == GLUT_KEY_LEFT)
		{
			sens = 0; // changement de sens
			depX = -1;
			depY = 0;
		}

}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
