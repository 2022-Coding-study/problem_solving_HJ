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
void matrixMultiple(int** a, int** b, int** x, int r, int c) {
	int i, j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			x[i][j] = a[i][j] * b[i][j];
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
void transMatrix(int** a, int r, int c);
int main(void)
{
	int** A, ** B, ** X, **T;
	int r1, c1, r2, c2, i;

	printf("Enter 행렬 A의 행과 열의 개수:\n");
	scanf("%d %d", &r1, &c1);

	printf("Enter 행렬 C의 행과 열의 개수<C의 행은 4이어야>:\n");
	scanf("%d %d", &r2, &c2);

	A = (int**)malloc(sizeof(int*) * r1);
	B = (int**)malloc(sizeof(int*) * r2);
	X = (int**)malloc(sizeof(int*) * r1);

	for (i = 0; i < r1; i++) {
		A[i] = (int*)malloc(sizeof(int) * c1);
		X[i] = (int*)malloc(sizeof(int) * c2);
	}
	for (i = 0; i < r2; i++) {
		B[i] = (int*)malloc(sizeof(int) * c2);
	}

	printf("\n%d x %d 행렬 A 입력:\n", r1, c1);
	readMatrix(A, r1, c1);
	printf("\n%d x %d 행렬 C 입력:\n", r2, c2);
	readMatrix(B, r2, c2);

	printf("행렬곱:\n");
	matrixMultiple(A, B, X, r1, c2);
	printMatrix(X, r1, c2);

	for (i = 0; i < r1; i++) {
		free(A[i]);
		free(X[i]);
	}
	for (i = 0; i < r2; i++) {
		free(B[i]);
	}

	free(A);
	free(B);
	free(X);

	return 0;

}