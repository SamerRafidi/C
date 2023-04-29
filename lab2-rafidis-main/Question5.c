#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

int length(const char source[]){
	int i;
	// Processes the source till NULL is reached which is at 0.
	for (i=0; source[i]!= 0; i++){
	}
	return i;
}

void string_copy(const char source[], char destination[], int n){
	// Initalize variables
	int i;
	for (i=0; i<n-1; i++){
		// Need to break the loop so i isn't bigger than n.
		if (i==length(source)){
			break;
		}
		destination[i]=source[i];
	}
	// Null character is added to destination if the requirements are not met
	destination[i]=0;
}
