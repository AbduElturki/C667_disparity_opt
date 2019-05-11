################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C6000 Compiler'
	"/home/abdu/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.2.5/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/home/abdu/ti/ccsv8/tools/compiler/ti-cgt-c6000_8.2.5/include" --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


