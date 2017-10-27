/*
 * matrix.h
 *
 *  Created on: 27/10/2017
 *      Author: estudiante
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>

#define LENGTH (10)

void multiply(float** a, float** b, float** c) {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j) {
			for (int k = 0; k < LENGTH; k) {
				c[i][j] += a[i][k] * b[k][j];
			}
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
