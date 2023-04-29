#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){
	// Initializing variables
	int limit;
	int i;
	int j;
	int ind = 0;
	// Increases a limit which counts how many diagonals have been counted
	for (limit=1; limit<(2*N3); limit++){
		// Reset at 0 after every index
		j = 0;
		// Accounts that every value in a diagonal is one row above each other
		for (i = limit-1; i>=0; i--){
			// Checks if the values are in the correct array
			if (i < N3 && j<N3){
				arr[ind] = mat[i][j];
				// Index is incremented by 1 if all the conditions are met
				ind++;
			}
			j++;
		}
	}
}
