#  Makefile to build Programming Assignment 2
#  10-8-10
#  Chip Bell

# Compiler
#C++ = g++ -02 -pg -fprofile-arcs -ftest-coverage
C++ = g++ -O3 
#  OpenGL libraries
FRAMEWORKS = -framework GLUT -framework OpenGL

# exectuable name
T1 = pollutionTest

# My Source
INCLUDES = *.h
OBJS = display.o interaction.o globals.o step.o

$(T1): main.cpp $(OBJS) $(INCLUDES) tags makefile
	$(C++)  main.cpp -o $(T1) $(OBJS) $(FRAMEWORKS)

display.o: display.cpp $(INCLUDES)
	$(C++) -c display.cpp

interaction.o: interaction.cpp $(INCLUDES) 
	$(C++) -c interaction.cpp 

globals.o: globals.cpp $(INCLUDES)
	$(C++) -c globals.cpp

step.o: step.cpp $(INCLUDES)
	$(C++) -c step.cpp

tags: *.cpp *.h 
	ctags *.h *.cpp 

clean:
	rm -f *.gcda
	rm -f *.gcov
	rm -f *.gcno
	rm -f *.o

pristine: clean
	rm -f $(T1)
	rm -f tags
