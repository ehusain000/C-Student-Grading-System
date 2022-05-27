################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Husain\ Eftekher\ HomeWork2.cpp \
../src/student.cpp 

OBJS += \
./src/Husain\ Eftekher\ HomeWork2.o \
./src/student.o 

CPP_DEPS += \
./src/Husain\ Eftekher\ HomeWork2.d \
./src/student.d 


# Each subdirectory must supply rules for building sources it contributes
src/Husain\ Eftekher\ HomeWork2.o: ../src/Husain\ Eftekher\ HomeWork2.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Husain Eftekher HomeWork2.d" -MT"src/Husain\ Eftekher\ HomeWork2.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


