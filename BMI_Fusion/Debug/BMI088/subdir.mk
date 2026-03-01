################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BMI088/bmi088.c 

OBJS += \
./BMI088/bmi088.o 

C_DEPS += \
./BMI088/bmi088.d 


# Each subdirectory must supply rules for building sources it contributes
BMI088/%.o BMI088/%.su BMI088/%.cyclo: ../BMI088/%.c BMI088/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BMI088

clean-BMI088:
	-$(RM) ./BMI088/bmi088.cyclo ./BMI088/bmi088.d ./BMI088/bmi088.o ./BMI088/bmi088.su

.PHONY: clean-BMI088

