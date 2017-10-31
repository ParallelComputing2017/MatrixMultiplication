/*
 * matrix.h
 *
 *  Created on: 27/10/2017
 *      Author: estudiante
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>
#include <math.h>

#define TOLERANCE    (0.001)   // tolerance used in floating point comparisons

long M_LENGTH = 2;

void mymultiply(float* a, float* b, float* c) {
	printf("mymultiply %lu \n", M_LENGTH);

	for (int i = 0; i < M_LENGTH; i++) {

		for (int j = 0; j < M_LENGTH; j++) {

			for (int k = 0; k < M_LENGTH; k++) {

				c[i * M_LENGTH + j] += a[i * M_LENGTH + k] * b[k * M_LENGTH + j];
			}
		}
	}
}

void allocateMatrix(float* matrix) {

	for (int i = 0; i < M_LENGTH; i++) {
		for (int j = 0; j < M_LENGTH; j++) {
			matrix[i * M_LENGTH + j] = 0;
		}
	}

}

void randomFill(float* matrix) {

	for (int i = 0; i < M_LENGTH; i++) {
		for (int j = 0; j < M_LENGTH; j++) {
			matrix[i * M_LENGTH + j] = rand() / (float) RAND_MAX;
		}
	}
}

void printMatrix(char* name, float* matrix) {
	printf("Matrix %s: \n", name);

	for (int i = 0; i < M_LENGTH; i++) {
		for (int j = 0; j < M_LENGTH; j++) {
			printf("%.2f  ", matrix[i * M_LENGTH + j]);
		}
		printf("\n");
	}
}

bool equal(float* a, float* b) {

	for (int i = 0; i < M_LENGTH; i++) {
		for (int j = 0; j < M_LENGTH; j++) {

			float a_element = a[i * M_LENGTH + j];
			float b_element = b[i * M_LENGTH + j];
			double diff = fabs(a_element - b_element);

			if (diff > TOLERANCE) {
				printf("(%i, %i) %.15f != %.15f  diff: %.15f\n", i, j, a_element, b_element,
						diff);
				return false;
			}
		}
	}
	return true;
}

#endif /* MATRIX_H_ */
