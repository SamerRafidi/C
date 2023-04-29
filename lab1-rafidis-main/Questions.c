
#include "Questions.h"



int Q1_for(){
	// Initializing sum
	int sum = 0;
	// For loop that iterates between 30 to 1000
	for (int i=30; i<=1000; i++){
		if (i % 4 == 0)
			sum += i; // Adding i to the sum if it is a multiple of 4

	}
	return sum;
}
int Q1_while(){
	// Initializing sum and i
	int sum = 0;
	int i = 30;
	// While loop that stops once i reaches 1000
	while (i <= 1000){
		if (i % 4 == 0)
			sum += i; // Adding i to the sum if it is a multiple of 4
			i++;

	}
	return sum;
}

int Q1_do(){
	// Initializing sum and i
	int sum = 0;
	int i = 30;
	do
	{
		if (i % 4 == 0)
			sum += i; // Adding i to the sum if it is a multiple of 4
			i++;

	}
	// While loop that stops once i reaches 1000
	while (i <= 1000);
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	// Initializing variable that determines whether or not the input is 5 digits long
	int IsFiveDigit = 0;
	// Checks if any positive integers are five digits
	if (((Q2_input / 10000) >= 1) && ((Q2_input / 10000) <= 10)){
		// Sets our variable to 1 if the input is 5 digits long
		IsFiveDigit = 1;
	}
	// Checks if any negative integers are five digits
	else if (((Q2_input / 10000) <= -1) && ((Q2_input / 10000) >= -10)){
		IsFiveDigit = 1;
	}
	else{
		// Sets out variable to 0 if the input is not 5 digits long
		IsFiveDigit = 0;
	}
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	// Initializing GPA
	float GPA;
	// Many if, else if, and else statements that depend on the value of the input
	if (Q3_input >= 90 && Q3_input <= 100){
		GPA = 4;
	}
	else if (Q3_input >= 80 && Q3_input < 90){
		GPA = 3;
	}
	else if (Q3_input >= 70 && Q3_input < 80){
		GPA = 2;
	}
	else if (Q3_input >= 60 && Q3_input < 70){
		GPA = 1;
	}
	else if (Q3_input >= 0 && Q3_input < 60){
		GPA = 0;
	}
	else{
		GPA = -1;
	}
	return GPA;
}
//===============================================================================================
double Q4(int Q4_input){
	// Initializing pi and i
	double pi=0;
	int i;
	// For loop that runs until the input is reached.
	for (i=0;i<Q4_input;i++){
		// Equation for our infinite series
		pi+=(4.0/(2*i+1))*(-1+2*((i+1)%2));
	}
	return pi;
}
//===============================================================================================
int Q5(){
	// Initializing our variables
	int totNumTribles=0;
	int hyp;
	int side1;
	int side2;
	// Many for loops to ensure that my 3 sides follow the pythagorean rules as well as ensuring that we stop at the value of 400.
	for (hyp=1;hyp<=400;hyp++){
		for(side2=1;side2<=hyp;side2++){
			for(side1=1;side1<=side2;side1++){
				// If statements checks if the given sides are a pythagorean triple. This will increase the counter.
				if (hyp*hyp == side1*side1 + side2*side2){
					totNumTribles++;
				}

			}
		}
	}
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
		// Initializing variables
	    int counts=0;
	    int x;
	    int y;
	    int sumOfNumber;
	    for (x = 1; x< Q6_input; x++){
	    	sumOfNumber = 0;
	    	// This for loop checks for all the numbers to see if they are factors
	    	for (y = 1; y < x; y++){
	    		if (x % y == 0){
	    			sumOfNumber += y; // If a number is a factor, it is added to the sum of the perfect number
	    		}

	    	}
	    	// If the number is a perfect number, it is added to the array and the count is incremented by 1
	    	if (sumOfNumber == x){
	    		perfect[counts]=x;
	    		counts++;
	    	}

	    }

	   return counts;
}
//===============================================================================================
int Q7a(int Q7_input){
	// Initializing variables
	int reversedInt=0;
	int IsSevenDigit = 0;
	// Checks if the input is 7 digits.
	if (((Q7_input / 1000000) >= 1) && ((Q7_input / 1000000) <= 10)){
		IsSevenDigit = 7;
	}
	else{
		IsSevenDigit = 0;
	}
	// If the number is 7 digits, the number goes through the while loop
	if (IsSevenDigit == 7){
		while (Q7_input != 0){
			// Multiply by 10 to leave a 0 at the end which gives space to the upcoming value
			reversedInt = reversedInt*10;
			// Formula helps reverse the digits
			reversedInt = reversedInt + Q7_input%10;
			Q7_input = Q7_input/10;
		}
	}
	return reversedInt;
	
}
int Q7b(int Q7b_input){
	// Initializing variable
	int reversedInt=0;
	while (Q7b_input != 0){
		// Multiply by 10 to leave a 0 at the end which gives space to the upcoming value
		reversedInt = reversedInt*10;
		// Formula helps reverse the digits
		reversedInt = reversedInt + Q7b_input%10;
		Q7b_input = Q7b_input/10;
	}
	return reversedInt;
}
