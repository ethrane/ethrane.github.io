# Basic Makefile

# "all" is the default target called by make if no option is specified.
# "Executable" is the name of the executable that will be made.  You
# can change it to whatever you want.
all: Executable

# Define Executable...
# add .o files to the end of both of these lines to include more source code.
Executable: Template.o MathTools.o
	g++ -o Executable Template.o MathTools.o

# For every new .o file you add, you must add another two lines like these:
Template.o: Template.cpp
	g++ -Wall -c -o Template.o Template.cpp
MathTools.o: MathTools.cpp
	g++ -Wall -c -o MathTools.o MathTools.cpp

# This clean section is supposed to delete temporary .o files.
# Currently, it is is not working.
clean:
	rm -f *.o
