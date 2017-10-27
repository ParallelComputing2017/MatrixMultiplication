/*
 * main.cpp
 *
 *  Created on: 27/10/2017
 *      Author: estudiante
 */
#include <stdlib.h>

#include "matrix.h"

int main(int argc, char *argv[]) {

	printf("hello 14 \n");
	float** h_a = (float**) calloc(LENGTH * LENGTH, sizeof(float));  // a vector
	float** h_b = (float**) calloc(LENGTH * LENGTH, sizeof(float));  // b vector
	float** h_c = (float**) calloc(LENGTH * LENGTH, sizeof(float));

	printf("hello 19 \n");

	randomFill(h_a);
	randomFill(h_b);
	allocateMatrix(h_c);

	printf("hello 24 \n");

	printMatrix(h_a);
	printMatrix(h_b);

	mymultiply(h_a, h_b, h_c);

	printMatrix(h_c);

	return 0;
}
