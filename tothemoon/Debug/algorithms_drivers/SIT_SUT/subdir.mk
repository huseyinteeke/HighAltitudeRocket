################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../algorithms_drivers/SIT_SUT/SIT_SUT.c 

OBJS += \
./algorithms_drivers/SIT_SUT/SIT_SUT.o 

C_DEPS += \
./algorithms_drivers/SIT_SUT/SIT_SUT.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms_drivers/SIT_SUT/%.o algorithms_drivers/SIT_SUT/%.su algorithms_drivers/SIT_SUT/%.cyclo: ../algorithms_drivers/SIT_SUT/%.c algorithms_drivers/SIT_SUT/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/High_altitude_rocket/tothemoon/algorithms_drivers/SIT_SUT -I"C:/High_altitude_rocket/tothemoon/Thirdparty/SEGGER/Config" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/SEGGER/OS" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/SEGGER/SEGGER" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/FreeRTOS" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/FreeRTOS/include" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"C:/High_altitude_rocket/tothemoon/algorithms_drivers/SensorsWeHave" -I"C:/High_altitude_rocket/tothemoon/tasks" -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-algorithms_drivers-2f-SIT_SUT

clean-algorithms_drivers-2f-SIT_SUT:
	-$(RM) ./algorithms_drivers/SIT_SUT/SIT_SUT.cyclo ./algorithms_drivers/SIT_SUT/SIT_SUT.d ./algorithms_drivers/SIT_SUT/SIT_SUT.o ./algorithms_drivers/SIT_SUT/SIT_SUT.su

.PHONY: clean-algorithms_drivers-2f-SIT_SUT

