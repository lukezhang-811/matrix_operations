#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// initialize the global variables
#define rows 5
#define cols 5

void fillMatrix(int matrix[rows][cols]) {
	// makes sure that rand() works
	srand(time(NULL));
	// using a nested forloop to fill the matrix with random int
	for(int i=0; i<rows; i++) {
		for(int j=0; j<cols; j++) {
			matrix[i][j] = rand()%100+1;
		}
	}
}

void printMatrix(int matrix[rows][cols]) {
	// using a nested forloop to print out each element of the matrix
	// prints a "[" and "]" to close each row of the matrix
	for(int i=0; i<rows; i++) {
		printf("[");
		for(int j=0; j<cols; j++) {
			printf(" %d ", matrix[i][j]);
		}
		printf("]");
		printf("\n");
	}
	printf("\n");
}

void transposeMatrix(int matrix[rows][cols]) {
	// using a nested forloop to initialze a temp variable to store the info of the original matrix
	// then transfer the that data to the transposed position on the matrix
	for(int i=0; i<rows; i++) {
		for(int j=0; j<i; j++) {
			int temp = *(*(matrix+i)+j);
			*(*(matrix+i)+j) = *(*(matrix+j)+i);
			*(*(matrix+j)+i) = temp;
		}
	}
}

void multiplyMatrix(int m1[2][cols], int m2[rows][cols], int resultMatrix[rows][cols]) {
	// using a nested forloop to initialize all resultMatrix elements as 0
	for(int l=0; l<rows; l++) {
		for(int h=0; h<cols; h++) {
			resultMatrix[l][h] = 0;
		}
	}
	// using a nested forloop with an additional forloop to calculate each element of resultMatrix
	for(int i=0; i<2; i++) {
		for(int j=0; j<cols; j++) {
			for(int k=0; k<cols; k++) {
				resultMatrix[i][j] += m1[i][k]*m2[k][j];
			}
		} 
	}
}


int main() {
	int matrix[rows][cols];
	fillMatrix(matrix);
	printMatrix(matrix);
	
	transposeMatrix(matrix);
	printMatrix(matrix);

	int matrix2[2][cols]={0,1,2,3,4,5,6,7,8,9};
 	int matrixResult[rows][cols];
 	
	multiplyMatrix(matrix2, matrix, matrixResult);
 	printMatrix(matrixResult);
 	
	return 0;
}

// Name: Luke Zhang
// ID: 260771133
