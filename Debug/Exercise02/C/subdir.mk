################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Exercise02/C/vadd_c.c 

OBJS += \
./Exercise02/C/vadd_c.o 

C_DEPS += \
./Exercise02/C/vadd_c.d 


# Each subdirectory must supply rules for building sources it contributes
Exercise02/C/%.o: ../Exercise02/C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/usr/local/cuda-7.5/bin/nvcc -I"/home/estudiante/Parallel Computing/opencl-workspace/Vadd/C_common" -G -g -O0 -std=c++11   -odir "Exercise02/C" -M -o "$(@:%.o=%.d)" "$<"
	/usr/local/cuda-7.5/bin/nvcc -I"/home/estudiante/Parallel Computing/opencl-workspace/Vadd/C_common" -G -g -O0 -std=c++11 --compile  -x c -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


