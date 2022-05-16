# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void readMatrix(int** a, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
}
void matrixAdd(int** a, int** b, int** x, int r, int c) { 
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			x[i][j]=a[i][j]+b[i][j];
		}
	}
}
void printMatrix(int** a, int r, int c) { 
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{
	int** A, ** B, ** X;
	int r, c, i;

	scanf("%d %d", &r, &c);

	A = (int**)malloc(sizeof(int*) * r);
	B = (int**)malloc(sizeof(int*) * r);
	X = (int**)malloc(sizeof(int*) * r);

	for (i = 0; i < r; i++) {
		A[i] = (int*)malloc(sizeof(int) * c);
		B[i] = (int*)malloc(sizeof(int) * c);
		X[i] = (int*)malloc(sizeof(int) * c);
	}

	readMatrix(A, r, c);
	readMatrix(B, r, c);

	printMatrix(A, r, c);
	printf("\n");
	printMatrix(B, r, c);
	printf("\n");

	matrixAdd(A, B, X, r, c);
	printMatrix(X, r, c);

	for (i = 0; i < r; i++) {
		free(A[i]);
		free(B[i]);
		free(X[i]);
	}

	free(A);
	free(B);
	free(X);

	return 0;

}