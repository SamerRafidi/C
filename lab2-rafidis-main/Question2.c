#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	// Initializing variables
	int isDiag=1;
	int i;
	int j;
	int diagonal;
	int TotalSum;
	// Iterates through every row
	for (i=0; i<N2; i++){
		// resets variables after every cycle
		diagonal = 0;
		TotalSum = 0;
		// Iterates through columns of a given row
		for (j=0; j<N2; j++){
			// If J does not equal i, this means that the term was not in the row and is added to the sum
			if (j != i){
				TotalSum += fabs(mat[i][j]);
			}
		// Checks if the matrix is diagonally dominant or not
		if (TotalSum >= fabs(mat[i][i])){
			isDiag = 0;
		}
		}
	}
    return isDiag;
}
