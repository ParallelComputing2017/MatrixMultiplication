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

void printLog(long matrix_size, cpu_timer s_timer, cpu_timer o_timer,
		cpu_timer ocl_tv_timer, cpu_timer ocl_shm_timer, bool test) {
	string sequential = s_timer.format(6, "%ws");
	string ocl_simple = o_timer.format(6, "%ws");
	string ocl_tv = ocl_tv_timer.format(6, "%ws");
	string ocl_shm = ocl_shm_timer.format(6, "%ws");
	string result = test ? "Passed" : "Failed";

	printf("%ld \t %s \t %s \t", matrix_size, sequential.c_str(),
			ocl_simple.c_str());
	printf("%s \t", ocl_tv.c_str());
	printf("%s \t", ocl_shm.c_str());

	printf("%s \t", result.c_str());
	printf("\n");
}

int main(int argc, char *argv[]) {

	for (int i = 2048; i <= 2048; i *= 2) {

		bool result = true;

		M_LENGTH = i;

		cpu_timer sequential_timer;
		cpu_timer opencl_timer, ocl_tv_timer, ocl_shm_timer;

		float* h_a = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float)); // a vector
		float* h_b = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float)); // b vector
		float* h_c = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float));
		float* h_s = (float*) calloc(M_LENGTH * M_LENGTH, sizeof(float));

		randomFill(h_a);
		randomFill(h_b);
		zeroFill(h_c);
		zeroFill(h_s);

		sequential_timer.start();

		mymultiply(h_a, h_b, h_s);

		sequential_timer.stop();
		//printMatrix((char *) "Sequential", h_s);

		opencl_timer.start();
		myopencl_simple(h_a, h_b, h_c);
		opencl_timer.stop();
		//printMatrix((char *) "OpenCL", h_c);

		result = result && equal(h_s, h_c);

		// OPENCL WITH TEMP VAR
		zeroFill(h_c);
		ocl_tv_timer.start();
		myopencl_temp_var(h_a, h_b, h_c);
		ocl_tv_timer.stop();

		result = result && equal(h_s, h_c);

		// OPENCL WITH shared memory
		zeroFill(h_c);
		ocl_shm_timer.start();
		myopencl_shared_memory(h_a, h_b, h_c);
		ocl_shm_timer.stop();

		result = result && equal(h_s, h_c);

		printf(
				"m_size \t sequential \t ocl_simple \t oclTempVar \t oclSharedMem \t test \n");
		printLog(M_LENGTH, sequential_timer, opencl_timer, ocl_tv_timer,
				ocl_shm_timer, result);

		// FREE memory

		free(h_a);
		free(h_b);
		free(h_c);
	}

	return 0;
}

