################################################################################
# @brief Compiles the code and then runs the created executable.
################################################################################
default: build run

################################################################################
# @brief Compiles main.c into executable run_test. Directory inc is included 
#        in the build and external library gpiod is linked to the directory.
#        Warnings are enabled and compilation error will occur at every
#        occurance of a warning. All warnings and errors must therefore be
#        solved before the executable is created.
################################################################################
build:
	@gcc ../src/main.c -o run_test -Wall -Werror -l gpiod -I ../inc

################################################################################
# @brief Runs executable run_test.
################################################################################
run:
	@./run_test