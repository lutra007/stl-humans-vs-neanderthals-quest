#!make -f

all: demo
	./$<

demo:  Demo.o 
	clang++-5.0 -std=c++17 $^ -o demo

test:  Test.o 
	clang++-5.0 -std=c++17 $^ -o test

%.o: %.cpp sequence.hpp main.hpp
	clang++-5.0 -std=c++17 --compile $< -o $@

version:
	clang++-5.0 --version

clean:
	rm -f *.o demo test
