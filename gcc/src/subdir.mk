# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/mysql.cpp 

OBJS += \
./src/mysql.o 

CPP_DEPS += \
./src/mysql.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -I"../../core/src" -I"../../lib/mysql-connector-c/include" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


