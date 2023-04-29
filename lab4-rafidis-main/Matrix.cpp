
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){
// Initialize variable
	rowsNum = row;
	colsNum = col;
	// Setting row and column to equal 3 if they are less than 0
	if (row <= 0){
		rowsNum = 3;
	}
	if (col <= 0){
		colsNum = 3;
	}
	// memory for matrixData
	matrixData = NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	for (int i=0; i < rowsNum; i++){
		matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	}
	// for loop that constructs a matrix with 0s
	for (int i=0; i < rowsNum; i++){
		for (int j = 0; j < colsNum; j++){
			matrixData[i][j] = 0;
		}

	}

}

Matrix::Matrix(int row, int col, int** table){
	// Initialize variables
	rowsNum = row;
	colsNum = col;
	matrixData = NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));
	for (int i=0; i < rowsNum; i++){
		matrixData[i] = (int*)malloc(colsNum*sizeof(int));
		for (int j = 0;j < colsNum; j++){
			matrixData[i][j] = table[i][j];
		}
	}
}

int Matrix::getElement(int i, int j){
	int element;
	// Checks if the row or column are in the index
	if (i<0 || i > rowsNum || j < 0 || j>colsNum){
		throw std::out_of_range("Invalid indexes.");
	}
	// Element is set to i and j if the condition above is not met
	else{
		element = matrixData[i][j];
	}

		return element;
}

bool Matrix::setElement(int x, int i, int j){
	// Checks if i and j are valid indices for the row and column
	if (i <= rowsNum || j<= colsNum){
		matrixData[i][j] = x;
		return true;
	}
    return false;
}


Matrix Matrix::copy(){
    Matrix copy=  Matrix(rowsNum,colsNum, matrixData);
    return  copy;
}


void Matrix::addTo( Matrix m ){
	// Checks if the rows and columns have the same numbers.
	if (m.getsizeofrows() != rowsNum || m.getsizeofcols() != colsNum){
		throw std::invalid_argument("Invalid operation");
	}
	else{
		for(int i = 0; i < rowsNum; i++){
			for (int j = 0; j < colsNum; j++){
				setElement(m.getElement(i,j) + matrixData[i][j],i,j);
			}
		}
	}
}


Matrix Matrix::subMatrix(int i, int j){

	Matrix subM = Matrix(i,j);
	if (i<0 || i > rowsNum || j < 0 || j > colsNum){
		throw std::out_of_range("Submatrix not defined");
	}
	else{
		Matrix subM(i+1, j+1, matrixData);
		return subM;
	}
    return  subM;
}


int Matrix::getsizeofrows(){
	return rowsNum;
}


int Matrix::getsizeofcols(){
    return colsNum;
}


bool Matrix::isUpperTr(){
	// For loop used to iterate through the matrix
	for (int i = 0; i < rowsNum; i++){
		for (int j = i + 1; j < rowsNum; j++){
			// If statement used to check if the diagonal is non-zero
			if (matrixData[j][i] != 0){
				return false;
			}
		}
	}
	return true;
}

string Matrix::toString(){
	string output="";
	for (int i = 0; i < rowsNum; i++){
		for (int j = 0; j < colsNum; j++){
			// For loop used to add each row as a string
			output += to_string(getElement(i,j)) + " ";
		}
		output += "\n";
	}
	//return output;
	 return output;
}
