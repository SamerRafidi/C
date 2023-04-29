#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Questions.h"

void letter_freq(const char word[], int freq[]){
	// Initializing variables
	int i;
	//
	for (i=0; i<26; i++){
		freq[i]=0;
	}
	// For every letter, the frequency is increased
	for (i=0; i<strlen(word); i++){
		if (word[i]>=65 && word[i] <= 90){
			freq[word[i]-65]++;
		}
		if (word[i]>=97 && word[i] <= 122){
			freq[word[i]-97]++;
		}
	}
}
