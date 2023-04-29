#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;

	// Write implementation here

	// File opened for reading
	FILE * inputFile=fopen(filename,"r");
	// Scans the file
	fscanf(inputFile,"%d",sizePtr);
	class_list=calloc(*sizePtr,sizeof(student));

	// Iteration for each index
	for(int i=0;i<*sizePtr;i++){
		class_list[i]=calloc(1,sizeof(student));
		fscanf(inputFile,"%d", &(class_list[i]->student_id));
		fscanf(inputFile,"%s", (class_list[i]->first_name));
		fscanf(inputFile,"%s", (class_list[i]->last_name));
	}
	fclose(inputFile);

	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	// Write implementation here
	for(int j=0;j<size;j++){
	        if(list[j]->student_id==idNo){
	            return j;
	        }
	    }
	    return -1;
}

void input_grades(char *filename, student **list, int size){
	
	// Write implementation here
	// Opens the grades file
	FILE*gradesFile=fopen(filename,"r");

	// Initializing variable
	int studentID = 0;
	for(int i=0;i<size;i++){
		fscanf(gradesFile,"%d",&studentID);
		int index=find(studentID,list,size);
		fscanf(gradesFile,"%d",&(list[index]->project1_grade));
		fscanf(gradesFile,"%d",&(list[index]->project2_grade));


	}
	// Close the file after finishing with it
	fclose(gradesFile);

}

void compute_final_course_grades(student **list, int size)
{
	// Write implementation here
	// For loops to calculate the final grade
	for(int i=0;i<size;i++){
	        list[i]->final_grade=((double)list[i]->project1_grade+(double)list[i]->project2_grade)/2.0;
	    }
}

void output_final_course_grades(char *filename, student **list, int size)
{
	// Write implementation here

	// Open file to write in
	FILE *outputfile=fopen(filename, "w");

	// Writes in the file
	fprintf(outputfile,"%d\n",size );
	for(int i=0;i<size;i++){
		fprintf(outputfile,"%d %f\n",list[i]->student_id,list[i]->final_grade );

	}
	fclose(outputfile);

}


void withdraw(int idNo, student **list, int* sizePtr){

	// Write implementation here
	int ind = find(idNo, list, *sizePtr);
	// Error statement will be printed if the index is -1
	if(ind == -1){
		printf("The ID you have entered could not be found");
	}
	else{
		free(list[ind]);
		int i;
		// Will shift each element to the left of the array
		for(i = ind + 1; i<*sizePtr; i++){
			list[i-1]=list[i];
		}
		*sizePtr -= 1;
	}
}

void destroy_list(student **list, int *sizePtr){

	// Write implementation here
	int i;
	for(i=0; i < *sizePtr; i++){
		free(list[i]);
	}
	// Deallocate memory
	free(list);
	*sizePtr = 0;

}
