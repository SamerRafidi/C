#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	// Initalize variables
	int i;
	int j;
	int ind = 0;
	int prev = -1;
	int same_value;
	// Iterate through terms in pos1
	for(i=0; i<k1; i++){
		// Variable which tracks any values that are the same
		same_value = 0;
		// Iterate through terms in pos2
		for(j=0; j<k2; j++){
			// Checks if any terms in pos1 = any terms in pos2
			if (pos1[i] == pos2[j]){
				// Triggers the value to 1 if there any of the same terms
				same_value = 1;
				prev = pos1[i];
				// Next condition which is met if the sum of the values is not 0.
				if (val1[i]+val2[j]!=0){
					// If the condition is met, that value will be added to val3 and pos3
					val3[ind] = val1[i]+val2[j];
					pos3[ind] = pos1[i];
					ind++;
				}
				break;
			}
			// Second condition if the first one isn't met from the start. This checks if pos2 is smaller than pos1 AND pos2 is greater than the previous numbers
			if (pos2[j] < pos1[i] && pos2[j]>prev){
				// If condition is met, the current value will be set as the previous one.
				prev = pos2[j];
				val3[ind] = val2[j];
				pos3[ind] = pos2[j];
				ind++;
			}

		}
		// Third condition if no conditions are met. This happens once we see that there are no smaller numbers and there are no similar values.
		if (same_value == 0){
			prev == pos1[i];
			val3[ind] = val1[i];
			pos3[ind] = pos1[i];
			ind++;
		}
		// More conditions check for any pos1 values that might fit.
		if (i == k1-1){
			// Iterates through all of the values in pos2.
			for(j=0; j<k2; j++){
				if (pos2[j]>prev){
					val3[ind] = val2[j];
					pos3[ind] = pos2[j];
					ind++;
					prev = pos2[j];
				}
			}
		}
	}
}
