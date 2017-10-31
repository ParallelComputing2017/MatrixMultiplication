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

void mymultiply(float* a, float* b, float* c) {
	printf("mymultiply \n");

	for (int i = 0; i < LENGTH; i++) {

		for (int j = 0; j < LENGTH; j++) {

			for (int k = 0; k < LENGTH; k++) {
				int row = i * LENGTH;
				int column = j;
				c[row + column] += a[i * LENGTH + k] * b[k * LENGTH + j];
			}
		}
	}
}

void allocateMatrix(float* matrix) {

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			matrix[i * LENGTH + j] = 0;
		}
	}

}

void randomFill(float* matrix) {
	int count = LENGTH;
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			matrix[i * LENGTH + j] = rand() / (float) RAND_MAX;
		}
	}
}

void printMatrix(char* name, float* matrix) {
	printf("Matrix %s: \n", name);

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			printf("%.2f  ", matrix[i * LENGTH + j]);
		}
		printf("\n");
	}
}

#endif /* MATRIX_H_ */
