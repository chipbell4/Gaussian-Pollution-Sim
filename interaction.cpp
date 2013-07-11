#include "includes.h"
#include "constants.h"
#include "globals.h"

void mouse(int button, int state, int x, int y)
{
	// handle mouse clicks
}

void keyboard(unsigned char key, int x, int y)
{
	// handle keyboard presses
	if(key == 'Q' || key == 'q')
	{
		// get time since start
		long t = glutGet(GLUT_ELAPSED_TIME);
		printf("Average FPS: %.5f\n", frameCount / (t/1000.0));
		exit(0);
	}
}
