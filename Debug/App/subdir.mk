################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../App/app.cpp \
../App/uart_fixed_len_recv.cpp \
../App/uart_flex_len_recv.cpp 

OBJS += \
./App/app.o \
./App/uart_fixed_len_recv.o \
./App/uart_flex_len_recv.o 

CPP_DEPS += \
./App/app.d \
./App/uart_fixed_len_recv.d \
./App/uart_flex_len_recv.d 


# Each subdirectory must supply rules for building sources it contributes
App/app.o: ../App/app.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../App -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/app.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
App/uart_fixed_len_recv.o: ../App/uart_fixed_len_recv.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../App -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/uart_fixed_len_recv.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
App/uart_flex_len_recv.o: ../App/uart_flex_len_recv.cpp
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DSTM32F103xE -DUSE_HAL_DRIVER -DDEBUG -c -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../App -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-threadsafe-statics -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"App/uart_flex_len_recv.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

