// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include <GL/freeglut.h>         //lädt alles für OpenGL
#include "Wuerfel.h"

float fRotation = 315.0;

void Init()	
{
   // Hier finden jene Aktionen statt, die zum Programmstart einmalig 
   // durchgeführt werden müssen
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);

}

void RenderScene() //Zeichenfunktion
{	
	
	glClearColor(1.0, 0.5, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glClear(GL_COLOR_BUFFER_BIT);
   // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
   glLoadIdentity ();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
   

   
   //eVerschiebe Würfel um Eins auf der Z-Achse
  // glTranslatef(0., 0., -1.); // Transformation
  
   glutWireCube(0.2);

   glRotatef(fRotation, 1, 1, 0);
   glRotatef(-45, 0, 0, 1);
   
   

   glPushMatrix();
   glScalef(1.5, 1., 1.);
   Wuerfel(0.4);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(-1.2, 0.,1.);
   glScalef(1.5, 0.6, 1);
   glTranslatef(1.2, 0., - 1.);
   Wuerfel(0.4);
   glPopMatrix();
  
   

   //glPushMatrix();
   //glScalef(1.3, 1., 1.);
   ////glRotatef(40, 1., 1., 1.);
   //Wuerfel(0.4);
   //glPopMatrix();

   //Würfel von vorne
   //        x   y   z
   gluLookAt(0., 0., 1.,	// Kamera-Position
   		   0., 0., 0.,	// Betrachtete Position 
   	       0., 1., 0.);	// Kamera-View-Up-Vektor

   
  // Wuerfel(0.4);
   glutSwapBuffers();



   //Aufgabe 11a - vorne oben
   /*gluLookAt(0., 1., 1.,	
			 0., 0., 0.,	
			 0., 1., 0.);
   */

   //Aufgabe 11b - Szene von rechts
   /*gluLookAt(1., 0., 0.,
	   0., 0., 0.,
	   0., 1., 0.);
   */

   //Aufgabe 11c - Szene von rechts oben
  /* gluLookAt(1., 1., 0.,
	   0., 0., 0.,
	   0., 1., 0.);
  */

  

}

void Reshape(int width,int height)
{
   // Hier finden die Reaktionen auf eine Veränderung der Größe des 
   // Graphikfensters statt

	//Matrix für Transformation: Frustum->viewport
	glMatrixMode(GL_PROJECTION);
	//Aktuelle Transformations-Matrix zuruecksetzen
	glLoadIdentity();
	//Viewport definieren
	glViewport(0, 0, width, height);
	//Frustum definieren (siehe unten)
	glOrtho(-2., 2, -2., 2., -1.0, 1.0); //Sichtbereich der Kamera -> -1 bis 1 in x-Richtung, -1 bis 1 in y-Richtung usw.

	//Aufgabe 11a)
	//glOrtho(-1., 1., -1., 1., 0.0, 3.0);

	//Aufgabe 11b)
	//glOrtho(-1., 1., -1., 1., -3.0, 3.0);

	//gluPerspective(senk. Oeffnungsw., Seitenverh., zNear, zFar);
	//gluPerspective(45, 1., 0.1, 2.0);

	


	//Matrix für Modellierung/Viewing
	glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)    
{
   // Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
   // erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
   // 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
   // inkrementiert und dem Callback wieder uebergeben. 
   std::cout << "value=" << value << std::endl;

   fRotation = fRotation - 1.0;
   if (fRotation <= 0.0) {
	   fRotation = fRotation + 360.0;
   }

   // RenderScene aufrufen
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
   glutInit( &argc, argv );                // GLUT initialisieren
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize( 600, 600 );         // Fenster-Konfiguration
   glutCreateWindow( "Fatih Mehmet Kilinc; Celal Virit" );   // Fenster-Erzeugung
   glutDisplayFunc( RenderScene );         // Zeichenfunktion bekannt machen
   glutReshapeFunc( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
   glutTimerFunc( 10, Animate, 0);
   Init();
   glutMainLoop();
   return 0;
}
