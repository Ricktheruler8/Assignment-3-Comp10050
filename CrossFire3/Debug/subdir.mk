################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../assignType.c \
../attack.c \
../boardOps.c \
../main.c \
../modCapabilties.c \
../reverseCapabilities.c \
../slotAdj.c \
../slotTypes.c \
../typeElf.c \
../typeHuman.c \
../typeOgre.c \
../typeWizard.c \
../userInt.c 

OBJS += \
./assignType.o \
./attack.o \
./boardOps.o \
./main.o \
./modCapabilties.o \
./reverseCapabilities.o \
./slotAdj.o \
./slotTypes.o \
./typeElf.o \
./typeHuman.o \
./typeOgre.o \
./typeWizard.o \
./userInt.o 

C_DEPS += \
./assignType.d \
./attack.d \
./boardOps.d \
./main.d \
./modCapabilties.d \
./reverseCapabilities.d \
./slotAdj.d \
./slotTypes.d \
./typeElf.d \
./typeHuman.d \
./typeOgre.d \
./typeWizard.d \
./userInt.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

