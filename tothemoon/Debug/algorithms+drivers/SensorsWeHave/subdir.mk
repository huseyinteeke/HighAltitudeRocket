################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../algorithms+drivers/SensorsWeHave/bme280.c 

OBJS += \
./algorithms+drivers/SensorsWeHave/bme280.o 

C_DEPS += \
./algorithms+drivers/SensorsWeHave/bme280.d 


# Each subdirectory must supply rules for building sources it contributes
algorithms+drivers/SensorsWeHave/%.o algorithms+drivers/SensorsWeHave/%.su algorithms+drivers/SensorsWeHave/%.cyclo: ../algorithms+drivers/SensorsWeHave/%.c algorithms+drivers/SensorsWeHave/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I"C:/High_altitude_rocket/tothemoon/algorithms+drivers/SensorsWeHave" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/SEGGER/Config" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/SEGGER/OS" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/SEGGER/SEGGER" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/FreeRTOS" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/FreeRTOS/include" -I"C:/High_altitude_rocket/tothemoon/Thirdparty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/High_altitude_rocket/tothemoon/algorithms+drivers/SensorsWeHave" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-algorithms-2b-drivers-2f-SensorsWeHave

clean-algorithms-2b-drivers-2f-SensorsWeHave:
	-$(RM) ./algorithms+drivers/SensorsWeHave/bme280.cyclo ./algorithms+drivers/SensorsWeHave/bme280.d ./algorithms+drivers/SensorsWeHave/bme280.o ./algorithms+drivers/SensorsWeHave/bme280.su

.PHONY: clean-algorithms-2b-drivers-2f-SensorsWeHave

