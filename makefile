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
	./submission input1.txt output1.txt
	./submission input2.txt output2.txt
	./submission input3.txt output3.txt
	./submission input4.txt output4.txt

test: clean submission
	./submission test

clean:
	rm -f *.o submission