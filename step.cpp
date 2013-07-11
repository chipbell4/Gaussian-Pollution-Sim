#include "includes.h"
#include "globals.h"

float gaussian(float mean, float stdDev, float x)
{
	return exp( -pow((x - mean),2.0) / (2*stdDev*stdDev) ) / 
		(stdDev *sqrt(2*PI) ) ;
}

void step()
{
	// copy grid over to old grid
	for(int i=0; i<WINDOW_DIM; i++)
	{
		for(int j=0; j<WINDOW_DIM; j++)
		{
			oldGrid[i][j] = grid[i][j];
		}
	}
	// for all cells in the grid, convolve with the REST OF THE GRID
	
	// the multiplier in the front of the integral
	float phi, dist;
	float angleG, distG, weight, distributionSum;
	for(int i=0; i<WINDOW_DIM; i++)
	{
		for(int j=0; j<WINDOW_DIM; j++)
		{
			grid[i][j] = 0;
			distributionSum = 0.0;
			for(int a=0; a<WINDOW_DIM; a++)
			{
				for(int b=0; b<WINDOW_DIM; b++)
				{
					if(j != b)
						phi = atan( (i-a)/(j-b) );
					else
						phi = PI/4;

					// now correct angle for the TRUE distance between points
					if(a < i && b>j)
						phi += PI/2;
					else if(a < i && b<j)
						phi -= PI;

					dist = sqrt( pow( (i-a), 2.0) + pow( (j-b), 2.0) ) * hD;
				
					angleG = gaussian(theta, sigma_theta, phi);
					distG =  gaussian(v/hD, sqrt(sigma_d*sigma_d/hD),
						dist);
	
					weight = angleG * distG;
					distributionSum += weight;
					grid[i][j] += oldGrid[a][b] * weight;
				}
			}
			grid[i][j] *= (1-alpha)/distributionSum;
		}
	}
}
