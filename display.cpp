#include "includes.h"
#include "constants.h"
#include "globals.h"
#include "prototypes.h"

void printGrid()
{
	for(int i=0; i<WINDOW_DIM; i++)
	{
		for(int j=0; j<WINDOW_DIM; j++)
			printf("%.3f ", grid[i][j]);
		puts("");
	}
	puts("");
}

void idleFunc()
{
	// set timing
	t2 = glutGet(GLUT_ELAPSED_TIME);
	float fps = 1;
	if(t1 != t2)
		fps = 1000.0/(t2-t1);

	// adjust time step
	//h = 1/fps;
	t1 = t2;

	// step through system if nescessary
	step();	

	// post to redraw
	glutPostRedisplay();
	
	// another frame drawn
	frameCount++;
}

void init()
{
	// Clear to a white screen
	glClearColor(1.0,1.0,1.0,1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (float) WINDOW_DIM,
		0.0, (float) WINDOW_DIM);
	glMatrixMode(GL_MODELVIEW);

	// Initialize Grid
	int midLeft = CENTER_PT - WINDOW_DIM/8;
	int midRight = CENTER_PT + WINDOW_DIM/8;
	for(int i=midLeft; i<midRight; i++)
	{
		for(int j=midLeft; j<midRight; j++)
		{
			grid[i][j] = 1.0;
		}
	}
}

void display()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 0.0, 1.0);
	glPointSize(10);
	// Draw code here
	glBegin(GL_POINTS);
	for(int i=0; i<WINDOW_DIM; i++)
		for(int j=0; j<WINDOW_DIM; j++)
		{
			glColor3f(grid[i][j], grid[i][j], grid[i][j]);
			glVertex2f(i, j);
		}
	glEnd();

	glutSwapBuffers();
}
