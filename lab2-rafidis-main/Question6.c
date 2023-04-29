#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	// Initialize variables
	int i;
	int ind = 0;
	for (i=0; i<size; i++){
		// Checks for non-zero values only to store.
		if (source[i]!= 0){
			val[ind] = source[i];
			pos[ind] = i;
			// Counts the amount of non-zero values
			ind++;
		}
	}
}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	int i;
	int j = 0;
	for (i=0; i<m; i++){
		// If i equals ind, then the source takes the value of ind
		if (i==pos[j]){
    		source[i]=val[j];
    		j++;
		}
	// If the conditions aren't met, the value will be 0
		else
		source[i]=0;
	}
}
