/*
 * main.cpp
 *
 *  Created on: 27/10/2017
 *      Author: estudiante
 */
#include <stdlib.h>

#include "matrix.h"
#include "mopencl.h"

void sequential(float* a, float* b, float* c) {
	mymultiply(a, b, c);
}

void opencl(float* a, float* b, float* c) {
	myopencl(a, b, c);
}

int main(int argc, char *argv[]) {

	M_LENGTH = 512;

	float* h_a = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float)); // a vector
	float* h_b = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float)); // b vector
	float* h_c = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float));
	float* h_s = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float));

	randomFill(h_a);
	randomFill(h_b);
	allocateMatrix(h_c);
	allocateMatrix(h_s);

	printf("hello 24 \n");

	sequential(h_a, h_b, h_s);
	printMatrix((char *) "Sequential", h_s);

	opencl(h_a, h_b, h_c);
	printMatrix((char *) "OpenCL", h_c);

	printf("Test: %s", (equal(h_s, h_c) ? "Passed" : "Failed"));

	// FREE memory

	free(h_a);
	free(h_b);
	free(h_c);

	return 0;
}

