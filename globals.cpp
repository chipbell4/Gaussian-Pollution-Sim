#include "constants.h"

float h = 1/26.0;
long t1 = 0;
long t2 = 0;
long frameCount = 0;

float hD = 1;
float alpha = 0.1;
float sigma_theta = 0.5;
float sigma_d = 1.0;
float theta = 3.14159/4;
float v = WINDOW_DIM/40;
float grid[WINDOW_DIM][WINDOW_DIM];
float oldGrid[WINDOW_DIM][WINDOW_DIM];
