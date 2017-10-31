/*
 * main.cpp
 *
 *  Created on: 27/10/2017
 *      Author: estudiante
 */
#include <stdlib.h>
#include <string.h>

#include <boost/timer/timer.hpp>

#include "matrix.h"
#include "mopencl.h"

using namespace std;
using namespace boost::timer;

void sequential(float* a, float* b, float* c) {
	mymultiply(a, b, c);
}

void opencl(float* a, float* b, float* c) {
	myopencl(a, b, c);
}

void printLog(long matrix_size, cpu_timer s_timer, cpu_timer o_timer,
		bool test) {
	string s_time = s_timer.format(3, "%ws");
	string o_time = o_timer.format(3, "%ws");
	string result = test ? "Passed" : "Failed";
	printf("%ld \t %s \t %s \t %s \n", matrix_size, s_time.c_str(),
			o_time.c_str(), result.c_str());
}

int main(int argc, char *argv[]) {

	M_LENGTH = 256;

	cpu_timer sequential_timer;
	cpu_timer opencl_timer;

	float* h_a = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float)); // a vector
	float* h_b = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float)); // b vector
	float* h_c = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float));
	float* h_s = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float));

	randomFill(h_a);
	randomFill(h_b);
	allocateMatrix(h_c);
	allocateMatrix(h_s);

	printf("hello 24 \n");

	sequential_timer.start();

	sequential(h_a, h_b, h_s);

	sequential_timer.stop();
	//printMatrix((char *) "Sequential", h_s);

	opencl_timer.start();

	opencl(h_a, h_b, h_c);

	opencl_timer.stop();
	//printMatrix((char *) "OpenCL", h_c);

	bool result = equal(h_s, h_c);
	printf("Test: %s \n", (result ? "Passed" : "Failed"));

	printLog(M_LENGTH, sequential_timer, opencl_timer, result);

	// FREE memory

	free(h_a);
	free(h_b);
	free(h_c);

	return 0;
}

