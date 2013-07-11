#include "constants.h"

// Timing variables
extern float h;
extern long t1;
extern long t2;
extern long frameCount;

// variables for the system
extern float hD; // Distance step
extern float alpha; // Pollution lost per second
extern float sigma_theta; //stddev of angular wind spread
extern float sigma_d; // std dev. of falloff curve
extern float theta; // current wind heading
extern float v; // current wind velocity
extern float grid[WINDOW_DIM][WINDOW_DIM];
extern float oldGrid[WINDOW_DIM][WINDOW_DIM];
