################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"/home/abdu/ti/ti-cgt-c6000_8.2.2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/home/abdu/ti/ti-cgt-c6000_8.2.2/include" --diag_wrap=off --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


