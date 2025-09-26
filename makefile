CXX = g++
CXXFLAGS = -Wall -g


all: submission

submission: submission.o file_operations.o point.o
	$(CXX) $(CXXFLAGS) submission.o file_operations.o point.o -o submission

submission.o: submission.cpp
	$(CXX) $(CXXFLAGS) -c submission.cpp

file_operations.o: file_operations.cpp file_operations.h
	$(CXX) $(CXXFLAGS) -c file_operations.cpp

point.o: point.cpp point.h
	$(CXX) $(CXXFLAGS) -c point.cpp

run: clean submission
	./submission input.txt output.txt

test: clean submission
	./submission test

clean:
	rm -f *.o submission