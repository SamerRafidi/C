#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
	char *z = NULL;
	
	// Initialize variables
    int x;
    int y;

    // Finds the length of each string given
    x=strlen(str1);
    y=strlen(str2);
    z=(char *)calloc(x + y + 1,sizeof(char));

    // i keeps increasing until it reaches x which is when the first string is reached
    for(int i=0;i<x;i++){
        z[i]=str1[i];
    }

    //
    for(int i=0;i<y;i++){
        z[x+i]=str2[i];
    }
    // Assigns null character for the last index
    z[x+y+1]="\0";

    // Returns the string
	return z;
}
