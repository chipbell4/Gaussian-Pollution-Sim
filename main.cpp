/*
	Chip Bell
	10-22-10
	CSC 315
	Programming Assignment 2
*/

// My include stuff
#include "includes.h"
#include "constants.h"
#include "prototypes.h"

int main(int argc, char** argv)
{
	// GLUT init stuff
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_DIM, WINDOW_DIM);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Hello World");

	// Some initialization	
	init();

	// Function pointer stuff
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idleFunc);

	// enter main event loop
	glutMainLoop();

	/*for(int i=0; i<100; i++)
	{
		printf("At time value: %d\n", i);
		step();
	}
	*/
	return 0;
}
