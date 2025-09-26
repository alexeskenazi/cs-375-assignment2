CXX = g++
CXXFLAGS = -Wall -g


all: submission

submission: submission.o read_input_file.o
	$(CXX) $(CXXFLAGS) submission.o read_input_file.o -o submission

submission.o: submission.cpp
	$(CXX) $(CXXFLAGS) -c submission.cpp

read_input_file.o: read_input_file.cpp read_input_file.h
	$(CXX) $(CXXFLAGS) -c read_input_file.cpp

run: clean submission
	./submission input.txt output.txt

test: clean submission
	./submission inputFile.txt outputFile.txt test

clean:
	rm -f *.o submission