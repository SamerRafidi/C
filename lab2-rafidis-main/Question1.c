#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
	// Initializing variable
	int i;
	for (i = 0; i < size; i++){
		// Every index for vector 3 is the sum of vector 1 and 2
		vector3[i] = vector1[i] + vector2[i];
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;
    int i;
    for (i = 0; i < size; i++){
    	// Value for the cumulative sum of vector 1 and 2 being multiplied
    	prod += vector1[i]*vector2[i];
    }
    return prod;
}
double norm2(double vector1[], int size)
{
	// Initializing variables
    double L2;
    // L2 is the square root of the scalar product of the vector chosen
    L2 = sqrt(scalar_prod(vector1, vector1, size));
    return L2;
}
