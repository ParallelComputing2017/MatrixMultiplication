/*
 * matrix.h
 *
 *  Created on: 27/10/2017
 *      Author: estudiante
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>

#define LENGTH (2)

void mymultiply(float** a, float** b, float** c) {
	printf("mymultiply \n");

	for (int i = 0; i < LENGTH; i++) {

		for (int j = 0; j < LENGTH; j++) {

			for (int k = 0; k < LENGTH; k++) {

				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void allocateMatrix(float** matrix) {

	for (int i = 0; i < LENGTH; i++) {
		matrix[i] = new float[LENGTH];
		for (int j = 0; j < LENGTH; j++) {
			matrix[i][j] = 0;
		}
	}

}

void randomFill(float** matrix) {
	int count = LENGTH;
	for (int i = 0; i < count; i++) {
		matrix[i] = new float[LENGTH];
		for (int j = 0; j < count; j++) {
			matrix[i][j] = rand() / (float) RAND_MAX;
		}
	}
}

void printMatrix(float** matrix) {
	printf("matrix: \n");
	int i = 0;
	int count = LENGTH;
	for (i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			printf("%.2f  ", matrix[i][j]);
		}
		printf("\n");
	}
}

#endif /* MATRIX_H_ */
