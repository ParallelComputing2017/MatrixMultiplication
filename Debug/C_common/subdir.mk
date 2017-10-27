################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../C_common/device_info.c \
../C_common/wtime.c 

OBJS += \
./C_common/device_info.o \
./C_common/wtime.o 

C_DEPS += \
./C_common/device_info.d \
./C_common/wtime.d 


# Each subdirectory must supply rules for building sources it contributes
C_common/%.o: ../C_common/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/usr/local/cuda-7.5/bin/nvcc -I"/home/estudiante/Parallel Computing/opencl-workspace/MatrixDot/C_common" -G -g -O0 -std=c++11   -odir "C_common" -M -o "$(@:%.o=%.d)" "$<"
	/usr/local/cuda-7.5/bin/nvcc -I"/home/estudiante/Parallel Computing/opencl-workspace/MatrixDot/C_common" -G -g -O0 -std=c++11 --compile  -x c -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


